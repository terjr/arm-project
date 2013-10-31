#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlalbb r0, r1, r4, r5", "smlalbb r2, r3, r6, r7");
}
