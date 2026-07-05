/*Obiettivo: OOP, Classi astratte, Interfacce, Ereditarietà 
Multipla e Funzioni Lambda.
Cosa fare: 1. Crea un'interfaccia (classe astratta pura) 
Incantatore con un metodo virtuale puro virtual void scagliaMagia() = 0;.
2. Crea una classe base astratta Personaggio con attributi 
pubblici nome e puntiVita, un costruttore personalizzato e 
un metodo virtual void mostraStato() = 0;.
3. Crea una classe figlia Mago che eredita sia da Personaggio 
che da Incantatore. Implementa (fai l'override) di entrambi i 
metodi richiesti usando il puntatore this->.
4. Nel main, crea un vettore di interi con i danni inflitti 
dalle magie {15, 30, 45}. Usa una funzione Lambda per 
raddoppiare tutti i danni dentro il vettore prima di stamparli.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Incantatore{
    public:
    virtual void scagliaMagia() = 0;
};

class Personaggio{
    public:
    string nome;
    int puntiVita;

    Personaggio(string nome, int puntiVita){
        this->nome = nome;
        this->puntiVita = puntiVita;
    }

    virtual void mostraStato() = 0;

};

class Mago : public Personaggio, public Incantatore{
    public:
    int danni;

    Mago(string nome, int puntiVita, int danni) : Personaggio(nome, puntiVita){
        this->danni = danni;
    }
    
    void scagliaMagia() override{
        cout << "[MAGIA] " << this->nome << " scaglia una palla di fuoco infliggendo " << this->danni << " danni!" << "\n";
    }

    void mostraStato() override{
        cout << "[STATO] " << this->nome << " ha attualmente " << this->puntiVita << " PV." << "\n";
    }
};


int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    vector<int> danniInflitti = {15, 30, 45};

    string nomeMago = "Gandalf";
    int hpMago = 150;
    int dannoMago = 35;

    Mago pergo1(nomeMago, hpMago, dannoMago);
    pergo1.scagliaMagia();
    pergo1.mostraStato();

    auto danniRadoppiati = [](int radoppio){
        return radoppio * 2;
    };

    for(int i = 0; i < danniInflitti.size(); i++){
        danniInflitti[i] = danniRadoppiati(danniInflitti[i]);
        cout << "Danno incantesimo " << i + 1 << " raddoppiato: " << danniInflitti[i] << "\n";
    }

    return 0;
}