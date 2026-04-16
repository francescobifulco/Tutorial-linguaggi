public class Lezione12_ciclo_for {
    public static void main(String[] args) {
        
        // --- 1. IL FOR CLASSICO ---
        // Struttura: (inizializzazione; condizione; incremento)
        // Utile quando sai esattamente quante volte ripetere (qui 5 volte).
        for(int i = 0; i < 5; i++) {
            System.out.println("for " + i);
        }

        // --- 2. CICLI ANNIDATI (Nested Loops) ---
        // Per ogni giro del ciclo esterno (i), il ciclo interno (j) completa tutti i suoi giri.
        // Risultato totale: 5 righe * 5 colonne = 25 stampe.
        for(int i = 0; i < 5; i++) {
            System.out.println("riga " + i);
            for(int j = 0; j < 5; j++){
                System.out.println("colonna " + j);
            }
        }

        // --- 3. FOR-EACH (Enhanced For Loop) ---
        // Si usa per scorrere gli Array (liste di dati).
        // Dice: "Per ogni 'numero' dentro l'array 'numeri', esegui il codice".
        int[] numeri = {10, 20, 30, 40, 50};
        for (int numero : numeri) {
            System.out.println("Elemento array: " + numero);
        }

        // --- 4. BREAK ---
        // Interrompe immediatamente il ciclo e "scappa" fuori.
        // Nota: nel tuo codice avevi 'if(1 == 4)', che è sempre falso. 
        // Se fosse 'if(i == 4)', il ciclo si fermerebbe al quarto giro.
        for(int i = 0; i < 5; i++){
            if(i == 4){ 
                break; 
            }
            System.out.println("break " + i);
        }

        // --- 5. CONTINUE ---
        // Non ferma il ciclo, ma salta solo il giro attuale e passa al prossimo.
        for(int i = 0; i < 5; i++){
            if(i == 2){ 
                continue; // Salta la stampa quando i è 2
            }
            System.out.println("continue " + i);
        }
    }
}