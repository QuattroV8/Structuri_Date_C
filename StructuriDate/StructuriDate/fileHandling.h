#pragma once

#include "stdio.h" // pentru operatiuni cu fisiere 
#include "stdlib.h" // pentru malloc/free 

#define  READMODE_TXT     "r"  // CONSTANTA CITIRE DIN FISIERE TEXT EXISTENTE IN DIRECTOR 
#define  WRITEMODE_TXT    "w" // CONSTANTA SCRIERE IN FISIERE TEXT (IN)EXISTENTE IN DIRECTOR 
#define  WRITEMODE_BINARY "wb" // CONSTANTA SCRIERE IN FISIERE BINARE (IN)EXISTENTE IN DIRECTOR 


/*
	* Primul parametru "file" va fi asociat cu fisierul pe care l deschidem
	* Al doilea parametru , e numele fisierului
	* Al treila parametru , e modalitatea de citire&scriere (SUNT 12 MODALITATI DE CITIRE/SCRIERE)
	* "w" --> citim fisiere text (EXISTA DEJA --> IL VA SUPRASCRIE && DACA NU --> IL VA CONSTRUI AUTOMAT) ;
	* "r" --> citim fisiere text (DACA NU EXISTA --> VA RETURNA EROARE) ;
	* "a" --> adaugare informatie fisier text (EXISTA DEJA --> IL VA SUPRASCRIE && DACA NU --> IL VA CONSTRUI AUTOMAT) ;
	* "wb" --> scriem in fisiere binare (idem "w") ;
	* "rb" --> citim in fisiere binare (idem "r") ;
	* "ab" --> citim in fisiere binare (idem "a") ;
	* "w+" --> citim & scriem in fisiere text (idem "w") ;
	* "r+" --> citim & scriem in fisiere text (idem "r") ;
	* "a+" --> citim & scriem & modificam in fisiere text (idem "a") ;
	* "wb+" --> citim & scriem in fisiere binare (idem "w");
	* "rb+" --> citim & scriem in fisiere binare (idem "r") ;
	* "ab+" --> citit & scriem & modificam in fisiere binare (idem "a");
	*
	 */


// Functie care returneaza un fisier la care se asociaza numele acestuia 
// cat si modalitatea de citire/scriere  
FILE* openFile(const char* nameFile, const char* readMode); 
int checkFile(FILE* file);
void closeFiles(FILE*** files, const unsigned nrFiles);