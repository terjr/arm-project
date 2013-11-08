#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("uxtb r0, r1", "uxtb r2, r3");
}
