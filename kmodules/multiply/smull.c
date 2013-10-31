#include "../base.c"

void runtest(void) {
    TEST_BENCH("smull r0, r1, r4, r5", "smull r2, r3, r6, r7");
}
