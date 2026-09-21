#include <raylib.h>

int main() {
    InitWindow(800, 450, "Lezione 10 - Iniziazione 3D");
    SetTargetFPS(60);

    // Definizione della telecamera 3D
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f }; // Posizione nello spazio 3D
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Punto verso cui guarda la telecamera
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };         // Vettore di orientamento verso l'alto
    camera.fovy = 45.0f;                                // Campo visivo (Field of View)
    camera.projection = CAMERA_PERSPECTIVE;             // Tipo di proiezione

    while (!WindowShouldClose()) {
        // Aggiorna la telecamera (ruota leggermente intorno alla scena)
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Inizio della modalità di rendering 3D
            BeginMode3D(camera);

                // Disegna un cubo rosso al centro (0,0,0) di dimensioni 2x2x2
                DrawCube((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, RED);
                
                // Disegna i contorni del cubo in nero
                DrawCubeWires((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BLACK);

                // Griglia di riferimento 3D sul piano
                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawFPS(10, 10);
            DrawText("Modalita 3D Attiva! Usa il mouse per ruotare", 10, 30, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}