#include <raylib.h>

typedef enum GameState { MENU, GAMEPLAY, GAMEOVER } GameState;

int main() {
    InitWindow(800, 450, "Lezione 6 - Game States");
    SetTargetFPS(60);

    GameState currentState = MENU;

    while (!WindowShouldClose()) {
        // --- AGGIORNAMENTO LOGICA IN BASE ALLO STATO ---
        switch (currentState) {
            case MENU:
                if (IsKeyPressed(KEY_ENTER)) currentState = GAMEPLAY;
                break;
            case GAMEPLAY:
                if (IsKeyPressed(KEY_P)) currentState = GAMEOVER;
                break;
            case GAMEOVER:
                if (IsKeyPressed(KEY_R)) currentState = MENU;
                break;
        }

        // --- RENDERING IN BASE ALLO STATO ---
        BeginDrawing();
            ClearBackground(RAYWHITE);

            switch (currentState) {
                case MENU:
                    DrawText("MENU PRINCIPALE - Premi INVIO per giocare", 150, 200, 20, DARKGRAY);
                    break;
                case GAMEPLAY:
                    DrawText("IN GIOCO - Premi 'P' per terminare", 220, 200, 20, BLUE);
                    break;
                case GAMEOVER:
                    DrawText("GAME OVER - Premi 'R' per ricominciare", 200, 200, 20, RED);
                    break;
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}