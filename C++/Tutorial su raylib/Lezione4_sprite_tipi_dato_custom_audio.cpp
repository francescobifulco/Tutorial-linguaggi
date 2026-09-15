#include <raylib.h>

struct Entity {
    Vector2 position;
    Texture2D texture;
    Sound soundEffect;

    void Draw() {
        DrawTextureV(texture, position, WHITE);
    }
};

int main() {
    InitWindow(800, 450, "Lezione 4 - Texture e Audio");
    InitAudioDevice(); // Obbligatorio prima di caricare audio!
    SetTargetFPS(60);

    // Caricamento risorse da disco
    Texture2D playerTex = LoadTexture("resources/player.png");
    Sound fxJump = LoadSound("resources/jump.wav");

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            PlaySound(fxJump); // Riproduce l'effetto sonoro
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(playerTex, 100, 100, WHITE);
        EndDrawing();
    }

    // Unload sempre obbligatorio per evitare memory leak
    UnloadTexture(playerTex);
    UnloadSound(fxJump);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}