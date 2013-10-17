#include <linux/init.h>
#include <linux/irqflags.h>
#include <linux/module.h>


#include "single_iter.h"
#include "../base.c"

unsigned int runtest(void) {
    TEST_BENCH("add r1, r2, "CONST1);
}
