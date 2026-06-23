#include <iostream>

// Definiamo il nostro namespace personalizzato.
// Immaginalo come una "scatola" o un cognome che protegge ciò che c'è dentro.
namespace Prova{
    int cout = 100; // Questa è una variabile intera, non ha nulla a che fare con std::cout!
    int cedo = 50;
}

// Invece di importare l'intero 'namespace std' (che può creare conflitti),
// importiamo esplicitamente solo ciò che ci serve.
using std::cout;
using std::endl;

// Lezione 5: La gestione del namespace in C++
int main(){
    
    // Qui il compilatore sa che 'cout' si riferisce a 'std::cout' 
    // grazie all'istruzione 'using std::cout;' scritta sopra.
    cout << "--- Uso dello standard namespace ---\n";
    cout << "Ciao, sto usando il cout standard di C++!\n";
    cout << "Questo va anche a capo usando endl." << endl;
    
    cout << "\n--- Accedere al namespace personalizzato ---\n";
    // Per accedere alle variabili dentro il namespace 'Prova', 
    // usiamo l'operatore di risoluzione dello scope '::' (i doppi due punti).
    cout << "Il valore di cout dentro il namespace Prova e': " << Prova::cout << "\n";
    cout << "Il valore di cedo dentro il namespace Prova e': " << Prova::cedo << "\n";

    return 0;
}