#include <stdlib.h>
#include <raylib.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

#ifndef TextToFloat
#define TextToFloat(testo) ((float)atof(testo))
#endif

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// ============================================================================
// STRUCT E TIPI DI DATO
// ============================================================================

struct Entita {
    Vector2 posizione;
    Texture2D texture;
    Sound effettoSonoro;

    void Disegna() {
        if (texture.id > 0) {
            DrawTextureV(texture, posizione, WHITE);
        }
    }
};

// Struttura Moneta (Collezionabile per extra punti)
struct Coin {
    Vector2 position;
    float radius;
    bool active;
};

struct Giocatore {
    Rectangle rettangolo;
    float velocita;     
    Color colore;        
    float velocitaY;     
    bool aTerra;         

    void Reset() {
        rettangolo = (Rectangle){100, 200, 40, 40};
        velocitaY = 0.0f;
        aTerra = false;
    }
};

// -----------------------------------------------------------------------------
// FUNZIONI DI GESTIONE SALVATAGGIO HIGH SCORE
// -----------------------------------------------------------------------------
int LoadHighScore(const std::string& filename) {
    std::ifstream file(filename);
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

void SaveHighScore(const std::string& filename, int score) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << score;
        file.close();
    }
}

typedef enum StatoGioco {
    MENU,
    GAMEPLAY,
    STATO_OPZIONI,
    GAMEOVER,
} StatoGioco;

// Helper per resettare completamente il mondo di gioco
void IniziaNuovaPartita(Giocatore& giocatore, std::vector<Rectangle>& platforms, float& lastPlatformX, Camera2D& telecamera) {
    giocatore.Reset();
    platforms.clear();
    
    // Piattaforma iniziale sotto i piedi del giocatore
    platforms.push_back((Rectangle){ 0, 400, 400, 20 });
    lastPlatformX = 400.0f;

    telecamera.zoom = 1.0f;
    telecamera.target = (Vector2){ 
        giocatore.rettangolo.x + giocatore.rettangolo.width / 2.0f, 
        giocatore.rettangolo.y + giocatore.rettangolo.height / 2.0f 
    };
}

// ============================================================================
// FUNZIONE PRINCIPALE (MAIN)
// ============================================================================

int main() {
    srand((unsigned int)time(NULL)); // Inizializza il generatore di numeri casuali

    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Progetto Gioco in C++");
    InitAudioDevice();
    SetTargetFPS(60);

    Music musicaDiSfondo = LoadMusicStream("Climbing_To_The_High_Score.mp3");
    PlayMusicStream(musicaDiSfondo);

    StatoGioco statoAttuale = MENU;

    const std::string saveFileName = "highscore.txt";

    // CARICAMENTO HIGH SCORE
    int highScore = LoadHighScore(saveFileName);

    float volumeMusica = 0.5f;        
    bool schermoIntero = false;       
    int risoluzioneSelezionata = 0;    
    bool modalitaModificaMenu = false;

    Giocatore giocatore;
    giocatore.velocita = 5.0f;
    giocatore.colore = BLUE;
    giocatore.Reset();

    Camera2D telecamera = { 0 };
    telecamera.offset = (Vector2){ 500.0f, 400.0f };
    telecamera.rotation = 0.0f;
    telecamera.zoom = 1.0f;

     // Vettori di Gioco
    std::vector<Rectangle> platforms;
    std::vector<Coin> coins;

    platforms.push_back((Rectangle){ 50, 300, 200, 20 });
    float lastPlatformX = 50.0f;

    // Variabili Punteggio
    int distanceScore = 0;
    int coinBonusScore = 0;
    int totalScore = 0;
    int comboMultiplier = 1;
    float comboTimer = 0.0f;

    const float gravita = 0.6f;        
    const float forzaSalto = -12.0f;   

    Rectangle ostacolo = {600, 250, 40, 50}; // Ostacolo rosso

    std::vector<Rectangle> platforms;
    float lastPlatformX = 50.0f;
    float rightEdge = 0.0f;
    float leftEdge = 0.0f;

    bool gameOver = false;
    bool newRecordAchieved = false;

    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();

        UpdateMusicStream(musicaDiSfondo);
        SetMasterVolume(volumeMusica);

        if (statoAttuale == STATO_OPZIONI) {
            if (IsWindowState(FLAG_FULLSCREEN_MODE) != schermoIntero) {
                ToggleFullscreen();
            }
        }

        // 50% di probabilità di generare una moneta sopra la piattaforma
        if (rand() % 2 == 0) {
            Coin c;
            c.position = (Vector2){ newPlat.x + newPlat.width / 2.0f, newPlat.y - 25.0f };
            c.radius = 10.0f;
            c.active = true;
            coins.push_back(c);
        }

        // -----------------------------------------------------------------
        // 4. COLLISIONI E RACCOLTA MONETE
        // -----------------------------------------------------------------
        player.canJump = false;
        Rectangle playerBox = { player.position.x - player.size/2, player.position.y - player.size, player.size, player.size };

        // Collisione Piattaforme
        for (const auto& platform : platforms) {
            if (CheckCollisionRecs(playerBox, platform)) {
                if (player.speed.y > 0 && (player.position.y - player.speed.y * deltaTime) <= platform.y) {
                    player.speed.y = 0;
                    player.position.y = platform.y;
                    player.canJump = true;
                }
            }
        }

        // Collisione Monete
        for (auto& coin : coins) {
            if (coin.active && CheckCollisionCircleRec(coin.position, coin.radius, playerBox)) {
                coin.active = false;
                    
                // Incrementa Punteggio con Moltiplicatore
                coinBonusScore += 100 * comboMultiplier;
                    
                // Aumenta Combo
                comboMultiplier++;
                comboTimer = 3.0f; // Il moltiplicatore dura 3 secondi
            }
        }

        // Gestione Timer Combo
        if (comboTimer > 0.0f) {
            comboTimer -= deltaTime;
            if (comboTimer <= 0.0f) {
                comboMultiplier = 1; // Reset moltiplicatore
            }
        }

        // -----------------------------------------------------------------
        // 5. CALCOLO PUNTEGGIO TOTALE
        // -----------------------------------------------------------------
        distanceScore = (int)(player.position.x / 10.0f);
        totalScore = distanceScore + coinBonusScore;

        // Aggiornamento dinamico dell'High Score in diretta
        if (totalScore > highScore) {
            highScore = totalScore;
            newRecordAchieved = true;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            switch (statoAttuale) {

                // ------------------------------------------------------------
                // STATO 1: MENU PRINCIPALE
                // ------------------------------------------------------------
                case MENU:
                    DrawText("NOME DEL GIOCO", 380, 100, 30, DARKBLUE);
                    DrawText("Tocca l'ostacolo rosso per andare in Game Over!", 280, 150, 18, GRAY);

                    if (GuiButton((Rectangle){400, 220, 200, 40}, "INIZIA GIOCO")) {
                        IniziaNuovaPartita(giocatore, platforms, lastPlatformX, telecamera);
                        statoAttuale = GAMEPLAY;
                    }
                    if (GuiButton((Rectangle){400, 280, 200, 40}, "OPZIONI")) {
                        statoAttuale = STATO_OPZIONI;
                    }
                    if (GuiButton((Rectangle){400, 340, 200, 40}, "ESCI")) {
                        goto pulizia_e_uscita;
                    }
                    break;

                // ------------------------------------------------------------
                // STATO 2: MENU OPZIONI
                // ------------------------------------------------------------
                case STATO_OPZIONI:
                    DrawText("IMPOSTAZIONI", 400, 100, 28, DARKGRAY);

                    DrawText("Volume Musica:", 280, 200, 20, BLACK);
                    GuiSlider((Rectangle){440, 200, 200, 20}, "0%", "100%", &volumeMusica, 0.0f, 1.0f);

                    DrawText("Schermo Intero:", 280, 250, 20, BLACK);
                    GuiCheckBox((Rectangle){440, 250, 20, 20}, "", &schermoIntero);

                    DrawText("Risoluzione:", 280, 300, 20, BLACK);
                    if (GuiDropdownBox((Rectangle){440, 300, 200, 30}, "800x450;1280x720;1920x1080", &risoluzioneSelezionata, modalitaModificaMenu)) {
                        modalitaModificaMenu = !modalitaModificaMenu;
                    }

                    if (!modalitaModificaMenu) {
                        if (GuiButton((Rectangle){400, 420, 200, 40}, "< INDIETRO")) {
                            statoAttuale = MENU;
                        }
                    }
                    break;

                // ------------------------------------------------------------
                // STATO 3: SCHERMATA DI GIOCO (GAMEPLAY)
                // ------------------------------------------------------------
                case GAMEPLAY:
                    // --- Input Tastiera ---
                    if (IsKeyDown(KEY_RIGHT)) giocatore.rettangolo.x += giocatore.velocita;
                    if (IsKeyDown(KEY_LEFT))  giocatore.rettangolo.x -= giocatore.velocita;

                    if (IsKeyPressed(KEY_SPACE) && giocatore.aTerra) {
                        giocatore.velocitaY = forzaSalto;
                        giocatore.aTerra = false;
                    }

                    // --- Applicazione Gravità e Movimento Verticale ---
                    giocatore.velocitaY += gravita;
                    giocatore.rettangolo.y += giocatore.velocitaY;
                    giocatore.aTerra = false;

                    // --- Gestione della Telecamera ---
                    telecamera.target = (Vector2){ 
                        giocatore.rettangolo.x + giocatore.rettangolo.width / 2.0f, 
                        giocatore.rettangolo.y + giocatore.rettangolo.height / 2.0f 
                    };

                    // --- Generazione Infinita Piattaforme ---
                    rightEdge = telecamera.target.x + screenWidth;
                    while (lastPlatformX < rightEdge + 300) {
                        float gap = (float)(rand() % 120 + 80);      // Distanza X (80 - 200 px)
                        float width = (float)(rand() % 100 + 80);    // Larghezza (80 - 180 px)
                        float heightY = (float)(rand() % 150 + 300); // Altezza Y (300 - 450 px)

                        lastPlatformX += gap + width;
                        platforms.push_back((Rectangle){ lastPlatformX, heightY, width, 20 });
                    }

                    // --- Pulizia Piattaforme Vecchie ---
                    leftEdge = telecamera.target.x - (screenWidth / 2.0f);
                    for (auto it = platforms.begin(); it != platforms.end(); ) {
                        if (it->x + it->width < leftEdge) {
                            it = platforms.erase(it);
                        } else {
                            ++it;
                        }
                    }

                    // --- Collisioni con le Piattaforme Dinamiche ---
                    for (const auto& platform : platforms) {
                        if (CheckCollisionRecs(giocatore.rettangolo, platform)) {
                            if (giocatore.velocitaY >= 0 && (giocatore.rettangolo.y + giocatore.rettangolo.height - giocatore.velocitaY) <= platform.y + 10) {
                                giocatore.rettangolo.y = platform.y - giocatore.rettangolo.height;
                                giocatore.velocitaY = 0;
                                giocatore.aTerra = true;
                            }
                        }
                    }

                    // --- Collisione con l'Ostacolo o Caduta nel Vuoto (Game Over) ---
                    if (CheckCollisionRecs(giocatore.rettangolo, ostacolo) || giocatore.rettangolo.y > 1000) {
                        statoAttuale = GAMEOVER;
                    }

                    // --- Rendering Mondo di Gioco ---
                    BeginMode2D(telecamera);

                        for (const auto& platform : platforms) {
                            DrawRectangleRec(platform, DARKGRAY);
                        }
                        DrawRectangleRec(ostacolo, RED);
                        DrawRectangleRec(giocatore.rettangolo, giocatore.colore);

                    EndMode2D();

                    // --- Rendering UI Fissa ---
                    DrawText("Frecce SINISTRA/DESTRA per muoverti | SPAZIO per saltare", 10, 10, 18, DARKGRAY);
                    DrawText("Premi ESC per tornare al menu", 10, 35, 18, GRAY);

                    if (IsKeyPressed(KEY_ESCAPE)) {
                        statoAttuale = MENU;
                    }
                    break;

                // ------------------------------------------------------------
                // STATO 4: SCHERMATA DI GAME OVER
                // ------------------------------------------------------------
                case GAMEOVER:{
                    DrawText("GAME OVER", 400, 300, 30, RED);
                    DrawText("Hai perso!", 440, 350, 20, DARKGRAY);
                    DrawText("Premi INVIO per tornare al menu principale", 280, 390, 20, DARKGRAY);

                    if (IsKeyPressed(KEY_ENTER)) {
                        statoAttuale = MENU;
                    }
                    break;

                     // -----------------------------------------------------------------
                     // 6. GAME OVER & SALVATAGGIO
                    // -----------------------------------------------------------------
                    if (player.position.y > screenHeight + 200) {
                        gameOver = true;
                
                        // Salviamo su file il nuovo punteggio record se superato
                        if (newRecordAchieved) {
                            SaveHighScore(saveFileName, highScore);
                        }
                    }

            camera.target = player.position;
                }
            }

            // Monete
                for (const auto& coin : coins) {
                    if (coin.active) {
                        DrawCircleV(coin.position, coin.radius, GOLD);
                        DrawCircleLines((int)coin.position.x, (int)coin.position.y, coin.radius, ORANGE);
                    }
                }

                // -----------------------------------------------------------------
            // HEADS-UP DISPLAY (HUD)
            // -----------------------------------------------------------------
            DrawText(TextFormat("SCORE: %i", totalScore), 20, 20, 24, BLACK);
            DrawText(TextFormat("HIGH SCORE: %i", highScore), 20, 50, 20, GOLD);

            // Indicatore Combo Moltiplicatore
            if (comboMultiplier > 1) {
                DrawText(TextFormat("COMBO x%i! (%.1fs)", comboMultiplier, comboTimer), 20, 80, 22, RED);
            }

            if (gameOver) {
                DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.85f));
                
                DrawText("GAME OVER", screenWidth/2 - MeasureText("GAME OVER", 40)/2, 120, 40, RED);
                DrawText(TextFormat("Punteggio Finale: %i", totalScore), screenWidth/2 - MeasureText(TextFormat("Punteggio Finale: %i", totalScore), 24)/2, 190, 24, WHITE);
                
                if (newRecordAchieved) {
                    DrawText("NUOVO RECORD!", screenWidth/2 - MeasureText("NUOVO RECORD!", 28)/2, 230, 28, GOLD);
                } else {
                    DrawText(TextFormat("Record attuale: %i", highScore), screenWidth/2 - MeasureText(TextFormat("Record attuale: %i", highScore), 20)/2, 230, 20, GRAY);
                }
            }
        EndDrawing();
    }

pulizia_e_uscita:
    UnloadMusicStream(musicaDiSfondo);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}