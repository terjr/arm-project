#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("ssat16 r1, "CONST4", r2", "ssat16 r3, "CONST4", r4");
}
