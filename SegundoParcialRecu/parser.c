#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "usuario.h"


int parser_FromText(FILE* pFile , LinkedList* pArray)
{
    int todoOk = -1;
    eUsuario* auxUser;
    char auxId[30];
    char auxUsuario[100];
    char auxLikes[30];
    char auxDislikes[30];
    char auxFollowers[30];

    if(pFile != NULL && pArray != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", auxId, auxUsuario, auxLikes, auxDislikes,auxFollowers);

    	while(!feof(pFile))
    	{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", auxId, auxUsuario, auxLikes, auxDislikes, auxFollowers);

            auxUser = user_newParametros(auxId, auxUsuario, auxLikes, auxDislikes, auxFollowers);

            if(auxUser != NULL)
            {
                ll_add(pArray, auxUser);
            }
    	}

    	todoOk = 1;
    }

    return todoOk;
}

