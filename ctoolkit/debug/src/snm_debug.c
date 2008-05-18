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


/* Feature test switches */

/* Standard includes */
#include <stdarg.h>             /* For variadic arguments */
#include <stdio.h>              /* For various printf */
#include <stdlib.h>             /* For abort */

/* Local includes */
#include "snm_types.h"          /* For uint32_t */

/* Set a limit for the size of output buffers
 * If this is changed, you must update test snm_test_debug_asserts_9
 */
#define SNM_DEBUG_BUFFER_SIZE (255)

/* Called for an assert: write an output message and then abort */
#if __STDC_VERSION__ == 199901L
    /*
     * For C99 we can use variadic macros to map onto the underlying functions
     *
     * This allows logging of the filename, line number and function name, in
     * addition to the user-supplied format and variadic arguments
     */
    void snm_assert_write(const char *File, uint32_t Line,
                          const char *Function,
                          const char *Format, ...) {
        char String[SNM_DEBUG_BUFFER_SIZE];
        int Count = 0;
        va_list ap;

        /*
         * Write the standard arguments to the string buffer
         *
         * Note that Count does not include the terminating null
         */
        Count = snprintf(String, SNM_DEBUG_BUFFER_SIZE,
                         "ASSERT! %s, line %i, %s() : ",
                         File, Line, Function);

        /*
         * Write the user-supplied variadic arguments to the string buffer
         *
         * Note that Count does not include the terminating null, and we need
         * to save 1 char for a subsequent newline
         */
        va_start(ap, Format);
        vsnprintf(String + Count, SNM_DEBUG_BUFFER_SIZE - Count - 1,
                  Format, ap);
        va_end(ap);

        /*
         * Output the result, with a newline
         *
         * It should actually be safe to use strcat here, as vsnprintf should
         * have performed all the necessary expansion for the format specifiers
         */
        printf("%s\n", String);

        /* This is an assert, so now we die */
        abort();
    }
#else
    /*
     * For ANSI/C89/C90 we cannot use variadic macros
     *
     * This only allows the user-supplied format and variadic arguments, and the
     * test has to be performed within the underlying function
     */
    void snm_assert_write(int Test, const char *Format, ...) {
        char String[SNM_DEBUG_BUFFER_SIZE];
        int Count = 0;
        va_list ap;

        /* If the test passes, return immediately */
        if(Test) return;
        
        /*
         * As this is not C99, we do not have the __FILE__ etc arguments
         *
         * Note that Count does not include the terminating null
         */
        Count = sprintf(String, "ASSERT! : ");

        /*
         * We do not know how large the Format and arguments will be until they
         * are actually processed, but then there is little that can be done
         *
         * Note that Count does not include the terminating null, and we need
         * to save 1 char for a subsequent newline
         */
        if(Count + 2 < SNM_DEBUG_BUFFER_SIZE) {
            /* Write the user-supplied variadic arguments to the string */
            va_start(ap, Format);
            vsprintf(String + Count, Format, ap);
            va_end(ap);

            /*
             * Output the result, with a newline
             *
             * It should actually be safe to use strcat here, as vsprintf
             * should have performed all the necessary expansion for the format
             * specifiers
             */
            printf("%s\n", String);
        } else if(Count + 2 == SNM_DEBUG_BUFFER_SIZE) {
            /* Just enough space to output the standard arguments */
            printf("%s", String);
        }
        /* No final else clause - we've already overrun the string buffer */

        /* This is an assert, so now we die */
        abort();
    }

    /*
     * Because ANSI/C89/C90 cannot use variadic macros, we cannot simply
     * disable a macro (map it to nothing) without causing warnings or errors
     * So we have to map it to a no-op function
     */
    void snm_assert_null(int Test, const char *Format, ...) {
        /* Do nothing */
    }
#endif

/* Called for a debug: write an output message */
#if __STDC_VERSION__ == 199901L
    /*
     * For C99 we can use variadic macros to map onto the underlying functions
     *
     * This allows logging of the filename, line number and function name, in
     * addition to the user-supplied format and variadic arguments
     */
    void snm_debug_write(const char *File, uint32_t Line,
                         const char *Function,
                         const char *Format, ...) {
        char String[SNM_DEBUG_BUFFER_SIZE];
        int Count = 0;
        va_list ap;

        /*
         * Write the standard arguments to the string buffer
         *
         * Note that Count does not include the terminating null
         */
        Count = snprintf(String, SNM_DEBUG_BUFFER_SIZE,
                         "DEBUG! %s, line %i, %s() : ",
                         File, Line, Function);

        /*
         * Write the user-supplied variadic arguments to the string buffer
         *
         * Note that Count does not include the terminating null, and we need
         * to save 1 char for a subsequent newline
         */
        va_start(ap, Format);
        vsnprintf(String + Count, SNM_DEBUG_BUFFER_SIZE - Count - 1,
                  Format, ap);
        va_end(ap);

        /*
         * Output the result, with a newline
         *
         * It should actually be safe to use strcat here, as vsnprintf should
         * have performed all the necessary expansion for the format specifiers
         */
        printf("%s\n", String);
    }
#else
    /*
     * For ANSI/C89/C90 we cannot use variadic macros
     *
     * This only allows the user-supplied format and variadic arguments, and the
     * test has to be performed within the underlying function
     */
    void snm_debug_write(const char *Format, ...) {
        char String[SNM_DEBUG_BUFFER_SIZE];
        int Count = 0;
        va_list ap;
        
        /*
         * As this is not C99, we do not have the __FILE__ etc arguments
         *
         * Note that Count does not include the terminating null
         */
        Count = sprintf(String, "DEBUG! : ");

        /*
         * We do not know how large the Format and arguments will be until they
         * are actually processed, but then there is little that can be done
         *
         * Note that Count does not include the terminating null, and we need
         * to save 1 char for a subsequent newline
         */
        if(Count + 2 < SNM_DEBUG_BUFFER_SIZE) {
            /* Write the user-supplied variadic arguments to the string */
            va_start(ap, Format);
            vsprintf(String + Count, Format, ap);
            va_end(ap);

            /*
             * Output the result, with a newline
             *
             * It should actually be safe to use strcat here, as vsprintf
             * should have performed all the necessary expansion for the format
             * specifiers
             */
            printf("%s\n", String);
        } else if(Count + 2 == SNM_DEBUG_BUFFER_SIZE) {
            /* Just enough space to output the standard arguments */
            printf("%s", String);
        }
        /* No final else clause - we've already overrun the string buffer */
    }

    /*
     * Because ANSI/C89/C90 cannot use variadic macros, we cannot simply
     * disable a macro (map it to nothing) without causing warnings or errors
     * So we have to map it to a no-op function
     */
    void snm_debug_null(const char *Format, ...) {
        /* Do nothing */
    }
#endif
