#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("rsc r1, r2, "CONST1, "rsc r3, r4, "CONST1);
}
