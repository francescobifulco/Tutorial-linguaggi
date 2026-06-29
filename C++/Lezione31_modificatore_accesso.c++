#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Persona {
    public:
    string nome;
    string cognome;
    int eta;

    Persona(string nome, string cognome, int eta) {
        this->nome = nome;
        this->cognome = cognome;
        this->eta = eta;
    }

    void provaSaluto(){
        saluta();
    }

    private:
    void saluta() {
        cout << "- Ciao, sono " << nome << " " << cognome << " (Eta': " << eta << ")\n";
    };

    protected:
    string prova;
    
};


// Lezione 31: I modificatori di Accesso nelle Classi in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    Persona persona2("Valerio", "Verdi", 30);
    persona2.provaSaluto();

    cout << persona2.nome << "\n";

    return 0;
}