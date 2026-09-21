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

    // Caricamento risorse ed entita'
    Entity player;
    player.position = (Vector2){ 100.0f, 100.0f };
    player.texture = LoadTexture("possabasse.jpg");
    player.soundEffect = LoadSound("Climbing_To_The_High_Score.mp3");

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            PlaySound(player.soundEffect); // Riproduce l'effetto sonoro
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            player.Draw(); // Disegna il personaggio a schermo
        EndDrawing();
    }

    // Unload sempre obbligatorio per evitare memory leak
    UnloadTexture(player.texture);
    UnloadSound(player.soundEffect);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}