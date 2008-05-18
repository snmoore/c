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

/* A byte is 8 bits (CHAR_BIT == 8) */
SNM_TEST_RESULT snm_test_types_sizes_1(void) {
    return (8 == CHAR_BIT) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int8_t is 1 byte */
SNM_TEST_RESULT snm_test_types_sizes_2(void) {
    return (1 == sizeof(int8_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uint8_t is 1 byte */
SNM_TEST_RESULT snm_test_types_sizes_3(void) {
    return (1 == sizeof(uint8_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int16_t is 2 bytes */
SNM_TEST_RESULT snm_test_types_sizes_4(void) {
    return (2 == sizeof(int16_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uint16_t is 2 bytes */
SNM_TEST_RESULT snm_test_types_sizes_5(void) {
    return (2 == sizeof(uint16_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int32_t is 4 bytes */
SNM_TEST_RESULT snm_test_types_sizes_6(void) {
    return (4 == sizeof(int32_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uint32_t is 4 bytes */
SNM_TEST_RESULT snm_test_types_sizes_7(void) {
    return (4 == sizeof(uint32_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int64_t is 8 bytes */
SNM_TEST_RESULT snm_test_types_sizes_8(void) {
    /* 64-bit types are not valid for all platforms */
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        return (8 == sizeof(int64_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return SNM_TEST_INCONCLUSIVE;
    #endif
}

/* uint64_t is 8 bytes */
SNM_TEST_RESULT snm_test_types_sizes_9(void) {
    /* 64-bit types are not valid for all platforms */
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        return (8 == sizeof(uint64_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return SNM_TEST_INCONCLUSIVE;
    #endif
}

/* intmax_t is 4 bytes, or 8 bytes if 64-bit integers are available */
SNM_TEST_RESULT snm_test_types_sizes_10(void) {
    /* 64-bit types are not valid for all platforms */
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        return (8 == sizeof(intmax_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return (4 == sizeof(intmax_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #endif
}

/* uintmax_t is 4 bytes, or 8 bytes if 64-bit integers are available */
SNM_TEST_RESULT snm_test_types_sizes_11(void) {
    /* 64-bit types are not valid for all platforms */
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        return (8 == sizeof(uintmax_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return (4 == sizeof(uintmax_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #endif
}

/* char_t is the same size as signed char */
SNM_TEST_RESULT snm_test_types_sizes_12(void) {
    return (sizeof(signed char) == sizeof(char_t)) ? SNM_TEST_PASS :
                                                     SNM_TEST_FAIL;
}

/* uchar_t is the same size as unsigned char */
SNM_TEST_RESULT snm_test_types_sizes_13(void) {
    return (sizeof(unsigned char) ==  sizeof(uchar_t)) ? SNM_TEST_PASS : 
                                                         SNM_TEST_FAIL;
}

/* utf8_t is 1 byte */
SNM_TEST_RESULT snm_test_types_sizes_14(void) {
    return (1 == sizeof(utf8_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* utf16_t is 2 bytes */
SNM_TEST_RESULT snm_test_types_sizes_15(void) {
    return (2 == sizeof(utf16_t)) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}
