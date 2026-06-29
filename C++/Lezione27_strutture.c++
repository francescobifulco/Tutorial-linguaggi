#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Definizione dei nostri modelli (Tipi di dato personalizzati)
struct Persona {
    string nome;
    string cognome;
    int eta;
};

struct Libro {
    string titolo, descrizione, anno, autore, coautore, recensione, valutazione;
};

struct File {
    string nome, estensione, data, modifica, percorso;
};

struct Cartella {
    string titolo, percorso, data, modifica;
    string file[5] = {"", "", "", "", ""}; // Inizializzazione corretta di array di stringhe vuote
};

// Lezione 27: La gestione delle Struct in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

cout << "=== 1. Gestione Singole Istanze ===\n";
    
    // Inizializzazione in linea (orizzontale)
    Persona persona1 = {"luca", "rossi", 25};
    
    // Inizializzazione verticale tramite operatore punto (.)
    Persona persona2;
    persona2.nome = "valerio";    // CORRETTO: assegnato a persona2 invece di sovrascrivere persona1
    persona2.cognome = "rocco";
    persona2.eta = 23;

    // Lettura dei dati tramite l'operatore punto
    cout << "Persona 1: " << persona1.nome << " " << persona1.cognome << " (" << persona1.eta << " anni)\n";
    cout << "Persona 2: " << persona2.nome << " " << persona2.cognome << " (" << persona2.eta << " anni)\n\n";


    cout << "=== 2. Combinazione Potente: Vector + Struct ===\n";
    
    // Creiamo un vettore dinamico che può contenere SOLO oggetti di tipo 'Persona'
    vector<Persona> registroAnagrafico;

    // Aggiungiamo le nostre struct al vettore
    registroAnagrafico.push_back(persona1);
    registroAnagrafico.push_back(persona2);
    // Possiamo anche aggiungere una persona al volo senza creare prima la variabile
    registroAnagrafico.push_back({"marco", "verdi", 30});

    // Scorriamo il vettore di struct con un comodissimo ciclo foreach
    for (const Persona& p : registroAnagrafico) {
        cout << "- " << p.nome << " " << p.cognome << ", Eta': " << p.eta << "\n";
    }

    return 0;
}