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
 * 20050202 2       simon@snmoore.net   Add initial debug support
 */


/* No check for circular includes here - may be parsed many times */


/*
 * Macros to enable or disable asserts and debugging
 *
 * DISABLED and ENABLED control everything; use of DISABLED is not recommended
 *
 * CRITICAL, IMPORTANT and TRIVIAL are addititive e.g. enabling TRIVIAL will
 * also enable CRITICAL and IMPORTANT
 */
#define SNM_ASSERT_DISABLED (0)
#define SNM_ASSERT_ENABLED  (1)

#define SNM_DEBUG_DISABLED  (0)
#define SNM_DEBUG_TRIVIAL   (1)
#define SNM_DEBUG_IMPORTANT (2)
#define SNM_DEBUG_CRITICAL  (4)

/* Function prototypes for the underlying functions */
#if __STDC_VERSION__ == 199901L
    /*
     * For C99 we can use variadic macros to map onto the underlying functions
     *
     * This allows logging of the filename, line number and function name, in
     * addition to the user-supplied format and variadic arguments
     */
    extern void snm_assert_write(const char *File, uint32_t Line,
                                 const char *Function,
                                 const char *Format, ...);

    extern void  snm_debug_write(const char *File, uint32_t Line,
                                 const char *Function,
                                 const char *Format, ...);
#else
    /*
     * For ANSI/C89/C90 we cannot use variadic macros
     *
     * This only allows the user-supplied format and variadic arguments, and the
     * test has to be performed within the underlying function
     */
    extern void snm_assert_write(int Test, const char *Format, ...);
    extern void snm_debug_write(const char *Format, ...);

    /*
     * Because ANSI/C89/C90 cannot use variadic macros, we cannot simply
     * disable a macro (map it to nothing) without causing warnings or errors
     * So we have to map it to a no-op function
     */
    extern void snm_assert_null(int Test, const char *Format, ...);
    extern void snm_debug_null(const char *Format, ...);
#endif

/* Macros to map asserts to the underlying functions */
#undef snm_assert
#if __STDC_VERSION__ == 199901L
    /* C99, so variadic macros are available */
    #if SNM_ASSERT != SNM_ASSERT_DISABLED
        /* Use variadic macros to test first, then call with extra arguments */
        #define snm_assert(Test, Format, ...)           \
            if(!(Test)) {                               \
                snm_assert_write(__FILE__, __LINE__,    \
                                 __func__,              \
                                 Format, __VA_ARGS__);  \
            }
    #else
        /* Do not map to anything, and discard all arguments */
        #define snm_assert(Format, ...)
    #endif
#else
    /* ANSI/C89/C90, so variadic macros are not available */
    #if SNM_ASSERT != SNM_ASSERT_DISABLED
        /* Map directly to the underlying function; call first, then test */
        #define snm_assert snm_assert_write
    #else
        /* Map to a no-op function */
        #define snm_assert snm_assert_null
    #endif
#endif

/* Macros to map debugs to the underlying functions */
#undef snm_debug_trivial
#undef snm_debug_important
#undef snm_debug_critical
#undef snm_debug_temp
#if __STDC_VERSION__ == 199901L
    /* C99, so variadic macros are available */
    #if SNM_DEBUG != SNM_DEBUG_DISABLED
        /*
         * CRITICAL, IMPORTANT and TRIVIAL are addititive
         * E.g. enabling TRIVIAL will also enable CRITICAL and IMPORTANT
         */
        #if (SNM_DEBUG_TRIVIAL      & SNM_DEBUG)
            #define snm_debug_trivial   snm_debug_temp
            #define snm_debug_important snm_debug_temp
            #define snm_debug_critical  snm_debug_temp
        #elif (SNM_DEBUG_IMPORTANT  & SNM_DEBUG)
            #define snm_debug_trivial(Format, ...)      /* Disabled */
            #define snm_debug_important snm_debug_temp
            #define snm_debug_critical  snm_debug_temp
        #elif (SNM_DEBUG_CRITICAL   & SNM_DEBUG)
            #define snm_debug_trivial(Format, ...)      /* Disabled */
            #define snm_debug_important(Format, ...)    /* Disabled */
            #define snm_debug_critical  snm_debug_temp
        #endif /* No else clause, as no other SNM_DEBUG value is valid */

        /* Use variadic macros to call with extra arguments */
        #define snm_debug_temp(Format, ...) \
            snm_debug_write(__FILE__, __LINE__, __func__, Format, __VA_ARGS__);
    #else
        /* Do not map to anything, and discard all arguments */
        #define snm_debug_trivial(Format, ...)
        #define snm_debug_important(Format, ...)
        #define snm_debug_critical(Format, ...)
    #endif
#else
    /* ANSI/C89/C90, so variadic macros are not available */
    #if SNM_DEBUG != SNM_DEBUG_DISABLED
        /* Map directly to the underlying function */
        #if (SNM_DEBUG_TRIVIAL      & SNM_DEBUG)
            #define snm_debug_trivial   snm_debug_write
            #define snm_debug_important snm_debug_write
            #define snm_debug_critical  snm_debug_write
        #elif (SNM_DEBUG_IMPORTANT  & SNM_DEBUG)
            #define snm_debug_trivial   snm_debug_null  /* Disabled */
            #define snm_debug_important snm_debug_write
            #define snm_debug_critical  snm_debug_write
        #elif (SNM_DEBUG_CRITICAL   & SNM_DEBUG)
            #define snm_debug_trivial   snm_debug_null  /* Disabled */
            #define snm_debug_important snm_debug_null  /* Disabled */
            #define snm_debug_critical  snm_debug_write
        #endif /* No else clause, as no other SNM_DEBUG value is valid */
    #else
        /* Map to a no-op function */
        #define snm_debug_trivial   snm_debug_null
        #define snm_debug_important snm_debug_null
        #define snm_debug_critical  snm_debug_null
    #endif
#endif
