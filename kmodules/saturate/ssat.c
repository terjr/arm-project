#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("ssat r1, "CONST4", r2", "ssat r3, "CONST4", r4");
}
