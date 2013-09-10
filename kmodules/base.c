#include <linux/init.h>
#include <linux/irqflags.h>
#include <linux/module.h>

#include "fast_loop.h"

MODULE_LICENSE("GPL");

unsigned int runtest(void);

static int hello_init(void) {
    unsigned long irqs;
    unsigned int cc;

    printk(KERN_ALERT "Hello, world\n");

    local_irq_save(irqs);
    preempt_disable();

    printk("Starting runtest()...\n");
    init_perfcounters(1, 0);
    cc = runtest();
    printk("runtest() done. %d cycles\n", cc);

    preempt_enable();
    local_irq_restore(irqs);
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
