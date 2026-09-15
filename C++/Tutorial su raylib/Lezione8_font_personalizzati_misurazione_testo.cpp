#include <raylib.h>

int main() {
    InitWindow(800, 450, "Lezione 8 - Font e Testo");
    SetTargetFPS(60);

    // Caricamento font custom
    Font customFont = LoadFontEx("resources/font.ttf", 32, 0, 250);

    const char* scoreText = "SCORE: 001500";
    float fontSize = 32.0f;
    float spacing = 2.0f;

    // Calcola la larghezza e altezza del testo in pixel
    Vector2 textSize = MeasureTextEx(customFont, scoreText, fontSize, spacing);

    while (!WindowShouldClose()) {
        // Posizionamento al centro dello schermo
        Vector2 textPosition = {
            (800 - textSize.x) / 2.0f,
            (450 - textSize.y) / 2.0f
        };

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTextEx(customFont, scoreText, textPosition, fontSize, spacing, GOLD);
        EndDrawing();
    }

    UnloadFont(customFont); // Unload obbligatorio
    CloseWindow();
    return 0;
}