#include "Lists.h" // Includem Headerul 

void insertAtHead(Linked_List** head,void* data,size_t sizeData)
{

	//// 1. ADAUGAM INFORMATIA CATRE NOD 

	// Alocam un bloc nou de memorie pentru segmentul pe care l introducem 

	Linked_List* newNode = (Linked_List*)malloc(sizeof(Linked_List));

	// Inseram date in bloc 

	newNode->Data = malloc(sizeData); // Alocam spatiu pentru informatie 
	memcpy_s(newNode->Data,sizeData,data,sizeData); // Transferam informatia spre blocul nou

	/// 2. CONSTRUIM LEGATURA CU URMATORUL NOD 

	newNode->nextElement = *head;  // URMATORUL NOD VA FI CAPUL CURENT (PRIMUL ELEMENT )
	*head = newNode;  // NOUL NOD VA FI CAPUL 
	
}

	void insertAtEnd(Linked_List** head, void* data, size_t sizeData)
	{
	//// 1. ADAUGAM INFORMATIA CATRE NOD 

	// Alocam un bloc nou de memorie pentru segmentul pe care l introducem 

	Linked_List* newNode = (Linked_List*)malloc(sizeof(Linked_List));

	// Inseram date in bloc 

	newNode->Data = malloc(sizeData); // Alocam spatiu pentru informatie 
	memcpy_s(newNode->Data, sizeData, data, sizeData); // Transferam informatia spre blocul nou

	// INFORMATIA SE ADAUGA LA FEL DOAR DIFERA LEGATURILE 

	newNode->nextElement = NULL; // Setam ca nodul construit sa fie ultimul element 

	if (*head == NULL) // Daca nu avem elemente in lista 
		*head = newNode; // NODUL VA DEVENI CAPUL LISTEI 

	// DACA NU 

	else
	{
		// ALTFEL VOM PARCURGE LISTA PANA LA FINAL 

		Linked_List* lastNode = *head;  

		while (lastNode->nextElement != NULL) // Parcurgem pana la ultimul element 
			lastNode = lastNode->nextElement; // Parcurgem nod cu nod (sau segment) 

		lastNode->nextElement = newNode; // Urmatorul element al ultimului nod va fi cel construit aici 
	}

}

void printLinkedList(Linked_List* head,void(*printDataGeneric)(void*))
{
	while (head != NULL)  // NAVIGAM PANA NU MAI EXISTA ELEMENTE 
	{
		(*printDataGeneric)(head->Data); // Printam INFORMATIA DIN NOD ADAPTATA LA TIPUL DE DATE PE CARE L VREM NOI
		head = head->nextElement; // NAVIGAM LA URMATORUL ELEMENT 
	}
}

void freeLinkedList(Linked_List** head, void(*deleteDataGeneric)(void*))
{
	// Preluam nodul actual sa l putem sterge 

	Linked_List* nodeToBeDeleted = head;  // Stergerea se face de la primul spre ultimul 

	while (*head != NULL) //navigam PANA la capat 
	{
		nodeToBeDeleted = *head; // Preluam referinta capului 
		*head = (*head)->nextElement; // Mutam capul la urmatorul element 

		//// Stergem informatia din nodul actual 

		(*deleteDataGeneric)(nodeToBeDeleted->Data);  // Stergem Generic 

		free(nodeToBeDeleted->Data); // Stergem blocul de memorie ocupata de informatie 
		free(nodeToBeDeleted); // Stergem nodul in sine 
	}

	*head = NULL; // SETAM LISTA PE NULL 
}
