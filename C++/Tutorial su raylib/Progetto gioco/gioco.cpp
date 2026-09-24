#include <stdlib.h>
#include <raylib.h>

#ifndef TextToFloat
#define TextToFloat(testo) ((float)atof(testo))
#endif

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// ============================================================================
// STRUCT E TIPI DI DATO
// ============================================================================

// Struttura generica per un'entità di gioco (oggetti con texture e suoni)
struct Entita {
    Vector2 posizione;
    Texture2D texture;
    Sound effettoSonoro;

    // Metodo: Disegna l'entità a schermo se la texture è caricata correttamente
    void Disegna() {
        if (texture.id > 0) {
            DrawTextureV(texture, posizione, WHITE);
        }
    }
};

// Struttura che rappresenta il Giocatore con le sue proprietà fisiche e grafiche
struct Giocatore {
    Rectangle rettangolo; // Coordinate (x,y) e dimensioni (larghezza, altezza)
    float velocita;       // Velocità di movimento orizzontale
    Color colore;         // Colore del rettangolo del giocatore
    float velocitaY;      // Velocità verticale (gestione salto e gravità)
    bool aTerra;          // Stato: true se si trova sopra una piattaforma

    // Metodo: Resetta la posizione iniziale e azzera le velocità/stati fisici
    void Reset() {
        rettangolo = (Rectangle){100, 200, 40, 40};
        velocitaY = 0.0f;
        aTerra = false;
    }
};

// Enumerazione per la gestione degli stati della macchina a stati del gioco
typedef enum StatoGioco {
    MENU,
    GAMEPLAY,
    STATO_OPZIONI,
    GAMEOVER
} StatoGioco;

// ============================================================================
// FUNZIONE PRINCIPALE (MAIN)
// ============================================================================

int main() {

    // ------------------------------------------------------------------------
    // 1. INIZIALIZZAZIONE FINESTRA E AUDIO
    // ------------------------------------------------------------------------
    InitWindow(1000, 800, "Progetto Gioco in C++");
    InitAudioDevice();
    SetTargetFPS(60);

    // Caricamento della musica di sottofondo
    Music musicaDiSfondo = LoadMusicStream("Climbing_To_The_High_Score.mp3");
    PlayMusicStream(musicaDiSfondo);

    // ------------------------------------------------------------------------
    // 2. VARIABILI DI STATO E IMPOSTAZIONI
    // ------------------------------------------------------------------------
    StatoGioco statoAttuale = MENU;

    float volumeMusica = 0.5f;          // Volume audio (da 0.0 a 1.0)
    bool schermoIntero = false;         // Attivazione/Disattivazione Schermo Intero
    int risoluzioneSelezionata = 0;    // Indice per il menu a tendina delle risoluzioni
    bool modalitaModificaMenu = false;  // Stato di modifica del menu a tendina Raygui

    // Inizializzazione Giocatore
    Giocatore giocatore;
    giocatore.velocita = 5.0f;
    giocatore.colore = BLUE;
    giocatore.Reset();

    // Inizializzazione Telecamera 2D
    Camera2D telecamera = { 0 };
    telecamera.offset = (Vector2){ 500.0f, 400.0f }; // Centra la vista al centro dello schermo (1000x800)
    telecamera.rotation = 0.0f;
    telecamera.zoom = 1.0f;

    // Costanti della Fisica
    const float gravita = 0.6f;          // Forza di gravità applicata ad ogni frame
    const float forzaSalto = -12.0f;     // Spinta verso l'alto applicata al salto

    // Definizione degli elementi della mappa
    Rectangle piattaforme[] = {
        {0, 500, 1200, 100}, // Terreno principale
        {200, 400, 200, 20}, // Piattaforma 1
        {500, 300, 180, 20}  // Piattaforma 2
    };
    int numeroPiattaforme = sizeof(piattaforme) / sizeof(piattaforme[0]);

    Rectangle ostacolo = {400, 350, 80, 150}; // Ostacolo rosso dannoso

    // ------------------------------------------------------------------------
    // 3. CICLO DI GIOCO PRINCIPALE (GAME LOOP)
    // ------------------------------------------------------------------------
    while (!WindowShouldClose()) {

        // --- Aggiornamento Audio e Impostazioni Generali ---
        UpdateMusicStream(musicaDiSfondo);
        SetMasterVolume(volumeMusica);

        if (statoAttuale == STATO_OPZIONI) {
            if (IsWindowState(FLAG_FULLSCREEN_MODE) != schermoIntero) {
                ToggleFullscreen();
            }
        }

        // --- Inizio Rendering Grafico ---
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Macchina a stati per definire cosa aggiornare e disegnare
            switch (statoAttuale) {

                // ------------------------------------------------------------
                // STATO 1: MENU PRINCIPALE
                // ------------------------------------------------------------
                case MENU:
                    DrawText("NOME DEL GIOCO", 380, 100, 30, DARKBLUE);
                    DrawText("Tocca l'ostacolo rosso per andare in Game Over!", 280, 150, 18, GRAY);

                    if (GuiButton((Rectangle){400, 220, 200, 40}, "INIZIA GIOCO")) {
                        giocatore.Reset();
                        telecamera.zoom = 1.0f;
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

                    // Controllo Volume Musica
                    DrawText("Volume Musica:", 280, 200, 20, BLACK);
                    GuiSlider((Rectangle){440, 200, 200, 20}, "0%", "100%", &volumeMusica, 0.0f, 1.0f);

                    // Controllo Schermo Intero
                    DrawText("Schermo Intero:", 280, 250, 20, BLACK);
                    GuiCheckBox((Rectangle){440, 250, 20, 20}, "", &schermoIntero);

                    // Controllo Risoluzione
                    DrawText("Risoluzione:", 280, 300, 20, BLACK);
                    if (GuiDropdownBox((Rectangle){440, 300, 200, 30}, "800x450;1280x720;1920x1080", &risoluzioneSelezionata, modalitaModificaMenu)) {
                        modalitaModificaMenu = !modalitaModificaMenu;
                    }

                    // Pulsante per tornare al Menu Principale
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
                    // Insegue il centro del giocatore
                    telecamera.target = (Vector2){ 
                        giocatore.rettangolo.x + giocatore.rettangolo.width / 2.0f, 
                        giocatore.rettangolo.y + giocatore.rettangolo.height / 2.0f 
                    };

                    // --- Collisioni con le Piattaforme ---
                    for (int i = 0; i < numeroPiattaforme; i++) {
                        if (CheckCollisionRecs(giocatore.rettangolo, piattaforme[i])) {
                            // Verifica se il giocatore sta cadendo dall'alto sulla piattaforma
                            if (giocatore.velocitaY >= 0 && (giocatore.rettangolo.y + giocatore.rettangolo.height - giocatore.velocitaY) <= piattaforme[i].y + 10) {
                                giocatore.rettangolo.y = piattaforme[i].y - giocatore.rettangolo.height;
                                giocatore.velocitaY = 0;
                                giocatore.aTerra = true;
                            }
                        }
                    }

                    // --- Collisione con l'Ostacolo (Game Over) ---
                    if (CheckCollisionRecs(giocatore.rettangolo, ostacolo)) {
                        statoAttuale = GAMEOVER;
                    }

                    // --- Rendering Mondo di Gioco (Coordinate di Mondo / Telecamera) ---
                    BeginMode2D(telecamera);

                        // Disegna le piattaforme
                        for (int i = 0; i < numeroPiattaforme; i++) {
                            DrawRectangleRec(piattaforme[i], DARKGRAY);
                        }
                        // Disegna l'ostacolo rosso
                        DrawRectangleRec(ostacolo, RED);
                        // Disegna il giocatore
                        DrawRectangleRec(giocatore.rettangolo, giocatore.colore);

                    EndMode2D();

                    // --- Rendering Interfaccia Utente (UI Fissa a Schermo) ---
                    DrawText("Frecce SINISTRA/DESTRA per muoverti | SPAZIO per saltare", 10, 10, 18, DARKGRAY);
                    DrawText("Premi ESC per tornare al menu", 10, 35, 18, GRAY);

                    if (IsKeyPressed(KEY_ESCAPE)) {
                        statoAttuale = MENU;
                    }
                    break;

                // ------------------------------------------------------------
                // STATO 4: SCHERMATA DI GAME OVER
                // ------------------------------------------------------------
                case GAMEOVER:
                    DrawText("GAME OVER", 400, 300, 30, RED);
                    DrawText("Hai toccato l'ostacolo!", 380, 350, 20, DARKGRAY);
                    DrawText("Premi INVIO per tornare al menu principale", 280, 390, 20, DARKGRAY);

                    if (IsKeyPressed(KEY_ENTER)) {
                        giocatore.Reset();
                        statoAttuale = MENU;
                    }
                    break;
            }

        EndDrawing();
    }

// ----------------------------------------------------------------------------
// 4. CHIUSURA E DEALLOCAZIONE RISORSE
// ----------------------------------------------------------------------------
pulizia_e_uscita:
    UnloadMusicStream(musicaDiSfondo);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}