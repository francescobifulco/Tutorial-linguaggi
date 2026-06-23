#include <iostream>
#include <string>
#include <cmath> // Libreria standard per le funzioni matematiche come sqrt()

using std::cout; 
using std::cin;
using std::string;

// Lezione 8: Come lavorare con i numeri in C++
int main() {

    // --- 1. OPERATORI ARITMETICI BASE ---
    int x = 5 + 5;
    cout << "=== Operatori Base ===\n";
    cout << "Somma diretta (5 + 5): " << x << "\n";
    
    int y = 5;
    int z = x + y; // Somma usando variabili
    cout << "Somma di variabili (x + y): " << z << "\n";
    
    // L'operatore modulo (%) restituisce il resto della divisione intera.
    // 10 diviso 4 fa 2, con il resto di 2.
    cout << "Modulo / Resto (10 % 4): " << 10 % 4 << "\n\n";


    // --- 2. PRECEDENZA DELLE OPERAZIONI ---
    // Senza parentesi, la moltiplicazione (*) e la divisione (/) hanno la precedenza sulla somma (+).
    // Calcolo: 5 * 15 = 75 -> 75 / 10 = 7 (divisione intera) -> 10 + 7 = 17
    int w = x + y * z / x;
    cout << "=== Precedenza Matematica ===\n";
    cout << "Senza parentesi (x + y * z / x): " << w << "\n";

    // Con le parentesi forziamo il computer a calcolare prima la somma.
    // Calcolo: (10 + 5) = 15 -> 15 * 15 = 225 -> 225 / 10 = 22
    int k = (x + y) * z / x;
    cout << "Con parentesi ((x + y) * z / x): " << k << "\n\n";


    // --- 3. INCREMENTO E DECREMENTO ---
    int eta = 20;
    cout << "=== Incremento e Decremento ===\n";
    cout << "Eta' di partenza: " << eta << "\n";
    
    eta++; // Post-incremento (eta diventa 21)
    ++eta; // Pre-incremento (eta diventa 22)
    cout << "Dopo due incrementi (eta++ e ++eta): " << eta << "\n";

    --eta; // Pre-decremento (eta diventa 21)
    eta--; // Post-decremento (eta diventa 20)
    cout << "Dopo due decrementi (--eta e eta--): " << eta << "\n\n";


    // --- 4. LA DIFFERENZA SOTTILE: PRE vs POST INCREMENTO ---
    cout << "=== Differenza Pre vs Post ===\n";
    
    // PRE-INCREMENTO (++eta): Prima incrementa il valore di eta, POI lo assegna.
    // eta diventa 21, e poi 21 viene assegnato a eta_incrementata.
    int eta_incrementata = ++eta;
    cout << "Uso di ++eta (Pre) -> eta_incrementata: " << eta_incrementata << ", eta attuale: " << eta << "\n";

    // POST-INCREMENTO (eta++): Prima assegna il valore attuale, POI incrementa eta.
    // eta_incrementata prende il valore attuale di eta (21), e DOPO eta diventa 22.
    eta_incrementata = eta++;
    cout << "Uso di eta++ (Post) -> eta_incrementata: " << eta_incrementata << ", eta attuale: " << eta << "\n\n";


    // --- 5. ASSEGNAMENTO COMPOSTO ---
    cout << "=== Assegnamento Composto ===\n";
    eta = 20;
    eta = eta + 5; // Metodo classico
    cout << "Metodo classico (eta = eta + 5): " << eta << "\n";

    eta += 5; // Scorciatoia (fa esattamente la stessa cosa, aggiunge 5 a eta)
    cout << "Scorciatoia (eta += 5): " << eta << "\n\n";


    // --- 6. FUNZIONI MATEMATICHE ASTRATTE (cmath) ---
    // std::sqrt() calcola la radice quadrata. Poiché 30 non è un quadrato perfetto, 
    // l'output mostrerà automaticamente la parte decimale anche se eta è un intero.
    cout << "=== Funzioni da <cmath> ===\n";
    cout << "Radice quadrata di eta (" << eta << "): " << std::sqrt(eta) << "\n";

    return 0;
}