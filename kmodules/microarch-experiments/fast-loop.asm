__asm__("mrc p15, 0, r0, c1, c0, 0\n"
        "bic r0, r0, #(0x1 << 12)\n"
        "mcr p15, 0, r0, c1, c0, 0\n"
        "mov r2, #0b111111111111111111111111111111\n"
        "b lbl\n"
        ".align\n"
        "lbl:\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "asr r1, r1, #1\n"
        "subs r2, r2, #1\n"
        "bne lbl\n"
        );
