//
// Created by Peter Fetros on 2/17/18.
//

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "bittle.h"
#include <stdint.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshift-count-overflow"
// Left Shift tests
void LeftShiftTest()
{
    uint8_t c = 0xe8;
    assert_int_equal(0, LS_8b(0,0));
    assert_int_equal(0, LS_8b(1,9));
    assert_int_equal(0, LS_8b(c,9));
    assert_int_equal(0xD0, LS_8b(c,1));
    assert_int_equal(0x80, LS_8b(c,4));

    uint16_t s = 0xe814;
    assert_int_equal(0, LS_16b(0,0));
    assert_int_equal(0, LS_16b(1,17));
    assert_int_equal(0xd028, LS_16b(s,1));
    assert_int_equal(0x1400, LS_16b(s,8));

    uint32_t i = 0xe8142b43;
    assert_int_equal(0, LS_32b(0,0));
    assert_int_equal(0, LS_32b(1,33));
    assert_int_equal(0xd0285686, LS_32b(i,1));
    assert_int_equal(0x2b430000, LS_32b(i,16));

    uint64_t l = 0xe8142b4376e4f177;
    assert_int_equal(0, LS_64b(0,0));
    assert_int_equal(0, LS_64b(1,65));
    assert_int_equal(0xd0285686edc9e2ee, LS_64b(l,1));
    assert_int_equal(0x76e4f17700000000, LS_64b(l,32));

}
// Logical Right Shift tests
void LogicalRightShiftTests()
{
    int8_t c = -0x74;
    assert_int_equal(0, LRS_8b(0,0));
    assert_int_equal(0x7F, LRS_8b(-1,1));
    assert_int_equal(0, LRS_8b(-1,8));
    assert_int_equal(0x46, LRS_8b(c,1));
    assert_int_equal(0x08, LRS_8b(c,4));

    int16_t s = -0x7400;
    assert_int_equal(0, LRS_16b(0,0));
    assert_int_equal(0x7FFF, LRS_16b(-1,1));
    assert_int_equal(0, LRS_16b(-1,16));
    assert_int_equal(0x4600, LRS_16b(s,1));
    assert_int_equal(0x8C, LRS_16b(s,8));

    int32_t i = -0x74000000;
    assert_int_equal(0, LRS_32b(0,0));
    assert_int_equal(0x7FFFFFFF, LRS_32b(-1,1));
    assert_int_equal(0, LRS_32b(-1,32));
    assert_int_equal(0x46000000, LRS_32b(i,1));
    assert_int_equal(0x8C00, LRS_32b(i,16));

    int64_t l = -0x7400000000000000;
    assert_int_equal(0, LRS_64b(0,0));
    assert_int_equal(0x7FFFFFFFFFFFFFFF, LRS_64b(-1,1));
    assert_int_equal(0, LRS_64b(-1,64));
    assert_int_equal(0x4600000000000000, LRS_64b(l,1));
    assert_int_equal(0x8c000000, LRS_64b(l,32));
}

void ArithmeticRightShiftTests()
{
    int8_t c = 0x74;
    assert_int_equal(0, ARS_8b(0,0));
    assert_int_equal((uint8_t)-1, ARS_8b(-1,1));
    assert_int_equal(0, ARS_8b(1,1));
    assert_int_equal(0x07, ARS_8b(c,4));
    assert_int_equal((uint8_t)-8, ARS_8b(-c,4));

    int16_t s = 0x7400;
    assert_int_equal(0, ARS_16b(0,0));
    assert_int_equal((uint16_t)-1, ARS_16b(-1,1));
    assert_int_equal(0, ARS_16b(1,1));
    assert_int_equal(116, ARS_16b(s,8));
    assert_int_equal((uint16_t)-116, ARS_16b(-s,8));

    int32_t i = 0x74000000;
    assert_int_equal(0, ARS_32b(0,0));
    assert_int_equal((uint32_t)-1, ARS_32b(-1,1));
    assert_int_equal(0, ARS_32b(1,1));
    assert_int_equal(0x7400, ARS_32b(i,16));
    assert_int_equal((uint32_t)-0x7400, ARS_32b(-i,16));

    int64_t l = 0x7400000000000000;
    assert_int_equal(0, ARS_64b(0,0));
    assert_int_equal((uint64_t)-1, ARS_64b(-1,1));
    assert_int_equal(0, ARS_64b(1,1));
    assert_int_equal(0x74000000, ARS_64b(l,32));
    assert_int_equal((uint64_t)-0x74000000, ARS_64b(-l,32));
}

void RotateRightTests()
{
    assert_int_equal(0, RR_8b(0,4));
    assert_int_equal((uint8_t)-1, RR_8b(-1,1));
    assert_int_equal(0x5A, RR_8b(0xA5,4));
    assert_int_equal(0x5A, RR_8b(0xFFA5,4));

    assert_int_equal(0, RR_16b(0,8));
    assert_int_equal((uint16_t)-1, RR_16b(-1,8));
    assert_int_equal(0x55AA, RR_16b(0x5AA5,4));
    assert_int_equal(0xA55A, RR_16b(0xFF5AA5,8));

    assert_int_equal(0, RR_32b(0,16));
    assert_int_equal((uint32_t)-1, RR_32b(-1,16));
    assert_int_equal(0xDA5BA42A, RR_32b(0xA5BA42AD,4));
    assert_int_equal(0x42ADA5BA, RR_32b(0xFFA5BA42AD,16));

    assert_int_equal(0, RR_64b(0,32));
    assert_int_equal((uint64_t)-1, RR_64b(-1,1));
    assert_int_equal(0x7A37FBC386CD65EF, RR_64b(0xA37FBC386CD65EF7,4));
}

void RotateLeftTests()
{
    assert_int_equal(0, RL_8b(0,4));
    assert_int_equal((uint8_t)-1, RL_8b(-1,4));
    assert_int_equal(0x5A, RL_8b(0xA5,4));
    assert_int_equal(0x5A, RL_8b(0xFFA5,4));

    assert_int_equal(0, RL_16b(0,8));
    assert_int_equal((uint16_t)-1, RL_16b(-1,8));
    assert_int_equal(0xAA55, RL_16b(0x5AA5,4));
    assert_int_equal(0xA55A, RL_16b(0xFF5AA5,8));

    assert_int_equal(0, RL_32b(0,16));
    assert_int_equal((uint32_t)-1, RL_32b(-1,16));
    assert_int_equal(0x5BA42ADA, RL_32b(0xA5BA42AD,4));
    assert_int_equal(0x42ADA5BA, RL_32b(0xFFA5BA42AD,16));

    assert_int_equal(0, RL_64b(0,32));
    assert_int_equal((uint64_t)-1, RL_64b(-1,32));
    assert_int_equal(0x37FBC386CD65EF7A, RL_64b(0xA37FBC386CD65EF7,4));
}

void CountSetBitsTests()
{
    uint64_t largeNumber = 0xABCD1234ABCD1234;

    int number = 0xA;
    int count = 0;
    CountSetBits_8b(number,count);
    assert_int_equal(0x2, count);
    count = 0;
    CountSetBits_8b(0,count);
    assert_int_equal(0, count);
    count = 0;
    CountSetBits_8b(UINT8_MAX,count);
    assert_int_equal(0x8, count);
    count = 0;
    CountSetBits_8b(largeNumber,count);
    assert_int_equal(0x3, count);

    number = 0xABCD;
    count = 0;
    CountSetBits_16b(number,count);
    assert_int_equal(0xA, count);
    count = 0;
    CountSetBits_16b(0,count);
    assert_int_equal(0, count);
    count = 0;
    CountSetBits_16b(UINT16_MAX,count);
    assert_int_equal(0x10, count);
    count = 0;
    CountSetBits_16b(largeNumber,count);
    assert_int_equal(0x5, count);

    number = 0xABCD1234;
    count = 0;
    CountSetBits_32b(number,count);
    assert_int_equal(0xF, count);
    count = 0;
    CountSetBits_32b(0,count);
    assert_int_equal(0, count);
    count = 0;
    CountSetBits_32b(UINT32_MAX,count);
    assert_int_equal(0x20, count);
    count = 0;
    CountSetBits_32b(largeNumber,count);
    assert_int_equal(0xf, count);

    count = 0;
    CountSetBits_64b(largeNumber,count);
    assert_int_equal(0x1E, count);
    count = 0;
    CountSetBits_64b(0,count);
    assert_int_equal(0, count);
    count = 0;
    CountSetBits_64b(UINT64_MAX,count);
    assert_int_equal(0x40, count);
    count = 0;
}

#pragma GCC diagnostic pop

int main(void)
{
    // Set up tests to run
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(LeftShiftTest),
            cmocka_unit_test(LogicalRightShiftTests),
            cmocka_unit_test(ArithmeticRightShiftTests),
            cmocka_unit_test(RotateLeftTests),
            cmocka_unit_test(RotateRightTests),
            cmocka_unit_test(CountSetBitsTests),
    };

    // Start main test runner
    return cmocka_run_group_tests(tests,NULL,NULL);
}
