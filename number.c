#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE1(sys_number, int, a)
{
        printk("El numero ingresado: %d \n", a)
        return 0;
}