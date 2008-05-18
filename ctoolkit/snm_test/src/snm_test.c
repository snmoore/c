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
 * 20050202 2       simon@snmoore.net   Add initial debug support
 */


/* Feature test switches */

/* Standard includes */
#include <stdio.h>              /* For printf */

/* Local includes */
#include "snm_types.h"          /* For utf8_t and int_t */
#include "snm_test.h"           /* For SNM_TEST_RESULT */

/* Asserts and debugging */
#define SNM_ASSERT  (SNM_ASSERT_ENABLED)
#define SNM_DEBUG   (SNM_DEBUG_DISABLED)
#include "snm_debug.h"

/* Structure to describe an individual test */
typedef struct {
    utf8_t*         Identifier;
    utf8_t*         Description;
    SNM_TEST_RESULT (*Function)();
    SNM_TEST_RESULT Result;
} TEST;    

/*
 * Text strings corresponding to SNM_TEST_RESULT 
 * Tabs are put in here to make layout easier
 */
static const utf8_t* ResultStrings[] = {
    /* This is a lazy way of initialising UTF8 strings
     * - casts are required because the platform char type may be signed or 
     *   unsigned (the C standards allow either), but utf8_t is unsigned
     */
    (utf8_t*)"Inconclusive",
    (utf8_t*)"Pass\t",
    (utf8_t*)"Fail\t"
};

/* Generate function declarations for the individual tests */
#define SNM_TEST_START(Identifier)
#define SNM_TEST_DESCRIPTION(Description)
#define SNM_TEST_FUNCTION(Function) extern SNM_TEST_RESULT Function(void);
#define SNM_TEST_END

#include "snm_test_types_misc.h"
#include "snm_test_types_sizes.h"
#include "snm_test_types_limits.h"
#include "snm_test_debug_asserts.h"
#include "snm_test_debug_debugs.h"

#undef SNM_TEST_START
#undef SNM_TEST_DESCRIPTION
#undef SNM_TEST_FUNCTION
#undef SNM_TEST_END

/* Generate an array of the individual tests */
static TEST Tests[] = {
    /*
     * This is a lazy way of initialising UTF8 strings
     * - casts are required because the platform char type may be signed or 
     *   unsigned (the C standards allow either), but utf8_t is unsigned
     */
    #define SNM_TEST_START(Identifier)          { (utf8_t*)Identifier,
    #define SNM_TEST_DESCRIPTION(Description)     (utf8_t*)Description,

    #define SNM_TEST_FUNCTION(Function)           Function,
    #define SNM_TEST_END                          SNM_TEST_INCONCLUSIVE },

    #include "snm_test_types_misc.h"
    #include "snm_test_types_sizes.h"
    #include "snm_test_types_limits.h"
    #include "snm_test_debug_asserts.h"
    #include "snm_test_debug_debugs.h"

    /* The trailing comma after the last test is not legal for C89 */ 
    { 
        (utf8_t*)"Invalid",
        (utf8_t*)"Marker for end of Tests array",
        NULL,
        SNM_TEST_INCONCLUSIVE    
    }

    #undef SNM_TEST_START
    #undef SNM_TEST_DESCRIPTION
    #undef SNM_TEST_FUNCTION
    #undef SNM_TEST_END
};

/* Return type is int, as defined by the C standards */
int main(void) {
    unsigned int NumTests           = (sizeof(Tests) / sizeof(TEST)) - 1;
    unsigned int NumInconclusive    = 0;
    unsigned int NumPass            = 0;
    unsigned int NumFail            = 0;
    unsigned int i;

    /* Run each test in order, tracking and printing the results */
    printf("\nTest\t\tResult\t\tDescription\n");
    printf(  "====\t\t======\t\t===========\n");
    for(i = 0; i < NumTests; i++) {
        Tests[i].Result = Tests[i].Function();

        printf("%s\t%s\t%s\n", Tests[i].Identifier,
                                ResultStrings[Tests[i].Result],
                                Tests[i].Description);

        switch(Tests[i].Result) {
            case SNM_TEST_INCONCLUSIVE:
                NumInconclusive++;
                break;
            case SNM_TEST_PASS:
                NumPass++;
                break;
            case SNM_TEST_FAIL:
                NumFail++;
                break;
            default:
                snm_assert(FALSE, "Invalid test result %d", Tests[i].Result);
                break;
        }
    }

    printf("\nTest Totals\n");
    printf(  "===========\n");
    printf(  "Inconclusive:\t%u\n", NumInconclusive);
    printf(  "Pass:\t\t%u\n",       NumPass);
    printf(  "Fail:\t\t%u\n",       NumFail);
    snm_assert(NumTests == (NumInconclusive + NumPass + NumFail),
               "Test totals do not add up (out by %d)",
               NumTests - NumInconclusive - NumPass - NumFail);

    /* Return 0 if all pass, else the count of the failures & inconclusive */
    return NumTests - NumPass;
}
