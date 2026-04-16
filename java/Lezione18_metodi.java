public class Lezione18_metodi {
    public static void main(String[] args) {
        // CHIAMATA SEMPLICE: Esegue il codice dentro il metodo.
        faiPasta();
        
        // CHIAMATA CON PARAMETRO: Passiamo l'informazione "carne" al metodo.
        cucinaPanzo("carne");
        
        // METODO VOID CON PARAMETRI: Esegue il calcolo e stampa lui stesso.
        addizione(5, 10);
        
        // METODO CON RETURN: Il metodo calcola il valore e lo "lancia" indietro.
        // Dobbiamo salvarlo in una variabile (totaleSpeso) per usarlo.
        int totaleSpeso = addizione2(102, 3);
        int prova = addizione2(40, 20);
        
        System.out.println(totaleSpeso);
        System.out.println(prova);
    }

    // 1. METODO VOID (Vuoto): Non riceve nulla e non restituisce nulla.
    static void faiPasta(){
        System.out.println("sto cucinando pasta");
    }

    // 2. METODO CON PARAMETRO: Riceve una Stringa per rendere l'azione dinamica.
    static void cucinaPanzo(String cibo){
        System.out.println("sto cucinando " + cibo);
    }

    // 3. METODO CON PIÙ PARAMETRI: Riceve due interi e stampa la somma.
    static void addizione(int a, int b){
        int riusltato = a + b;
        System.out.println(riusltato);
    }

    // 4. METODO CON RITORNO (int): Sostituiamo 'void' con il tipo di dato che vogliamo ottenere.
    // Usiamo la parola chiave 'return' per far uscire il risultato dal metodo.
    static int addizione2(int a, int b){
        int riusltato = a + b;
        return riusltato; // Finisce qui e riporta il valore al main
    }
}