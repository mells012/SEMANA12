#include <stdio.h>

int main (int argc, char *argv[]) {

    float *puntero1, *puntero2;
    float aux=30;
    puntero1=&aux;
    puntero2=&aux;

    printf("el valor de aux es: %f\n",aux);
    printf("la ubicacion de aux en memoria es: %p\n",&aux);

    printf("el contenido del puntero 1 es: %f\n",*puntero1);
    printf("la ubicacion de memoria del puntero 1 es: %p\n",puntero1);

    *puntero1 =100;
    printf("-------------------------------------\n");
    printf("el valor de aux es: %f\n",aux);

    *puntero2=3000;
    printf("--------------------------------------\n");
    printf("el valor de aux es: %f\n", aux);
    return 0;
    }