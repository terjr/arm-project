#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlaldx r0, r1, r4, r5", "smlaldx r2, r3, r6, r7");
}
