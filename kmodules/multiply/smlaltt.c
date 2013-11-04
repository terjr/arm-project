#include "../base.c"

void runtest(void) {
    TEST_BENCH("smlaltt r0, r1, r4, r5", "smlaltt r2, r3, r6, r7");
}
