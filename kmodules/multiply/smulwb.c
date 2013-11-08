#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("smulwb r0, r1, r2", "smulwb r3, r4, r5");
}
