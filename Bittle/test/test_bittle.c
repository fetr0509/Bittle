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
    assert_int_equal(0, LRS_8(0,0));
    assert_int_equal(0x7F, LRS_8(-1,1));
    assert_int_equal(0, LRS_8(-1,8));
    assert_int_equal(0x46, LRS_8(c,1));
    assert_int_equal(0x08, LRS_8(c,4));

    int16_t s = -0x7400;
    assert_int_equal(0, LRS_16(0,0));
    assert_int_equal(0x7FFF, LRS_16(-1,1));
    assert_int_equal(0, LRS_16(-1,16));
    assert_int_equal(0x4600, LRS_16(s,1));
    assert_int_equal(0x8C, LRS_16(s,8));

    int32_t i = -0x74000000;
    assert_int_equal(0, LRS_32(0,0));
    assert_int_equal(0x7FFFFFFF, LRS_32(-1,1));
    assert_int_equal(0, LRS_32(-1,32));
    assert_int_equal(0x46000000, LRS_32(i,1));
    assert_int_equal(0x8C00, LRS_32(i,16));

    int64_t l = -0x7400000000000000;
    assert_int_equal(0, LRS_64(0,0));
    assert_int_equal(0x7FFFFFFFFFFFFFFF, LRS_64(-1,1));
    assert_int_equal(0, LRS_64(-1,64));
    assert_int_equal(0x4600000000000000, LRS_64(l,1));
    assert_int_equal(0x8c000000, LRS_64(l,32));
}
#pragma GCC diagnostic pop

int main(void)
{
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(LeftShiftTest),
            cmocka_unit_test(LogicalRightShiftTests),
    };


    return cmocka_run_group_tests(tests,NULL,NULL);
}
