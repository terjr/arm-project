#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("smmlsr r1, r2, r5, r6", "smmlsr r3, r4, r7, r8");
}
