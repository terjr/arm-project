#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlatt r0, r1, r4, r5", "smlatt r2, r3, r6, r7");
}
