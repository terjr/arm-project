#include "../base.c"

void runtest(void) {
    TEST_BENCH("smmls r0, r1, r4, r5", "smmls r2, r3, r6, r7");
}
