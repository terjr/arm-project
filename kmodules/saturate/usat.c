#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("usat r1, "CONST4", r2", "usat r3, "CONST4", r4");
}
