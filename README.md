# System Call 
El objetivo principal de este repositorio era incluir los archivos necesarios para agregar un system call a un contenedor de Docker. Sin embargo, como se explicará más adelante esto es imposible. 

## El Proceso Inicial
Como primer punto, se llevó a cabo el proceso en una máquina virtual. Se utilizó una imagen de Ubuntu 18.04.3 y se manejó a través de VirtualBox para Windows. Una vez configurada la imagen se pudo empezar a realizar el proceso. 

![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img1.png)

Con el ambiente listo para el cambio, procedí a hacer los necesarios comandos:

```
sudo apt-get update 
sudo apt get upgrade
```

![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img2.png)

Posteriormente revisé la versión de kernel que la máquina estaba corriendo. 

![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img3.png)

Con esa información, utilicé el comando:

```
wget https://mirrors.edge.kernel.org/pub/linux/kernel/v5.x/linux-5.0.1.tar.xz
```
Para descargar el kernel que iba a modificar. A esto le siguió descomprimir el archivo descargado y modificar algunos archivos internos del mismo. En pocas palabras hice lo siguiente:

1. Crear un directorio con el nombre "number"
2. Crear un archivo "number.c" con el código de la system call 
3. Crear un Makefile para ese archivo 
4. Modificar la tabla "syscall_64.tbl" con el número de la nueva llamada 
5. Agregar el nombre de la system call al Makefile del Kernel 
6. Ingresar el prototipo de la llamada al archivo de "syscalls.h"

## Compilación del Kernel 
Al terminar de modificar los archivos, descargué algunas librerías importantes. 
```
sudo make menuconfig
sudo make -j8 (en cualquier otro caso ese 8 es la cantidad de cores virtuales o físicos que maneja la computadora)
```
![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img4.png)
![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img5.png)

Al finalizar la compilación se reinicia la computadora para aplicar el boot nuevo. Y al revisar con el comando del principio se puede ver que cambió la versión de kernel. 

![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img6.png)

Por último se puede probar la llamada con el código de "test.c"
![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img7.png)

Al ingresar el comando:

```
dmesg
```

Después de correr la función que llama a la system call, se puede visualizar el resultado de cada llamada. 
![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/img8.png)

## Docker - Imposible 

La diferencia principal entre un contenedor y una máquina virtual es la relación que cada uno tiene con el sistema operativo. El concepto de máquina virtual engloba a todo el sistema operativo, es decir, cada máquina virtual tiene su propia simulación de un sistema operativo específico, y con esto su propio kernel. Por el otro lado, un contenedor no tiene un kernel propio. Los contenedores se basan en utilizar el kernel del host, es decir de la máquina que lo está corriendo. Por lo tanto, para poder añadir un system call a un contenedor de docker no hay otra manera de hacerlo más que agregarlo al kernel del host y después probarlo en el contenedor, sin embargo, sería una modificación independiente; pues, al compartir la imagen de docker ese system call no se podría utilizar en ninguna otra computadora. En pocas palabras, no se puede. 

![ScreenShot](https://raw.githubusercontent.com/JoseGuzmanZamora/systemcall/master/images/imgf.png)

Como se puede verificar, la versión de kernel que muestra es una especial para docker, pero en realidad no es un kernel per se, sino una interfaz que consume el kernel de la docker-machine que lo está corriendo. 


