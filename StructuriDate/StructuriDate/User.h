#pragma once

#include "roles.h" // Pentru Roluri 

#define FILENAME_USER_INPUT "dateIntrareUtilizatoriLeagueCS.txt" 

typedef struct User
{
	// INFORMATIE UTILIZATOR 
     unsigned id;
	 char* username;
	 char* email;
	 char* password;
	 unsigned nrPosts;
	 unsigned isBanned; // NU AVEM VALOARE BOOLEANA IN C (bool)
	 Role* roles; // Colectie de grupuri din care face parte utilizatorul 
}User;


User* fetchUsersFromTxtFile(FILE* inputTxt,Role* roles);

void printUser(User user);

void freeUser(User user);




