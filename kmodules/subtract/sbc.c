#include "../base.c"

void runtest(void) {
    TEST_BENCH("sbc r1, r2, "CONST1, "sbc r3, r4, "CONST1);
}
