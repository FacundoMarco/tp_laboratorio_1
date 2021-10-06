#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int PedirEntero (char mensaje[])
{
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}


float PedirFloat (char mensaje[])
{
    float numeroIngresado;

    printf("%s \n", mensaje);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}

void PedirString (char mensaje[], char stringIngresado[])
{
    printf("%s \n", mensaje);
    fflush(stdin);
    scanf("%[^\n]", stringIngresado);
}
