#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// Lezione 14: Lo Swith in C++
int main(){

    std::setlocale(LC_ALL, "it_IT.utf8");

    int giorno;

    cout << "Scrivi un numero da 1-7 che rappresenta la settimana: ";
    cin >> giorno;

    cout << "\n===============================" << "\n";
    cout << "Risultato dello Switch:\n";

    // Lo switch valuta la variabile 'giorno' e salta 
    // direttamente al case corrispondente
    switch (giorno){
    case 1:
        cout << "Lunedì" << "\n";
        break; // Il break impedisce al codice di scivolare nei case successivi
    case 2:
        cout << "Martedì" << "\n";
        break;
    case 3:
        cout << "Mercoledì" << "\n";
        break;
    case 4:
        cout << "Giovedì" << "\n";
        break;
    case 5:
        cout << "Venerdiì" << "\n";
        if(giorno % 2 != 0){
            cout << "è un giorno dispari" << "\n";
        }
        break;
    case 6:
        cout << "Sabato" << "\n";
        break;
    case 7:
        cout << "Domenica" << "\n";
        break;
    case 0:
        cout << "Giorno non valido (la settimana inizia da 1)" << "\n";
        break;
    default:
       // Il default scatta se il valore inserito non corrisponde a NESSUNO dei case precedenti
       cout << "ERRORE: Il valore '" << giorno << "' inserito non esiste nel calendario." << "\n";
       break;
    }
    cout << "===============================\n";

    return 0;
}