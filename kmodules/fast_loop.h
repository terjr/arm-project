#define FAST_LOOP(instr) do { \
    __asm__("mrc p15, 0, r0, c1, c0, 0\n" \
            "bic r0, r0, #(0x1 << 12)\n" \
            "mcr p15, 0, r0, c1, c0, 0\n" \
            "mov r7, #0x3fffffff\n" \
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
} while (0);

#define CONST1 "#55"
#define CONST2 "#0x55"
#define CONST3 "#0xAA"
