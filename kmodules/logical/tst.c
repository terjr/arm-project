#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("tst r1, "CONST1, "tst r2, "CONST1);
}
