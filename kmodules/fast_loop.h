
static inline unsigned int get_cyclecount(void);
static inline void init_perfcounters(int32_t do_reset, int32_t enable_divider);



#define FAST_LOOP(instr) do { \
    __asm__("mcr p15, 0, %0, c9, c14, 2\n" :: 'r'(1)); \
    long __cc = get_cyclecount(); \
    __asm__("mrc p15, 0, r0, c1, c0, 0\n" \
            "bic r0, r0, #(0x1 << 12)\n" \
            "mcr p15, 0, r0, c1, c0, 0\n" \
            "mov r7, #0x3fffffff\n" \
            "mov r0, #0x55\n" \
            "mov r1, #0x71\n" \
            "mov r2, #0x11\n" \
            "mov r3, #0x01\n" \
            "b lbl\n" \
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
            "bne lbl\n"); \
} while (0); \
return get_cyclecount() - __c; \

#define CONST0 "#1"
#define CONST1 "#55"
#define CONST2 "#0x55"
#define CONST3 "#0xAA"
