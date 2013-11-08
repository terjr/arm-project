#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("ror r1, r2, "CONST0, "ror r3, r4, "CONST0);
}
