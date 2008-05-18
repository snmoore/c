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


/* No check for circular includes here - will be parsed many times */


/* 
 * Describe each of the individual tests, and define which function implements
 * each test
 */    
SNM_TEST_START("Debug:Asserts:1")
    SNM_TEST_DESCRIPTION("No assert when asserts disabled")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_1)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:2")
    SNM_TEST_DESCRIPTION("No assert when test is true")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_2)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:3")
    SNM_TEST_DESCRIPTION("Assert when test is false")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_3)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:4")
    SNM_TEST_DESCRIPTION("Assert with empty format and arguments")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_4)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:5")
    SNM_TEST_DESCRIPTION("Assert with empty format and 1 argument")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_5)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:6")
    SNM_TEST_DESCRIPTION("Assert with format and 0 arguments")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_6)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:7")
    SNM_TEST_DESCRIPTION("Assert with format and 1 arguments")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_7)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:8")
    SNM_TEST_DESCRIPTION("Assert with format and 3 arguments")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_8)
SNM_TEST_END

SNM_TEST_START("Debug:Asserts:9")
    SNM_TEST_DESCRIPTION("Assert with maximal length string")
    SNM_TEST_FUNCTION(snm_test_debug_asserts_9)
SNM_TEST_END
