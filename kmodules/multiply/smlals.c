#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlals r0, r1, r4, r5", "smlals r2, r3, r6, r7");
}
