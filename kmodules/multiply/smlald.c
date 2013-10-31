#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlald r0, r1, r4, r5", "smlald r2, r3, r6, r7");
}
