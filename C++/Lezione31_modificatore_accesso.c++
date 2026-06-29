#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Persona {
    // --- 1. ACCESSO PUBBLICO ---
    // Visibile ovunque: sia dentro la classe, sia dalle classi 
    // figlie, sia all'esterno (nel main)
    public:
    string nome;
    string cognome;
    int eta;

    Persona(string nome, string cognome, int eta) {
        this->nome = nome;
        this->cognome = cognome;
        this->eta = eta;
    }

    // Metodo pubblico che fa da "ponte" (interfaccia) 
    // per attivare funzioni private
    void provaSaluto(){
        saluta(); // Può farlo perché si trova dentro la classe
    }

    // --- 2. ACCESSO PRIVATO ---
    // Visibile ESCLUSIVAMENTE all'interno di questa classe. 
    // Nemmeno le classi figlie che ereditano da Persona 
    // potranno toccarlo direttamente.
    private:
    void saluta() {
        cout << "- Ciao, sono " << nome << " " << cognome << " (Eta': " << eta << ")\n";
    }

    // --- 3. ACCESSO PROTETTO ---
    // Una via di mezzo: si comporta come 'private' per il mondo 
    // esterno (il main non può leggerlo),
    // ma si comporta come 'public' per le classi figlie 
    // che erediteranno da questa classe!
    protected:
    string prova;
    
};


// Lezione 31: I modificatori di Accesso nelle Classi in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== Test Modificatori di Accesso ===\n\n";

    Persona persona2("Valerio", "Verdi", 30);
    
    // 1. Chiamata a metodo pubblico (che chiama internamente quello privato) -> FUNZIONA
    persona2.provaSaluto();

    // 2. Accesso a una variabile pubblica -> FUNZIONA
    cout << "Accesso pubblico diretto al nome: " << persona2.nome << "\n\n";

    // --- COSA PROVOCHEREBBE UN ERRORE DI COMPILAZIONE: ---
    // persona2.saluta(); --> ERRORE! 'saluta' è private in questo contesto.
    // persona2.prova = "test"; --> ERRORE! 'prova' è protected in questo contesto.

    return 0;
}