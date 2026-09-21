#include <raylib.h>

int main() {
    // 1. Inizializzazione della finestra
    InitWindow(800, 450, "Lezione 1 - Hello Raylib");
    SetTargetFPS(60); // Blocca il rendering a 60 FPS

    // 2. Ciclo di gioco principale
    while (!WindowShouldClose()) {
        // --- AGGIORNAMENTO LOGICA ---
        // (es. calcolo posizioni, fisica)

        // --- RENDERING / DISEGNO ---
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Benvenuto in Raylib!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    // 3. De-allocazione risorse
    CloseWindow();
    return 0;
}