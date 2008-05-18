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
 * 20050203 2       simon@snmoore.net   Add initial debug support
 */


/* Feature test switches */
#define _POSIX_SOURCE           /* For POSIX compliance */

/* Standard includes */
#include <stdlib.h>             /* For exit */
#include <stdio.h>              /* For FILE, fdopen, fclose, fgets */
#include <errno.h>              /* For global errno variable */
#include <string.h>             /* For strstr, strlen, memset */
#include <unistd.h>             /* POSIX, for pipe, fork, dup2, close */
#include <sys/wait.h>           /* POSIX, for wait */
#include <signal.h>             /* POSIX, for SIGABRT */

/* Local includes */
#include "snm_types.h"          /* For TRUE */
#include "snm_test.h"           /* For SNM_TEST_RESULT */

/* Asserts and debugging */
#define SNM_DEBUG (SNM_DEBUG_CRITICAL)
#include "snm_debug.h"

/* Size should correlate with snm_debug.c */
#define SNM_DEBUG_BUFFER_SIZE (255)

/* Global text array, used for snm_test_debug_asserts_9 */
char Text[SNM_DEBUG_BUFFER_SIZE];

/* Result from safely performing the assert */
typedef enum {
    SNM_SAFE_ASSERT_UNKNOWN_ERROR,
    SNM_SAFE_ASSERT_ASSERTED,
    SNM_SAFE_ASSERT_NO_ASSERT
} SNM_SAFE_ASSERT;


/* Common function to test asserts safely (i.e without aborting) */
SNM_TEST_RESULT snm_test_debug_safe_assert(void(*Function)(void),
                                           SNM_SAFE_ASSERT ExpectedResult,
                                           const char *ExpectedString) {
    int Status;     /* Exit status of the child */
    int Pipe[2];    /* Pipe from child to parent, STDOUT redirects to this */
    FILE *Read;     /* File handle used to read from the pipe */
    char *String;   /* Pointer to string (if any) captured from the child */
    char Buffer[SNM_DEBUG_BUFFER_SIZE] = { '\0' };

    /* Create a pipe to capture STDOUT from child and pipe it to the parent */
    if(pipe(&Pipe[0]) != 0) {
        snm_debug_critical("Failed to create pipe", NULL);
        return SNM_TEST_INCONCLUSIVE;
    }

    /* Create a child process to use for asserts */
    switch(fork()) {
        case -1:
            /* Problem creating the child process */
            snm_debug_critical("Failed to fork child process", NULL);
            return SNM_TEST_INCONCLUSIVE;
        case 0:
            /*
             * This is the child process (fork returns 0 to the child)
             */
            snm_debug_trivial("Child: forked successfully", NULL);

            /* Redirect STDOUT to the pipe */
            if(dup2(Pipe[1], STDOUT_FILENO) != STDOUT_FILENO) {
                snm_debug_critical("Failed to redirect STDOUT=>pipe, error %i",
                                   errno);
            }

            /* Close unused file descriptors */
            if( !( (close(Pipe[0]) == 0) &&
                   (close(Pipe[1]) == 0)    ) ) {
                return SNM_TEST_INCONCLUSIVE;
            }

            /*
             * So now any debug or assert that writes to STDOUT will
             * actually be redirected through the pipe to the parent
             */

            /* Perform the assert */
            if(Function != NULL) {
                Function();
            }

            /* Exit normally, if we got this far (assert test was true) */
            exit(EXIT_SUCCESS);
            break;
        default:
            /*
             * This is the parent process (fork returns child pid to parent)
             */
            snm_debug_trivial("Parent: forked successfully", NULL);

            /* Use the pipe for reading */
            if((Read = fdopen(Pipe[0], "r")) == NULL) {
                snm_debug_critical("Parent: failed to read from pipe, error %i",
                                   errno);
                return SNM_TEST_INCONCLUSIVE;
            }

            /* Close unused file descriptors */
            if(close(Pipe[1]) != 0) {
                snm_debug_critical("Parent: failed to close Pipe[1], error %i",
                                   errno);
                return SNM_TEST_INCONCLUSIVE;
            }

            /* Read assert text (if any) from the pipe */
            String = fgets(Buffer, 255, Read);

            /* Wait for the child process to terminate */
            wait(&Status);

            /* Close the pipe */
            if(fclose(Read) != 0) {
                snm_debug_critical("Parent: failed to close Read, error %i",
                                   errno);
                return SNM_TEST_INCONCLUSIVE;
            }
            break;
    }

    /*
     * This code is only executed by the parent process
     */
    snm_debug_trivial("Returned from fork, only parent executing this", NULL);

    /* Did the child process terminate normally, with no assert? */
    if(WIFEXITED(Status) && (EXIT_SUCCESS == WEXITSTATUS(Status))) {
        snm_debug_trivial("Child process terminated normally, no assert", NULL);
        return (SNM_SAFE_ASSERT_NO_ASSERT == ExpectedResult) ? SNM_TEST_PASS
                                                             : SNM_TEST_FAIL;
    }

    /* Did the child process abort due to an assert? */
    if(WIFSIGNALED(Status) && (SIGABRT == WTERMSIG(Status))) {
        snm_debug_trivial("Child process aborted, with an assert", NULL);

        /* We had an assert, but were we expecting one? */
        if(SNM_SAFE_ASSERT_ASSERTED != ExpectedResult) {
                snm_debug_trivial("FAIL! Asserted, but not expected", NULL);
                return SNM_TEST_FAIL;
        }

        if((NULL == ExpectedString) && (NULL == String)) {
            /* Pass if no assert text expected, and none received */
            snm_debug_trivial("PASS! Asserted, no text expected or received",
                              NULL);
            return SNM_TEST_PASS;
        }
        else if((NULL != ExpectedString) && (NULL != String)) {
            /* Pass if assert text was expected, and we got a match */
            if(NULL != strstr(String, ExpectedString)) {
                /* The string exactly matches */
                snm_debug_trivial("PASS! Asserted, text matches", NULL);
                return SNM_TEST_PASS;
            }
            else if(strlen(String) == (SNM_DEBUG_BUFFER_SIZE -1)) {
                /* No exact match, but max length - it got truncated */
                snm_debug_trivial("PASS! Asserted, text truncated", NULL);
                return SNM_TEST_PASS;
            }
        }
        else {
            snm_debug_trivial("FAIL! Asserted, but text mismatch", NULL);
            return SNM_TEST_FAIL;
        }
    }

    /* If we get this far, then something unexpected must have happened */
    snm_debug_important("Something unexpected happened", NULL);
    if(WIFEXITED(Status)) {
        snm_debug_important("Child exited with %i", WEXITSTATUS(Status));
    }
    else if(WIFSIGNALED(Status)) {
        snm_debug_important("Child terminated upon signal %i",WTERMSIG(Status));
    }
    else if(WIFSTOPPED(Status)) {
        snm_debug_important("Child stopped upon signal %i", WSTOPSIG(Status));
    }
    return SNM_TEST_INCONCLUSIVE;
}


/* No assert when asserts disabled */
void snm_test_debug_asserts_1_assert(void) {
    /* Disable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_DISABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "No assert when asserts disabled", NULL);
}

SNM_TEST_RESULT snm_test_debug_asserts_1(void) {
    /* There should be no assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_1_assert,
                                      SNM_SAFE_ASSERT_NO_ASSERT,
                                      NULL);
}


/* No assert when test is true */
void snm_test_debug_asserts_2_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(TRUE, "No assert when test is true", NULL);
}

SNM_TEST_RESULT snm_test_debug_asserts_2(void) {
    /* There should be no assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_2_assert,
                                      SNM_SAFE_ASSERT_NO_ASSERT,
                                      NULL);
}


/* Assert when test is false */
void snm_test_debug_asserts_3_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "Assert when test is false", NULL);
}

SNM_TEST_RESULT snm_test_debug_asserts_3(void) {
    /* There should be an assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_3_assert,
                                      SNM_SAFE_ASSERT_ASSERTED,
                                      "Assert when test is false");
}


/* Assert with empty format and arguments */
void snm_test_debug_asserts_4_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "", NULL);
}

SNM_TEST_RESULT snm_test_debug_asserts_4(void) {
    /* There should be an assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_4_assert,
                                      SNM_SAFE_ASSERT_ASSERTED,
                                      "");
}


/* Assert with empty format and 1 argument */
void snm_test_debug_asserts_5_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "", SNM_DEBUG);
}

SNM_TEST_RESULT snm_test_debug_asserts_5(void) {
    /* There should be an assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_5_assert,
                                      SNM_SAFE_ASSERT_ASSERTED,
                                      "");
}


/* Assert with format and 0 arguments */
void snm_test_debug_asserts_6_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "Assert with format and 0 arguments", NULL);
}

SNM_TEST_RESULT snm_test_debug_asserts_6(void) {
    /* There should be an assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_6_assert,
                                      SNM_SAFE_ASSERT_ASSERTED,
                                      "Assert with format and 0 arguments");
}


/* Assert with format and 1 arguments */
void snm_test_debug_asserts_7_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "Assert with format and %i arguments", 1);
}

SNM_TEST_RESULT snm_test_debug_asserts_7(void) {
    /* There should be an assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_7_assert,
                                      SNM_SAFE_ASSERT_ASSERTED,
                                      "Assert with format and 1 arguments");
}


/* Assert with format and 3 arguments */
void snm_test_debug_asserts_8_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "Assert with %s and %i %s", "format", 3, "arguments");
}

SNM_TEST_RESULT snm_test_debug_asserts_8(void) {
    /* There should be an assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_8_assert,
                                      SNM_SAFE_ASSERT_ASSERTED,
                                      "Assert with format and 3 arguments");
}


/* Assert with maximal length string */
void snm_test_debug_asserts_9_assert(void) {
    /* Enable asserts */
    #undef  SNM_ASSERT
    #define SNM_ASSERT (SNM_ASSERT_ENABLED)
    #include "snm_debug.h"

    /* Try an assert */
    snm_assert(FALSE, "%s", Text);
}

SNM_TEST_RESULT snm_test_debug_asserts_9(void) {
    /* This should be truncated, as it will be prefixed by other text */
    memset(&Text[0], '_', SNM_DEBUG_BUFFER_SIZE - 1);
    Text[SNM_DEBUG_BUFFER_SIZE - 1] = '\0';

    /* There should be an assert */
    return snm_test_debug_safe_assert(snm_test_debug_asserts_9_assert,
                                      SNM_SAFE_ASSERT_ASSERTED,
                                      Text);
}
