#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Persona{
    // Attributi con valori di default
    public:
    string nome = "Luca";
    string cognome = "rossi";
    int eta = 25;

    // Metodo 1: Saluto base
    void saluta(){
        cout << "[Metodo Classe] Ciao sono una persona" << "\n";
    }

    // Metodo 2: Overloading di saluta con parametro.
    // L'uso di 'this->nome' indica l'attributo 
    // dell'oggetto, differenziandosi dal parametro 'nome'.
    void saluta(string nome){
        cout << "[Metodo Classe Overload] Ricevuto parametro esterno: " << nome << "\n";
        cout << "[Metodo Classe Overload] Ma l'attributo di questo oggetto (this->nome) e': " << this->nome << "\n";
    }

    // Metodo 3: Saluto usando l'attributo implicitamente
    void saluta1() {
        cout << "[Metodo Classe 1] Ciao sono " << nome << "\n";
    }
};

// FUNZIONE GLOBALE
// Non appartiene alla classe Persona. Vive fuori e può 
// essere chiamata ovunque nel main.
void saluta(string nome) {
    cout << "[Funzione Globale] Ciao sono " << nome << "\n";
}

// Lezione 29: La gestione delle Classi e degli Oggetti in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    // Creazione di due istanze indipendenti
    Persona persona1;
    Persona persona2;

    // Modifica degli attributi pubblici
    persona1.nome = "Marco";
    persona2.nome = "Valerio";

    cout << "=== 1. Lettura degli attributi ===\n";
    cout << "Persona 1 si chiama: " << persona1.nome << "\n";
    cout << "Persona 2 si chiama: " << persona2.nome << "\n\n";

    cout << "=== 2. Test Funzione Globale vs Metodi ===\n";
    // Chiama la funzione globale fuori dalla classe
    saluta(persona1.nome); 
    cout << "\n";

    cout << "=== 3. Test esecuzione Metodi di Classe ===\n";
    // Chiama il metodo base di persona1 ("Marco")
    persona1.saluta(); 
    cout << "------------------------\n";

    // Chiama il metodo in overload di 
    // persona2 ("Valerio") passando il suo stesso nome
    persona2.saluta(persona2.nome); 
    cout << "------------------------\n";

    // Chiama il metodo saluta1 di persona1 ("Marco")
    persona1.saluta1(); 
    cout << "------------------------\n";

    // Chiama il metodo in overload di persona1 
    // ("Marco") passando una stringa casuale "x"
    persona1.saluta("x");
    return 0;
}