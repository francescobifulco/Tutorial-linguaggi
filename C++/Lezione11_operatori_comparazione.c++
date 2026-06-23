#include <iostream>
#include <string>
#include <typeinfo>

using std::cout; 
using std::cin;
using std::string;

// Lezione 11: Gli operatori di comparazione in C++
int main(){

    // --- 1. VARIABILI BOOLEANE DI BASE ---
    bool x = false;
    bool y = true;

    // --- 2. OPERATORI DI CONFRONTO STANDARD ---
    bool condizione = 5 < 10;     // Minore (<): 5 è minore di 10? Sì (true)
    bool condizione2 = 10 <= 10;  // Minore o uguale (<=): 10 è uguale a 10? Sì (true)

    // Diverso o Disuguale (!=): controlla se i due valori sono differenti.
    // 11 è diverso da 10? Sì, quindi il risultato è vero (true).
    bool condizione3 = 11 != 10;

    // --- 3. APPLICAZIONE PRATICA: CONTROLLO PARITÀ ---
    // Questo è l'algoritmo standard in programmazione per vedere se un numero è pari.
    // Calcolo: 4 % 2 fa 0 (il resto di 4 diviso 2). 
    // Poi confronta: il resto (0) è uguale a 0? Sì (true). Se fosse stato dispari, il resto sarebbe stato 1.
    bool pari = 4 % 2 == 0;

    // --- 4. CONFRONTO AVANZATO TRA TIPI DI DATO ---
    // Usiamo l'operatore '==' applicato a typeid per verificare se due elementi hanno lo stesso tipo.
    // typeid(65) rappresenta un 'int', mentre typeid("65") rappresenta una stringa (o meglio, un array di char).
    // Sono lo stesso tipo di dato? No, quindi il risultato sarà falso (false).
    bool comparazione = typeid(65) == typeid("65");


    // --- 5. STAMPE SUL TERMINALE ---
    // Attiviamo boolalpha per vedere "true"/"false" invece di "1"/"0"
    cout << std::boolalpha;

    cout << "=== Variabili e Confronti Base ===\n";
    cout << "Valore di x: " << x << "\n";
    cout << "5 < 10: " << condizione << "\n";
    cout << "10 <= 10: " << condizione2 << "\n";
    cout << "11 != 10: " << condizione3 << "\n\n";

    cout << "=== Trucchetti e Logica Avanzata ===\n";
    cout << "Il numero 4 e' pari? (4 % 2 == 0): " << pari << "\n";
    cout << "Il tipo di 65 e' uguale al tipo di \"65\"?: " << comparazione << "\n";

    return 0;
}