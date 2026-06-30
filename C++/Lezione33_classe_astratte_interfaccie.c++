#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// === CLASSE ASTRATTA ===
class Persona {
public:
    string nome;
    string cognome;
    int eta;

    Persona(string nome, string cognome) {
        this->cognome = cognome;
        this->nome = nome;
        this->eta = 20;
    }

    // Funzione virtuale pura: obbliga chiunque 
    // erediti da Persona a implementare questo metodo
    virtual void saluta() = 0;
};

// === INTERFACCIA (Classe Astratta Pura) ===
// Contiene solo comportamento (metodi da implementare), nessuna variabile.
class ProvaInterfacce {
    public:
    virtual void saluta() = 0;
};

// Studente "È UNA" Persona e allo stesso tempo "IMPLEMENTA" ProvaInterfacce
class Studente : public Persona, public ProvaInterfacce {
public:
    string classe;

    Studente(string nome, string cognome, string classe) : Persona(nome, cognome) {
        this->classe = classe;
    }

    // Questo singolo override soddisfa l'obbligo sia di Persona che di ProvaInterfacce!
    void saluta() override {
        cout << "Ciao, sono lo studente " << nome << " della classe " << classe << "\n";
    }

    void diClasse() {
        cout << "La mia classe e' la " << classe << "\n";
    }
};

int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== 1. Istanza della classe Figlia ===\n";
    Studente studente1("Luca", "Rossi", "4A");
    studente1.saluta();
    studente1.diClasse();
    cout << "Nome: " << studente1.nome << "\n\n"; 

    // --- TENTATIVI CHE PROVOCHEREBBERO ERRORE DI COMPILAZIONE (Giusto così!): ---
    // Persona p("Mario", "Rossi"); --> ERRORE! Impossibile istanziare un oggetto di una classe astratta.
    // ProvaInterfacce pi;        --> ERRORE! Impossibile istanziare un'interfaccia.

    cout << "=== 2. Il Vero Potere: Polimorfismo con i Puntatori ===\n";
    // Creiamo un puntatore del tipo dell'interfaccia, ma lo puntiamo allo studente reale!
    ProvaInterfacce* interfacciaPtr = &studente1;
    
    // Tramite questo puntatore posso chiamare solo i metodi previsti dall'interfaccia
    interfacciaPtr->saluta(); // Esegue correttamente il codice dello Studente!
    
    // interfacciaPtr->diClasse(); --> ERRORE! ProvaInterfacce non sa cosa sia 'diClasse()'.
    return 0;
}
