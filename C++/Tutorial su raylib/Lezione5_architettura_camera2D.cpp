#include <raylib.h>

int main() {
    InitWindow(800, 450, "Lezione 5 - Camera2D e Viewport");
    SetTargetFPS(60);

    Vector2 playerPos = { 400, 225 };

    // Configurazione della telecamera
    Camera2D camera = { 0 };
    camera.target = playerPos;
    camera.offset = (Vector2){ 400.0f, 225.0f }; // Centra il player sullo schermo
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose()) {
        // Movimento
        if (IsKeyDown(KEY_RIGHT)) playerPos.x += 4;
        if (IsKeyDown(KEY_LEFT))  playerPos.x -= 4;

        // La telecamera segue il player
        camera.target = playerPos;

        // Zoom dinamico con la rotellina del mouse
        camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

        BeginDrawing();
            ClearBackground(DARKGRAY);

            // Inizio rendering nello spazio di mondo (coordinate della telecamera)
            BeginMode2D(camera);

                // Disegna oggetti del mondo
                DrawRectangle(-500, -500, 1000, 1000, LIGHTGRAY); // Terreno
                DrawCircleV(playerPos, 20, RED);

            EndMode2D(); // Fine rendering mondo

            // Disegno dell'Interfaccia Utente (HUD) in coordinate schermo fisse
            DrawText("HUD: Schermo Fisso", 10, 10, 20, YELLOW);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}