#include "../base.c"

void runtest(void) {
    TEST_BENCH("orr r1, r2, "CONST1, "orr r3, r4, "CONST1);
}
