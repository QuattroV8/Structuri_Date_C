#include "../StructuriDate/roles.h" // Legam cu headerul asociat acestuia 

Role* fetchRoles(FILE* rolesInput) // Preluam din fisier 
{
	if (rolesInput == NULL) // FISIER NEASOCIAT SAU INVALID 
		return NULL;  // RETURNAM NULL 

	// Daca nu 

	Role* roles = (Role*)malloc(sizeof(Role)); // Alocam un rol pe moment 

	char bufferLine[MAX_BUFFER_STRING_ROLES]; // Va Stoca liniile 

	unsigned i = 1;

	while (fgets(bufferLine,MAX_BUFFER_STRING_ROLES, rolesInput)) // Citim fiecare linie pana nu mai avem de citi
	{

		char* pieceOfLine, * nextPieceOfLine;

		pieceOfLine = strtok_s(bufferLine, DELIMITATER, &nextPieceOfLine); // Preluam ID-ul (PRIMA PARTE A LINII)

		roles[i - 1].id = atoi(pieceOfLine); // CONVERTIM LINIA IN intreg prin "atoi"

		pieceOfLine = strtok_s(NULL, DELIMITATER, &nextPieceOfLine); // Preluam NUMELE (PARTEA A DOUA A LINII)

		allocAndFetchString(&roles[i-1].nameRole,pieceOfLine);


		if (!feof(rolesInput)) // Verificam daca suntem la finalul fisierului 
		{
			roles[i - 1].isLastRole = 0; // Inca nu avem ultimul rol
			roles = realloc(roles, sizeof(Role) * (++i)); // Mai alocam spatiu pentru un rol
		}

		else
			//Daca da 
			roles[i - 1].isLastRole = 1; // Avem ultimul rol 
	}
	return roles;
}

void showRoles(Role* roles)
{
	unsigned i = 0;

	printf_s(" Colectia de Roluri : { \n");

	do {  // Parcurgem colectia de roluri 
		printf_s("ID ROL : %d \t NUME ROL : %s\n", roles[i].id, roles[i].nameRole);
		i++;
	} while (!roles[i-1].isLastRole);

	printf_s(" } \n\n");
}

void showRolesOnFile(Role* roles, FILE* rolesOuputText)
{
	// fprintf_s --> este functia care ne permite sa scriem in fisiere 

	if (!checkFile(rolesOuputText) || roles == NULL) // Avem un fisier invalid  
		return; // NU CONTINUAM 

	//Daca e ok 

	unsigned i = 0; 

	fprintf_s(rolesOuputText," Colectia de Roluri : { \n");

	do {  // Parcurgem colectia de roluri 
		fprintf_s(rolesOuputText,"ID ROL : %d \t NUME ROL : %s\n", roles[i].id, roles[i].nameRole);
		i++;
	} while (!roles[i - 1].isLastRole);

	fprintf_s(rolesOuputText," } \n\n");
}

void writeRolesOnBinaryData(Role* roles, FILE* rolesOutputBinary)
{
	if (!checkFile(rolesOutputBinary) || roles == NULL) // FACEM O VALIDARE ATAT FISIERULUI CAT SI STRUCTURII 
		return;  // NU CONTINUAM 

	// Daca e ok , transcriem structura in fisier : 

	// fwrite() --> este functia pentru scrierea entitatilor in binar
	// 
	unsigned i = 0; 

	do {  // Parcurgem colectia de roluri 
		fwrite(&roles[i].id,sizeof(int),1,rolesOutputBinary); // Trecem in binar id-ul 
		fwrite(roles[i].nameRole,sizeof(char),strlen(roles[i].nameRole), rolesOutputBinary); // Trecem numele rolului in binar 
		i++;
	} while (!roles[i - 1].isLastRole);
	

}


void freeRoles(Role** roles)
{
	unsigned i = 0;
	do   // Parcurgem fiecare Rol 
	{
		free((*roles)[i].nameRole); // Si eliberam memoria alocata de numele rolului 
		i++;
	} while (!(*roles)[i - 1].isLastRole);

	free(*roles);  // Eliberam colectia 
	*roles = NULL;
}
