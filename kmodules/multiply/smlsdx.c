#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlsdx r0, r1, r4, r5", "smlsdx r2, r3, r6, r7");
}
