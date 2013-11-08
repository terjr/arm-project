#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("smulwt r0, r1, r2", "smulwt r3, r4, r5");
}
