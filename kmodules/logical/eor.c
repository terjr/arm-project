#include "../base.c"

void runtest(void) {
    TEST_BENCH("eor r1, r1, "CONST1, "eor r1, r1, "CONST1);
}
