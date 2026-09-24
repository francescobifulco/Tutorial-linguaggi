#include <stdlib.h>
#include <raylib.h>

#ifndef TextToFloat
#define TextToFloat(text) ((float)atof(text))
#endif

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// Stati della Macchina a Stati
typedef enum GameState {
    STATE_MENU,
    STATE_GAMEPLAY,
    STATE_GAMEOVER
} GameState;

// Struttura del Giocatore
struct Player {
    Rectangle rect;
    float speed;
    Color color;

    // Metodo per resettare le posizioni iniziali
    void Reset() {
        rect = (Rectangle){ 100, 200, 40, 40 };
    }
};

int main() {
    InitWindow(800, 450, "Lezione 13 - Gestione Game Over");
    SetTargetFPS(60);

    GameState currentState = STATE_MENU;

    // Inizializzazione Giocatore ed Ostacolo Letale
    Player player;
    player.Reset();
    player.speed = 5.0f;
    player.color = BLUE;

    Rectangle obstacle = { 400, 150, 80, 150 }; // Ostacolo rosso pericoloso

    while (!WindowShouldClose()) {

        // --- LOGICA E AGGIORNAMENTO ---
        switch (currentState) {

            case STATE_MENU:
                // Nessun aggiornamento necessario nel menu
                break;

            case STATE_GAMEPLAY:
                // 1. Movimento del Giocatore
                if (IsKeyDown(KEY_RIGHT)) player.rect.x += player.speed;
                if (IsKeyDown(KEY_LEFT))  player.rect.x -= player.speed;
                if (IsKeyDown(KEY_UP))    player.rect.y -= player.speed;
                if (IsKeyDown(KEY_DOWN))  player.rect.y += player.speed;

                // 2. Controllo Collisione Letale
                if (CheckCollisionRecs(player.rect, obstacle)) {
                    currentState = STATE_GAMEOVER; // Transizione immediata a Game Over
                }
                break;

            case STATE_GAMEOVER:
                // Se premi INVIO, resetti il gioco e torni al Menu
                if (IsKeyPressed(KEY_ENTER)) {
                    player.Reset(); // FONDAMENTALE: Ripristina la posizione iniziale
                    currentState = STATE_MENU;
                }
                break;
        }

        // --- RENDERING ---
        BeginDrawing();
            ClearBackground(RAYWHITE);

            switch (currentState) {

                case STATE_MENU:
                    DrawText("SCHERMATA PRINCIPALE", 260, 120, 25, DARKBLUE);
                    DrawText("Tocca l'ostacolo rosso per andare in Game Over!", 180, 160, 18, GRAY);

                    if (GuiButton((Rectangle){ 300, 220, 200, 40 }, "INIZIA GIOCO")) {
                        player.Reset(); // Assicura che la posizione sia pulita all'avvio
                        currentState = STATE_GAMEPLAY;
                    }
                    break;

                case STATE_GAMEPLAY:
                    // Disegna l'ostacolo e il player
                    DrawRectangleRec(obstacle, RED);
                    DrawRectangleRec(player.rect, player.color);

                    DrawText("Usa le FRECCE per muoverti", 10, 10, 18, DARKGRAY);
                    DrawText("Evita l'ostacolo ROSSO!", 10, 35, 18, RED);
                    break;

                case STATE_GAMEOVER:
                    // Schermata Rossa di Sconfitta
                    ClearBackground(MAROON);
                    
                    DrawText("GAME OVER!", 290, 150, 40, WHITE);
                    DrawText("Hai toccato l'ostacolo!", 285, 210, 20, LIGHTGRAY);
                    DrawText("Premi [INVIO] per tornare al Menu", 230, 280, 20, YELLOW);
                    break;
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}