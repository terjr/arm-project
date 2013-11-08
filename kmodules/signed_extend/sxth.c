#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("sxth r0, r1", "sxth r2, r3");
}
