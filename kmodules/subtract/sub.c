#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("sub r1, r2, "CONST1, "sub r3, r4, "CONST1);
}
