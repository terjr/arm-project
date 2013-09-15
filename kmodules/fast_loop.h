static inline unsigned int get_cyclecount(void) {
    unsigned int value;
    // Read CCNT Register
    asm volatile ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(value));
    return value;
}

static inline void init_perfcounters(int32_t do_reset, int32_t enable_divider) {
    // in general enable all counters (including cycle counter)
    int32_t value = 1;

    // peform reset:
    if (do_reset)
    {
        value |= 2;     // reset all counters to zero.
        value |= 4;     // reset cycle counter to zero.
    }

    if (enable_divider)
        value |= 8;     // enable "by 64" divider for CCNT.

    value |= 16;

    // program the performance-counter control-register:
    asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(value));

    // enable all counters:
    asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));

    // clear overflows:
    asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
}

#define FAST_LOOP(instr) \
    unsigned int _cc = 0; \
\
/* disable i-cache */\
    __asm__ volatile ( \
            "mrc p15, 0, r0, c1, c0, 0\n" \
            "bic r0, r0, #(0x1 << 12)\n" \
            "mcr p15, 0, r0, c1, c0, 0\n"); \
            /* set up loop */ \
    __asm__ volatile ( \
            "mov r7, #0x3fffffff\n" \
            "mov r0, #0x55\n" \
            "mov r1, #0x71\n" \
            "mov r2, #0x11\n" \
            "mov r3, #0x01\n"); \
            /* reset cycle counter */ \
  /* program the performance-counter control-register: */ \
    asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x17)); \
    /* enable all counters: */ \
    asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f)); \
    /* clear overflows: */ \
    asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f)); \
 \
    __asm__ volatile ("b lbl\n" \
            ".align\n" \
            "lbl:\n" \
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
            "subs r7, r7, #1\n" \
            "bne lbl\n" : "=r"(_cc)); \
return get_cyclecount()

#define CONST0 "#1"
#define CONST1 "#55"
#define CONST2 "#0x55"
#define CONST3 "#0xAA"
