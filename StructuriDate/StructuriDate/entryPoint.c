/* Legam toate entry point toate headerele dependente */
#include "../StructuriDate/roles.h" 
#include "../StructuriDate/fileHandling.h"
#include "../StructuriDate/User.h"
#include "../StructuriDate//Lists.h"

// stringHandling.h nu este dependent de entry point
// 

// CONSTANTELE MACRO SUNT UTILE CA LE PUTEM UTILIZA LA NIVEL GLOBAL (PE TOT FISIERUL)
// NOTA** :  E O PRACTICA BUNA DE A FOLOSI MACRO SPRE DEOSEBIRE DE CONSTANTE "MAGICE" (NUMERE PRIN COD)

#define NR_FILES   2  // STABILIM UN NUMAR DE FISIERE


int main()
{
	FILE** file = NULL; 

	file = (FILE**)malloc(sizeof(FILE*)*NR_FILES); // DECLARAM O COLECTIE DE FISIERE 

	file[0] = openFile(FILENAME_INPUT_ROLES, READMODE_TXT); // CITIM ROLURILE DINTR-UN FISIER TEXT 
	file[1] = openFile(FILENAME_USER_INPUT, READMODE_TXT); // CITIM UTILIZATORI DINTR-UN FISIER TEXT 

	// dateIntrareLeagueCS.txt && dateIntrareRoluriLeagueCS.txt TREBUIE SA EXISTE IN DIRECTOR (ALTFEL VA ESUA)

	Role* roles = fetchRoles(file[0]); // Am primit lista cu rolurile 

	User* users = fetchUsersFromTxtFile(file[1],roles); // Am primit informatia despre utilizatori 

	Linked_List* list = NULL; // Declaram lista nula 

	for (int i = 0; i < 3; i++) // Primii 3 ii inseram de la cap 
		insertAtHead(&list, users + i, sizeof(users[i])); // inseram al doilea element al listei ca cap al listei (1)

	for (int i = 3; i < 6; i++) // Ceilalti de la coada 
		insertAtEnd(&list, users + i, sizeof(users[i])); // inseram al doilea element al listei ca cap al listei (1)

	printLinkedList(list, printUser);

	// ELIBERAM RESURSELE 
	freeLinkedList(&list, freeUser); // Eliberam Nodurile + Lista va fi NULA
	freeRoles(&roles); // Eliberam resursele ocupate de entitate 
	free(users); // Stergem colectia
	closeFiles(&file,NR_FILES); // Eliberam resursele ocupate de fisiere 

	if (file == NULL)
		printf("COLECTIA DE FISIERE A FOST ELIBERATA CU SUCCES !! ");


	return 0;
}