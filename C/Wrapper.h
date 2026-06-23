#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <io.h>

// Definiamo le macro per la funzione _access (0 = esistenza)
#ifndef F_OK
#define F_OK 0
#endif

void creareFileNoEsiste();
void inserisciPrestito();
void inserisciRestituzione();
void stampaFile(char* filePath);
void printMenu();