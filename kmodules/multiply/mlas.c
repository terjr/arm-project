#include "../base.c"

void runtest(void) {
    TEST_BENCH("mlas r0, r1, r4, r5", "mlas r2, r3, r6, r7");
}
