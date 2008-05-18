/*
 * Copyright (c) 2004 - 2005, Simon Moore (simon@snmoore.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  Redistributions of source code must retain the above copyright notice, this
 *  list of conditions and the following disclaimer.
 *
 *  Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 *  Neither the name of Simon Moore, snmoore.net nor the names of its
 *  contributors may be used to endorse or promote products derived from this
 *  software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * History
 *
 * Date     Bug#    Author              Description
 * -----------------------------------------------------------------------------
 * 20050130 1       simon@snmoore.net   Add initial types support
 * 20050404 4       simon@snmoore.net	Fix 64bit limits and do not try to use
 *                                      long long when not c99
 */


/* Check for circular includes */
#if !defined(SNM_TYPES_HEADER)
#define SNM_TYPES_HEADER


/* Standard includes */
#include <limits.h>     /* Required for integer limits */

/* Default to C99 (ISO/IEC 9899:1999) types if available */
#if __STDC_VERSION__ == 199901L
    #include <stdint.h>
    #define SNM_64BIT_TYPES_AVAILABLE
#else
    /* Not using C99, but we'll try to typedef similar types */
    #if !defined(SNM_CTOOLKIT_TYPES_IN_USE)
        #define SNM_CTOOLKIT_TYPES_IN_USE
    #endif

    /* Define sensible integer types, similar to C99 */
    #if CHAR_BIT != 8
        #error CHAR_BIT !=8, cannot safely typedef integer types
    #else
        /*
         * Reminder:
         *      sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long)
         *
         *      char         >= 8-bits
         *      short        >= 16-bits  
         *      int          >= 16-bits
         *      long         >= 32-bits
         *      long long    >= 64-bits (C99 only)
         */

	    /* C has no equivalent of #ifdef or defined() for typedefs
	     *
	     * So we create new tyepdefs here; if typedefs already exist
	     * this will result in compiler warnings due to redeclarations,
	     * but the only other option is a ./configure approach
         */

        /* 8-bit integer types (unsigned limit 2^8 - 1) */
        #if 255U == UCHAR_MAX
            typedef   signed char           int8_t;
            typedef unsigned char          uint8_t;
        #else
            #error Cannot find a valid 8-bit integer type
        #endif

        #define  INT8_MIN -128
        #define  INT8_MAX  127
        #define UINT8_MAX  255U

        /* 16-bit integer types (unsigned limit 2^16 - 1) */
        #if   65535U == USHRT_MAX
            typedef   signed short     int  int16_t;
            typedef unsigned short     int uint16_t;
        #elif 65535U == UINT_MAX
            typedef   signed           int  int16_t;
            typedef unsigned           int uint16_t;
        #else
            #error Cannot find a valid 16-bit integer type
        #endif

        #define  INT16_MIN -32768
        #define  INT16_MAX  32767
        #define UINT16_MAX  65535U

        /* 32-bit integer types (unsigned limit 2^32 - 1) */
        #if   4294967295U == USHRT_MAX
            typedef   signed short     int  int32_t;
            typedef unsigned short     int uint32_t;
        #elif 4294967295U == UINT_MAX
            typedef   signed           int  int32_t;
            typedef unsigned           int uint32_t;
        #elif 4294967295U == ULONG_MAX
            typedef   signed long      int  int32_t;
            typedef unsigned long      int uint32_t;
        #else
            #error Cannot find a valid 32-bit integer type
        #endif

        #define  INT32_MIN -2147483648
        #define  INT32_MAX  2147483647
        #define UINT32_MAX  4294967295U

        /*
         * 64-bit integer types (unsigned limit 2^64 - 1)
         *
         * Note: cannot use 64-bit value 18446744073709551616 without
         *       protection, as 64-bit types may not be available
         */
        #if   4294967295U < USHRT_MAX
            #if 18446744073709551615U == USHRT_MAX
                typedef   signed short     int  int64_t;
                typedef unsigned short     int uint64_t;
                #define SNM_64BIT_TYPES_AVAILABLE
            #endif
        #elif 4294967295U < UINT_MAX
            #if 18446744073709551615U == UINT_MAX
                typedef   signed int       int  int64_t;
                typedef unsigned int       int uint64_t;
                #define SNM_64BIT_TYPES_AVAILABLE
            #endif
        #elif 4294967295U < ULONG_MAX
            #if 18446744073709551615U == ULONG_MAX
                typedef   signed long      int  int64_t;
                typedef unsigned long      int uint64_t;
                #define SNM_64BIT_TYPES_AVAILABLE
            #endif
        #else
            /* A valid 64-bit integer type may not be available */
        #endif

        #if defined(SNM_64BIT_TYPES_AVAILABLE)
            #define  INT64_MIN  -9223372036854775808
            #define  INT64_MAX   9223372036854775807
            #define UINT64_MAX  18446744073709551615U
        #endif

        /* Maximal size integer types */
        #if defined(SNM_64BIT_TYPES_AVAILABLE)
            typedef  int64_t  intmax_t;
            typedef uint64_t uintmax_t; 
            #define  INTMAX_MIN  INT64_MIN
            #define  INTMAX_MAX  INT64_MAX
            #define UINTMAX_MAX UINT64_MAX
        #else
            typedef  int32_t  intmax_t;
            typedef uint32_t uintmax_t;             
            #define  INTMAX_MIN  INT32_MIN
            #define  INTMAX_MAX  INT32_MAX
            #define UINTMAX_MAX UINT32_MAX
        #endif
    #endif /* CHAR_BIT != 8 */
#endif /* __STDC_VERSION__ == 199901L */

/* Define character types, using a similar naming convention */
typedef   signed char  char_t;
typedef unsigned char uchar_t;

typedef uint8_t  utf8_t;
typedef uint16_t utf16_t;

/*
 * Define a boolean type, using a similar naming convention 
 * - see the C FAQ questions 9.1 and 9.2 for guidelines on using this
 *   (currently http://www.eskimo.com/~scs/C-faq)
 */
#if !defined(FALSE) && !defined(TRUE)
    typedef enum {
        FALSE,
        TRUE
    } bool_t;
#else
    #error Cannot safely typedef boolean type, as FALSE and/or TRUE exist
#endif

/* Pickup NULL from stddef.h, to match FALSE and TRUE naming convention */
#include <stddef.h>
#if !defined(NULL)
    #error Cannot find standard definition for NULL
#endif  


/* Check for circular includes */    
#else
#error Circular include with snm_types.h 
#endif
