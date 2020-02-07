#include <linux/kernel.h>

asmlinkage int sys_number(int a)
{
        printk("El número que ingresó es: %d \n", a)
        return 0;
}