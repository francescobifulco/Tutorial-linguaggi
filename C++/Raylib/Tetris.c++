#include <raylib.h> // Include la libreria grafica Raylib per gestire finestra e disegno
#include "grid.h" // Include la definizione della classe Grid

int main(){
    // 1. Inizializza la finestra di gioco (Larghezza: 300px, Altezza: 600px, Titolo)
    InitWindow(300, 600, "raylib Tetris");

    // Imposta il limite di fotogrammi al secondo a 60 FPS
    SetTargetFPS(60);

    // 2. Definisci un colore personalizzato in formato RGBA (Rosso, Verde, Blu, Opacità)
    Color darkBlue = {44, 44, 127, 255};

    // Crea un'istanza (oggetto) della classe Grid chiamata 'grid'
    Grid grid = Grid();

    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[17][8] = 7;

    // Stampa la matrice iniziale nella console per controllo (debug)
    grid.Print();

    // Ciclo di gioco principale: continua finché l'utente non chiude la finestra
    while (WindowShouldClose() == false){
        
        // Inizia la fase di rendering (disegno) del fotogramma
        BeginDrawing();
        
        // Pulisce lo schermo riempiendolo con il colore blu scuro
        ClearBackground(darkBlue);
        
        // Disegna la griglia di gioco sullo schermo
        grid.Draw();
        
        // Conclude la fase di rendering e mostra il fotogramma a schermo
        EndDrawing();
    }
    
    CloseWindow();
}