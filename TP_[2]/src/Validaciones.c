#include <stdio.h>
#include <string.h>
#include "Validaciones.h"

int PedirEntero(char mensajeA[], char mensajeB[],char numero[], int min, int max) {
	char numeroIngresado[1000];

	printf("%s", mensajeA);
	scanf("%s", numeroIngresado);
	while (numeroIngresado < min || numeroIngresado > max) {
		printf("%s", mensajeB);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}

float PedirFloat(char mensajeA[], char mensajeB[], int min, int max) {
	float numeroIngresado;

	printf("%s", mensajeA);
	scanf("%f", &numeroIngresado);
	while (numeroIngresado < min || numeroIngresado >max) {
		printf("%s", mensajeB);
		scanf("%f", &numeroIngresado);
		}
		return numeroIngresado;
	}

	void PedirString(char mensaje[], char stringIngresado[]) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", stringIngresado);
	}

	int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
	{
	    int retorno=-1;
	    int auxInt;
	    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
	    {
	        do
	        {
	            printf("%s\n",mensaje);
	            scanf("%d",&auxInt);
	            if(auxInt>=minimo && auxInt<=maximo)
	            {
	                *pResultado=auxInt;
	                retorno=0;
	                break;
	            }
	            else
	            {
	                printf("%s\n",mensajeError);
	                reintentos--;
	            }
	        }while(reintentos>0);
	    }
	    return retorno;
	}
