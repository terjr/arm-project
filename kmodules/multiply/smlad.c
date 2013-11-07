#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlad r0, r1, r4, r5", "smlad r2, r3, r6, r7");
}
