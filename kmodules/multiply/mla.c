#include "../base.c"

void runtest(void) {
    TEST_BENCH("mla r0, r1, r4, r5", "mla r2, r3, r6, r7");
}
