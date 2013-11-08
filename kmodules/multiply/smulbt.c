#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("smulbt r0, r1, r2", "smulbt r3, r4, r5");
}
