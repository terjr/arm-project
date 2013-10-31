#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlawb r0, r1, r4, r5", "smlawb r2, r3, r6, r7");
}
