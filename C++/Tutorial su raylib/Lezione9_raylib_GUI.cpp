#include <stdlib.h>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    InitWindow(800, 450, "Lezione 9 - UI e Raygui");
    SetTargetFPS(60);

    bool showBox = false;

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Pulsante GUI
            if (GuiButton((Rectangle){ 300, 200, 200, 40 }, "Cliccami!")) {
                showBox = true;
            }

            // Finestra di dialogo (messaggio popup)
            if (showBox) {
                int result = GuiMessageBox((Rectangle){ 250, 150, 300, 150 }, "Info", "Raygui Funzionante!", "OK");
                if (result >= 0) {
                    showBox = false; // Chiude la finestra al click di OK o sulla X
                }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}