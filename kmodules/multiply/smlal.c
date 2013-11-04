#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlal r0, r1, r4, r5", "smlal r2, r3, r6, r7");
}
