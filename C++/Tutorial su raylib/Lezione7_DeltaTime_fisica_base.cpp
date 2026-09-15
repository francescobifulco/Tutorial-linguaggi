#include <raylib.h>

int main() {
    InitWindow(800, 450, "Lezione 7 - Delta Time e Gravita'");
    SetTargetFPS(60);

    Vector2 position = { 400, 100 };
    float velocityY = 0.0f;
    const float gravity = 980.0f; // Pixel / s^2
    const float jumpForce = -400.0f;
    bool isGrounded = false;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime(); // Tempo del frame in secondi

        // Applicazione della gravità
        velocityY += gravity * deltaTime;
        position.y += velocityY * deltaTime;

        // Collisione con il pavimento (y = 350)
        if (position.y >= 350) {
            position.y = 350;
            velocityY = 0;
            isGrounded = true;
        }

        // Salto
        if (IsKeyPressed(KEY_SPACE) && isGrounded) {
            velocityY = jumpForce;
            isGrounded = false;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(0, 370, 800, 370, GRAY); // Pavimento
            DrawCircleV(position, 20, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}