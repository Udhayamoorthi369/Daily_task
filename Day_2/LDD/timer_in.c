
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/jiffies.h>
#include <linux/timer.h>
#include <linux/kdev_t.h>
#include <linux/input.h>
#include <asm/io.h>

#define TIMEOUT_1 20000
#define TIMEOUT_2 10000

static struct timer_list my_timer;
static struct input_dev *my_dev;

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

const unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

//MODULE_LICENSE("GPL");
static int irq = 1,  dev = 0xaa;
#define KBD_DATA_REG        0x60    /* I/O port for keyboard data */
#define KBD_SCANCODE_MASK   0x7f
#define KBD_STATUS_MASK     0x80

static irqreturn_t keyboard_handler(int irq, void *dev)
{
	char scancode;
	scancode = inb(KBD_DATA_REG);
	pr_info("Character %c %s\n",
			kbdus[scancode & KBD_SCANCODE_MASK],
			scancode & KBD_STATUS_MASK ? "Released" : "Pressed");
        return IRQ_NONE;
}
/* registering irq */
void timer_callback(struct timer_list *data)
{

 

input_report_key(my_dev,KEY_A,1);
	input_report_key(my_dev,KEY_A,0);
	input_report_key(my_dev,KEY_B,1);
        input_report_key(my_dev,KEY_B,0);
	input_report_key(my_dev,KEY_C,1);
        input_report_key(my_dev,KEY_C,0);
	input_report_key(my_dev,KEY_D,1);
        input_report_key(my_dev,KEY_D,0);
	input_report_key(my_dev,KEY_E,1);
        input_report_key(my_dev,KEY_E,0);
	input_report_key(my_dev,KEY_F,1);
        input_report_key(my_dev,KEY_F,0);
	input_report_key(my_dev,KEY_G,1);
        input_report_key(my_dev,KEY_G,0);
	input_report_key(my_dev,KEY_H,1);
        input_report_key(my_dev,KEY_H,0);
	input_report_key(my_dev,KEY_I,1);
        input_report_key(my_dev,KEY_I,0);
	input_report_key(my_dev,KEY_J,1);
        input_report_key(my_dev,KEY_J,0);
	input_report_key(my_dev,KEY_K,1);
        input_report_key(my_dev,KEY_K,0);
	input_report_key(my_dev,KEY_L,1);
        input_report_key(my_dev,KEY_L,0);
	input_report_key(my_dev,KEY_M,1);
        input_report_key(my_dev,KEY_M,0);
	input_report_key(my_dev,KEY_N,1);
        input_report_key(my_dev,KEY_N,0);
	input_report_key(my_dev,KEY_O,1);
        input_report_key(my_dev,KEY_O,0);
	input_report_key(my_dev,KEY_P,1);
        input_report_key(my_dev,KEY_P,0);
	input_report_key(my_dev,KEY_Q,1);
        input_report_key(my_dev,KEY_Q,0);
	input_report_key(my_dev,KEY_R,1);
        input_report_key(my_dev,KEY_R,0);
	input_report_key(my_dev,KEY_S,1);
        input_report_key(my_dev,KEY_S,0);
	input_report_key(my_dev,KEY_T,1);
        input_report_key(my_dev,KEY_T,0);
	input_report_key(my_dev,KEY_U,1);
        input_report_key(my_dev,KEY_U,0);
	input_report_key(my_dev,KEY_V,1);
        input_report_key(my_dev,KEY_V,0);
	input_report_key(my_dev,KEY_W,1);
        input_report_key(my_dev,KEY_W,0);
	input_report_key(my_dev,KEY_X,1);
        input_report_key(my_dev,KEY_X,0);
	input_report_key(my_dev,KEY_Y,1);
        input_report_key(my_dev,KEY_Y,0);
	input_report_key(my_dev,KEY_Z,1);
        input_report_key(my_dev,KEY_Z,0); 
	input_sync(my_dev);
	

	mod_timer(&my_timer,jiffies+msecs_to_jiffies(TIMEOUT_2));
}


static int my_timer_init(void)
{
	my_dev = input_allocate_device();

	set_bit(EV_KEY,my_dev->evbit);
	set_bit(KEY_A,my_dev->keybit);
	set_bit(KEY_B,my_dev->keybit);
	set_bit(KEY_C,my_dev->keybit);
	set_bit(KEY_D,my_dev->keybit);
	set_bit(KEY_E,my_dev->keybit);
	set_bit(KEY_F,my_dev->keybit);
	set_bit(KEY_G,my_dev->keybit);
	set_bit(KEY_H,my_dev->keybit);
	set_bit(KEY_I,my_dev->keybit);
	set_bit(KEY_J,my_dev->keybit);
	set_bit(KEY_K,my_dev->keybit);
	set_bit(KEY_L,my_dev->keybit);
	set_bit(KEY_M,my_dev->keybit);
	set_bit(KEY_N,my_dev->keybit);
	set_bit(KEY_O,my_dev->keybit);
	set_bit(KEY_P,my_dev->keybit);
	set_bit(KEY_Q,my_dev->keybit);
	set_bit(KEY_R,my_dev->keybit);
	set_bit(KEY_S,my_dev->keybit);
	set_bit(KEY_T,my_dev->keybit);
	set_bit(KEY_U,my_dev->keybit);


	input_register_device(my_dev);


	timer_setup(&my_timer,timer_callback,0);
	mod_timer(&my_timer,msecs_to_jiffies(TIMEOUT_1));
  pr_info("%s: In init\n", __func__);
        return request_irq(irq, keyboard_handler, IRQF_SHARED,"my_keyboard_handler", &dev);
	
pr_info("timer module is loaded into kernel..\n");
	return 0;
}

static void my_timer_exit(void)
{
	del_timer(&my_timer);
	input_unregister_device(my_dev);
synchronize_irq(irq); /* synchronize interrupt */
        free_irq(irq, &dev);

	pr_info("timer module is unloaded from the kernel..\n");

}

module_init(my_timer_init);
module_exit(my_timer_exit);

MODULE_LICENSE("GPL");

