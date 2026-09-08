#pragma once            // Evita che questo file venga incluso più di una volta durante la compilazione
#include <vector>       // Include la libreria standard C++ per i vettori dinamici
#include <raylib.h>     // Include Raylib per poter usare il tipo di dato 'Color'

class Grid
{
    public:
    Grid();             // Costruttore: inizializza le variabili principali della griglia
    void Initialize();  // Pulisce la griglia impostando tutte le celle a 0
    void Print();       // Stampa i valori della matrice sulla console
    void Draw();        // Disegna le celle della griglia a schermo con i relativi colori
    
    int grid[20][10];   // Matrice bidimensionale di 20 righe per 10 colonne (rappresenta il campo)

    private:
    std::vector<Color> GetCellColors(); // Metodo privato che restituisce la lista dei colori
    
    int numRows;        // Numero totale di righe (20)
    int numCols;        // Numero totale di colonne (10)
    int cellSize;       // Dimensione in pixel di ogni singola cella (30px)
    
    std::vector<Color> colors; // Vettore contenente i colori associati ai valori dei blocchi
};