#pragma once

#include "string.h"
#include "stdlib.h"

// FUNCTII & CONSTANTE PENTRU MANIPULAREA SIRURILOR DE CARACTERE

// MACROS


#define STRING_LENGHT(string) (strlen(string)+1) // NE DETERMINA LUNGIMEA SIRULUI DE CARACTERE + 1 (NULL CARACTER) 
#define MAX_STRING_LINE 256 // Alocam maxim 256 de caractere pentru linii 


void allocAndFetchString(char** target, char* source);