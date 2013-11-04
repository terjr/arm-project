#include "../base.c"

void runtest(void) {
    TEST_BENCH("eor r1, r2, "CONST1, "eor r3, r4, "CONST1);
}
