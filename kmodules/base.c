#include <linux/init.h>
#include <linux/irqflags.h>
#include <linux/module.h>

#include "test_bench.h"

#define CONST0 "#1"
#define CONST1 "#55"
#define CONST2 "#0x55"
#define CONST3 "#0xAA"

MODULE_LICENSE("GPL");

void runtest(void);

static int hello_init(void) {
    unsigned long irqs;

    printk(KERN_ALERT "Hello, world\n");

    local_irq_save(irqs);
    preempt_disable();

    printk("Starting runtest()...\n");
    runtest();
    printk("runtest() done.\n");

    preempt_enable();
    local_irq_restore(irqs);
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
