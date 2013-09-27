#include "loop_util.h"

#define TEST_BENCH(instr) \
    unsigned int value, value2; \
\
    printk("Testing "instr"\n");\
\
    DISABLE_L1_CACHE(); \
    INIT_RANDOM_REGVALS(); \
\
\
    /* Loop for power-meassure */ \
    FAST_LOOP("lbl", instr, "0x1fffffff"); \
\
    /* Loops for instruction length (cycles) determination */ \
    CACHE_WARMUP("lbl2"); \
    FAST_LOOP("lbl2", instr, "0xa"); \
    READ_CYCLE_COUNTER(value); \
    printk("part1 done. %d cycles, 10 iterations\n", value); \
\
    CACHE_WARMUP("lbl3"); \
    FAST_LOOP("lbl3", instr, "0xb"); \
    READ_CYCLE_COUNTER(value2); \
    printk("part2 done. %d cycles, 11 iterations\n", value2); \
\
    return value2 - value;

