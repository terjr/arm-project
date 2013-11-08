#include "../base.c"

#undef num_iterations
#define num_iterations "0x3fffffff"


void runtest(void) {
    TEST_BENCH("usat16 r1, "CONST4", r2", "usat16 r3, "CONST4", r4");
}
