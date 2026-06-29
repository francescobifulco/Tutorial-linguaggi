#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Persona {
    public:
    string nome = "Luca";
    string cognome = "rossi";
    int eta = 25;

    // 1. Costruttore di Default (Senza parametri)
    // Sovrascrive i valori iniziali se non viene passato nulla
    Persona(){
        nome = "sconosciuto";
        cognome = "sconosciuto";
        eta = 100;
    }

    // 2. Costruttore con 1 parametro
    Persona(string nome){
        this->nome = nome;
        this->cognome = "sconosciuto";
        this->eta = 0;
    }

    // 3. Costruttore con 2 parametri
    Persona(string nome, string cognome){
        this->nome = nome;
        this->cognome = cognome;
        this->eta = 0;
    }

    // 4. Costruttore completo con 3 parametri
    Persona(string nome, string cognome, int eta){
        this->nome = nome;
        this->cognome = cognome;
        this->eta = eta;
    }

    void saluta() {
        cout << "- Ciao, sono " << nome << " " << cognome << " (Eta': " << eta << ")" << "\n";
    }
};



// Lezione 30: La gestione del costruttutore in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== Test Inizializzazione con Costruttori ===\n\n";

    // Ciascuna istanza chiama un costruttore diverso in base ai parametri passati
    Persona persona1("Luca");                   // Chiama il costruttore (1 parametro)
    Persona persona2("Valerio", "Verdi", 30);   // Chiama il costruttore completo (3 parametri)
    Persona persona3("Ciro", "Esposito");       // Chiama il costruttore (2 parametri)
    Persona persona4;                           // Chiama il costruttore di Default (Nota: SENZA parentesi tonde!)

    // Verifichiamo i saluti nel terminale
    persona1.saluta();
    persona2.saluta();
    persona3.saluta();
    persona4.saluta();

    return 0;
}