#include "raylib.h"
#include <vector>
#include <cstdlib> // Per rand()

struct Player {
    Vector2 position;
    Vector2 speed;
    bool canJump;
    float size;
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Lezione 15 - Piattaforme Infinite");

    // Inizializzazione Giocatore
    Player player = { 0 };
    player.position = (Vector2){ 100, 200 };
    player.speed = (Vector2){ 200, 0 }; // Avanzamento automatico verso destra
    player.canJump = false;
    player.size = 30.0f;

    float gravity = 800.0f;
    float jumpSpeed = -350.0f;

    // Vettore per gestire le piattaforme in modo dinamico
    std::vector<Rectangle> platforms;

    // Piattaforma iniziale di partenza
    platforms.push_back((Rectangle){ 50, 300, 200, 20 });

    // Tracciamo la X dell'ultima piattaforma generata
    float lastPlatformX = 50.0f;

    // Configurazione Camera2D
    Camera2D camera = { 0 };
    camera.offset = (Vector2){ screenWidth / 4.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    bool gameOver = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        if (!gameOver) {
            // -----------------------------------------------------------------
            // 1. MOVIMENTO E FISICA GIOCATORE
            // -----------------------------------------------------------------
            player.position.x += player.speed.x * deltaTime; // Corre verso destra
            player.speed.y += gravity * deltaTime;           // Gravità
            player.position.y += player.speed.y * deltaTime;

            // Salto
            if (IsKeyPressed(KEY_SPACE) && player.canJump) {
                player.speed.y = jumpSpeed;
                player.canJump = false;
            }

            // -----------------------------------------------------------------
            // 2. GENERAZIONE INFINITA DELLE PIATTAFORME
            // -----------------------------------------------------------------
            // Genera nuove piattaforme se l'ultima è vicina al bordo destro visibile
            float rightEdge = camera.target.x + screenWidth;

            while (lastPlatformX < rightEdge + 300) {
                // Distanza casuale tra la piattaforma corrente e la successiva
                float gap = (float)(rand() % 120 + 80);   // Distanza X (80 - 200 px)
                float width = (float)(rand() % 100 + 80);  // Larghezza piattaforma (80 - 180 px)
                float heightY = (float)(rand() % 150 + 200); // Altezza Y (200 - 350 px)

                lastPlatformX += gap + width;
                platforms.push_back((Rectangle){ lastPlatformX, heightY, width, 20 });
            }

            // -----------------------------------------------------------------
            // 3. ELIMINAZIONE PIATTAFORME VECCHIE (CLEANUP)
            // -----------------------------------------------------------------
            // Rimuove le piattaforme completamente uscite a sinistra dello schermo
            float leftEdge = camera.target.x - (screenWidth / 2.0f);

            for (auto it = platforms.begin(); it != platforms.end(); ) {
                if (it->x + it->width < leftEdge) {
                    it = platforms.erase(it); // Elimina elemento e aggiorna l'iteratore
                } else {
                    ++it;
                }
            }

            // -----------------------------------------------------------------
            // 4. GESTIONE COLLISIONI
            // -----------------------------------------------------------------
            player.canJump = false;
            Rectangle playerBox = { player.position.x - player.size/2, player.position.y - player.size, player.size, player.size };

            for (const auto& platform : platforms) {
                if (CheckCollisionRecs(playerBox, platform)) {
                    // Controlla se il giocatore sta cadendo dall'alto sulla piattaforma
                    if (player.speed.y > 0 && (player.position.y - player.speed.y * deltaTime) <= platform.y) {
                        player.speed.y = 0;
                        player.position.y = platform.y;
                        player.canJump = true;
                    }
                }
            }

            // -----------------------------------------------------------------
            // 5. CONDIZIONE DI GAME OVER
            // -----------------------------------------------------------------
            // Se il giocatore cade sotto il margine dello schermo
            if (player.position.y > screenHeight + 200) {
                gameOver = true;
            }

            // Aggiorna la posizione della camera per seguire il giocatore
            camera.target = player.position;

        } else {
            // Riavvio del gioco con R
            if (IsKeyPressed(KEY_R)) {
                player.position = (Vector2){ 100, 200 };
                player.speed = (Vector2){ 200, 0 };
                platforms.clear();
                platforms.push_back((Rectangle){ 50, 300, 200, 20 });
                lastPlatformX = 50.0f;
                gameOver = false;
            }
        }

        // ---------------------------------------------------------------------
        // DISEGNO
        // ---------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

                // Disegna le piattaforme attive
                for (const auto& platform : platforms) {
                    DrawRectangleRec(platform, DARKGRAY);
                }

                // Disegna il giocatore
                DrawRectangle(player.position.x - player.size/2, player.position.y - player.size, player.size, player.size, RED);

            EndMode2D();

            // UI / HUD (Testo fisso a schermo)
            DrawText(TextFormat("Piattaforme attive in memoria: %i", (int)platforms.size()), 10, 10, 20, DARKBLUE);
            DrawText(TextFormat("Punteggio (Distanza): %i m", (int)player.position.x / 10), 10, 35, 20, GREEN);

            if (gameOver) {
                DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.8f));
                DrawText("GAME OVER", screenWidth/2 - MeasureText("GAME OVER", 40)/2, 150, 40, RED);
                DrawText("Premere [R] per Ricominciare", screenWidth/2 - MeasureText("Premere [R] per Ricominciare", 20)/2, 230, 20, WHITE);
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}