#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("smmulr r0, r3, r4", "smmulr r1, r2, r5");
}
