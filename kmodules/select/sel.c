#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("sel r0, r1, r2", "sel r3, r4, r5");
}
