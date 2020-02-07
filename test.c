#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
         long int resultado = syscall(335, 90);
         printf("Syscall number_hello: %d\n", resultado);
         return 0;
}