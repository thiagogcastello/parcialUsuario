
#ifndef INPUT_H_
#define INPUT_H_


/***
 * @fn int esNumerica(char*)
 * @brief verifica si la cadena ingresada es numerica
 *
 * @param cadena cadena de caracteres a ser analizada
 * @return retorna 1 si la cadena es numerica o 0 si no lo es
 */
int esNumerica(char* cadena);

/***
 * @fn int utnGetNumero(int*, char*, char*, int, int, int)
 * @brief solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje mensaje a ser mostrado
 * @param mensajeError mensaje de errror a ser mostrado
 * @param minimo numero maximo a ser aceptado
 * @param maximo numero minimo a ser aceptado
 * @param reintentos numero de reintentos admitidos
 * @return retorna 0 si se obtuvo el numero y -1 si no
 */
int utnGetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);

/***
 * @fn int getNumeroShort(short*, char*, char*, short, short, int)
 * @brief solicita un numero (de tipo short) al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje mensaje a ser mostrado
 * @param mensajeError mensaje de error a ser mostrado
 * @param minimo numero maximo a ser aceptado
 * @param maximo numero minimo a ser aceptado
 * @param reintentos numero de reintentos admitidos
 * @return retorna 0 si se obtuvo el numero y -1 si no
 */
int getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, short minimo,short maximo,int reintentos);

/***
 * @fn int esFlotante(char*)
 * @brief verifica si la cadena ingresada es numerica y flotante
 *
 * @param cadena cadena de caracteres a ser analizada
 * @return retorna 1 si la cadena es numero y 0 si no lo es
 */
int esFlotante(char* cadena);

/***
 * @fn int getFloat(float*)
 * @brief verifica si la cadena ingresada es numerica
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return retorna 0 si se obtiene un numero entero y -1 si no
 */
int getFloat(float* pResultado);

/***
 * @fn int utnGetFloat(float*, char*, char*, float, float, int)
 * @brief solicita un numero al usuario, luego de verificarlo devuelve el resultado (flotante)
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje es el mensaje a ser mostrado
 * @param mensajeError es el mensaje de error a ser mostrado
 * @param minimo es el numero minimo a ser aceptado
 * @param maximo es el numero maximo a ser aceptado
 * @param reintentos es la cantidad de reingresos disponibles
 * @return retorna 0 si se obtuvo el numero y -1 si no
 */
int utnGetFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/***
 * @fn int pedirCadena(char[], int, char[])
 * @brief pide al usuario un texto por teclado y valida que no supere el largo permitido
 *
 * @param cadena a evaluar
 * @param largo largo del mensaje permitido
 * @param mensaje mensaje que se imprime para pedir datos
 * @return devuelve -1 si el largo de la cadena es incorrecto y 1 si es correcto
 */
int pedirCadena(char cadena[],int largo,char mensaje[]);

/***
 * @fn int pedirNombreYApellido(int, int, int, char*)
 * @brief funcion que pide nombre y apellido al usuario y los acomoda
 *
 * @param largo largo de la cadena total
 * @param largoNombre largo maximo del nombre
 * @param largoApellido largo maximo del apellido
 * @param nombreApellido puntero que concatena el nombre y el apellido
 * @return retorna 1 si sale todo bien y -1 si no puede concatenar
 */
int pedirNombreYApellido(int largo, int largoNombre, int largoApellido, char *nombreApellido);

/***
 * @fn int validarCadenaSoloLetras(char cadena[])
 * @brief funcion que pide nombre y apellido al usuario y los acomoda
 *
 * @param largo largo de la cadena total
 * @return retorna 1 si sale todo bien, 0 si encontro un caracter no alfabetico y -1 si hubo un problema con la cadena
 */
int validarCadenaSoloLetras(char cadena[]);


/** \brief int getCaracter(char* c, char mje[], char mjeError[])
 *
 * \param c puntero donde se escribira el caracter s o n
 * \param
 * \param
 * \return retorna 1 si sale todo bien, 0 si funciono de manera incorrecta
 *
 */

int getCaracterSN(char* c, char mje[], char mjeError[]);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int getCaracter(char* c, char mje[], char mjeError[]);

int getChars(char array[], int len, char * mensaje, char * mensajeError,int maximoReintentos);

int validarLetras(char cadena[]);

int getIntInText(char *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int validarRangoDeNumero(char * numeroIngresado, int minimo, int maximo);

int validarNumero(char * cadena);

#endif /* INPUT_H_ */
