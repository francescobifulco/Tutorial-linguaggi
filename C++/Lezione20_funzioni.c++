#include <iostream>
#include <string>
#include <typeinfo>
#include "funtiani.h++" // Creazione di un file header personalizzato, che include tutte le funzioni

using std::cin;
using std::cout;
using std::string;

// --- 1. PROTOTIPI DELLE FUNZIONI (Dichiarazioni) ---
// Diciamo al compilatore che queste funzioni esistono, 
// così possiamo definirle in fondo al file.
int calcalaSecondiInAnni2();
int calcalaSecondiInAnni3(int anno = 1); // Valore di default impostato qui nel prototipo

void scriviCiao(){
    cout << "Ciao" << "\n";
}

// Funzione VOID (Vuota): esegue un'azione 
// (stampa) ma non restituisce un dato utilizzabile nel main.
void calcalaSecondiInAnni() {
    int secondiInAnno = 60 * 60 * 24 * 365 * 1;
    cout << "Stampa diretta da funzione void: " << secondiInAnno << "\n";
}

// Lezione 20: Le Funzioni in C++ 
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

   cout << "=== 1. Funzioni con Return ===\n";
    // Salviamo il valore restituito dalla funzione dentro una variabile del main
    int secondiInAnno = calcalaSecondiInAnni2();
    cout << "Secondi in 1 anno (salvati in variabile): " << secondiInAnno << "\n\n";

    cout << "=== 2. Calcoli Manuali Rimasti ===\n";
    int secondiIn2Anno = 60 * 60 * 24 * 365 * 2;
    cout << "Secondi in 2 anni (manuale): " << secondiIn2Anno << "\n";

    int secondiIn3Anno = 60 * 60 * 24 * 365 * 3;
    cout << "Secondi in 3 anni (manuale): " << secondiIn3Anno << "\n\n";

    cout << "=== 3. Chiamate di Funzione ===\n";
    scriviCiao();
    calcalaSecondiInAnni();

    // Possiamo usare il return direttamente dentro il cout senza salvarlo prima
    cout << "Uso diretto nel cout di Anni2: " << calcalaSecondiInAnni2() << "\n\n";

    cout << "=== 4. Logica con Funzioni ===\n";
    // 31.536.000 è MAGGIORE di 3.000.000
    if (calcalaSecondiInAnni2() > 3000000) {
        cout << "Il calcolo di Anni2 e' maggiore di 3.000.000\n\n";
    }
    
    cout << "=== 5. Funzioni con Parametri e Default ===\n";
    // Passiamo il parametro 2 -> Calcolerà per 2 anni
    int risultatoDueAnni = calcalaSecondiInAnni3(2);
    cout << "Secondi in 2 anni (con parametro 2): " << risultatoDueAnni << "\n";

    // Non passiamo nulla -> Sfrutta il valore di default impostato nel prototipo (anno = 1)
    int risultatoDefault = calcalaSecondiInAnni3();
    cout << "Secondi con parametro di default (1 anno): " << risultatoDefault << "\n";

    return 0;
}

// --- 2. DEFINIZIONE DELLE FUNZIONI ---

// Questa funzione restituisce un intero al main
int calcalaSecondiInAnni2() {
    int secondiInAnno = 60 * 60 * 24 * 365 * 1;
    return secondiInAnno; // Sputa fuori il valore verso chi ha chiamato la funzione
}

// Questa funzione accetta un parametro in ingresso
int calcalaSecondiInAnni3(int anno) { // Nota: il valore di default si scrive solo nel prototipo in alto
    int secondiInAnno = 60 * 60 * 24 * 365 * anno;
    return secondiInAnno;
}