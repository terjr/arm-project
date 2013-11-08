#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("cmp r1, "CONST1, "cmp r2, "CONST1);
}
