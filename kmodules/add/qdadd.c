#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("qdadd r1, r2, r3", "qdadd r4, r5, r6");
}
