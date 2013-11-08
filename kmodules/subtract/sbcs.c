#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("sbcs r1, r2, "CONST1, "sbcs r3, r4, "CONST1); }
