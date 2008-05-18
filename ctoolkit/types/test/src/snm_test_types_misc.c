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
 */


/* Feature test switches */

/* Standard includes */

/* Local includes */
#include "snm_types.h"          /* The types that are under test */
#include "snm_test.h"           /* For SNM_TEST_RESULT */

/* Asserts and debugging */
#define SNM_ASSERT  (SNM_ASSERT_DISABLED)
#define SNM_DEBUG   (SNM_DEBUG_DISABLED)
#include "snm_debug.h"

/* Using CToolkit types when in C99 (ISO/IEC 9899:1999) mode */
SNM_TEST_RESULT snm_test_types_misc_1(void) {
    #if __STDC_VERSION__ == 199901L
        #if defined(SNM_CTOOLKIT_TYPES_IN_USE)
            return SNM_TEST_FAIL;
        #else
            return SNM_TEST_PASS;
        #endif
    #else
            return SNM_TEST_INCONCLUSIVE;
    #endif
}

/* FALSE exists and is 0 */
SNM_TEST_RESULT snm_test_types_misc_2(void) {
    return (0 == FALSE) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* TRUE exists and is 1 */
SNM_TEST_RESULT snm_test_types_misc_3(void) {
    return (1 == TRUE) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* NULL exists and is a reasonable null pointer constant */
SNM_TEST_RESULT snm_test_types_misc_4(void) {
    #if defined(NULL)
        return (NULL == (void*)0) ? SNM_TEST_PASS : SNM_TEST_INCONCLUSIVE;
    #else
        return SNM_TEST_FAIL;
    #endif
}
