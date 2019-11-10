#ifndef ERRORFILE
#define ERRORFILE

#include "supervisor.h"

#define WRONG_PARAMETER_ERROR_MESSAGE "Le parametre offert est invalide. \nVeuillez presenter vos parametres sous la forme {nom -> valeur}.\nLa donnee n'a pas ete prise en compte."

void easy_error_with_message(char * error_message);

#endif