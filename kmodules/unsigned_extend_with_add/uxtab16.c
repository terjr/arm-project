#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("uxtab16 r0, r1, r2", "uxtab16 r3, r4, r5");
}
