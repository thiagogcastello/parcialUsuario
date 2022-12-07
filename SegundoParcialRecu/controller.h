#include "usuario.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_cargarDesdeTexto(char* path , LinkedList* pArray);

int controller_cargarDesdeBinario(char* path , LinkedList* pArray);

void controller_mostrarUsuarios(LinkedList* list);

void controller_mostrarUsuario(eUsuario* p);

int controller_menuOpciones();

int controller_setTiempos(LinkedList* lista);

void* setTiempoRandom(void* pElement);

int subMenuFiltroGenero();

int controller_filtroGenero(LinkedList* lista);

int controller_setLikes(LinkedList* lista);

int controller_setDislikes(LinkedList* lista);

int controller_setFollowers(LinkedList* lista);

void* setFollowersRandom(void* pElement);

void* setDislikesRandom(void* pElement);

void* setLikesRandom(void* pElement);


#endif // CONTROLLER_H_INCLUDED
