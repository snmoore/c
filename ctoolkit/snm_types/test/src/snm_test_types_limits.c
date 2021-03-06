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
 * 20160401 3       simon@snmoore.net   Fix the 64-bit limit checks and adjust
 *                                      the other tests for consistency
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

/*
 * The limits here are generally tested by setting explicit bits and using
 * using bitwise operations, rather than relying upon hand-coded values (that
 * are size dependent), arithmetic operations or overflow behaviour.
 *
 * For signed min, treat as unsigned and set the top bit, then cast, e.g.:
 *      type MinValue = (type)1u << ((sizeof(type) * CHAR_BIT) - 1);
 *
 * For signed max, use a loop to shift each relevant bit into place, e.g.:
 *      size_t i;
 *      type MaxValue = 0;
 *      for(i = 0; i < ((sizeof(type) * CHAR_BIT) - 1); i++) {
 *          MaxValue |= 1 << i;
 *      }
 *
 * For unsigned max, take the complement of zero to set all bits, e.g.:
 *      type MaxValue = ~0;
 */

/* int8_t minimum is INT8_MIN */
SNM_TEST_RESULT snm_test_types_limits_1(void) {
    int8_t MinValue = (int8_t)1u << ((sizeof(int8_t) * CHAR_BIT) - 1);

    snm_debug_trivial("MinValue: %hhi, 0x%hhx, INT8_MIN: %hhi",
                      MinValue, MinValue & 0xFF, INT8_MIN);

    return (INT8_MIN == MinValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int8_t maximum is INT8_MAX */
SNM_TEST_RESULT snm_test_types_limits_2(void) {
    size_t i;
    int8_t MaxValue = 0;
    for(i = 0; i < ((sizeof(int8_t) * CHAR_BIT) - 1); i++) {
        MaxValue |= 1 << i;
    }

    snm_debug_trivial("MaxValue: %hhi, 0x%hhx, INT8_MAX: %hhi",
                      MaxValue, MaxValue & 0xFF, INT8_MAX);

    return (INT8_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uint8_t maximum is UINT8_MAX */
SNM_TEST_RESULT snm_test_types_limits_3(void) {
    uint8_t MaxValue = ~0;

    snm_debug_trivial("MaxValue: %hhu, 0x%hhx, UINT8_MAX: %hhu",
                      MaxValue, MaxValue & 0xFF, UINT8_MAX);

    return (UINT8_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int16_t minimum is INT16_MIN */
SNM_TEST_RESULT snm_test_types_limits_4(void) {
    int16_t MinValue = (int16_t)1u << ((sizeof(int16_t) * CHAR_BIT) - 1);

    snm_debug_trivial("MinValue: %hi, 0x%hx, INT16_MIN: %hi",
                      MinValue, MinValue, INT16_MIN);

    return (INT16_MIN == MinValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int16_t maximum is INT16_MAX */
SNM_TEST_RESULT snm_test_types_limits_5(void) {
    size_t i;
    int16_t MaxValue = 0;
    for(i = 0; i < ((sizeof(int16_t) * CHAR_BIT) - 1); i++) {
        MaxValue |= 1 << i;
    }

    snm_debug_trivial("MaxValue: %hi, 0x%hx, INT16_MAX: %hi",
                      MaxValue, MaxValue, INT16_MAX);

    return (INT16_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uint16_t maximum is UINT16_MAX */
SNM_TEST_RESULT snm_test_types_limits_6(void) {
    uint16_t MaxValue = ~0;

    snm_debug_trivial("MaxValue: %hu, 0x%hx, UINT16_MAX: %hu",
        MaxValue, MaxValue, UINT16_MAX);

    return (UINT16_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int32_t minimum is INT32_MIN */
SNM_TEST_RESULT snm_test_types_limits_7(void) {
    int32_t MinValue = (int32_t)1u << ((sizeof(int32_t) * CHAR_BIT) - 1);

    snm_debug_trivial("MinValue: %i, 0x%x, INT32_MIN: %i",
                      MinValue, MinValue, INT32_MIN);

    return (INT32_MIN == MinValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int32_t maximum is INT32_MAX */
SNM_TEST_RESULT snm_test_types_limits_8(void) {
    size_t i;
    int32_t MaxValue = 0;
    for(i = 0; i < ((sizeof(int32_t) * CHAR_BIT) - 1); i++) {
        MaxValue |= 1 << i;
    }

    snm_debug_trivial("MaxValue: %i, 0x%x, INT32_MAX: %i",
                      MaxValue, MaxValue, INT32_MAX);

    return (INT32_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uint32_t maximum is UINT32_MAX */
SNM_TEST_RESULT snm_test_types_limits_9(void) {
    uint32_t MaxValue = ~0;

    snm_debug_trivial("MaxValue: %u, 0x%x, UINT32_MAX: %u",
                      MaxValue, MaxValue, UINT32_MAX);

    return (UINT32_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* int64_t minimum is INT64_MIN */
SNM_TEST_RESULT snm_test_types_limits_10(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        int64_t MinValue = (int64_t)1llu << ((sizeof(int64_t) * CHAR_BIT) - 1);

        snm_debug_trivial("MinValue: %lli, 0x%llx, INT64_MIN: %lli",
                          MinValue, MinValue, INT64_MIN);
 
        return (INT64_MIN == MinValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return SNM_TEST_INCONCLUSIVE;
    #endif
}

/* int64_t maximum is INT64_MAX */
SNM_TEST_RESULT snm_test_types_limits_11(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        size_t i;
        int64_t MaxValue = 0;
        for(i = 0; i < ((sizeof(int64_t) * CHAR_BIT) - 1); i++) {
            MaxValue |= 1ll << i;
        }

        snm_debug_trivial("MaxValue: %lli, 0x%llx, INT64_MAX: %lli",
                          MaxValue, MaxValue, INT64_MAX);

        return (INT64_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return SNM_TEST_INCONCLUSIVE;
    #endif
}

/* uint64_t maximum is UINT64_MAX */
SNM_TEST_RESULT snm_test_types_limits_12(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        uint64_t MaxValue = ~0;

        snm_debug_trivial("MaxValue: %llu, 0x%llx, UINT64_MAX: %llu",
                          MaxValue, MaxValue, UINT64_MAX);

        return (UINT64_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return SNM_TEST_INCONCLUSIVE;
    #endif
}

/* intmax_t minimum is INTMAX_MIN */
SNM_TEST_RESULT snm_test_types_limits_13(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        intmax_t MinValue = (intmax_t)1llu << ((sizeof(intmax_t) * CHAR_BIT) - 1);

        snm_debug_trivial("MinValue: %lli, 0x%llx, INTMAX_MIN: %lli",
                          MinValue, MinValue, INTMAX_MIN);
    #else
        intmax_t MinValue = (intmax_t)1u << ((sizeof(intmax_t) * CHAR_BIT) - 1);

        snm_debug_trivial("MinValue: %i, 0x%x, INTMAX_MIN: %i",
                          MinValue, MinValue, INTMAX_MIN);    
    #endif

    return (INTMAX_MIN == MinValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* intmax_t maximum is INTMAX_MAX */
SNM_TEST_RESULT snm_test_types_limits_14(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        size_t i;
        intmax_t MaxValue = 0;
        for(i = 0; i < ((sizeof(intmax_t) * CHAR_BIT) - 1); i++) {
            MaxValue |= 1ll << i;
        }

        snm_debug_trivial("MaxValue: %lli, 0x%llx, INTMAX_MAX: %lli",
                          MaxValue, MaxValue, INTMAX_MAX);
    #else
        size_t i;
        intmax_t MaxValue = 0;
        for(i = 0; i < ((sizeof(intmax_t) * CHAR_BIT) - 1); i++) {
            MaxValue |= 1 << i;
        }

        snm_debug_trivial("MaxValue: %i, 0x%x, INTMAX_MAX: %i",
                          MaxValue, MaxValue, INTMAX_MAX);    
    #endif

    return (INTMAX_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uintmax_t maximum is UINTMAX_MAX */
SNM_TEST_RESULT snm_test_types_limits_15(void) {
    uintmax_t MaxValue = ~0;

    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        snm_debug_trivial("MaxValue: %llu, 0x%llx, UINTMAX_MAX: %llu",
                          MaxValue, MaxValue, UINTMAX_MAX);
    #else
        snm_debug_trivial("MaxValue: %u, 0x%x, UINTMAX_MAX: %u",
                          MaxValue, MaxValue, UINTMAX_MAX);    
    #endif

    return (UINTMAX_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* INTMAX_MIN is INT32_MIN, or INT64_MIN if 64-bit */
SNM_TEST_RESULT snm_test_types_limits_16(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        return (INTMAX_MIN == INT64_MIN) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return (INTMAX_MIN == INT32_MIN) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #endif
}

/* INTMAX_MAX is INT32_MAX, or INT64_MAX if 64-bit */
SNM_TEST_RESULT snm_test_types_limits_17(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        return (INTMAX_MAX == INT64_MAX) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return (INTMAX_MAX == INT32_MAX) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #endif
}

/* UINTMAX_MAX is UINT32_MAX, or UINT64_MAX if 64-bit */
SNM_TEST_RESULT snm_test_types_limits_18(void) {
    #if defined(SNM_64BIT_TYPES_AVAILABLE)
        return (UINTMAX_MAX == UINT64_MAX) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #else
        return (UINTMAX_MAX == UINT32_MAX) ? SNM_TEST_PASS : SNM_TEST_FAIL;
    #endif
}

/* char_t minimum is SCHAR_MIN */
SNM_TEST_RESULT snm_test_types_limits_19(void) {
    char_t MinValue = (char_t)1u << ((sizeof(char_t) * CHAR_BIT) - 1);

    snm_debug_trivial("MinValue: %hhi, 0x%hhx, SCHAR_MIN: %hhi",
                      MinValue, MinValue & 0xFF, SCHAR_MIN);

    return (SCHAR_MIN == MinValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* char_t maximum is SCHAR_MAX */
SNM_TEST_RESULT snm_test_types_limits_20(void) {
    size_t i;
    char_t MaxValue = 0;
    for(i = 0; i < ((sizeof(char_t) * CHAR_BIT) - 1); i++) {
        MaxValue |= 1 << i;
    }

    snm_debug_trivial("MaxValue: %hhi, 0x%hhx, SCHAR_MAX: %hhi",
                      MaxValue, MaxValue & 0xFF, SCHAR_MAX);

    return (SCHAR_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* uchar_t maximum is UCHAR_MAX */
SNM_TEST_RESULT snm_test_types_limits_21(void) {
    uchar_t MaxValue = ~0;

    snm_debug_trivial("MaxValue: %hhu, 0x%hhx, UCHAR_MAX: %hhu",
                      MaxValue, MaxValue & 0xFF, UCHAR_MAX);

    return (UCHAR_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* utf8_t maximum is UINT8_MAX */
SNM_TEST_RESULT snm_test_types_limits_22(void) {
    utf8_t MaxValue = ~0;

    snm_debug_trivial("MaxValue: %hhu, 0x%hhx, UINT8_MAX: %hhu",
                      MaxValue, MaxValue & 0xFF, UINT8_MAX);

    return (UINT8_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}

/* utf16_t maximum is UINT16_MAX */
SNM_TEST_RESULT snm_test_types_limits_23(void) {
    utf16_t MaxValue = ~0;

    snm_debug_trivial("MaxValue: %hu, 0x%hx, UINT16_MAX: %hu",
                      MaxValue, MaxValue, UINT16_MAX);

    return (UINT16_MAX == MaxValue) ? SNM_TEST_PASS : SNM_TEST_FAIL;
}
