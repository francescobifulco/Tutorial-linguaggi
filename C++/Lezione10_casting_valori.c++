#include <iostream>
#include <string>
#include <typeinfo> // Libreria fondamentale per poter usare la funzione typeid().name()

using std::cin;
using std::cout;
using std::string;

// Lezione 10: La gestione del casting dei valori in C++
int main(){

    // --- 1. CASTING IMPLICITO (Automatico / Restringimento) ---
    cout << "=== 1. Casting Implicito (Automatico) ===\n";
    int x = 10;
    cout << "Valore iniziale di x (int): " << x << "\n";
    
    // Quando assegni un double (10.5) a un int, il C++ taglia i decimali AUTOMATICAMENTE.
    // Non arrotonda a 11, elimina semplicemente il .5 (Narrowing Conversion).
    x = 10.5;
    cout << "Valore di x dopo x = 10.5 (i decimali vengono persi): " << x << "\n";

    // Passiamo da un int (piccolo) a un float (più grande). Non c'è perdita di dati (Widening Conversion).
    float y = x;
    // std::fixed forza la stampa della parte decimale per mostrarti la precisione del float.
    cout << "Valore di y (float) stampato con std::fixed: " << std::fixed << y << "\n";

    // Resettiamo la formattazione di cout per le stampe successive (rimuove il blocco di std::fixed)
    cout << std::defaultfloat;


    // --- 2. CASTING IMPLICITO CON I CARATTERI (Tabella ASCII) ---
    cout << "\n=== 2. Conversione Implicita Char -> Int ===\n";
    char carattere = 'A'; // Sistemato il refuso "carratere"
    // Il computer non salva le lettere come simboli, ma come numeri (Codice ASCII).
    // Assegnando un char a un int, ricaviamo il suo codice numerico.
    int carattereIntero = carattere;
    cout << "Il carattere '" << carattere << "' convertito in intero corrisponde al codice ASCII: " << carattereIntero << "\n\n";

    // --- 3. CASTING ESPLICITO (static_cast) ---
    cout << "=== 3. Casting Esplicito (static_cast) ===\n";
    // Lo static_cast<tipo>(variabile) è il modo più sicuro, moderno e corretto di fare casting in C++.
    // Diciamo chiaramente al compilatore: "So cosa sto facendo, trasforma questo float in un int".
    int z = static_cast<int>(y);
    cout << "Valore di z dopo static_cast<int>(y): " << z << "\n";

    // Convertiamo il numero contenuto in x (che è 10) nel rispettivo carattere ASCII.
    // Nella tabella ASCII, il codice 10 corrisponde al carattere speciale "Nuova Riga" (\n), 
    // quindi questa stampa farà semplicemente un salto di riga invisibile nel terminale!
    cout << "Carattere ASCII del numero " << x << ": " << static_cast<char>(x) << "\n\n";

    // --- 4.LETTURA DEI TIPI DI DATO (RTTI) ---
    cout << "=== 4. Scoprire il tipo di dato con typeid ===\n";
    // typeid().name() restituisce l'identificativo del tipo di dato della variabile.
    // NOTA: l'output dipende dal compilatore! Su GCC/g++ (MSYS2) potrebbe stampare semplicemente 'f' per float, 'i' per int, ecc.
    cout << "Il tipo di dato della variabile 'y' e': " << typeid(y).name() << "\n";

    return 0;
}