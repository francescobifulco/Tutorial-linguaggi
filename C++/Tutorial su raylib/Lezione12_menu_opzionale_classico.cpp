#include <stdlib.h>
#include <raylib.h>

#ifndef TextToFloat
#define TextToFloat(text) ((float)atof(text))
#endif

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// Definizione degli stati di gioco
typedef enum GameState {
    STATE_MENU,
    STATE_OPTIONS,
    STATE_GAMEPLAY
} GameState;

int main() {
    InitWindow(800, 450, "Lezione 12 - Menu Opzioni Classico - Raylib");
    InitAudioDevice();
    SetTargetFPS(60);

    GameState currentState = STATE_MENU;

    // --- VARIABILI DELLE IMPOSTAZIONI ---
    float musicVolume = 0.5f;       // Volume da 0.0 a 1.0
    bool isFullscreen = false;      // Stato schermo intero
    int selectedResolution = 0;     // Indice risoluzione selezionata
    bool dropdownEditMode = false;  // Stato del menu a tendina

    while (!WindowShouldClose()) {
        
        // --- LOGICA E AGGIORNAMENTO ---
        if (currentState == STATE_OPTIONS) {
            // Applica il volume in tempo reale
            SetMasterVolume(musicVolume);

            // Gestione Schermo Intero
            if (IsWindowState(FLAG_FULLSCREEN_MODE) != isFullscreen) {
                ToggleFullscreen();
            }
        }

        // --- RENDERING ---
        BeginDrawing();
            ClearBackground(RAYWHITE);

            switch (currentState) {

                // 1. SCHERMATA MENU PRINCIPALE
                case STATE_MENU:
                    DrawText("NOME DEL GIOCO", 280, 80, 30, DARKBLUE);

                    if (GuiButton((Rectangle){ 300, 160, 200, 40 }, "GIOCA")) {
                        currentState = STATE_GAMEPLAY;
                    }
                    if (GuiButton((Rectangle){ 300, 220, 200, 40 }, "OPZIONI")) {
                        currentState = STATE_OPTIONS;
                    }
                    if (GuiButton((Rectangle){ 300, 280, 200, 40 }, "ESCI")) {
                        CloseAudioDevice();
                        CloseWindow();
                        return 0;
                    }
                    break;

                // 2. SCHERMATA OPZIONI
                case STATE_OPTIONS:
                    DrawText("IMPOSTAZIONI", 310, 50, 28, DARKGRAY);

                    // --- Regolazione Volume Audio ---
                    DrawText("Volume Musica:", 200, 130, 20, BLACK);
                    GuiSlider((Rectangle){ 360, 130, 200, 20 }, "0%", "100%", &musicVolume, 0.0f, 1.0f);

                    // --- Controllo Schermo Intero ---
                    DrawText("Schermo Intero:", 200, 180, 20, BLACK);
                    GuiCheckBox((Rectangle){ 360, 180, 20, 20 }, "", &isFullscreen);

                    // --- Selezione Risoluzione ---
                    DrawText("Risoluzione:", 200, 230, 20, BLACK);
                    if (GuiDropdownBox((Rectangle){ 360, 230, 200, 30 }, "800x450;1280x720;1920x1080", &selectedResolution, dropdownEditMode)) {
                        dropdownEditMode = !dropdownEditMode;
                    }

                    // --- Pulsante Indietro ---
                    if (!dropdownEditMode) {
                        if (GuiButton((Rectangle){ 300, 340, 200, 40 }, "< INDIETRO")) {
                            currentState = STATE_MENU;
                        }
                    }
                    break;

                // 3. SCHERMATA DI GIOCO
                case STATE_GAMEPLAY:
                    DrawText("IN GIOCO!", 350, 200, 30, GREEN);
                    DrawText("Premi ESC per tornare al menu", 250, 250, 20, GRAY);
                    
                    if (IsKeyPressed(KEY_ESCAPE)) {
                        currentState = STATE_MENU;
                    }
                    break;
            }

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}