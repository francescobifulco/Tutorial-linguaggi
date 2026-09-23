#include <raylib.h>

struct Entity {
    Vector2 position;
    Texture2D texture;

    void Draw() {
        DrawTextureV(texture, position, WHITE);
    }
};

int main() {
    InitWindow(800, 450, "Lezione 11 - Musica di Sottofondo");
    InitAudioDevice(); // Obbligatorio per qualsiasi audio in Raylib
    SetTargetFPS(60);

    // Caricamento entità e immagine
    Entity player;
    player.position = (Vector2){ 100.0f, 100.0f };
    player.texture = LoadTexture("Gemini_Generated_Image_c76wxac76wxac76w.jpg");

    // Caricamento della traccia musicale (Music invece di Sound per tracce lunghe)
    Music backgroundMusic = LoadMusicStream("Climbing_To_The_High_Score.mp3");

    // Fai partire la musica SUBITO prima del ciclo principale
    PlayMusicStream(backgroundMusic);

    while (!WindowShouldClose()) {
        // FONDAMENTALE: Mantiene il flusso audio attivo a ogni frame
        UpdateMusicStream(backgroundMusic);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            player.Draw();
        EndDrawing();
    }

    // Unload delle risorse
    UnloadTexture(player.texture);
    UnloadMusicStream(backgroundMusic); // Scarica la traccia musicale
    CloseAudioDevice();
    CloseWindow();
    return 0;
}