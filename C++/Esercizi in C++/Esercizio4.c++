/*Obiettivo: Funzioni, passaggi di parametri, scope e puntatori/reference.
Cosa fare: Scrivi una funzione chiamata autentica che accetta tre parametri: 
una stringa per l'username inserito, una stringa per la password e un 
puntatore a booleano (bool* statoLogin).
Logica: * Se l'username è "admin" e la password è "secret123",
modifica il valore puntato da statoLogin impostandolo a true. 
Altrimenti impostalo a false.
Nel main, crea una variabile bool loggato = false;. 
Chiama la funzione passando l'indirizzo di memoria di loggato (&loggato).
Stampa nel main se l'accesso è stato eseguito con successo controllando 
il valore della variabile loggato.*/

#include <iostream>
#include <string>

using namespace std;

void autentica(string username, string password, bool* statoLogin){
    if (username == "admin" && password == "secret123"){
        *statoLogin = true;
    }else{
        *statoLogin = false;
    }
}

int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    bool loggato = false;
    string username;
    string password;

    cout << "Inserire l'username: ";
    cin >> username;
    
    cout << "Inserire la password: ";
    cin >> password;

    autentica(username, password, &loggato);

    if (loggato) {
        cout << "[ACCESSO CONSENTITO] Benvenuto Amministratore!\n";
    } else {
        cout << "[ACCESSO NEGATO] Username o password errati.\n";
    }

    return 0;
}