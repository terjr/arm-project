#include "../base.c"

void runtest(void) {
    TEST_BENCH("umull r0, r1, r4, r5", "umull r2, r3, r6, r7");
}
