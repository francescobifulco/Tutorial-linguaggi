/*Obiettivo: std::vector, Struct e iteratori.
Cosa fare: Crea una struct Studente con attributi 
nome (stringa) e mediaVoti (double). Nel main, crea un vector di questa struct.
Logica:
Aggiungi in coda (push_back) 3 studenti a tua scelta.
Usa il metodo .insert() per inserire un nuovo studente 
in seconda posizione (indice 1).
Stampa l'elenco completo usando un ciclo Range-based for (foreach).
Usa il metodo .erase() per rimuovere l'ultimo studente della 
lista sfruttando gli iteratori (.begin() o .end()).*/


#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

struct Studente {
    string nome;
    double mediaVoti;
};

int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    vector<Studente> listaStudenti;

    cout << "=== 1. Inserimento iniziale di 3 Studenti ===\n";
    for (int i = 0; i < 3; i++) {
        Studente nuovoStudente;
        cout << "Inserisci il nome dello studente " << i + 1 << ": ";
        cin >> nuovoStudente.nome;
        cout << "Inserisci la sua media voti: ";
        cin >> nuovoStudente.mediaVoti;
        
        listaStudenti.push_back(nuovoStudente);
        cout << "-----------------------------------\n";
    }

    cout << "\n=== 2. Inserimento in seconda posizione (Indice 1) tramite .insert() ===\n";
    Studente studenteSpeciale;
    cout << "Inserisci il nome dello studente da inserire in seconda posizione: ";
    cin >> studenteSpeciale.nome;
    cout << "Inserisci la sua media voti: ";
    cin >> studenteSpeciale.mediaVoti;

    listaStudenti.insert(listaStudenti.begin() + 1, studenteSpeciale);


    cout << "\n=== 3. Stampa dell'elenco completo (Range-based for) ===\n";
    for (const Studente& s : listaStudenti) {
        cout << "- Studente: " << s.nome << " | Media Voti: " << s.mediaVoti << "\n";
    }


    cout << "\n=== 4. Eliminazione dell'ultimo studente tramite .erase() ===\n";
    if (!listaStudenti.empty()) {
        listaStudenti.erase(listaStudenti.end() - 1);
        cout << "[OK] Ultimo studente rimosso con successo.\n";
    }


    cout << "\n=== 5. Elenco Finale Aggiornato ===\n";
    for (const Studente& s : listaStudenti) {
        cout << "- Studente: " << s.nome << " | Media Voti: " << s.mediaVoti << "\n";
    }

    return 0;
}