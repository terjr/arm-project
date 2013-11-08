#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("sxtb r0, r1", "sxtb r2, r3");
}
