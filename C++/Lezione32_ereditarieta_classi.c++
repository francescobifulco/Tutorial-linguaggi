#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// === CLASSE PADRE ===
class Persona {
public:
    string nome;
    string cognome;
    int eta;

    Persona(string nome, string cognome){
        this->cognome = cognome;
        this->nome = nome;
        this->eta = 20;
    }

    void saluta(){
        cout << "Ciao, sono una persona e mi chiamo " << nome << "\n";
    }

};

// === 1. EREDITARIEATÀ PUBBLICA (Il tuo codice) ===
// Tutto ciò che è public in Persona rimane public in Studente
class Studente : public Persona{
    public:
    string classe;
    
    // Uso corretto della lista di inizializzazione per il costruttore padre
    Studente(string nome, string cognome, string classe) : Persona(nome, cognome) {
        this->classe = classe;
    }

    // Override del metodo saluta()
    void saluta() {
        cout << "Ciao, sono lo studente " << nome << " della classe " << classe << "\n";
    }

    void diClasse() {
        cout << "La mia classe e' la " << classe << "\n";
    }
};

// === 2. EREDITARIEATÀ PRIVATA (Nuovo esempio) ===
// nome, cognome, eta e saluta() diventano PRIVATE dentro Insegnante.
class Insegnante : private Persona {
public:
    string materia;

    Insegnante(string nome, string cognome, string materia) : Persona(nome, cognome) {
        this->materia = materia;
    }

    // Il main NON può chiamare direttamente saluta() di Persona,
    // quindi creiamo un metodo pubblico interno che fa da ponte.
    void siPresenta() {
        cout << "Buongiorno, sono il docente di " << materia << ".\n";
        // Posso ancora usare i dati del padre al mio interno? ASSOLUTAMENTE SÌ!
        cout << "Il mio nome e' " << nome << " " << cognome << ".\n"; 
        saluta(); // Chiamata interna al metodo del padre, che qui è diventato privato
    }
};

// Lezione 32: La gestione del ereditarieta delle classi in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== 1. Test Ereditarieta' Pubblica ===\n";
    Studente studente1("Luca", "Rossi", "4A");
    
    // FUNZIONA: 'saluta' e 'diClasse' sono pubblici
    studente1.saluta();
    studente1.diClasse();
    // FUNZIONA: 'nome' è pubblico in Persona e resta pubblico in Studente
    cout << "Nome studente accessibile dal main: " << studente1.nome << "\n\n"; 


    cout << "=== 2. Test Ereditarieta' Privata ===\n";
    Insegnante prof1("Mario", "Bianchi", "Informatica");

    // FUNZIONA: siPresenta() è un metodo esplicitamente pubblico di Insegnante
    prof1.siPresenta();

    // --- COSA PROVOCHEREBBE ERRORE DI COMPILAZIONE SE DECOMMENTATO: ---
    // prof1.saluta();  --> ERRORE! 'saluta' è privato dentro Insegnante.
    // cout << prof1.nome; --> ERRORE! 'nome' è privato dentro Insegnante.
    return 0;


}