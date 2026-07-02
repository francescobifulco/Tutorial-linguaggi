#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread> // OBBLIGATORIO per this_thread::sleep_for
#include <chrono> // OBBLIGATORIO per chrono::seconds

using std::cout;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using namespace std;

// Lezione 35: Lavorare con i File in C++ e Gestione del Tempo
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== 1. Scrittura Base (Crea o Sovrascrive) ===\n";

    ofstream outputFile("prova.txt");
    
    if (outputFile.is_open()) {
        outputFile << "Prima riga originale\n";
        cout << "[OK] File 'prova.txt' creato con successo.\n";
        outputFile.close();
    } else {
        cout << "[ERRORE] Creazione file fallita.\n";
    }

    // --- PAUSA DI 2 SECONDI (this_thread::sleep_for) ---
    cout << "\n[ATTESA] Il programma si ferma per 2 secondi...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "[ATTESA] Ripresa dell'esecuzione!\n\n";

    cout << "=== 2. Modalita' ios::app (Append - Aggiungi in coda) ===\n";
    // Apre il file SENZA cancellare il contenuto precedente; si posiziona alla fine del testo.
    ofstream outputFileApp("prova.txt", std::ios::out | std::ios::app);
    if (outputFileApp.is_open()) {
        outputFileApp << "Questa riga viene AGGIUNTA in fondo grazie a ios::app\n";
        cout << "[OK] Testo aggiunto in coda.\n";
        outputFileApp.close();
    }

    cout << "\n=== 3. Lettura del File (ifstream) ===\n";

    ifstream inputFile("prova.txt");
    if (inputFile.is_open()) {
        string line;
        cout << "--- Contenuto attuale di 'prova.txt': ---\n";
        while (getline(inputFile, line)) {
            cout << line << "\n";
        }
        cout << "----------------------------------------\n";
        inputFile.close();
    } else {
        cout << "[ERRORE] Impossibile aprire 'prova.txt' in lettura.\n";
    }

    cout << "\n=== 4. Modalita' ios::trunc (Truncate - Svuota) ===\n";
    
    // Apre il file e cancella ISTANTANEAMENTE tutto ciò che c'era dentro (lo azzera).
    ofstream outputFileTrunc("prova.txt", std::ios::out | std::ios::trunc);
    if (outputFileTrunc.is_open()) {
        outputFileTrunc << "Tabula Rasa! ios::trunc ha cancellato tutto il vecchio testo.\n";
        cout << "[OK] File svuotato e riscritto.\n";
        outputFileTrunc.close();
    }

    cout << "\n=== 5. Verifica Finale dopo TRUNC ===\n";
    inputFile.open("prova.txt"); // Riapriamo lo stream di lettura
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << "Contenuto finale: " << line << "\n";
        }
        inputFile.close();
    }

    string nomeFile = "archivio_temporaneo.txt";

    // Usiamo .c_str() se memorizziamo il nome in una variabile stringa del C++
    ofstream fileOutput(nomeFile, std::ios::out | std::ios::app);

    if (fileOutput.is_open()) {
        fileOutput << "Nuovo record inserito nel log.\n";
        cout << "[OK] File '" << nomeFile << "' aggiornato con successo.\n";
        fileOutput.close(); // Chiusura fondamentale, altrimenti il file resta bloccato!
    } else {
        cout << "[ERRORE] Impossibile aprire il file in scrittura.\n";
    }

    cout << "=== 6. Pulizia della Memoria (Funzione remove) ===\n";
    // remove() accetta una stringa classica del C. 
    // Passando nomeFile.c_str() convertiamo la stringa C++ nel formato corretto.
    if (remove(nomeFile.c_str()) == 0) {
        cout << "[ELIMINATO] Il file '" << nomeFile << "' e' stato rimosso dal disco.\n";
    } else {
        cout << "[ERRORE] Impossibile eliminare il file. Controlla che non sia aperto altrove.\n";
    }

    return 0;
}