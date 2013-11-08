#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("sxtb16 r1, r2", "sxtb16 r3, r4");
}
