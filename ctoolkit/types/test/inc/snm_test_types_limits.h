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
SNM_TEST_START("Types:Limits:1")
    SNM_TEST_DESCRIPTION("int8_t minimum is INT8_MIN (-128)")
    SNM_TEST_FUNCTION(snm_test_types_limits_1)
SNM_TEST_END

SNM_TEST_START("Types:Limits:2")
    SNM_TEST_DESCRIPTION("int8_t maximum is INT8_MAX (127)")
    SNM_TEST_FUNCTION(snm_test_types_limits_2)
SNM_TEST_END

SNM_TEST_START("Types:Limits:3")
    SNM_TEST_DESCRIPTION("uint8_t maximum is UINT8_MAX (255)")
    SNM_TEST_FUNCTION(snm_test_types_limits_3)
SNM_TEST_END

SNM_TEST_START("Types:Limits:4")
    SNM_TEST_DESCRIPTION("int16_t minimum is INT16_MIN (-32768)")
    SNM_TEST_FUNCTION(snm_test_types_limits_4)
SNM_TEST_END

SNM_TEST_START("Types:Limits:5")
    SNM_TEST_DESCRIPTION("int16_t maximum is INT16_MAX (32767)")
    SNM_TEST_FUNCTION(snm_test_types_limits_5)
SNM_TEST_END

SNM_TEST_START("Types:Limits:6")
    SNM_TEST_DESCRIPTION("uint16_t maximum is UINT16_MAX (65535)")
    SNM_TEST_FUNCTION(snm_test_types_limits_6)
SNM_TEST_END

SNM_TEST_START("Types:Limits:7")
    SNM_TEST_DESCRIPTION("int32_t minimum is INT32_MIN (-2147483648)")
    SNM_TEST_FUNCTION(snm_test_types_limits_7)
SNM_TEST_END

SNM_TEST_START("Types:Limits:8")
    SNM_TEST_DESCRIPTION("int32_t maximum is INT32_MAX (2147483647)")
    SNM_TEST_FUNCTION(snm_test_types_limits_8)
SNM_TEST_END

SNM_TEST_START("Types:Limits:9")
    SNM_TEST_DESCRIPTION("uint32_t maximum is UINT32_MAX (4294967295)")
    SNM_TEST_FUNCTION(snm_test_types_limits_9)
SNM_TEST_END

SNM_TEST_START("Types:Limits:10")
    SNM_TEST_DESCRIPTION("int64_t minimum is INT64_MIN (-9223372036854775808)")
    SNM_TEST_FUNCTION(snm_test_types_limits_10)
SNM_TEST_END

SNM_TEST_START("Types:Limits:11")
    SNM_TEST_DESCRIPTION("int64_t maximum is INT64_MAX (9223372036854775807)")
    SNM_TEST_FUNCTION(snm_test_types_limits_11)
SNM_TEST_END

SNM_TEST_START("Types:Limits:12")
    SNM_TEST_DESCRIPTION("uint64_t maximum is UINT64_MAX (18446744073709551615)")
    SNM_TEST_FUNCTION(snm_test_types_limits_12)
SNM_TEST_END

SNM_TEST_START("Types:Limits:13")
    SNM_TEST_DESCRIPTION("intmax_t minimum is INTMAX_MIN")
    SNM_TEST_FUNCTION(snm_test_types_limits_13)
SNM_TEST_END

SNM_TEST_START("Types:Limits:14")
    SNM_TEST_DESCRIPTION("intmax_t maximum is INTMAX_MAX")
    SNM_TEST_FUNCTION(snm_test_types_limits_14)
SNM_TEST_END

SNM_TEST_START("Types:Limits:15")
    SNM_TEST_DESCRIPTION("uintmax_t maximum is UINTMAX_MAX")
    SNM_TEST_FUNCTION(snm_test_types_limits_15)
SNM_TEST_END

SNM_TEST_START("Types:Limits:16")
    SNM_TEST_DESCRIPTION("INTMAX_MIN is INT32_MIN, or INT64_MIN if 64-bit integers are available")
    SNM_TEST_FUNCTION(snm_test_types_limits_16)
SNM_TEST_END

SNM_TEST_START("Types:Limits:17")
    SNM_TEST_DESCRIPTION("INTMAX_MAX is INT32_MAX, or INT64_MAX if 64-bit integers are available")
    SNM_TEST_FUNCTION(snm_test_types_limits_17)
SNM_TEST_END

SNM_TEST_START("Types:Limits:18")
    SNM_TEST_DESCRIPTION("UINTMAX_MAX is UINT32_MAX, or UINT64_MAX if 64-bit integers are available")
    SNM_TEST_FUNCTION(snm_test_types_limits_18)
SNM_TEST_END

SNM_TEST_START("Types:Limits:19")
    SNM_TEST_DESCRIPTION("char_t minimum is SCHAR_MIN (-128)")
    SNM_TEST_FUNCTION(snm_test_types_limits_19)
SNM_TEST_END

SNM_TEST_START("Types:Limits:20")
    SNM_TEST_DESCRIPTION("char_t maximum is SCHAR_MAX (127)")
    SNM_TEST_FUNCTION(snm_test_types_limits_20)
SNM_TEST_END

SNM_TEST_START("Types:Limits:21")
    SNM_TEST_DESCRIPTION("uchar_t maximum is UCHAR_MAX (255)")
    SNM_TEST_FUNCTION(snm_test_types_limits_21)
SNM_TEST_END

SNM_TEST_START("Types:Limits:22")
    SNM_TEST_DESCRIPTION("utf8_t maximum is UINT8_MAX (255)")
    SNM_TEST_FUNCTION(snm_test_types_limits_22)
SNM_TEST_END

SNM_TEST_START("Types:Limits:23")
    SNM_TEST_DESCRIPTION("utf16_t maximum is UINT16_MAX (65535)")
    SNM_TEST_FUNCTION(snm_test_types_limits_23)
SNM_TEST_END
