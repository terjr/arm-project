#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("smultt r0, r1, r2", "smultt r3, r4, r5");
}
