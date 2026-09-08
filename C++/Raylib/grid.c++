#include "grid.h"     // Include la dichiarazione della classe Grid
#include <iostream>   // Include la libreria per l'input/output (usata da std::cout)

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

// Crea e restituisce un vettore contenente tutti i colori dei blocchi di Tetris
std::vector<Color> Grid::GetCellColors(){
    // Definiamo i colori RGBA personalizzati
    Color darkGrey = {26, 31, 40, 255};  // 0: Cella vuota (Sfondo griglia)
    Color green = {47, 230, 23, 255};    // 1: S-Piece
    Color red = {232, 18, 18, 255};      // 2: Z-Piece
    Color orange = {226, 116, 17, 255};  // 3: L-Piece
    Color yellow = {237, 234, 4, 255};   // 4: O-Piece
    Color purple = {166, 0, 247, 255};  // 5: T-Piece
    Color cyan = {21, 204, 209, 255};    // 6: I-Piece
    Color blue = {13, 64, 216, 255};     // 7: J-Piece

    // Restituisce l'elenco completo sotto forma di vettore
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
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
            DrawRectangle(column * cellSize, row * cellSize, cellSize, cellSize, colors[cellValue]);
        }
    }
}