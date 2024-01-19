/**
 * @brief alt_bn128 syscall test
 */
#include <sol/alt_bn128.h>
#include <sol/assert.h>
#include <sol/string.h>

extern uint64_t entrypoint(const uint8_t *input) {
  // Addition
  {
    uint8_t result[ALT_BN128_ADDITION_OUTPUT_LEN];
    uint8_t expected[] = {
        0x22, 0x43, 0x52, 0x5c, 0x5e, 0xfd, 0x4b, 0x9c, 0x3d, 0x3c, 0x45,
        0xac, 0xc,  0xa3, 0xfe, 0x4d, 0xd8, 0x5e, 0x83, 0xa,  0x4c, 0xe6,
        0xb6, 0x5f, 0xa1, 0xee, 0xae, 0xe2, 0x2,  0x83, 0x97, 0x3,  0x30,
        0x1d, 0x1d, 0x33, 0xbe, 0x6d, 0xa8, 0xe5, 0x9,  0xdf, 0x21, 0xcc,
        0x35, 0x96, 0x47, 0x23, 0x18, 0xe,  0xed, 0x75, 0x32, 0x53, 0x7d,
        0xb9, 0xae, 0x5e, 0x7d, 0x48, 0xf1, 0x95, 0xc9, 0x15};

    uint8_t input[] = {
        0x18, 0xb1, 0x8a, 0xcf, 0xb4, 0xc2, 0xc3, 0x2,  0x76, 0xdb, 0x54, 0x11,
        0x36, 0x8e, 0x71, 0x85, 0xb3, 0x11, 0xdd, 0x12, 0x46, 0x91, 0x61, 0xc,
        0x5d, 0x3b, 0x74, 0x3,  0x4e, 0x9,  0x3d, 0xc9, 0x6,  0x3c, 0x90, 0x9c,
        0x47, 0x20, 0x84, 0xc,  0xb5, 0x13, 0x4c, 0xb9, 0xf5, 0x9f, 0xa7, 0x49,
        0x75, 0x57, 0x96, 0x81, 0x96, 0x58, 0xd3, 0x2e, 0xfc, 0xd,  0x28, 0x81,
        0x98, 0xf3, 0x72, 0x66, 0x7,  0xc2, 0xb7, 0xf5, 0x8a, 0x84, 0xbd, 0x61,
        0x45, 0xf0, 0xc,  0x9c, 0x2b, 0xc0, 0xbb, 0x1a, 0x18, 0x7f, 0x20, 0xff,
        0x2c, 0x92, 0x96, 0x3a, 0x88, 0x1,  0x9e, 0x7c, 0x6a, 0x1,  0x4e, 0xed,
        0x6,  0x61, 0x4e, 0x20, 0xc1, 0x47, 0xe9, 0x40, 0xf2, 0xd7, 0xd,  0xa3,
        0xf7, 0x4c, 0x9a, 0x17, 0xdf, 0x36, 0x17, 0x6,  0xa4, 0x48, 0x5c, 0x74,
        0x2b, 0xd6, 0x78, 0x84, 0x78, 0xfa, 0x17, 0xd7};

    sol_alt_bn128_group_op(ALT_BN128_ADD, input, SOL_ARRAY_SIZE(input), result);

    sol_assert(0 ==
               sol_memcmp(result, expected, ALT_BN128_ADDITION_OUTPUT_LEN));
  }
  // Multiplication
  {
    uint8_t result[ALT_BN128_MULTIPLICATION_OUTPUT_LEN];
    uint8_t expected[] = {
        0x7,  0xa,  0x8d, 0x6a, 0x98, 0x21, 0x53, 0xca, 0xe4, 0xbe, 0x29,
        0xd4, 0x34, 0xe8, 0xfa, 0xef, 0x8a, 0x47, 0xb2, 0x74, 0xa0, 0x53,
        0xf5, 0xa4, 0xee, 0x2a, 0x6c, 0x9c, 0x13, 0xc3, 0x1e, 0x5c, 0x3,
        0x1b, 0x8c, 0xe9, 0x14, 0xeb, 0xa3, 0xa9, 0xff, 0xb9, 0x89, 0xf9,
        0xcd, 0xd5, 0xb0, 0xf0, 0x19, 0x43, 0x7,  0x4b, 0xf4, 0xf0, 0xf3,
        0x15, 0x69, 0xe,  0xc3, 0xce, 0xc6, 0x98, 0x1a, 0xfc};

    uint8_t input[] = {
        0x2b, 0xd3, 0xe6, 0xd0, 0xf3, 0xb1, 0x42, 0x92, 0x4f, 0x5c, 0xa7, 0xb4,
        0x9c, 0xe5, 0xb9, 0xd5, 0x4c, 0x47, 0x3,  0xd7, 0xae, 0x56, 0x48, 0xe6,
        0x1d, 0x2,  0x26, 0x8b, 0x1a, 0xa,  0x9f, 0xb7, 0x21, 0x61, 0x1c, 0xe0,
        0xa6, 0xaf, 0x85, 0x91, 0x5e, 0x2f, 0x1d, 0x70, 0x30, 0x9,  0x9,  0xce,
        0x2e, 0x49, 0xdf, 0xad, 0x4a, 0x46, 0x19, 0xc8, 0x39, 0xc,  0xae, 0x66,
        0xce, 0xfd, 0xb2, 0x4,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
        0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
        0x0,  0x0,  0x0,  0x0,  0x11, 0x13, 0x8c, 0xe7, 0x50, 0xfa, 0x15, 0xc2};

    sol_alt_bn128_group_op(ALT_BN128_MUL, input, SOL_ARRAY_SIZE(input), result);

    sol_assert(
        0 == sol_memcmp(result, expected, ALT_BN128_MULTIPLICATION_OUTPUT_LEN));
  }
  // Pairing
  {
    uint8_t result[ALT_BN128_PAIRING_OUTPUT_LEN];
    uint8_t expected[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                          0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                          0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1};

    uint8_t input[] = {
        0x1c, 0x76, 0x47, 0x6f, 0x4d, 0xef, 0x4b, 0xb9, 0x45, 0x41, 0xd5, 0x7e,
        0xbb, 0xa1, 0x19, 0x33, 0x81, 0xff, 0xa7, 0xaa, 0x76, 0xad, 0xa6, 0x64,
        0xdd, 0x31, 0xc1, 0x60, 0x24, 0xc4, 0x3f, 0x59, 0x30, 0x34, 0xdd, 0x29,
        0x20, 0xf6, 0x73, 0xe2, 0x4,  0xfe, 0xe2, 0x81, 0x1c, 0x67, 0x87, 0x45,
        0xfc, 0x81, 0x9b, 0x55, 0xd3, 0xe9, 0xd2, 0x94, 0xe4, 0x5c, 0x9b, 0x3,
        0xa7, 0x6a, 0xef, 0x41, 0x20, 0x9d, 0xd1, 0x5e, 0xbf, 0xf5, 0xd4, 0x6c,
        0x4b, 0xd8, 0x88, 0xe5, 0x1a, 0x93, 0xcf, 0x99, 0xa7, 0x32, 0x96, 0x36,
        0xc6, 0x35, 0x14, 0x39, 0x6b, 0x4a, 0x45, 0x20, 0x3,  0xa3, 0x5b, 0xf7,
        0x4,  0xbf, 0x11, 0xca, 0x1,  0x48, 0x3b, 0xfa, 0x8b, 0x34, 0xb4, 0x35,
        0x61, 0x84, 0x8d, 0x28, 0x90, 0x59, 0x60, 0x11, 0x4c, 0x8a, 0xc0, 0x40,
        0x49, 0xaf, 0x4b, 0x63, 0x15, 0xa4, 0x16, 0x78, 0x2b, 0xb8, 0x32, 0x4a,
        0xf6, 0xcf, 0xc9, 0x35, 0x37, 0xa2, 0xad, 0x1a, 0x44, 0x5c, 0xfd, 0xc,
        0xa2, 0xa7, 0x1a, 0xcd, 0x7a, 0xc4, 0x1f, 0xad, 0xbf, 0x93, 0x3c, 0x2a,
        0x51, 0xbe, 0x34, 0x4d, 0x12, 0xa,  0x2a, 0x4c, 0xf3, 0xc,  0x1b, 0xf9,
        0x84, 0x5f, 0x20, 0xc6, 0xfe, 0x39, 0xe0, 0x7e, 0xa2, 0xcc, 0xe6, 0x1f,
        0xc,  0x9b, 0xb0, 0x48, 0x16, 0x5f, 0xe5, 0xe4, 0xde, 0x87, 0x75, 0x50,
        0x11, 0x1e, 0x12, 0x9f, 0x1c, 0xf1, 0x9,  0x77, 0x10, 0xd4, 0x1c, 0x4a,
        0xc7, 0xf,  0xcd, 0xfa, 0x5b, 0xa2, 0x2,  0x3c, 0x6f, 0xf1, 0xcb, 0xea,
        0xc3, 0x22, 0xde, 0x49, 0xd1, 0xb6, 0xdf, 0x7c, 0x20, 0x32, 0xc6, 0x1a,
        0x83, 0xe,  0x3c, 0x17, 0x28, 0x6d, 0xe9, 0x46, 0x2b, 0xf2, 0x42, 0xfc,
        0xa2, 0x88, 0x35, 0x85, 0xb9, 0x38, 0x70, 0xa7, 0x38, 0x53, 0xfa, 0xce,
        0x6a, 0x6b, 0xf4, 0x11, 0x19, 0x8e, 0x93, 0x93, 0x92, 0xd,  0x48, 0x3a,
        0x72, 0x60, 0xbf, 0xb7, 0x31, 0xfb, 0x5d, 0x25, 0xf1, 0xaa, 0x49, 0x33,
        0x35, 0xa9, 0xe7, 0x12, 0x97, 0xe4, 0x85, 0xb7, 0xae, 0xf3, 0x12, 0xc2,
        0x18, 0x0,  0xde, 0xef, 0x12, 0x1f, 0x1e, 0x76, 0x42, 0x6a, 0x0,  0x66,
        0x5e, 0x5c, 0x44, 0x79, 0x67, 0x43, 0x22, 0xd4, 0xf7, 0x5e, 0xda, 0xdd,
        0x46, 0xde, 0xbd, 0x5c, 0xd9, 0x92, 0xf6, 0xed, 0x9,  0x6,  0x89, 0xd0,
        0x58, 0x5f, 0xf0, 0x75, 0xec, 0x9e, 0x99, 0xad, 0x69, 0xc,  0x33, 0x95,
        0xbc, 0x4b, 0x31, 0x33, 0x70, 0xb3, 0x8e, 0xf3, 0x55, 0xac, 0xda, 0xdc,
        0xd1, 0x22, 0x97, 0x5b, 0x12, 0xc8, 0x5e, 0xa5, 0xdb, 0x8c, 0x6d, 0xeb,
        0x4a, 0xab, 0x71, 0x80, 0x8d, 0xcb, 0x40, 0x8f, 0xe3, 0xd1, 0xe7, 0x69,
        0xc,  0x43, 0xd3, 0x7b, 0x4c, 0xe6, 0xcc, 0x1,  0x66, 0xfa, 0x7d, 0xaa};

    sol_alt_bn128_group_op(ALT_BN128_PAIRING, input, SOL_ARRAY_SIZE(input), result);

    sol_assert(0 == sol_memcmp(result, expected, ALT_BN128_PAIRING_OUTPUT_LEN));
  }

  return SUCCESS;
}
