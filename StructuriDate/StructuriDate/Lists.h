#pragma once

#include "stdlib.h" // malloc/free 
#include "string.h" // memcpy


typedef struct LinkedList{  // LISTA INLANTUITA GENERICA (O PUTEM FOLOSI CU ORICE TIP DE DATE FARA SA DECLARAM MAI MULTE STRUCTURI)
	void* Data;           // Pastram informatia pentru elementul curent 
    struct LinkedList* nextElement;// Ne corelam cu urmatorul element 
}Linked_List;


void insertAtHead(Linked_List** head, void* data, size_t sizeData); // Inseram de la inceputul listei (Transfer prin adresa , inseram date in lista)
void insertAtEnd(Linked_List** head, void* data, size_t sizeData); // Inseram la sfarsitul listei  


void printLinkedList(Linked_List* head, void(*printDataGeneric)(void*)); // Printam lista 

void freeLinkedList(Linked_List** head, void(*deleteDataGeneric)(void*)); // Eliberam Lista 