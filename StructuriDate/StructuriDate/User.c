#include "User.h"

User* fetchUsersFromTxtFile(FILE* inputTxt, Role* roles)
{
	if (!checkFile(inputTxt))
		return NULL; // Fisier Invalid + Returnam o valoare NULA Colectiei  

	// Daca totul e ok 

	unsigned i = 1;
	char bufferLine[MAX_STRING_LINE];

	User* newUser = (User*)malloc(sizeof(User)); // Alocam pentru un utilizator (MOMENTAN) 
		
		// Noua Structura 

	while ((fgets(bufferLine, MAX_STRING_LINE, inputTxt)) != NULL)  // Citim Linie cu Linie din Fisier 
	{
	 
		char*Token, *nextToken; // Prima va retine informatia curenta iar cealalta referinta la cea mai ramas din linie 

		// Inseram Date
		
		/// ID 
		Token = strtok_s(bufferLine,DELIMITATER,&nextToken); // Preluam ID-ul din linie in format de STRING
		newUser[i-1].id = atoi(Token); // Convertim din string in intreg + Il Incarcam in Structura 

		// NUME 
		Token = strtok_s(NULL, DELIMITATER, &nextToken); // Preluam NUMELE din linie in format de STRING 
		allocAndFetchString(&newUser[i-1].username,Token); // Il Incarcam in Structura 


		// Adresa de Mail 
		Token = strtok_s(NULL, DELIMITATER, &nextToken); // Preluam EMAIL din linie in format de STRING 
		allocAndFetchString(&newUser[i-1].email, Token);  // Il Incarcam in Structura 

		// Parola
		Token = strtok_s(NULL, DELIMITATER, &nextToken); // Preluam EMAIL din linie in format de STRING 
		allocAndFetchString(&newUser[i-1].password, Token);  // Il Incarcam in Structura 

		// NrPosts 
		Token = strtok_s(NULL, DELIMITATER, &nextToken); // Preluam NUMARUL DE POSTURI DIN STRUCTURA 
		newUser[i-1].nrPosts = atoi(Token); // CONVERTIM DIN STRING IN INTREG SI IL INCARCAM 

		// e Banat 
		Token = strtok_s(NULL, DELIMITATER, &nextToken); // IDEM 
		newUser[i-1].isBanned = atoi(Token);

		// Grupurile din care face parte 

		unsigned j = 1; // (Accesul la itemul curent se va face la (j-1))

		while ((Token = strtok_s(NULL, DELIMITATER, &nextToken)) != NULL) // Preluam ID cu ID
		{
			unsigned targetIdRole, k = 0;
			targetIdRole = atoi(Token); // Convertim ID-ul din string in intreg 

			do {
				if (targetIdRole == roles[k].id) // DACA AM REGASIT ID-UL IN COLECTIE DE ROLURI 
				{
					newUser[i-1].roles = j == 1 ?
						(Role*)malloc(sizeof(Role)) // DACA SUNTEM LA PRIMA ITERATIE 
						: (Role*)realloc(newUser[i-1].roles, sizeof(Role) * j); // DACA SUNTEM LA J ITERATIE
					// Preluam Referintele (ODATA ELIBERATE ROLURILE SI ELE ISI VOR PIERDE INFORMATIA )
					newUser[i-1].roles[j-1].id = roles[k].id;
					newUser[i-1].roles[j-1].nameRole = roles[k].nameRole;
					newUser[i-1].roles[j-1].isLastRole = 0; // NU ESTE ULTIMUL ELEMENT DIN LISTA 
					break; // NU ARE ROST SA PARCURGEM TOATA STRUCTURA 
				}
				k++; // Incrementam cu un pas 
			} while(!roles[k-1].isLastRole); // Parcurgem toate rolurile PANA AJUNGEM LA ULTIMUL 
			j++;  // Marim colectia cu un element 
		}
		newUser[i-1].roles[j-2].isLastRole = 1; // ESTE ULTIMUL ELEMENT DIN LISTA 


		if (!feof(inputTxt))  // Daca mai sunt date in fisier 
			newUser = realloc(newUser, sizeof(User) * (++i)); // Mai alocam un utilizator 
	
	}

	return newUser;

}

void printUser(User user)
{
	static unsigned i = 0;  // Retinem i pe toate apelurile 
	printf_s("User %d : { \n",i);
	printf_s("\tID UTILIZATOR: %d ,\n",user.id);
	printf_s("\tNUME UTILIZATOR: %s ,\n",user.username);
	printf_s("\tADRESA MAIL UTILIZATOR: %s ,\n",user.email);
	printf_s("\tPAROLA : %s ,\n",user.password);
	printf_s("\tNUMAR POSTURI : %d ,\n", user.nrPosts);
	printf_s("\tESTE BANAT : %s ,\n", user.isBanned ? "DA" : "NU");
	printf_s("\t\tROLURI DETINUTE : {\n");
	unsigned j = 0;
	do {
		printf_s("\n\tID ROL : %d | NUME ROL :%s",user.roles[j].id,user.roles[j].nameRole);
		j++;
	} while(!user.roles[j-1].isLastRole);

	printf_s("\n}\n}");

	i++;
}

void freeUser(User user)
{
	//Stergem sirurile de caractere  
	free(user.username);
	free(user.email);
	free(user.password);
	
	// ROLURILE VOR FI STERSE SEPARATE in functia freeRoles() 
}
