#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("smlabt r0, r1, r4, r5", "smlabt r2, r3, r6, r7");
}
