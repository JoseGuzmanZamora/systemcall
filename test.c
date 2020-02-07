#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
        int resultado = syscall(335, 32);
        printf("Syscall number_hello: %d\n", resultado);
        return 0;
}