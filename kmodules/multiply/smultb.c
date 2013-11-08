#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("smultb r0, r1, r2", "smultb r3, r4, r5");
}
