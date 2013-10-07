#define DISABLE_L1_CACHE() \
    __asm__ volatile ( \
            "mrc p15, 0, r0, c1, c0, 0\n" \
            "bic r0, r0, #(0x1 << 12)\n" \
            "mcr p15, 0, r0, c1, c0, 0\n" \
            )

#define INIT_ITER_COUNT(iter_count) \
    __asm__ volatile ( \
            "mov r7, #"iter_count"\n" \
            )

#define INIT_RANDOM_REGVALS() \
    __asm__ volatile ( \
            "mov r0, #0x55\n" \
            "mov r1, #0x71\n" \
            "mov r2, #0x11\n" \
            "mov r3, #0x01\n" \
            )

#define LOOP_HEAD(label) \
    __asm__ volatile ( \
            ".balign 64\n" \
            label":" \
            )

#define LOOP_TAIL(label) \
    __asm__ volatile ( \
            "subs r7, r7, #1\n" \
            "bne "label"\n" \
            )

#define NOP() __asm__ volatile ("nop\n")

#define NOP_x2() NOP(); NOP()
#define NOP_x4() NOP_x2(); NOP_x2()
#define NOP_x8() NOP_x4(); NOP_x4()
#define NOP_x16() NOP_x8(); NOP_x8()
#define NOP_x32() NOP_x16(); NOP_x16()

#define NOP_x59() \
    NOP_x32(); NOP_x16(); NOP_x8(); NOP_x2(); NOP()

#define MAP_EVENT_COUNTER(counter, event) \
    __asm__ volatile ("mcr p15, 0, %0, c9, c12, 5\n" :: "r"(counter << 2)); \
    __asm__ volatile ("mcr p15, 0, %0, c9, c13, 1\n" :: "r"(event))

/*
 * Initiate event counter using event number (table A.18)
 * and monitor register (table 9.1)
 */

#define INIT_PERF_COUNTERS() \
    MAP_EVENT_COUNTER(0, 0x70); \
    MAP_EVENT_COUNTER(0, 0x71); \
    MAP_EVENT_COUNTER(0, 0x72)


#define RESET_COUNTERS() \
    __asm__ volatile (".balign 64\n"); \
    NOP_x59(); \
    __asm__ volatile ("mcr p15, 0, %0, c9, c12, 3\n" :: "r"(0x8000003f)); \
    __asm__ volatile ("mcr p15, 0, %0, c9, c12, 1\n" :: "r"(0x8000003f)); \
    __asm__ volatile ("mcr p15, 0, %0, c9, c12, 0\n" :: "r"(0x17))

#define PRINT_PERFCOUNTER(n) \
    __asm__ volatile ("mcr p15, 0, %0, c9, c12, 5\n" :: "r"(n)); \
    __asm__ volatile ("mrc p15, 0, %0, c9, c13, 2\n" : "=r"(perf)); \
    printk("Eventctr #%d = %d\n", n, perf)

#define PRINT_COUNTERS() \
    __asm__ volatile ("mcr p15, 0, %0, c9, c12, 1\n" :: "r"(0x0)); \
    __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0\n": "=r"(perf)); \
    printk("Cycle count: %d\n", perf); \
            PRINT_PERFCOUNTER(0); \
            PRINT_PERFCOUNTER(1); \
            PRINT_PERFCOUNTER(2); \
            PRINT_PERFCOUNTER(3); \
            PRINT_PERFCOUNTER(4); \
            PRINT_PERFCOUNTER(5)

#define CACHE_WARMUP(label) \
    INIT_ITER_COUNT("0xff"); \
    __asm__ volatile ("mov r7, r7, lsl #8\n"); \
    __asm__ volatile ( \
            "warmup"label":\n" \
            "ldr r0, "label"\n" \
            "ldr r1, "label"+32\n" \
            "subs r7, r7, #1\n" \
            "bne warmup"label"\n" \
            "mov %[instruction], r1\n" \
            : [instruction] "=r"(content)); \
            printk("Instr: %x\n", content)

#define FAST_LOOP_nHAZARDS(label, instr1, instr2, iter_count) \
    INIT_ITER_COUNT(iter_count); \
    RESET_COUNTERS(); \
    LOOP_HEAD(label); \
    __asm__ volatile ( \
        instr1"\n" \
        instr2"\n" \
        instr1"\n" \
        instr2"\n" \
        instr1"\n" \
        instr2"\n" \
        instr1"\n" \
        instr2"\n" \
        instr1"\n" \
        instr2"\n" \
        instr1"\n" \
        instr2"\n" \
        instr1"\n" \
       ); \
    LOOP_TAIL(label); \



#define FAST_LOOP(label, instr, iter_count) \
    INIT_ITER_COUNT(iter_count); \
    RESET_COUNTERS(); \
    LOOP_HEAD(label); \
    __asm__ volatile ( \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        instr"\n" \
        ); \
    LOOP_TAIL(label); \

