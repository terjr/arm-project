#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("rscs r1, r2, "CONST1, "rscs r3, r4, "CONST1);
}
