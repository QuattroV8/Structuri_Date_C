#include "../StructuriDate/fileHandling.h"

FILE* openFile(const char* nameFile, const char* readMode) // Aplicam modificari catre pointer
{

	FILE* file = NULL;

	errno_t errFileOpen = fopen_s(&file, nameFile, readMode); // Deschidem fisierul in functie de parametrii ceruti

	if (errFileOpen) // DACA A INTAMPINAT O EROARE 
		printf("Error : %d \n", errFileOpen);

	else // DACA TOTUL E IN REGULA 
		printf("**FISIERUL %s S-A DESCHIS CU SUCCES !**\n", nameFile);

	return file;
}

int checkFile(FILE* file)
{
	return file ? 1 : 0; // VERIFICAM DACA FISIERUL EXISTA IN MEMORIE 
}

void closeFiles(FILE*** files,const unsigned nrFiles) // Eliberam colectia de fisiere 
{
	for (int i = 0; i < nrFiles; i++)
		fclose((*files)[i]); // Eliberam fiecare fisier 

	// Eliberam colectia de fisiere 

	free(*files);
	*files = NULL;
}



