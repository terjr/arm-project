#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlsldx r0, r1, r4, r5", "smlsldx r2, r3, r6, r7");
}
