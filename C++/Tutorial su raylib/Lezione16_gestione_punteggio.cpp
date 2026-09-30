#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <fstream>  // Per la gestione dei file (High Score)
#include <string>

// Struttura Giocatore
struct Player {
    Vector2 posizione;
    Vector2 velocita;
    bool puoSaltare;
    float dimensione;
};

// Struttura Moneta (Collezionabile per extra punti)
struct Coin {
    Vector2 posizione;
    float raggio;
    bool attiva;
};

// -----------------------------------------------------------------------------
// FUNZIONI DI GESTIONE SALVATAGGIO HIGH SCORE
// -----------------------------------------------------------------------------
int CaricaPunteggioMassimo(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    int punteggioMassimo = 0;
    if (file.is_open()) {
        file >> punteggioMassimo;
        file.close();
    }
    return punteggioMassimo;
}

void SalvaPunteggioMassimo(const std::string& nomeFile, int punteggio) {
    std::ofstream file(nomeFile);
    if (file.is_open()) {
        file << punteggio;
        file.close();
    }
}

int main() {
    const int larghezzaSchermo = 800;
    const int altezzaSchermo = 450;

    InitWindow(larghezzaSchermo, altezzaSchermo, "Lezione 16 - Sistema Punteggio e High Score");

    const std::string nomeFileSalvataggio = "highscore.txt";

    // CARICAMENTO HIGH SCORE
    int punteggioMassimo = CaricaPunteggioMassimo(nomeFileSalvataggio);

    // Inizializzazione Giocatore
    Player giocatore = { 0 };
    giocatore.posizione = (Vector2){ 100, 200 };
    giocatore.velocita = (Vector2){ 220, 0 };
    giocatore.puoSaltare = false;
    giocatore.dimensione = 30.0f;

    float gravita = 850.0f;
    float velocitaSalto = -360.0f;

    // Vettori di Gioco
    std::vector<Rectangle> piattaforme;
    std::vector<Coin> monete;

    piattaforme.push_back((Rectangle){ 50, 300, 200, 20 });
    float ultimaPosizionePiattaformaX = 50.0f;

    // Variabili Punteggio
    int punteggioDistanza = 0;
    int punteggioMonete = 0;
    int punteggioTotale = 0;
    int moltiplicatoreCombo = 1;
    float tempoCombo = 0.0f;

    // Camera2D
    Camera2D camera = { 0 };
    camera.offset = (Vector2){ larghezzaSchermo / 4.0f, altezzaSchermo / 2.0f };
    camera.zoom = 1.0f;

    bool giocoFinito = false;
    bool nuovoRecordRaggiunto = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float tempoFrame = GetFrameTime();

        if (!giocoFinito) {
            // -----------------------------------------------------------------
            // 1. FISICA E MOVIMENTO
            // -----------------------------------------------------------------
            giocatore.posizione.x += giocatore.velocita.x * tempoFrame;
            giocatore.velocita.y += gravita * tempoFrame;
            giocatore.posizione.y += giocatore.velocita.y * tempoFrame;

            if (IsKeyPressed(KEY_SPACE) && giocatore.puoSaltare) {
                giocatore.velocita.y = velocitaSalto;
                giocatore.puoSaltare = false;
            }

            // -----------------------------------------------------------------
            // 2. GENERAZIONE PROCEDURALE PIATTAFORME E MONETE
            // -----------------------------------------------------------------
            float bordoDestro = camera.target.x + larghezzaSchermo;

            while (ultimaPosizionePiattaformaX < bordoDestro + 300) {
                float spazio = (float)(rand() % 110 + 90);
                float larghezza = (float)(rand() % 100 + 80);
                float altezzaY = (float)(rand() % 140 + 200);

                ultimaPosizionePiattaformaX += spazio + larghezza;
                Rectangle nuovaPiattaforma = { ultimaPosizionePiattaformaX, altezzaY, larghezza, 20 };
                piattaforme.push_back(nuovaPiattaforma);

                // 50% di probabilità di generare una moneta sopra la piattaforma
                if (rand() % 2 == 0) {
                    Coin moneta;
                    moneta.posizione = (Vector2){ nuovaPiattaforma.x + nuovaPiattaforma.width / 2.0f, nuovaPiattaforma.y - 25.0f };
                    moneta.raggio = 10.0f;
                    moneta.attiva = true;
                    monete.push_back(moneta);
                }
            }

            // -----------------------------------------------------------------
            // 3. CLEANUP ELEMENTI FUORI SCHERMO
            // -----------------------------------------------------------------
            float bordoSinistro = camera.target.x - (larghezzaSchermo / 2.0f);

            for (auto it = piattaforme.begin(); it != piattaforme.end(); ) {
                if (it->x + it->width < bordoSinistro) it = piattaforme.erase(it);
                else ++it;
            }

            for (auto it = monete.begin(); it != monete.end(); ) {
                if (it->posizione.x + it->raggio < bordoSinistro) it = monete.erase(it);
                else ++it;
            }

            // -----------------------------------------------------------------
            // 4. COLLISIONI E RACCOLTA MONETE
            // -----------------------------------------------------------------
            giocatore.puoSaltare = false;
            Rectangle rettangoloGiocatore = { giocatore.posizione.x - giocatore.dimensione / 2, giocatore.posizione.y - giocatore.dimensione, giocatore.dimensione, giocatore.dimensione };

            // Collisione Piattaforme
            for (const auto& piattaforma : piattaforme) {
                if (CheckCollisionRecs(rettangoloGiocatore, piattaforma)) {
                    if (giocatore.velocita.y > 0 && (giocatore.posizione.y - giocatore.velocita.y * tempoFrame) <= piattaforma.y) {
                        giocatore.velocita.y = 0;
                        giocatore.posizione.y = piattaforma.y;
                        giocatore.puoSaltare = true;
                    }
                }
            }

            // Collisione Monete
            for (auto& moneta : monete) {
                if (moneta.attiva && CheckCollisionCircleRec(moneta.posizione, moneta.raggio, rettangoloGiocatore)) {
                    moneta.attiva = false;

                    // Incrementa Punteggio con Moltiplicatore
                    punteggioMonete += 100 * moltiplicatoreCombo;

                    // Aumenta Combo
                    moltiplicatoreCombo++;
                    tempoCombo = 3.0f; // Il moltiplicatore dura 3 secondi
                }
            }

            // Gestione Timer Combo
            if (tempoCombo > 0.0f) {
                tempoCombo -= tempoFrame;
                if (tempoCombo <= 0.0f) {
                    moltiplicatoreCombo = 1; // Reset moltiplicatore
                }
            }

            // -----------------------------------------------------------------
            // 5. CALCOLO PUNTEGGIO TOTALE
            // -----------------------------------------------------------------
            punteggioDistanza = (int)(giocatore.posizione.x / 10.0f);
            punteggioTotale = punteggioDistanza + punteggioMonete;

            // Aggiornamento dinamico dell'High Score in diretta
            if (punteggioTotale > punteggioMassimo) {
                punteggioMassimo = punteggioTotale;
                nuovoRecordRaggiunto = true;
            }

            // -----------------------------------------------------------------
            // 6. GAME OVER & SALVATAGGIO
            // -----------------------------------------------------------------
            if (giocatore.posizione.y > altezzaSchermo + 200) {
                giocoFinito = true;

                // Salviamo su file il nuovo punteggio record se superato
                if (nuovoRecordRaggiunto) {
                    SalvaPunteggioMassimo(nomeFileSalvataggio, punteggioMassimo);
                }
            }

            camera.target = giocatore.posizione;

        } else {
            // Reset con [R]
            if (IsKeyPressed(KEY_R)) {
                giocatore.posizione = (Vector2){ 100, 200 };
                giocatore.velocita = (Vector2){ 220, 0 };
                piattaforme.clear();
                monete.clear();
                piattaforme.push_back((Rectangle){ 50, 300, 200, 20 });
                ultimaPosizionePiattaformaX = 50.0f;

                punteggioMonete = 0;
                punteggioTotale = 0;
                moltiplicatoreCombo = 1;
                tempoCombo = 0.0f;
                nuovoRecordRaggiunto = false;

                giocoFinito = false;
            }
        }

        // ---------------------------------------------------------------------
        // RENDER
        // ---------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode2D(camera);
                // Piattaforme
                for (const auto& piattaforma : piattaforme) {
                    DrawRectangleRec(piattaforma, DARKGRAY);
                }

                // Monete
                for (const auto& moneta : monete) {
                    if (moneta.attiva) {
                        DrawCircleV(moneta.posizione, moneta.raggio, GOLD);
                        DrawCircleLines((int)moneta.posizione.x, (int)moneta.posizione.y, moneta.raggio, ORANGE);
                    }
                }

                // Player
                DrawRectangle(giocatore.posizione.x - giocatore.dimensione / 2, giocatore.posizione.y - giocatore.dimensione, giocatore.dimensione, giocatore.dimensione, RED);
            EndMode2D();

            // -----------------------------------------------------------------
            // HEADS-UP DISPLAY (HUD)
            // -----------------------------------------------------------------
            DrawText(TextFormat("SCORE: %i", punteggioTotale), 20, 20, 24, BLACK);
            DrawText(TextFormat("HIGH SCORE: %i", punteggioMassimo), 20, 50, 20, GOLD);

            // Indicatore Combo Moltiplicatore
            if (moltiplicatoreCombo > 1) {
                DrawText(TextFormat("COMBO x%i! (%.1fs)", moltiplicatoreCombo, tempoCombo), 20, 80, 22, RED);
            }

            if (giocoFinito) {
                DrawRectangle(0, 0, larghezzaSchermo, altezzaSchermo, Fade(BLACK, 0.85f));

                DrawText("GAME OVER", larghezzaSchermo / 2 - MeasureText("GAME OVER", 40) / 2, 120, 40, RED);
                DrawText(TextFormat("Punteggio Finale: %i", punteggioTotale), larghezzaSchermo / 2 - MeasureText(TextFormat("Punteggio Finale: %i", punteggioTotale), 24) / 2, 190, 24, WHITE);

                if (nuovoRecordRaggiunto) {
                    DrawText("NUOVO RECORD!", larghezzaSchermo / 2 - MeasureText("NUOVO RECORD!", 28) / 2, 230, 28, GOLD);
                } else {
                    DrawText(TextFormat("Record attuale: %i", punteggioMassimo), larghezzaSchermo / 2 - MeasureText(TextFormat("Record attuale: %i", punteggioMassimo), 20) / 2, 230, 20, GRAY);
                }

                DrawText("Premere [R] per Giocare Ancora", larghezzaSchermo / 2 - MeasureText("Premere [R] per Giocare Ancora", 20) / 2, 300, 20, LIGHTGRAY);
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}