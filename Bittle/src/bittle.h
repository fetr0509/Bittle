//
// Created by Peter Fetros on 2/18/18.
//

#ifndef TEST_DRIVEN_C_BITTLE_H
#define TEST_DRIVEN_C_BITTLE_H

#include <limits.h>
#include <stdint.h>

#define LS_8b(number, shift) (((number) << (shift)) & ~(UINT64_MAX << 8))
#define LS_16b(number, shift) (((number) << (shift)) & ~(UINT64_MAX << 16))
#define LS_32b(number, shift) (((number) << (shift)) & ~(UINT64_MAX << 32))
#define LS_64b(number, shift) (((number) << (shift)) & ~(UINT64_MAX << 64))

#define LRS_8(number, shift) (((number) >> (shift)) & ~(UINT64_MAX << (8 - (shift))))
#define LRS_16(number, shift) (((number) >> (shift)) & ~(UINT64_MAX << (16 - (shift))))
#define LRS_32(number, shift) (((number) >> (shift)) & ~(UINT64_MAX << (32 - (shift))))
#define LRS_64(number, shift) (((number) >> (shift)) & ~(UINT64_MAX << (64 - (shift))))

#endif //TEST_DRIVEN_C_BITTLE_H
