#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "../StructuriDate/stringHandling.h"
#include "fileHandling.h"


// Definim constante necesare 

#define MAX_BUFFER_STRING_ROLES         30 // MAXIM BITI ALOCATI PENTRU ROLURI 
#define DELIMITATER                     "|"
#define FILENAME_INPUT_ROLES            "dateIntrareRoluriLeagueCS.txt"
#define FILENAME_OUTPUT_ROLES           "dateIesireRoluriLeagueCS.txt" 
#define FILENAME_OUTPUT_ROLES_BINARY    "dateIesireRoluriLeagueCS.bin"

// Definim Structura pentru fiecare rol 

typedef struct Roles {   // Definim articolul Roluri  cu doua campuri 
	unsigned id;
	char* nameRole;
	unsigned isLastRole; // Aflam daca este ultimul rol 
}Role; // Sub aceasta eticheta putem construi instante


// Definim functii pentru incarcarea , accesarea , modificarea si stergerea acestora . 

Role* fetchRoles(FILE* rolesInput); // Incarcam Rolurile in memorie  
void showRoles(Role* roles); // Afisam Rolurile 
void showRolesOnFile(Role* roles, FILE* rolesOuputText);
void writeRolesOnBinaryData(Role* roles, FILE* rolesOutputBinary);
void freeRoles(Role** roles); // Stergem rolurile din memorie




