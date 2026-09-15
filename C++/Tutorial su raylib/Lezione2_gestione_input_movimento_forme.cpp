#include <raylib.h>

int main() {
    InitWindow(800, 450, "Lezione 2 - Input e Movimento");
    SetTargetFPS(60);

    Vector2 playerPos = { 400, 225 };
    float speed = 5.0f;

    while (!WindowShouldClose()) {
        // Input da tastiera
        if (IsKeyDown(KEY_RIGHT)) playerPos.x += speed;
        if (IsKeyDown(KEY_LEFT))  playerPos.x -= speed;
        if (IsKeyDown(KEY_UP))    playerPos.y -= speed;
        if (IsKeyDown(KEY_DOWN))  playerPos.y += speed;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(playerPos, 25, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}