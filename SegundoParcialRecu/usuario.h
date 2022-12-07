#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct
{
    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;

}eUsuario;

#endif // PELICULA_H_INCLUDED

eUsuario* user_newParametros(char* idStr,char* user,char* likes, char* dislikes, char* followers);

eUsuario* user_new();

int user_setId(eUsuario* this, int id);

int user_getId(eUsuario* this, int* id);

int user_setUser(eUsuario* this,char* user);

int user_getUser(eUsuario* this,char* user);

int user_setLikes(eUsuario* this, int likes);

int user_getLikes(eUsuario* this,int* likes);

int user_setDislikes(eUsuario* this, int dislikes);

int user_getDislikes(eUsuario* this, int* dislikes);

int user_setFollowers(eUsuario* this, int followers);

int user_getFollowers(eUsuario* this, int* followers);

