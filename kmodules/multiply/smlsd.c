#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlsd r0, r1, r4, r5", "smlsd r2, r3, r6, r7");
}
