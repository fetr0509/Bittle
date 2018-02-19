//
// Created by Peter Fetros on 2/17/18.
//

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "bittle.h"

void test1()
{
    assert_int_equal(0, 0);
}

void test2()
{
    assert_int_equal(5, 5);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test1),
            cmocka_unit_test(test2),
    };


    return cmocka_run_group_tests(tests,NULL,NULL);
}
