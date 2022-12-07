#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"
int esNumerica(char* cadena)
{
	int retorno =1;
	int i=0;


	if(cadena[0 == '-'])
	{
		i=1;
	}

	for( ;cadena[i] != '\0';i++)
	{
		if(cadena[i]> '9' || cadena [i] <'0')
		{
			retorno =0;
			break;

		}
	}
	return retorno;
}

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);

	cadena[strlen(cadena)-1] = '\0';

	return 0;
}

static int getInt(int* pResultado)
{
	int retorno =-1;
	char buffer [4000];


	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno =0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}

int utnGetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);

			if(getInt(&bufferInt) ==0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno =0;
				break;
			}
			else
			{
				reintentos --;
				printf("%s",mensajeError);
			}

			switch(reintentos)
			{

				case 0:
					printf("Queda 1 intento\n");
				break;
				case 1:
					printf("Quedan 2 intentos\n");
				break;
				case 2:
					printf("Quedan 3 intentos\n");
				break;
			}
		}while(reintentos >=0);

	}
	return retorno;
}


static int getShort(short* pResultado)
{
	int retorno =-1;
	char buffer [4000];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno =0;
		*pResultado = atoi(buffer);

	}
	return retorno;
}

int getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, short minimo,short maximo,int reintentos)
{
	int retorno = -1;
	short bufferShort;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{

		do
		{
			printf("%s",mensaje);


			if(getShort(&bufferShort) ==0 && bufferShort >= minimo && bufferShort <= maximo)
			{
				*pResultado = bufferShort;
				retorno =0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}

			switch(reintentos)
			{

				case 0:
					printf("Queda 1 intento\n");
				break;
				case 1:
					printf("Quedan 2 intentos\n");
				break;
				case 2:
					printf("Quedan 3 intentos\n");
				break;
			}
		}while(reintentos >=0);
	}
	return retorno;
}

int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utnGetFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);

		switch(reintentos)
		{
			case 0:
				printf("Queda 1 intento\n");
			break;
			case 1:
				printf("Quedan 2 intentos\n");
			break;
			case 2:
				printf("Quedan 3 intentos\n");
			break;
		}
	}
	return retorno;
}

int pedirCadena(char cadena[],int largo,char mensaje[])
{
	int retorno,largoCadena;
	char buffer[1024];

	retorno = -1;//Si el len de la cadena es 0 o menos

    	if(largo > 0)
    	{
    		printf("%s",mensaje);
    		fflush(stdin);
    		scanf("%[^\n]", buffer);

    		largoCadena = strlen(buffer);
    		retorno = 0;

    		if(largo > largoCadena)
    		{
    			strcpy(cadena,buffer);
    			retorno = 1;
    		}
    	}
	return retorno;
}

int pedirNombreYApellido(int largo, int largoNombre, int largoApellido, char *nombreApellido)
{
	int retorno;
	char nombre[largoNombre];
	char apellido[largoApellido];

	retorno = -1; //si no toma el nombre

	if(largo > 0 && largoNombre > 0 && largoApellido > 0)
	{
	    pedirCadena(nombre, largoNombre ,"Ingrese nombre: ");


        while(validarCadenaSoloLetras(nombre) == 0 )
        {
            pedirCadena(nombre, largoNombre ,"Error. Se ingreso un caracter invalido.\nIngrese nombre: ");
        }

		pedirCadena(apellido, largoApellido ,"Ingrese apellido: ");

		while(validarCadenaSoloLetras(apellido) == 0 )
        {
            pedirCadena(apellido, largoNombre ,"Error. Se ingreso un caracter invalido.\nIngrese apellido: ");
        }

		strlwr(nombre);		//convierto a min los dos arrays
		strlwr(apellido);

		nombre[0] = toupper(nombre[0]);
		apellido[0] = toupper(apellido[0]);

		for(int i = 0; i < largoApellido; i++)
		{
			if(nombre[i] == ' ')
			{
				nombre[i+1] = toupper(nombre[i+1]);	 //transformo en mayuscula 1 letra y la guardo en la misma posicion
				apellido[0] = toupper(apellido[0]);

			}
			if(apellido[i] == ' ')
            {
                apellido[i+1] = toupper(apellido[i+1]);
            }
		}


		strcpy(nombreApellido,apellido);	//copio en un auxiliar los datos para no modificar el original
		strcat(nombreApellido,", ");		//concateno
		strcat(nombreApellido,nombre);

		retorno = 1;
	}

	return retorno;

	return retorno;
}

int validarCadenaSoloLetras(char cadena[])
{
    int todoOk = -1;
    int tam;

    tam = strlen(cadena);

    if(cadena != NULL)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(!isalpha(cadena[i]) && cadena[i] != ' ')
            {
                todoOk = 0;
                break;
            }else{
                todoOk=1;
            }
        }
    }
    return todoOk;
}


int getCaracterSN(char* c, char mje[], char mjeError[])
{
    int todoOk=0;

    if(c != NULL)
    {
        int ret;

        printf(mje);
        fflush(stdin);
        ret = scanf("%c", c);

        while(ret != 1 || isalpha(*c) == 0 || ( *c != 'n' && *c != 's'))
        {
            printf(mjeError);
            printf(mje);
            fflush(stdin);
            ret = scanf("%c", c);
        }

        todoOk=1;
    }

    return todoOk;
}

int getCaracter(char* c, char mje[], char mjeError[])
{
    int todoOk=0;

    if(c != NULL)
    {
        int ret;

        printf(mje);
        fflush(stdin);
        ret = scanf("%c", c);

        while(ret != 1 || isalpha(*c) == 0 )
        {
            printf(mjeError);
            printf(mje);
            fflush(stdin);
            ret = scanf("%c", c);
        }

        todoOk=1;
    }

    return todoOk;
}

int getChars(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos)
{

	char auxChar[52];
	int retorno;
	retorno = -1;

	if (array != NULL && mensaje != NULL && mensajeError != NULL &&
			len > 0 && maximoReintentos >= 0) {
			do
			{
				printf("%s", mensaje);
				fflush(stdin);
				if(myGets(auxChar,sizeof(auxChar))==0)
				{
					if(validarLetras(auxChar)==1)
					{
						strncpy(array, auxChar, len);
						retorno = 0;
						break;
					}
					else
					{
						printf("%s", mensajeError);
						retorno = -1;
						maximoReintentos--;
					}
				}
				else
				{
					maximoReintentos--;
				}

			}while(maximoReintentos > 0);

		}


	return retorno;
}

int validarLetras(char cadena[])
{
	int retorno=0;
	int len = strlen(cadena);

	if(cadena!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(cadena[0] == ' ')
			{
				break;
			}
			if((cadena[i]>='A' && cadena[i]<='Z') || (cadena[i]>='a' && cadena[i]<='z') || cadena[i]==' ')
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getIntInText(char *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos) {

	char auxNumeroIngresado[128];
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo
			&& maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			if(myGets(auxNumeroIngresado, sizeof(auxNumeroIngresado))==0 && validarNumero(auxNumeroIngresado)==1
					&& validarRangoDeNumero(auxNumeroIngresado, minimo, maximo)==0)
			{
				strncpy(pNumeroIngresado, auxNumeroIngresado, sizeof(&pNumeroIngresado));
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				maximoDeReintentos--;
				retorno = -1;
			}
		} while (maximoDeReintentos > 0);
	}

	return retorno;
}

int validarRangoDeNumero(char * numeroIngresado, int minimo, int maximo)
{
	int retorno = -1;
	int numeroAVericar;

	numeroAVericar = atoi(numeroIngresado);

	if(numeroIngresado != NULL && numeroAVericar >= minimo && numeroAVericar <= maximo)
	{
		retorno = 0;
	}

	return retorno;
}

int validarNumero(char * cadena)
{
	int retorno;
	int i;

	i = 0;
	retorno = 1;

	if(cadena != NULL)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		for( ; cadena[i] != '\0'; i++)
		{
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}


	return retorno;
}
