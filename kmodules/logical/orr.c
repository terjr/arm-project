#include "../base.c"

void runtest(void) {
    TEST_BENCH("orr r1, r1, "CONST1, "orr r1, r1, "CONST1);
}
