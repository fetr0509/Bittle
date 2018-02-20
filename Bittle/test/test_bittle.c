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
// Left shift tests
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
#pragma GCC diagnostic pop

void LogicalRightShiftTests()
{

}

int main(void)
{
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(LeftShiftTest),
            cmocka_unit_test(LogicalRightShiftTests),
    };


    return cmocka_run_group_tests(tests,NULL,NULL);
}
