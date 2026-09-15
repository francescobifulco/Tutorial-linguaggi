#include <raylib.h>

int main() {
    InitWindow(800, 450, "Lezione 3 - Collisioni");
    SetTargetFPS(60);

    Rectangle player = { 100, 100, 50, 50 };
    Rectangle obstacle = { 300, 150, 200, 100 };

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) player.x += 4;
        if (IsKeyDown(KEY_LEFT))  player.x -= 4;
        if (IsKeyDown(KEY_UP))    player.y -= 4;
        if (IsKeyDown(KEY_DOWN))  player.y += 4;

        // Controllo collisione AABB vs AABB
        bool collision = CheckCollisionRecs(player, obstacle);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawRectangleRec(obstacle, GRAY);
            // Se c'è collisione il giocatore diventa rosso, altrimenti blu
            DrawRectangleRec(player, collision ? RED : BLUE);
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}