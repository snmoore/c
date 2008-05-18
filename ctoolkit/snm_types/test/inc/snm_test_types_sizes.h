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


/* No check for circular includes here - will be parsed many times */


/* 
 * Describe each of the individual tests, and define which function implements
 * each test
 */    
SNM_TEST_START("Types:Sizes:1")
    SNM_TEST_DESCRIPTION("A byte is 8 bits (CHAR_BIT == 8)")
    SNM_TEST_FUNCTION(snm_test_types_sizes_1)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:2")
    SNM_TEST_DESCRIPTION("int8_t is 1 byte")
    SNM_TEST_FUNCTION(snm_test_types_sizes_2)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:3")
    SNM_TEST_DESCRIPTION("uint8_t is 1 byte")
    SNM_TEST_FUNCTION(snm_test_types_sizes_3)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:4")
    SNM_TEST_DESCRIPTION("int16_t is 2 bytes")
    SNM_TEST_FUNCTION(snm_test_types_sizes_4)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:5")
    SNM_TEST_DESCRIPTION("uint16_t is 2 bytes")
    SNM_TEST_FUNCTION(snm_test_types_sizes_5)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:6")
    SNM_TEST_DESCRIPTION("int32_t is 4 bytes")
    SNM_TEST_FUNCTION(snm_test_types_sizes_6)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:7")
    SNM_TEST_DESCRIPTION("uint32_t is 4 bytes")
    SNM_TEST_FUNCTION(snm_test_types_sizes_7)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:8")
    SNM_TEST_DESCRIPTION("int64_t is 8 bytes")
    SNM_TEST_FUNCTION(snm_test_types_sizes_8)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:9")
    SNM_TEST_DESCRIPTION("uint64_t is 8 bytes")
    SNM_TEST_FUNCTION(snm_test_types_sizes_9)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:10")
    SNM_TEST_DESCRIPTION("intmax_t is 4 bytes, or 8 bytes if 64-bit integers are available")
    SNM_TEST_FUNCTION(snm_test_types_sizes_10)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:11")
    SNM_TEST_DESCRIPTION("uintmax_t is 4 bytes, or 8 bytes if 64-bit integers are available")
    SNM_TEST_FUNCTION(snm_test_types_sizes_11)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:12")
    SNM_TEST_DESCRIPTION("char_t is the same size as signed char")
    SNM_TEST_FUNCTION(snm_test_types_sizes_12)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:13")
    SNM_TEST_DESCRIPTION("uchar_t is the same size as unsigned char")
    SNM_TEST_FUNCTION(snm_test_types_sizes_13)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:14")
    SNM_TEST_DESCRIPTION("utf8_t is 1 byte")
    SNM_TEST_FUNCTION(snm_test_types_sizes_14)
SNM_TEST_END

SNM_TEST_START("Types:Sizes:15")
    SNM_TEST_DESCRIPTION("utf16_t is 2 bytes")
    SNM_TEST_FUNCTION(snm_test_types_sizes_15)
SNM_TEST_END
