#include <linux/init.h>
#include <linux/irqflags.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void runtest(void);

static int hello_init(void) {
    printk(KERN_ALERT "Hello, world\n");

    unsigned long irqs;
    local_irq_save(irqs);

    printk("Interrupts enabled: 0x%X\n", irqs);

    runtest();

    local_irq_restore(irqs);
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
