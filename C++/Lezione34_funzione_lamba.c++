#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// Funzione classica (statica e nominata)
int quadrato(int x){
    return x * x;
}

// Lezione 34: Le funzioni Lambda in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");
    
    int num = 5;

    // --- 1. LAMBDA SENZA CATTURA ---
    // Le parentesi quadre [] sono vuote. Funziona 
    // esattamente come una funzione normale.
    auto quadratoLambda = [](int x){
        return x * x;
    };
    
    // --- 2. LAMBDA CON CATTURA PER VALORE (Copia) ---
    // Inserendo 'num' nelle parentesi quadre, 
    // la lambda fa una COPIA congelata di 'num' in quel momento.
    auto quadratoLambda2 = [num](){
        return num * num;
    };
    
    int risultato = quadrato(num);
    int risultatoLambda = quadratoLambda(num);
    int risultatoLambda2 = quadratoLambda2();
    
    cout << "=== 1. Test Base Lambda ===\n";
    cout << "Funzione classica: " << risultato << "\n";
    cout << "Lambda parametrica: " << risultatoLambda << "\n";
    cout << "Lambda con cattura [num]: " << risultatoLambda2 << "\n\n";

    // --- 3. CATTURA E PARAMETRI INSIEME ---
    // Cattura 'num' dall'esterno e accetta un 
    // intero 'y' come parametro quando viene chiamata.
    auto prova = [num](int y){
        int x = 10;
        return num * num + (x + y);
    };

    int risultato2 = prova(10); // num*num (25) + (10 + 10) = 45
    
    cout << "=== 2. Test Cattura + Parametri ===\n";
    cout << "Risultato espressione complessa: " << risultato2 << "\n\n";

    // --- 4. SCOPE LOCALE DI BLOCCO ---
    // La lambda 'provaIf' nasce e muore all'interno delle graffe dell'IF.
    if (num <= 10){
        auto provaIf = [num](){
            return num * num;
        };
        cout << "[Dentro IF] Risultato: " << provaIf() << "\n";
    }
    cout << "\n";

    // --- 5. APPLICAZIONE PRATICA: TRASFORMAZIONE DI LISTE ---
    cout << "=== 3. Modifica Vettore tramite Lambda ===\n";
    vector<int> vettore = {1, 2, 3, 4, 5};
    
    auto f = [](int x){
        return (x + 5 - 3) * 10;
    };
    
    for(int i = 0; i < vettore.size(); i++){
        vettore[i] = f(vettore[i]);
        cout << "Elemento modificato [" << i << "]: " << vettore[i] << "\n";
    }

    // --- 6. AGGIUNTA DIDATTICA: CATTURA PER VALORE vs RIFERIMENTO ---
    cout << "=== 4. Differenza di Cattura (Copia vs Reference) ===\n";
    int variabileEsterna = 10;

    auto catturaCopia = [variabileEsterna]() { return variabileEsterna; };
    auto catturaRiferimento = [&variabileEsterna]() { return variabileEsterna; };

    variabileEsterna = 999; // Modifichiamo la variabile originale prima di eseguire le lambda

    cout << "Lambda con [copia]: " << catturaCopia() << "\n";        // Stampa ancora 10! È rimasta congelata al valore iniziale.
    cout << "Lambda con [&reference]: " << catturaRiferimento() << "\n"; // Stampa 999! Vede il valore aggiornato in tempo reale.
    
    return 0;
}
