#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlalbt r0, r1, r4, r5", "smlalbt r2, r3, r6, r7");
}
