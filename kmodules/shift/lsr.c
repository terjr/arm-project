#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("lsr r1, r2, "CONST0, "lsr r3, r4, "CONST0);
}
