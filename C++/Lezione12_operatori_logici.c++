#include <iostream>
#include <string>
#include <typeinfo> 

using std::cout; 
using std::cin;
using std::string;
using std::boolalpha;

// Lezione 12: Gli operatori di logica in C++
int main() {

    // VARIABILI DI PARTENZA
    bool isOnline = true; // Sistemato il refuso "isOnile"
    int numero = 61;
    int numero2 = 103;

    bool x = 65 < 100; // true
    bool y = 50 != 50; // false

    // --- 1. OPERATORE AND (&&) ---
    // Restituisce TRUE solo se ENTRAMBE le condizioni sono vere.
    // Condizione: (61 è dispari? SÌ, true) AND (61 è minore di 100? SÌ, true).
    // true && true -> Risultato: true
    bool condizione = (numero % 2 != 0) && (numero < 100);

    // --- 2. OPERATORE OR (||) ---
    // Restituisce TRUE se ALMENO UNA delle condizioni è vera.
    // Condizione: (61 è dispari? SÌ, true) OR (61 è minore di 100? SÌ, true).
    // true || true -> Risultato: true
    bool condizione2 = (numero % 2 != 0) || (numero < 100);

    // --- 3. OPERATORE NOT (!) ---
    // Ribalta il risultato: trasforma true in false, e false in true.
    // (numero < 100) è vero (true), ma il '!' davanti lo trasforma in false.
    bool condizione3 = !(numero < 100);
    bool diverso = !isOnline; // isOnline è true, quindi !isOnline diventa false

   // --- 4. SUPER CONTROLLO COMBINATO (Logica Complessa) ---
    // Analizziamolo in due parti separate dal && centrale:
    // Parte A: (61 è pari? NO, false && 61 < 100? SÌ, true) -> false && true = false
    // Parte B: (103 è dispari? SÌ, true && 103 >= 100? SÌ, true && 103 <= 200? SÌ, true) -> true
    // Risultato Finale: Parte A (false) && Parte B (true) -> Risultato: false
    bool controllo = (numero % 2 == 0 && numero < 100) && (numero2 % 2 != 0 && numero2 >= 100 && numero2 <= 200);

    // --- STAMPE SUL TERMINALE ---
    cout << boolalpha; // Attiva la stampa testuale di true/false

    cout << "=== Operatori Logici Fondamentali ===\n";
    cout << "AND (&&) -> Entrambe vere (dispari e < 100): " << condizione << "\n";
    cout << "OR  (||) -> Almeno una vera (dispari o < 100): " << condizione2 << "\n";
    cout << "NOT (!)  -> Negazione di (61 < 100): " << condizione3 << "\n";
    cout << "NOT (!)  -> Stato inverso di isOnline: " << diverso << "\n\n";

    cout << "=== Controllo Logico Avanzato ===\n";
    cout << "Risultato della macro-condizione combinata: " << controllo << "\n";

    return 0;
}