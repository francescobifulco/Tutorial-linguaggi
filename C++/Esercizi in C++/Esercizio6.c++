/*Obiettivo: Gestione dei File (ofstream/ifstream),
modalità di apertura, sleep_for ed Eccezioni (try-catch).
Cosa fare: Crea una funzione chiamata scriviLog che
accetta una stringa di testo.
Logica:
All'interno della funzione, prova ad aprire un file chiamato
registro.txt in modalità Append (ios::app).
Se il file non si apre, lancia un'eccezione di tipo runtime_error.
Se si apre, scrivi la stringa di testo seguita da un a capo, e chiudi il file.
Nel main, avvolgi la chiamata a questa funzione dentro un blocco try-catch.
Scrivi nel log "Avvio programma".
Metti in pausa il programma per 2 secondi con this_thread::sleep_for.
Scrivi una seconda riga nel log "Chiusura programma".
Leggi tutto il contenuto del file e stampalo a schermo per confermare
che l'operazione sia riuscita. */

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include <clocale>

using namespace std;

void scriviLog(){
    ofstream outputFile("registro.txt", ios::app);
    if (outputFile.is_open()){
        outputFile << "Questa riga viene AGGIUNTA in fondo grazie a ios::app\n";
        cout << "[OK] Testo aggiunto in coda.\n";
        cout << "Chiusura programma" << "\n";
        outputFile.close();
    } else{
        throw runtime_error("Impossibile accedere o aprire il file 'registro.txt'");
    } 
}

int main()
{
    std::setlocale(LC_ALL, "it_IT.utf8");

    try{
        cout << "\n[ATTESA] Il programma si ferma per 2 secondi...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "[ATTESA] Ripresa dell'esecuzione!\n\n";
        scriviLog();
    }
    catch(runtime_error& e)
    {
        cerr << "[ERRORE DI SISTEMA INTERCETTATO]: " << e.what() << '\n';
    }
    
    ifstream inputFile("registro.txt");
    
    if (inputFile.is_open()) {
        string riga;
        cout << "--- Contenuto attuale di 'registro.txt': ---\n";
        while (getline(inputFile, riga)) {
            cout << riga << "\n";
        }
        cout << "--------------------------------------------\n";
        inputFile.close();
    } else {
        cout << "Errore: Impossibile leggere il file dei log.\n";
    }

    return 0;
}
