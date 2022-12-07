#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


int parser_FromText(FILE* pFile , LinkedList* pArrayListJugador);

int parser_FromBinary(FILE* pFile , LinkedList* pArrayListJugador);

#endif // PARSER_H_INCLUDED
