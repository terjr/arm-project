#include "loop_util.h"

#define TEST_BLOCK(instr1, instr2, label, iterations) \
    CACHE_WARMUP(label); \
    INIT_PERF_COUNTERS(); \
    FAST_LOOP_nHAZARDS(label, instr1, instr2, iterations); \
    PRINT_COUNTERS()
 
#define TEST_BENCH(instr1, instr2) \
    unsigned int content, perf; \
\
    printk("Testing "instr1" and "instr2"\n");\
\
    DISABLE_L1_CACHE(); \
    INIT_RANDOM_REGVALS(); \
\
    /* Loop for power-meassure */ \
    FAST_LOOP_nHAZARDS("lbl", instr1, instr2,"0x1fffffff"); \
\
    /* Loops for instruction length (cycles) determination */ \
    TEST_BLOCK(instr1, instr2, "part1", "5"); \
    TEST_BLOCK(instr1, instr2, "part2", "6"); \
    TEST_BLOCK(instr1, instr2, "part3", "0xfa"); \
    TEST_BLOCK(instr1, instr2, "part4", "0xfb"); \

