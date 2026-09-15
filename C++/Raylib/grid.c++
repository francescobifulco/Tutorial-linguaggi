#include "grid.h"     // Include la dichiarazione della classe Grid
#include <iostream>   // Include la libreria per l'input/output (usata da std::cout)
#include "colors.h"

// Costruttore della classe Grid
Grid::Grid(){
    numRows = 20;     // Imposta le righe della griglia a 20
    numCols = 10;     // Imposta le colonne della griglia a 10
    cellSize = 30;    // Imposta la dimensione di ogni blocco a 30x30 pixel
    
    Initialize();     // Chiama il metodo per riempire la griglia di zeri
    colors = GetCellColors(); // Inizializza il vettore dei colori con la tavolozza definita
}

// Inizializza la matrice impostando ogni cella a 0 (cella vuota)
void Grid::Initialize(){
    for(int row = 0; row < numRows; row++){            // Cicla attraverso ogni riga
        for(int column = 0; column < numCols; column++){ // Cicla attraverso ogni colonna
            grid[row][column] = 0;                     // Imposta la cella corrente a 0
        }
    }
}

// Stampa la matrice numerica sulla console per verificare lo stato della griglia
void Grid::Print(){
    for(int row = 0; row < numRows; row++){            // Scorri tutte le righe
        for(int column = 0; column < numCols; column++){ // Scorri tutte le colonne
            std::cout << grid[row][column] << " ";     // Stampa il valore seguito da uno spazio
        }
        std::cout << std::endl;                        // Va a capo alla fine di ogni riga
    }
}

// Disegna la griglia di gioco nella finestra tramite le funzioni di Raylib
void Grid::Draw(){
    for(int row = 0; row < numRows; row++){            // Scorri le righe
        for(int column = 0; column < numCols; column++){ // Scorri le colonne
            
            // Prende il valore numerico (id del colore) presente nella cella attuale
            int cellValue = grid[row][column];
            
            // Disegna un rettangolo pixel per pixel:
            // Posizione X = colonna * 30, Posizione Y = riga * 30
            // Larghezza = 30, Altezza = 30, Colore preso dal vettore 'colors'
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}