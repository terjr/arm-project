#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("uxtb16 r1, r2", "uxtb16 r3, r4");
}
