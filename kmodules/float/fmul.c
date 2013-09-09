asm(
    ".arch armv7-a\t\n"
	".eabi_attribute 27, 3\t\n"
    ".eabi_attribute 28, 1\t\n"
    ".fpu neon\t\n"
    ".eabi_attribute 20, 1\t\n"
    ".eabi_attribute 21, 1\t\n"
    ".eabi_attribute 23, 3\t\n"
    ".eabi_attribute 24, 1\t\n"
    ".eabi_attribute 25, 1\t\n"
    ".eabi_attribute 26, 2\t\n"
    ".eabi_attribute 30, 6\t\n"
    ".eabi_attribute 18, 4\t\n"
    );

#include "../base.c"

void runtest(void) {
    FAST_LOOP("fmuls s15,s14, s15");
}
