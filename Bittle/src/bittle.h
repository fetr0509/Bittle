//
// Created by Peter Fetros on 2/18/18.
//

#ifndef TEST_DRIVEN_C_BITTLE_H
#define TEST_DRIVEN_C_BITTLE_H

#include <limits.h>
#include <stdint.h>

#ifdef INT8_MAX

#define LS_8b(number, shift) (((number) << (shift)) & UINT8_MAX)
#define LRS_8b(number, shift) ((((number) >> (shift)) & ~(UINT64_MAX << (8 - (shift)))) & UINT8_MAX)
#define ARS_8b(number, shift) ((((number) >> (shift)) | (-((number) >> 7) << (8 - (shift)))) & UINT8_MAX)
#define RR_8b(number, shift) (((((uint8_t)number) >> (shift))|(((uint8_t)number) << (8 - (shift)))) & UINT8_MAX)
#define RL_8b(number, shift) (((((uint8_t)number) << (shift))|(((uint8_t)number) >> (8 - (shift)))) & UINT8_MAX)
#define CountSetBits_8b(number, countVariable)          \
do {                                                    \
    uint8_t bitIndex = (uint8_t)number;                 \
    while(bitIndex) {                                   \
        countVariable += bitIndex & 1;                  \
        bitIndex = bitIndex >> 1;                       \
    }                                                   \
} while (0)                                             \

#endif //INT8

#ifdef INT16_MAX

#define LS_16b(number, shift) (((number) << (shift)) & UINT16_MAX)
#define LRS_16b(number, shift) ((((number) >> (shift)) & ~(UINT64_MAX << (16 - (shift)))) & UINT16_MAX)
#define ARS_16b(number, shift) ((((number) >> (shift)) | (-((number) >> 15) << (16 - (shift)))) & UINT16_MAX)
#define RR_16b(number, shift) (((((uint16_t)number) >> (shift))|(((uint16_t)number) << (16 - (shift)))) & UINT16_MAX)
#define RL_16b(number, shift) (((((uint16_t)number) << (shift))|(((uint16_t)number) >> (16 - (shift)))) & UINT16_MAX)
#define CountSetBits_16b(number, countVariable)         \
do {                                                    \
    uint16_t bitIndex = (uint16_t)number;               \
    while(bitIndex) {                                   \
        countVariable += bitIndex & 1;                  \
        bitIndex = bitIndex >> 1;                       \
    }                                                   \
} while (0)                                             \

#endif //INT16


#ifdef INT32_MAX

#define LS_32b(number, shift) (((number) << (shift)) & UINT32_MAX)
#define LRS_32b(number, shift) ((((number) >> (shift)) & ~(UINT64_MAX << (32 - (shift)))) & UINT32_MAX)
#define ARS_32b(number, shift) ((((number) >> (shift)) | (-((number) >> 31) << (32 - (shift)))) & UINT32_MAX)
#define RR_32b(number, shift) (((((uint32_t)number) >> (shift))|(((uint32_t)number) << (32 - (shift)))) & UINT32_MAX)
#define RL_32b(number, shift) (((((uint32_t)number) << (shift))|(((uint32_t)number) >> (32 - (shift)))) & UINT32_MAX)
#define CountSetBits_32b(number, countVariable)         \
do {                                                    \
    uint32_t bitIndex = (uint32_t)number;               \
    while(bitIndex) {                                   \
        countVariable += bitIndex & 1;                  \
        bitIndex = bitIndex >> 1;                       \
    }                                                   \
} while (0)                                             \

#endif //INT32


#ifdef INT64_MAX

#define LS_64b(number, shift) (((number) << (shift)) & UINT64_MAX)
#define LRS_64b(number, shift) ((((number) >> (shift)) & ~(UINT64_MAX << (64 - (shift)))) & UINT64_MAX)
#define ARS_64b(number, shift) ((((number) >> (shift)) | (-((number) >> 63) << (64 - (shift)))) & UINT64_MAX)
#define RR_64b(number, shift) (((((uint64_t)number) >> (shift))|(((uint64_t)number) << (64 - (shift)))) & UINT64_MAX)
#define RL_64b(number, shift) (((((uint64_t)number) << (shift))|(((uint64_t)number) >> (64 - (shift)))) & UINT64_MAX)
#define CountSetBits_64b(number, countVariable)         \
do {                                                    \
    uint64_t bitIndex = (uint64_t)number;               \
    while(bitIndex) {                                   \
        countVariable += bitIndex & 1;                  \
        bitIndex = bitIndex >> 1;                       \
    }                                                   \
} while (0)                                             \

#endif //INT64

#endif //TEST_DRIVEN_C_BITTLE_H
