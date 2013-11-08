#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("sxtab16 r0, r1, r2", "sxtab16 r3, r4, r5");
}
