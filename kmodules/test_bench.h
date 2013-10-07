#include "loop_util.h"

#define TEST_BLOCK(instr1, instr2, label, iterations, value) \
    CACHE_WARMUP(label); \
    FAST_LOOP_nHAZARDS(label, instr1, instr2, iterations); \
    READ_CYCLE_COUNTER(value)
 
#define TEST_BENCH(instr1, instr2) \
    unsigned int value, value2, content; \
\
    printk("Testing "instr1" and "instr2"\n");\
\
    DISABLE_L1_CACHE(); \
    INIT_RANDOM_REGVALS(); \
\
\
    /* Loop for power-meassure */ \
    FAST_LOOP_nHAZARDS("lbl", instr1, instr2,"0x1fffffff"); \
\
    /* Loops for instruction length (cycles) determination */ \
    TEST_BLOCK(instr1, instr2, "part1", "5", value); \
    printk("part1 done. %d cycles, 5 iterations\n", value); \
\
    TEST_BLOCK(instr1, instr2, "part2", "6", value2); \
    printk("part2 done. %d cycles, 6 iterations\n", value2); \
\
    TEST_BLOCK(instr1, instr2, "part3", "0xfa", value); \
    printk("part3 done. %d cycles, 0xfa iterations\n", value); \
\
    TEST_BLOCK(instr1, instr2, "part4", "0xfb", value2); \
    printk("part4 done. %d cycles, 0xfb iterations\n", value2); \
\
    return value2 - value;

