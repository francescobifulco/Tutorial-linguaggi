#include <iostream>
#include <string>

// Importiamo solo ciò che ci serve dallo standard namespace
using std::cout;
using std::string;

// DICHIARAZIONE DELLE STRUTTURE E DELLE CLASSI
// Di norma si dichiarano FUORI dal main, così sono riutilizzabili in tutto il programma.

// Una Struct raggruppa diverse variabili sotto un unico nome (di default i membri sono PUBBLICI)
struct Persona {
    string nome;
    string cognome;
    int eta;
};

// Una Classe è simile alla struct, ma è alla base della programmazione a oggetti (di default i membri sono PRIVATI)
class ClasseProva {
public: // Mettiamo 'public' per poter accedere a queste variabili da fuori
    int x;
    int y;
};

// LEzione 6: Tutti i tipi di dato in C++
int main(){

// --- 1. TIPI PRIMITIVI (Numerici e Booleani) ---
    int variabileInt = 8; // Numeri interi
    float variabileFloat = 34.5646f; // Numeri decimali a singola precisione (si mette la 'f' alla fine)
    double variabileDouble = 24.4443; // Numeri decimali a doppia precisione (più accurati)
    char variabileChar = 'A'; // Carattere singolo (si usano gli apici singoli '')
    bool variabileBool = false; // Booleano (può essere solo true [1] o false [0])

    // --- 2. TIPI DI DATO COMPLESSI / STRUTTURATI ---
    string variabileString = "Ciao a tutti"; // Stringa di testo (usa le virgolette doppie "")
    int numeri[5] = {10, 88, 40, 44, 3};     // Array (collezione fissa di elementi dello stesso tipo)

    // ISTANZIAZIONE (Creazione degli oggetti dalle 
    // struct e classi definite sopra)
    Persona utente;
    utente.nome = "Francy";
    utente.cognome = "Rossi";
    utente.eta = 24;

    ClasseProva oggetto;
    oggetto.x = 10;
    oggetto.y = 20;

    // --- STAMPE SUL TERMINALE ---
    cout << "=== TIPI PRIMITIVI ===\n";
    cout << "Int: " << variabileInt << "\n";
    cout << "Float: " << variabileFloat << "\n";
    cout << "Double: " << variabileDouble << "\n";
    cout << "Char: " << variabileChar << "\n";
    cout << "Bool: " << variabileBool << " (in C++ false viene stampato come 0)\n\n";

    cout << "=== TIPI COMPLESSI ===\n";
    cout << "String: " << variabileString << "\n";
    cout << "Primo elemento dell'array: " << numeri[0] << "\n";
    cout << "Ultimo elemento dell'array: " << numeri[4] << "\n\n";

    cout << "=== STRUCT E CLASSI ===\n";
    cout << "Dati Persona -> Nome: " << utente.nome << ", Cognome: " << utente.cognome << ", Eta': " << utente.eta << "\n";
    cout << "Coordinate Classe -> X: " << oggetto.x << ", Y: " << oggetto.y << "\n";

    return 0;
}