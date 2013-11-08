#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("teq r1, "CONST1, "teq r2, "CONST1);
}
