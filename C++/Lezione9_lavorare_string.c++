#include <iostream>
#include <string> // Essenziale per usare l'oggetto string e funzioni come stoi()

using std::cout; 
using std::cin;
using std::string;

// Lezione 9: Gestione con le string in C++
int main(){

    // --- 1. ASSEGNAZIONE E ACCESSO AI CARATTERI ---
    cout << "=== 1. Accesso e Modifica Caratteri ===\n";
    string eta = "luca"; // Nota: anche se si chiama 'eta', contiene testo
    cout << "Valore iniziale: " << eta << "\n";

    eta = "rossi";
    cout << "Dopo la riassegnazione: " << eta << "\n";

    // Le stringhe sono array di caratteri (indicizzati da 0). Usa gli apici singoli '' per i singoli char.
    eta[0] = 'R'; 
    cout << "Dopo la modifica del primo carattere (eta[0] = 'R'): " << eta << "\n";

    // Leggiamo un singolo carattere specifico (la terza lettera, indice 2)
    cout << "Il carattere all'indice 2 (eta[2]): " << eta[2] << "\n\n";

    // --- 2. CONCATENAZIONE ---
    cout << "=== 2. Concatenazione ===\n";
    string nome = "Valerio";
    string cognome = "Esposito";

    // Uniamo le stringhe usando l'operatore '+'
    string nome_completo = nome + " " + cognome;
    cout << "Nome completo concatenato: " << nome_completo << "\n";

    // Il metodo .append() attacca del testo direttamente alla fine della stringa originaria
    nome_completo.append(" ciao");
    cout << "Dopo il metodo .append(\" ciao\"): " << nome_completo << "\n\n";

    // --- 3. CONVERSIONE (Casting da Stringa a Intero) ---
    cout << "=== 3. Conversione con stoi() ===\n";
    string nome2 = "30";
    // stoi significa "String To Integer". Converte il testo numerico in un int matematico.
    int nuovo_nome = std::stoi(nome2) + std::stoi("25"); 
    cout << "Risultato della somma matematica (30 + 25): " << nuovo_nome << "\n\n"; // Sistemata la variabile di stampa

   // --- 4. LUNGHEZZA E INDICI ---
    cout << "=== 4. Lunghezza e Dimensione ===\n";
    // .size() e .length() fanno esattamente la stessa cosa: restituiscono il numero di caratteri.
    cout << "Lunghezza con .size(): " << nome_completo.size() << "\n";
    cout << "Lunghezza con .length(): " << nome_completo.length() << "\n";

    // Trucco per prendere l'ultimo carattere di una stringa dinamica (lunghezza - 1)
    cout << "Ultimo carattere del nome '" << nome << "': " << nome[nome.length() - 1] << "\n\n";
    
    // --- 5. PULIZIA E CONTROLLO ERRORE ---
    cout << "=== 5. Clear ed Empty ===\n";
    string x = "ciao";
    x.clear(); // Svuota completamente la stringa
    cout << "Stringa 'x' dopo x.clear(): \"" << x << "\"\n";
    // .empty() restituisce un booleano: true (1) se la stringa è vuota, false (0) se contiene qualcosa.
    cout << "La stringa 'x' e' vuota? (.empty()): " << x.empty() << " (Significa True/Sì)\n\n";
    
    // --- 6. FUNZIONI AVANZATE (Ricerca, Sottostringhe, Sostituzione) ---
    cout << "=== 6. Metodi Avanzati ===\n";
    // .find() cerca la posizione di un carattere o parola. Restituisce l'indice (0-based).
    // In "Valerio", la 'a' è la seconda lettera $\rightarrow$ indice 1.
    cout << "Posizione della 'a' in '" << nome << "': " << nome.find('a') << "\n";

    // .substr(posizione_inizio, quanti_caratteri) estrae una porzione di testo
    // Prende 4 caratteri partendo dall'indice 1
    cout << "Estratto .substr(1, 4) di '" << nome_completo << "': " << nome_completo.substr(1, 4) << "\n";
    
    // Se metti solo l'indice di inizio, taglia da lì fino alla fine della stringa
    cout << "Estratto .substr(1) (fino alla fine): " << nome_completo.substr(1) << "\n";
    
    // Taglia escludendo il primo carattere e gli ultimi due
    cout << "Estratto dinamico .substr(1, length - 2): " << nome_completo.substr(1, nome_completo.length() - 2) << "\n";

    // .replace(da_dove_iniziare, quanti_caratteri, "nuovo_testo") sostituisce una porzione
    cout << "Dopo il .replace(1, 3, \"rio\"): " << nome_completo.replace(1, 3, "rio") << "\n";

    return 0;
}