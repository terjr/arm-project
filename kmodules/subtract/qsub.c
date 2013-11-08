#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("qsub r0, r1, r2", "qsub r3, r4, r5");
}
