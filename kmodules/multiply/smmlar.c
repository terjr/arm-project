#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("smmlar r1, r2, r5, r6", "smmlar r3, r4, r7, r8");
}
