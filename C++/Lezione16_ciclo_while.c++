#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::string;

// Lezione 15: La gestione del ciclo while e do-while in C++
int main() {

    std::setlocale(LC_ALL, "it_IT.utf8");

    // --- 1. IL CICLO WHILE (Controllo all'inizio) ---
    // Verifica la condizione PRIMA di eseguire il codice. 
    // Se la condizione è falsa all'inizio, non parte mai.
    cout << "=== 1. Ciclo While ===\n";
    int i = 0;
    while(i <= 5){
        cout << "Questo è l'iterazione numero del ciclo while: " << i << "\n";
        i++; // Fondamentale per evitare un ciclo infinito! 
    }
    cout << "\n";
    
    // --- 2. IL CICLO DO-WHILE (Controllo alla fine) ---
    // Esegue il codice ALMENO UNA VOLTA, e poi controlla la condizione.
    cout << "=== 2. Ciclo Do-While ===\n";
    int k = 0;
    do{
        cout << "Questo è l'iterazione numero del ciclo do-while: " << k << "\n";
        k++;
    }while (k <= 5);
    cout << "\n";
    
    // --- 3. APPLICAZIONE PRATICA: GIOCO DEL NUMERO SEGRETO ---
    cout << "=== 3. Gioco: Indovina il Numero Segreto ===\n";
    int numeroSegreto = 5;
    int numeroUtente;
    int tentativi = 0;
    const int maxTentativi = 3;

    do{
        cout << "Tentativo " << (tentativi + 1) << "/" << maxTentativi << " - Indovina il numero: ";
        cin >> numeroUtente;
        
        if (numeroUtente == numeroSegreto){
            cout << "Complimenti, HAI VINTO!\n";
            break;
        }else{
            tentativi += 1;
            if (tentativi < maxTentativi) {
                cout << "Sbagliato! Riprova...\n\n";
            }
        }
        // Il ciclo continua FINCHÉ i tentativi fatti 
        // sono MINORI di quelli massimi consentiti
    } while (tentativi < maxTentativi);

    // Se usciamo dal ciclo e l'utente NON ha indovinato il numero
    if (numeroUtente != numeroSegreto) {
        cout << "\nHai terminato i tentativi! Il numero segreto era: " << numeroSegreto << ". GAME OVER.\n";
    }
    
    return 0;
}