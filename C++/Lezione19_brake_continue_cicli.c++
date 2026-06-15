#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// Lezione 19: Le parole chiave per la gestione dei cicli in C++ (break, continue, goto)
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    // --- 1. LA PAROLA CHIAVE: break ---
    // Il break interrompe il ciclo COMPLETAMENTE 
    // e passa alla prima riga di codice fuori dal loop.
    cout << "=== 1. Esempio con BREAK ===\n";
    for (int i = 0; i < 10; i++){
        if (i == 5){
            // Il ciclo si ferma qui. I numeri da 5 a 9 non verranno mai stampati.
            break;
        }
        cout << "Valore i: " << i << "\n";
    }
    cout << "Uscito dal primo ciclo for a causa del break." << "\n\n";
    
    // --- 2. LA PAROLA CHIAVE: continue ---
    // Il continue interrompe SOLO il giro attuale. 
    // Salta il codice rimanente sotto di esso
    // e vola direttamente al prossimo incremento (i++).
    cout << "=== 2. Esempio con CONTINUE ===\n";
    for (int i = 0; i < 10; i++){
        if (i == 5){
            // Salta la stampa SOLO per il numero 5, poi il ciclo continua con il 6!
            continue;
        }
        cout << "Valore i: " << i << "\n";
    }
    cout <<"Finito il secondo ciclo for (ha solo saltato il 5)." << "\n\n";

    // --- 3. LA PAROLA CHIAVE: goto ---
    // Il goto salta direttamente a una riga contrassegnata da 
    // un'etichetta (label) seguita da due punti ':'.
    cout << "=== 3. Esempio con GOTO ===\n";
    int contatore = 1;

    inizio_loop: // Questa è l'etichetta (label)
    
    cout << "Contatore GOTO: " << contatore << "\n";
    contatore++;

    if (contatore <= 3) {
        // Salta indietro all'etichetta "inizio_loop" creando un ciclo manuale!
        goto inizio_loop; 
    }

    cout << "Saltato fuori dal ciclo manuale del goto.\n\n";

    // Esempio d'uso comune del goto: uscire d'un colpo 
    // da una situazione di emergenza
    cout << "Inizio un finto calcolo pericoloso...\n";
    bool errore_grave = true;

    if (errore_grave) {
        // Salta direttamente alla fine, saltando i cout intermedi
        goto gestione_errori; 
    }

    cout << "Questa stringa non verrà MAI stampata perché il goto la salta.\n";

    gestione_errori: // Etichetta di destinazione del salto di emergenza
    cout << "-> [GOTO] Rilevato errore grave: la sicurezza ha reindirizzato il flusso qui!\n";

    return 0;
}