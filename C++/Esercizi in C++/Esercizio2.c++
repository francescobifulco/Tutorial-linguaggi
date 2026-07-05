/*Obiettivo: Loop (for), array statici, calcolo della lunghezza 
e manipolazione numerica.Cosa fare: Crea un array statico di 
interi contenente 8 voti (es. {6, 7, 4, 8, 5, 9, 6, 10}).Logica: 
Il programma deve scorrere l'array (calcolando la lunghezza 
dinamicamente con il trucco del sizeof):Deve contare quanti 
voti sono sufficienti ($\ge 6$).Deve calcolare la media 
matematica esatta dei voti (attenzione al tipo di dato decimali!).
Deve stampare a schermo se all'interno dell'array è presente almeno 
un 10, interrompendo il ciclo immediatamente con un break non appena 
lo trova.*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    int votiScolastici[8] = {6, 7, 4, 8, 5, 9, 6, 10};
    int lunghezza = sizeof(votiScolastici) / sizeof(int);
    float media;
    int somma = 0;
    int conteggio = 0;

    for(int i = 0; i < lunghezza; i++){
        if (votiScolastici[i] >= 6){
            conteggio ++;
        }
        somma += votiScolastici[i];
    }
    
    media = (float)somma/lunghezza;
    
    cout << "Il totale dei voti sufficienti sono: " << conteggio << "\n";
    cout << "La media dei voti e: " << media << "\n"; 

    int votiScolastici10[8] = {6, 7, 4, 10, 5, 9, 6, 10};
    lunghezza = sizeof(votiScolastici10) / sizeof(int);
    for(int i = 0; i < lunghezza; i++){
        if (votiScolastici10[i] == 10){
            cout << "Ho trovato un 10 all'indice " << i << "! Interrompo la ricerca con il break. Ciao!\n";
            break;
            
        }
    }

    return 0;
}