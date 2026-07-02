#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> // Buona pratica: include esplicitamente le eccezioni standard come runtime_error

using namespace std;

// Funzione che valida l'operazione prima di eseguirla
int divide(int a, int b){
    if (b == 0){
        // Lanciamo l'eccezione: l'esecuzione della funzione si interrompe IMMEDIATAMENTE qui
        throw runtime_error("Errore: non divisibile per 0.");
    }
    return a / b;
}

// Lezione 36: La Gestire delle Eccezioni con TRY e CATCH in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== 1. Test con Eccezione (Divisione per 0) ===\n";
    try{
        // Questo codice viene monitorato. Se lancia un'eccezione, il C++ salta subito al catch
        int result = divide(10, 0); // Questa riga NON verrà eseguita
        cout << result << "\n";
    } // Intercettiamo l'eccezione per riferimento costante (evita copie inutili)
    catch(const exception& e){
        // e.what() restituisce la stringa di errore che hai scritto dentro il throw
        cerr << "[CATCH INTERCETTATO] " << e.what() << '\n';
    }

    cout << "\n=== 2. Test Senza Eccezione (Divisione Valida) ===\n";
    try {
        int resultValido = divide(10, 2);
        cout << "Risultato valido: " << resultValido << "\n"; // Questa viene eseguita!
    }
    catch (const runtime_error& e) {
        cerr << "[CATCH] Questo non si aprira' mai: " << e.what() << '\n';
    }

    cout << "\n=== 3. Continuazione del Flusso ===\n";
    // Grazie al catch, il programma non è crashato e arriva tranquillamente qui
    cout << "Il programma e' sopravvissuto e dice: ciao!\n";

    return 0;
}