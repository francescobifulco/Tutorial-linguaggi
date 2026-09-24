#include <raylib.h>

struct Player {
    Rectangle rect;
    float speed;
    float speedY;
    bool isGrounded; // Indica se il giocatore sta toccando il terreno
};

int main() {
    InitWindow(800, 600, "Lezione Platform - Gravita e Salto");
    SetTargetFPS(60);

    // 1. Inizializzazione Giocatore
    Player player;
    player.rect = (Rectangle){ 100, 100, 40, 40 };
    player.speed = 5.0f;
    player.speedY = 0.0f;
    player.isGrounded = false;

    // Costanti Fisiche
    const float gravity = 0.6f;      // Forza di gravità
    const float jumpForce = -12.0f;   // Spinta verso l'alto (valore negativo)

    // 2. Definizione delle Piattaforme
    Rectangle platforms[] = {
        { 0, 500, 800, 100 },   // Terreno principale
        { 200, 400, 200, 20 },  // Piattaforma 1
        { 500, 300, 180, 20 }   // Piattaforma 2
    };
    int numPlatforms = sizeof(platforms) / sizeof(platforms[0]);

    while (!WindowShouldClose()) {

        // --- 1. INPUT ORIZZONTALE ---
        if (IsKeyDown(KEY_RIGHT)) player.rect.x += player.speed;
        if (IsKeyDown(KEY_LEFT))  player.rect.x -= player.speed;

        // --- 2. SALTO ---
        if (IsKeyPressed(KEY_SPACE) && player.isGrounded) {
            player.speedY = jumpForce;
            player.isGrounded = false; // Il giocatore non è più a terra
        }

        // --- 3. APPLICAZIONE GRAVITÀ ---
        player.speedY += gravity;
        player.rect.y += player.speedY;

        // Reset dello stato a terra prima del controllo collisioni
        player.isGrounded = false;

        // --- 4. GESTIONE COLLISIONI CON LE PIATTAFORME ---
        for (int i = 0; i < numPlatforms; i++) {
            // Controlla se il rettangolo del player interseca la piattaforma
            if (CheckCollisionRecs(player.rect, platforms[i])) {
                
                // Atterraggio: Se sta cadendo (speedY >= 0) e i suoi piedi sono vicini alla superficie
                if (player.speedY >= 0 && (player.rect.y + player.rect.height - player.speedY) <= platforms[i].y + 10) {
                    player.rect.y = platforms[i].y - player.rect.height; // Allinea i piedi alla superficie
                    player.speedY = 0;                                    // Ferma la caduta
                    player.isGrounded = true;                             // Permette di saltare di nuovo
                }
            }
        }

        // --- RENDERING ---
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Disegna le piattaforme
            for (int i = 0; i < numPlatforms; i++) {
                DrawRectangleRec(platforms[i], DARKGRAY);
            }

            // Disegna il giocatore
            DrawRectangleRec(player.rect, BLUE);

            // Testo informativo
            DrawText("Frecce SINI/DESTRA per muoverti | SPAZIO per saltare", 10, 10, 20, DARKGRAY);
            if (player.isGrounded) {
                DrawText("Stato: A TERRA", 10, 35, 18, GREEN);
            } else {
                DrawText("Stato: IN VOLO", 10, 35, 18, ORANGE);
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}