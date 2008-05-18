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
 * 20050408 5       simon@snmoore.net   Do not overflow buffer for test with
 *                                      maximal length string when in C90 mode
 * 20051128 6       simon@snmoore.net   Use hard limit for output buffer size
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

/* Local includes */
#include "snm_types.h"          /* For TRUE */
#include "snm_test.h"           /* For SNM_TEST_RESULT */

/* Asserts and debugging */
#define SNM_ASSERT (SNM_ASSERT_ENABLED)
#include "snm_debug.h"

/* Global text array, used for snm_test_debug_debugs_16 */
char Text[SNM_DEBUG_BUFFER_SIZE];

/* Result from quietly performing the debug */
typedef enum {
    SNM_QUIET_DEBUG_UNKNOWN_ERROR,
    SNM_QUIET_DEBUG_A_DEBUG,
    SNM_QUIET_DEBUG_NO_DEBUG
} SNM_QUIET_DEBUG;


/* Common function to test debugs quietly */
SNM_TEST_RESULT snm_test_debug_quiet_debug(void(*Function)(void),
                                           SNM_QUIET_DEBUG ExpectedResult,
                                           const char *ExpectedString) {
    int Status;     /* Exit status of the child */
    int Pipe[2];    /* Pipe from child to parent, STDOUT redirects to this */
    FILE *Read;     /* File handle used to read from the pipe */
    char *String;   /* Pointer to string (if any) captured from the child */
    char Buffer[SNM_DEBUG_BUFFER_SIZE] = { '\0' };

    /* Create a pipe to capture STDOUT from child and pipe it to the parent */
    if(pipe(&Pipe[0]) != 0) {
        snm_assert(FALSE, "Failed to create pipe", NULL);
        return SNM_TEST_INCONCLUSIVE;
    }

    /* Create a child process to use for asserts */
    switch(fork()) {
        case -1:
            /* Problem creating the child process */
            snm_assert(FALSE, "Failed to fork child process", NULL);
            return SNM_TEST_INCONCLUSIVE;
        case 0:
            /*
             * This is the child process (fork returns 0 to the child)
             */

            /* Redirect STDOUT to the pipe */
            if(dup2(Pipe[1], STDOUT_FILENO) != STDOUT_FILENO) {
                snm_assert(FALSE,
                           "Failed to redirect STDOUT=>pipe, error %i",
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

            /* Perform the debug */
            if(Function != NULL) {
                Function();
            }

            /* Exit normally */
            exit(EXIT_SUCCESS);
            break;
        default:
            /*
             * This is the parent process (fork returns child pid to parent)
             */

            /* Use the pipe for reading */
            if((Read = fdopen(Pipe[0], "r")) == NULL) {
                snm_assert(FALSE,
                           "Parent: failed to read from pipe, error %i",
                           errno);
                return SNM_TEST_INCONCLUSIVE;
            }

            /* Close unused file descriptors */
            if(close(Pipe[1]) != 0) {
                snm_assert(FALSE,
                           "Parent: failed to close Pipe[1], error %i",
                           errno);
                return SNM_TEST_INCONCLUSIVE;
            }

            /* Read debug text (if any) from the pipe */
            String = fgets(Buffer, SNM_DEBUG_BUFFER_SIZE, Read);

            /* Wait for the child process to terminate */
            wait(&Status);

            /* Close the pipe */
            if(fclose(Read) != 0) {
                snm_assert(FALSE,
                           "Parent: failed to close Read, error %i",
                           errno);
                return SNM_TEST_INCONCLUSIVE;
            }
            break;
    }

    /*
     * This code is only executed by the parent process
     */

    /* Did the child process terminate normally, with no assert? */
    if(WIFEXITED(Status) && (EXIT_SUCCESS == WEXITSTATUS(Status))) {
        if((NULL == ExpectedString) && (NULL == String)) {
            /* Pass if no debug text expected, and none received */
            return SNM_TEST_PASS;
        }
        else if((NULL != ExpectedString) && (NULL != String)) {
            /* Pass if debug text was expected, and we got a match */
            if(NULL != strstr(String, ExpectedString)) {
                /* The string exactly matches */
                return SNM_TEST_PASS;
            }
            else if(strlen(String) == (SNM_DEBUG_BUFFER_SIZE -1)) {
                /* No exact match, but max length - it got truncated */
                return SNM_TEST_PASS;
            }
        }
        else {
            return SNM_TEST_FAIL;
        }
    }

    /* If we get this far, then something unexpected must have happened */
    if(WIFEXITED(Status)) {
        snm_assert(FALSE, "Child exited with %i, string length %i",
                   WEXITSTATUS(Status), strlen(String));
    }
    else if(WIFSIGNALED(Status)) {
        snm_assert(FALSE, "Child terminated upon signal %i, string length %i",
                   WTERMSIG(Status), strlen(String));
    }
    else if(WIFSTOPPED(Status)) {
        snm_assert(FALSE, "Child stopped upon signal %i, string length %i",
                   WSTOPSIG(Status), strlen(String));
    }
    return SNM_TEST_INCONCLUSIVE;
}


/* No debugs when debugs disabled */
void snm_test_debug_debugs_1_debug(void) {
    /* Disable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_DISABLED)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("No debug when debugs disabled", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_1(void) {
    /* There should be no debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_1_debug,
                                      SNM_QUIET_DEBUG_NO_DEBUG,
                                      NULL);
}


/* snm_debug_critical when SNM_DEBUG_CRITICAL */
void snm_test_debug_debugs_2_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("snm_debug_critical when SNM_DEBUG_CRITICAL", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_2(void) {
    /* There should be an debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_2_debug,
                                SNM_QUIET_DEBUG_A_DEBUG,
                                "snm_debug_critical when SNM_DEBUG_CRITICAL");
}


/* No snm_debug_important when SNM_DEBUG_CRITICAL */
void snm_test_debug_debugs_3_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_important("No snm_debug_important when SNM_DEBUG_CRITICAL", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_3(void) {
    /* There should be no debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_3_debug,
                                      SNM_QUIET_DEBUG_NO_DEBUG,
                                      NULL);
}


/* No snm_debug_trivial when SNM_DEBUG_CRITICAL */
void snm_test_debug_debugs_4_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_trivial("No snm_debug_trivial when SNM_DEBUG_CRITICAL", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_4(void) {
    /* There should be no debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_4_debug,
                                      SNM_QUIET_DEBUG_NO_DEBUG,
                                      NULL);
}


/* snm_debug_critical when SNM_DEBUG_IMPORTANT */
void snm_test_debug_debugs_5_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_IMPORTANT)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("snm_debug_critical when SNM_DEBUG_IMPORTANT", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_5(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_5_debug,
                                SNM_QUIET_DEBUG_A_DEBUG,
                                "snm_debug_critical when SNM_DEBUG_IMPORTANT");
}


/* snm_debug_important when SNM_DEBUG_IMPORTANT */
void snm_test_debug_debugs_6_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_IMPORTANT)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_important("snm_debug_important when SNM_DEBUG_IMPORTANT", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_6(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_6_debug,
                                SNM_QUIET_DEBUG_A_DEBUG,
                                "snm_debug_important when SNM_DEBUG_IMPORTANT");
}


/* No snm_debug_trivial when SNM_DEBUG_IMPORTANT */
void snm_test_debug_debugs_7_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_IMPORTANT)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_trivial("No snm_debug_trivial when SNM_DEBUG_IMPORTANT", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_7(void) {
    /* There should be no debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_7_debug,
                                      SNM_QUIET_DEBUG_NO_DEBUG,
                                      NULL);
}


/* snm_debug_critical when SNM_DEBUG_TRIVIAL */
void snm_test_debug_debugs_8_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_TRIVIAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("snm_debug_critical when SNM_DEBUG_TRIVIAL", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_8(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_8_debug,
                                SNM_QUIET_DEBUG_A_DEBUG,
                                "snm_debug_critical when SNM_DEBUG_TRIVIAL");
}


/* snm_debug_important when SNM_DEBUG_TRIVIAL */
void snm_test_debug_debugs_9_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_TRIVIAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_important("snm_debug_important when SNM_DEBUG_TRIVIAL", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_9(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_9_debug,
                                SNM_QUIET_DEBUG_A_DEBUG,
                                "snm_debug_important when SNM_DEBUG_TRIVIAL");
}


/* snm_debug_trivial when SNM_DEBUG_TRIVIAL */
void snm_test_debug_debugs_10_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_TRIVIAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_trivial("snm_debug_trivial when SNM_DEBUG_TRIVIAL", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_10(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_10_debug,
                                SNM_QUIET_DEBUG_A_DEBUG,
                                "snm_debug_trivial when SNM_DEBUG_TRIVIAL");
}


/* Debug with empty format and arguments */
void snm_test_debug_debugs_11_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_11(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_11_debug,
                                      SNM_QUIET_DEBUG_A_DEBUG,
                                      "");
}


/* Debug with empty format and 1 argument */
void snm_test_debug_debugs_12_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("", SNM_ASSERT);
}

SNM_TEST_RESULT snm_test_debug_debugs_12(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_12_debug,
                                      SNM_QUIET_DEBUG_A_DEBUG,
                                      "");
}


/* Debug with format and 0 arguments */
void snm_test_debug_debugs_13_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("Debug with format and 0 arguments", NULL);
}

SNM_TEST_RESULT snm_test_debug_debugs_13(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_13_debug,
                                      SNM_QUIET_DEBUG_A_DEBUG,
                                      "Debug with format and 0 arguments");
}


/* Debug with format and 1 argument */
void snm_test_debug_debugs_14_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("Debug with format and %i argument", 1);
}

SNM_TEST_RESULT snm_test_debug_debugs_14(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_14_debug,
                                      SNM_QUIET_DEBUG_A_DEBUG,
                                      "Debug with format and 1 argument");
}


/* Debug with format and 3 arguments */
void snm_test_debug_debugs_15_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("Debug with %s and %i %s", "format", 3, "arguments");
}

SNM_TEST_RESULT snm_test_debug_debugs_15(void) {
    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_15_debug,
                                      SNM_QUIET_DEBUG_A_DEBUG,
                                      "Debug with format and 3 arguments");
}


/* Debug with maximal length string */
void snm_test_debug_debugs_16_debug(void) {
    /* Enable debugs */
    #undef  SNM_DEBUG
    #define SNM_DEBUG (SNM_DEBUG_CRITICAL)
    #include "snm_debug.h"

    /* Try a debug */
    snm_debug_critical("%s", Text);
}

SNM_TEST_RESULT snm_test_debug_debugs_16(void) {
/* The debug text will be prefixed by some preamble (which may include file
 * and line numbers etc)
 *
 * In C99 mode, the debug code should safely truncate the debug text (e.g. by
 * using vsnprintf), and hence we actually want to test this
 *
 * In ANSI/C89/C90 mode, truncation may not be safe (e.g. because vsnprintf is
 * not available) and may cause an abort (_will_ cause an abort on OpenBSD), so
 * we need to size the debug text to ensure that no truncation is necessary
 */
#if __STDC_VERSION__ == 199901L
    memset(&Text[0], '_', SNM_DEBUG_BUFFER_SIZE - 1);
    Text[SNM_DEBUG_BUFFER_SIZE - 1] = '\0';
#else
    int PreambleLength = strlen("DEBUG! : ");
    memset(&Text[0], '_', SNM_DEBUG_BUFFER_SIZE - 1 - PreambleLength);
    Text[SNM_DEBUG_BUFFER_SIZE - 1 - PreambleLength] = '\0';
#endif

    /* There should be a debug */
    return snm_test_debug_quiet_debug(snm_test_debug_debugs_16_debug,
                                      SNM_QUIET_DEBUG_A_DEBUG,
                                      Text);
}
