#include <linux/init.h>
#include <linux/irqflags.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void runtest(void);

static int hello_init(void) {
    printk(KERN_ALERT "Hello, world\n");

    unsigned long irqs;
    local_irq_save(irqs);

    printk("Starting runtest()...\n");
    runtest();
    printk("runtest() done.\n");

    local_irq_restore(irqs);
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
