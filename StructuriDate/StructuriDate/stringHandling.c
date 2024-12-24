#include "../StructuriDate/stringHandling.h" // Legam cu fisierul header asociat acestuia

void allocAndFetchString(char** target, char* source)
{
	size_t sizeTarget = STRING_LENGHT(source);
	*target = (char*)malloc(sizeTarget); // Alocam cu dimensiunea ajustata 
	strcpy_s(*target,sizeTarget, source); // Copiem informatia spre noul string 
}