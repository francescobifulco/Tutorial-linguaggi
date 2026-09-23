#include <stdlib.h>
#include <raylib.h>

#ifndef TextToFloat
#define TextToFloat(text) ((float)atof(text))
#endif

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    InitWindow(800, 450, "Lezione 9 - UI e Raygui");
    SetTargetFPS(60);

    bool showBox = false;
    int activeBtn = -1;

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Pulsante GUI
            if (GuiButton((Rectangle){ 300, 200, 200, 40 }, "Cliccami!")) {
                showBox = true;
                activeBtn = -1;
            }

            // Finestra di dialogo (messaggio popup)
            if (showBox) {
                int result = GuiMessageBox((Rectangle){ 250, 150, 300, 150 }, "Info", "Raygui Funzionante!", "OK", &activeBtn);
                if (result >= 0) {
                    showBox = false; // Chiude la finestra al click di OK o sulla X
                }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}