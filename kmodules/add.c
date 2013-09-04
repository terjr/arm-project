#include "base.c"

void runtest(void) {
    int a = 0;
    int i;
    for (i = 0; i < 10000; i++)
        a = a + a;
}
