/*1. Il Calcolatore di Tariffe (Riepilogo Lezioni 1-16)
Obiettivo: Gestire input/output, operatori, logica condizionale e switch.
Cosa fare: Chiedi all'utente di inserire la sua età e il giorno della 
settimana (usa un intero: 1 per lunedì, 2 per martedì, ecc.).
Logica: * Il prezzo base di un biglietto è 10€.
Se il giorno è mercoledì (3), applica uno sconto del 20% a tutti.
Se l'età è minore di 12 anni o maggiore di 65 anni, si applica uno 
sconto del 40% (i due sconti non si sommano, prendi il più vantaggioso).
Se il giorno inserito non è tra 1 e 7, mostra un messaggio di errore 
usando il caso default di uno switch.
Stampa: Il prezzo finale formattato correttamente.*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    std::setlocale(LC_ALL, "it_IT.utf8");

    int eta;
    int scelta;
    const double prezzoBase = 10.0;

    cout << "Inserisci la tua eta: " << "\n";
    cin >> eta;

    cout << "Inserisci il giorno della settimana (1 = Lunedì, ..., 7 = Domenica): " << "\n";
    cin >> scelta;

    double scontoDaApplicare = 0.0;
    switch (scelta){
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
            scontoDaApplicare = 0.0; 
            break;
    
    default: cout << "Errore: Giorno non valido!" << "\n"; break;
    }

    if (eta <= 12 || eta >= 65) {
        if (40.0 > scontoDaApplicare) {
            scontoDaApplicare = 40.0;
        }
    }
    
    double importoSconto = prezzoBase * (scontoDaApplicare / 100.0);
    double prezzoFinale = prezzoBase - importoSconto;

    cout << "\nPercentuale di sconto applicata: " << scontoDaApplicare << "%\n";
    cout << "Il prezzo finale del biglietto è: " << prezzoFinale << "€\n";

    return 0;
}