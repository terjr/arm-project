#include "loop_util.h"

#define TEST_BLOCK(instr1, instr2, label, iterations) \
    printk(LOG_PREFIX"Running "instr1" and "instr2" for "iterations" iterations\n"); \
    CACHE_WARMUP(label); \
    FAST_LOOP_nHAZARDS(label, instr1, instr2, iterations); \
    PRINT_COUNTERS()

#define TEST_BLOCK_3(instr1, instr2, instr3, label, iterations) \
    printk(LOG_PREFIX"Running "instr1", "instr2" and "instr3" for "iterations" iterations\n"); \
    CACHE_WARMUP(label); \
    FAST_LOOP_3(label, instr1, instr2, instr3, iterations); \
    PRINT_COUNTERS()

#define TEST_BENCH(instr1, instr2) \
    unsigned int content, perf; \
\
    __asm__ volatile ("mrc p15, 0, %0, c9, c12, 0" : "=r"(content)); \
    printk("IMP: %#x, IDCODE: %#x, N: %d\n", content >> 24, (content >> 16) & 0xff, (content >> 11) & 0xf); \
    __asm__ volatile ("mrc p15, 0, %0, c0, c0, 0" : "=r"(content));\
    printk("IMP: %#x, VAR: %#x, ARCH: %#x, PPN: %#x, Rev: %#x\n", \
            content >> 24, (content >> 20) & 0xf, (content >> 16) & 0xf, \
            (content >> 4) & 0xfff, content & 0xf\
            );\
/*    printk("Testing "instr1" and "instr2"\n");\ */ \
\
    DISABLE_L1_CACHE(); \
    INIT_PERF_COUNTERS(); \
    INIT_RANDOM_REGVALS(); \
\
    /* Loop for power-meassure */ \
    FAST_LOOP_nHAZARDS("lbl", instr1, instr2,"0x1fffffff"); \
\
    /* Loops for instruction length (cycles) determination */ \
    TEST_BLOCK(instr1, instr2, "part1", "2"); \
    TEST_BLOCK(instr1, instr2, "part2", "6"); \
    TEST_BLOCK(instr1, instr2, "part3", "0xfa"); \
    TEST_BLOCK(instr1, instr2, "part4", "0xfb");
/*
    TEST_BLOCK_3(instr1, instr2, instr3, "part5", "5");
*/
