
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>


static int irq = 1,  device = 0xaa, c = 0;

static irqreturn_t key_handler(int irq, void *device)
{
        pr_info("Keyboard Counter:%d\n", c++);
        return IRQ_NONE;
}
/* registering irq */
static int test_interrupt_init(void)
{
        pr_info("%s: In init\n", __func__);
        return request_irq(irq, key_handler, IRQF_SHARED,"my_keyboard_handler", &device);
}

static void test_interrupt_exit(void)
{
        pr_info("%s: In exit\n", __func__);
        synchronize_irq(irq); /* synchronize interrupt */
        free_irq(irq, &device);
}

module_init(test_interrupt_init);
module_exit(test_interrupt_exit);

MODULE_LICENSE("GPL");

