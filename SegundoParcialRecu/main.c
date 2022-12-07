#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "usuario.h"
#include "input.h"


int main()
{
    int option = 0;
    int flagCargaArchivo=0;
    int flagDuracionCargada=0;
    LinkedList* listaUsuarios = ll_newLinkedList();
    srand(time(NULL));

    do{
        system("cls");

        option = controller_menuOpciones();

        switch(option)
        {
            case 1:
            	if(!flagCargaArchivo)
            	{
            		controller_cargarDesdeTexto("posts.csv", listaUsuarios);
            		flagCargaArchivo = 1;
            		system("pause");
            	}else{
            		printf("Los archivos ya han sido cargados.\n");
            		system("pause");
            	}
            	break;

            case 2:
                if(flagCargaArchivo)
                {
                    controller_mostrarUsuarios(listaUsuarios);
                    flagDuracionCargada=1;
                    system("pause");
                }else{
                    printf("Antes de mostrar la lista se debe cargarla (opcion 1).\n");
                }
            	break;

            case 3:
                if(flagCargaArchivo)
                {
                    listaUsuarios = ll_map(listaUsuarios, setFollowersRandom);

                    controller_mostrarUsuarios(listaUsuarios);

                    system("pause");
                }else{
                    printf("Antes de mostrar la lista se debe cargarla (opcion 1).\n");
                    system("pause");
                }
				break;

            case 4:
                if(flagDuracionCargada)
                {
                    //controller_filtroGenero(listaPeliculas);
                }else
                {
                    printf("Primero debe asignarse la duracion de las peliculas (opcion 3)\n");
                }
				break;

            case 5:

				break;

            case 6:

				break;

            case 7:

				break;

            default:
            	printf("Se ingreso una opcion Invalida.\n");
				break;
        }
    }while(option != 7);

    return 0;
}




