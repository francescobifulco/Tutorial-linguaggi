#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// ==========================================
// 1. DEFINIZIONE DELLA CLASSE BASE
// ==========================================
class Eroe {
// ENCAPSULATION (Incapsulamento): Proteggiamo i dati sensibili.
// Questi attributi sono accessibili SOLO dall'interno della classe stessa.
private:
    string nome;
    int salute;
    int livello;

// Tutto ciò che si trova sotto 'public' è accessibile anche dal main().
public:
    // CONSTRUTTORE (Constructor): Il metodo speciale che viene chiamato 
    // automaticamente quando creiamo un nuovo oggetto (istanza).
    Eroe(string nomeEroe, int saluteIniziale) {
        nome = nomeEroe;
        salute = saluteIniziale;
        livello = 1; // Impostiamo un valore iniziale di default
        cout << "[Costruttore] E' nato l'eroe: " << nome << "!\n";
    }

    // DISTRUTTORE (Destructor): Si attiva automaticamente quando l'oggetto muore 
    // o esce dallo scope (ha una tilde '~' davanti). Utile per pulire la memoria.
    ~Eroe() {
        cout << "[Distruttore] L'eroe " << nome << " ha lasciato il mondo.\n";
    }

    // GETTER: Metodo pubblico per LEGGERE un dato privato in modo sicuro
    string getNome() const { 
        return nome; 
    }
    
    int getSalute() const { 
        return salute; 
    }

    // SETTER: Metodo pubblico per MODIFICARE un dato privato con dei controlli di sicurezza
    void subisciDanno(int danno) {
        if (danno > 0) {
            salute -= danno;
            if (salute < 0) salute = 0;
            cout << nome << " subisce " << danno << " danni! Salute rimasta: " << salute << "\n";
        }
    }

    // METODO NORMALE (Azione dell'oggetto)
    // Usiamo 'virtual' per permettere il POLIMORFISMO (le classi figlie potranno modificarlo)
    virtual void attacca() {
        cout << nome << " sferra un attacco base!\n";
    }
};


// ==========================================
// 2. INHERITANCE (Ereditarietà)
// ==========================================
// La classe 'Guerriero' eredita tutte le proprietà e i metodi pubblici di 'Eroe'
class Guerriero : public Eroe {
private:
    int forzaFisica;

public:
    // Il costruttore del figlio deve richiamare il costruttore del padre tramite la "lista di inizializzazione" (: Eroe(...))
    Guerriero(string nomeEroe, int saluteIniziale, int forza) : Eroe(nomeEroe, saluteIniziale) {
        forzaFisica = forza;
    }

    // POLYMORPHISM (Polimorfismo / Override): 
    // Ridefiniamo il metodo 'attacca' specificatamente per il Guerriero usando la parola chiave 'override'
    void attacca() override {
        cout << getNome() << " solleva lo spadone e sferra un COLPO CRITICO da " << forzaFisica << " danni!\n";
    }
};


// ==========================================
// CONTESTO PRINCIPALE (MAIN)
// ==========================================
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");
    
    cout << "=== 1. Creazione di Istanze (Oggetti) ===\n";
    // Creiamo un oggetto base
    Eroe eroeBase("Luke", 100);
    eroeBase.attacca();
    
    // Proviamo a modificare la salute direttamente? eroeBase.salute = 0; -> ERRORE! E' private.
    // Usiamo il metodo sicuro (Setter):
    eroeBase.subisciDanno(30);
    cout << "\n";

    cout << "=== 2. Test dell'Ereditarieta' e Polimorfismo ===\n";
    // Creiamo un oggetto della classe figlia
    Guerriero guerriero1("Guts", 150, 45);
    
    // Il Guerriero può usare i metodi del padre (Ereditarietà)
    guerriero1.subisciDanno(20); 
    
    // Il Guerriero attacca a modo suo (Polimorfismo / Override)
    guerriero1.attacca(); 
    cout << "\n";

    cout << "=== 3. Chiusura del Programma (Uscita dallo Scope) ===\n";
    // Qui il main sta per finire: guardiamo i distruttori entrare in azione automaticamente!
    return 0;
}