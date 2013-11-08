#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("sxtah r0, r1, r2", "sxtah r3, r4, r5");
}
