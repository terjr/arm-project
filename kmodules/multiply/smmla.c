#include "../base.c"

void runtest(void) {
    TEST_BENCH("smmla r0, r1, r4, r5", "smmla r2, r3, r6, r7");
}
