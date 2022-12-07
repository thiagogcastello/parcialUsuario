#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "LinkedList.h"
#include "parser.h"
#include "input.h"



/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArray LinkedList*
 * \return int
 *
 */
int controller_cargarDesdeTexto(char* path , LinkedList* pArray)
{
    int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArray != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_FromText(pArchivo,pArray);
			printf("\nCarga exitosa de usuarios.\n");
			retorno = 0;
		}
		else
		{
			printf("\nError con la carga de usuarios\n");
		}
		fclose(pArchivo);
	}
    return retorno;
}


void controller_mostrarUsuario(eUsuario* p)
{
    printf("%-10d| %-25s| %-10d   | %-10d | %-10d \n",p->id, p->user, p->likes, p->dislikes, p->followers);
}

void controller_mostrarUsuarios(LinkedList* list)
{
    int tam;
    eUsuario* pElement = NULL;

    if(list != NULL)
    {
        tam = ll_len(list);
        printf("ID |     USUARIO        |   LIKES     | DISLIKES | FOLLOWERS \n");

        for(int i=0; i<tam;i++)
        {
            pElement = (eUsuario*)ll_get(list, i);
            if(pElement != NULL)
            {
                controller_mostrarUsuario(pElement);
            }
        }
    }
}

int controller_menuOpciones()
{
    int opcion;

    printf("1.Cargar Archivo.\n");
    printf("2.Imprimir Lista.\n");
    printf("3.Asignar estadisticas.\n");
    printf("4.Filtrar por mejores posteos.\n");
    printf("5.Filtrar por haters.\n");
    printf("6.Ordenar por cantidad de followers.\n");
    printf("7.Mostrar mas popular.\n");
    printf("7.Salir.\n");
    utnGetNumero(&opcion, "Ingrese una opcion: ", "Error.\nVuelva a ingresar una opcion:", 1,8,5);


    return opcion;
}

void* setLikesRandom(void* pElement)
{
    void* retorno = pElement;
    int max=5000;
    int min=600;
    int valor;
    eUsuario* auxElement = NULL;

    auxElement = user_new();

    if(pElement != NULL)
    {
        auxElement = (eUsuario*)pElement;

        valor = ((rand() % (max - min + 1)) + min);

        user_setLikes(auxElement,valor);

        retorno = auxElement;
    }
    return retorno;
}

void* setDislikesRandom(void* pElement)
{
    void* retorno = pElement;
    int max=3500;
    int min=300;
    int valor;
    eUsuario* auxElement=NULL;

    auxElement = user_new();

    if(pElement != NULL)
    {
        auxElement = (eUsuario*)pElement;

        valor = ((rand() % (max - min + 1)) + min);

        user_setDislikes(auxElement, valor);

        retorno = auxElement;
    }
    return retorno;
}

void* setFollowersRandom(void* pElement)
{
    void* retorno = NULL;
    int max=20000;
    int min=10000;
    int valor;

    eUsuario* auxElement=NULL;

    auxElement = user_new();

    if(pElement != NULL)
    {
        auxElement = (eUsuario*) pElement;

        valor = ((rand() % (max - min + 1)) + min);

        user_setFollowers(auxElement, valor);

        retorno = auxElement;
    }
    return retorno;
}


