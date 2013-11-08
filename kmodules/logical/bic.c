#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("bic r1, r2, "CONST1, "bic r3, r4, "CONST1);
}
