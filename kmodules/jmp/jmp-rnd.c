#include "../base.c"

void runtest(void) {
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
            "b .+24\n" \
            "b .+20\n" \
            "b .+16\n" \
            "b .+12\n" \
            "b .+8\n" \
            "b .+4\n" \
            "b .+14\n" \
            "b .-2\n" \
            "b .-6\n" \
            "b .-10\n" \
            "b .-14\n" \
            "b .-18\n" \
            "b .-22\n" \
            "subs r7, r7, #1\n" \
            "bne lbl\n"); \
}
