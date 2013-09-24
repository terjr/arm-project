#include "loop_util.h"

#define TEST_BENCH(instr) \
    unsigned int value; \
\
    DISABLE_L1_CACHE(); \
    INIT_RANDOM_REGVALS(); \
\
    FAST_LOOP("lbl", instr, "0x1fffffff"); \
\
    FAST_LOOP("lbl2", instr, "0x1"); \
\
    READ_CYCLE_COUNTER("value"); \
    return value;

