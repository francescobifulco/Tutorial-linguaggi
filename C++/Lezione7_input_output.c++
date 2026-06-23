#include <iostream>
#include <string>

// Importiamo solo le funzionalità necessarie per una gestione pulita dell'I/O
using std::cout; 
using std::cin;
using std::string;

// Lezione 7: La gestione di Input e Output in C++
int main() {

    // --- PARTE 1: OUTPUT (Scrittura) ---
    int x = 35;
    // Differenza tra endl e \n:
    cout << "Ciao, ho " << x << " anni." << std::endl; // Va a capo e svuota il buffer (più lento)
    cout << "Ciao, ho " << x << " anni.\n";            // Va a capo in modo diretto (più efficiente)

    cout << "\n====================================\n";
    cout << "     REGISTRAZIONE NUOVO UTENTE     \n";
    cout << "====================================\n\n";

    // --- PARTE 2: INPUT (Lettura) ---
    string nome;
    string cognome;
    int eta;

    // Rimuovendo '\n' alla fine della richiesta, l'utente digiterà il testo 
    // direttamente di fianco ai due punti, rendendo il terminale molto più pulito.
    cout << "Inserisci il tuo nome: ";
    cin >> nome;

    cout << "Inserisci il tuo cognome: ";
    cin >> cognome;

    cout << "Inserisci la tua eta': ";
    cin >> eta;

    cout << "\n====================================\n";
    // --- PARTE 3: OUTPUT DEI DATI RACCOLTI ---
    cout << "Benvenuto nel sistema, " << nome << " " << cognome << "!\n";
    cout << "I tuoi dati confermano che hai " << eta << " anni.\n";
    cout << "====================================\n";
    
    return 0;
}