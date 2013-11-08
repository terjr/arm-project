#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("asr r1, r2, "CONST0, "asr r3, r4, "CONST0);
}
