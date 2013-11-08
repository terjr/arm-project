#include "../base.c"

#undef num_iterations
#define num_iterations "0x7fffffff"


void runtest(void) {
    TEST_BENCH("mvn r1, r2", "mvn r3, r4");
}
