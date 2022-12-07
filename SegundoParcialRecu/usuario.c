#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "usuario.h"

eUsuario* user_new()
{
	eUsuario* newUser;

	newUser = (eUsuario*) malloc(sizeof(eUsuario));

	if(newUser != NULL)
	{
		newUser->id=-1;
		strcpy(newUser->user, "");
		newUser->likes = -1;
		newUser->dislikes = -1;
		newUser->followers = -1;
	}

	return newUser;
}

eUsuario* user_newParametros(char* idStr,char* userStr,char* likesStr, char* dislikesStr, char* followersStr)
{
	eUsuario* newUser = NULL;
	int todoOk=0;

	newUser = user_new();

	if(idStr != NULL && userStr != NULL && likesStr != NULL && dislikesStr != NULL && followersStr != NULL)
	{
		if(user_setId(newUser, atoi(idStr))== 0 && user_setUser(newUser, userStr)==0 &&
			user_setLikes(newUser, atoi(likesStr)) ==0 && user_setDislikes(newUser, atoi(dislikesStr)) == 0 &&
            user_setFollowers(newUser, atoi(followersStr)) == 0)
		{
			todoOk=1;
		}
		if(!todoOk)
        {
            free(newUser);
            newUser = NULL;
        }
	}

	return newUser;
}

int user_setId(eUsuario* this, int id)
{
    int retorno = -1;

	if(this != NULL && id >= 1)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int user_getId(eUsuario* this, int* id)
{
    int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int user_setUser(eUsuario* this,char* user)
{
	int retorno = -1;

	if(this != NULL && user != NULL)
	{
		strcpy(this->user, user);
		retorno = 0;
	}

	return retorno;
}


int user_getUser(eUsuario* this,char* user)
{
	int retorno = -1;

		if(this != NULL && user != NULL)
		{
			strcpy(user, this->user);
			retorno = 0;
		}

		return retorno;
}

int user_setLikes(eUsuario* this, int likes)
{
    int retorno = -1;

	if(this != NULL && likes >= 0)
	{
		this->likes = likes;
		retorno = 0;
	}

	return retorno;
}

int user_getLikes(eUsuario* this, int* likes)
{
    int retorno = -1;

	if(this != NULL && likes != NULL)
	{
		*likes = this->likes;
		retorno = 0;
	}

	return retorno;
}


int user_setDislikes(eUsuario* this, int dislikes)
{
    int retorno = -1;

	if(this != NULL && dislikes >= 0)
	{
		this->dislikes = dislikes;
		retorno = 0;
	}

	return retorno;
}

int user_getDislikes(eUsuario* this, int* dislikes)
{
    int retorno = -1;

	if(this != NULL && dislikes != NULL)
	{
		*dislikes = this->dislikes;
		retorno = 0;
	}

	return retorno;
}

int user_setFollowers(eUsuario* this, int followers)
{
    int retorno = -1;

	if(this != NULL && followers >= 0)
	{
		this->followers = followers;
		retorno = 0;
	}

	return retorno;
}

int user_getFollowers(eUsuario* this, int* followers)
{
    int retorno = -1;

	if(this != NULL && followers != NULL)
	{
		*followers = this->followers;
		retorno = 0;
	}

	return retorno;
}


