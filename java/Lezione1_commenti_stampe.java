// Definizione della classe principale. 
// In Java, tutto il codice deve trovarsi all'interno di una classe.
public class Lezione1_commenti_stampe {

    // Questo è il metodo "main". È il punto di partenza di ogni programma Java.
    // Senza questo metodo, il computer non saprebbe da dove iniziare l'esecuzione.
    public static void main(String[] args){
        
        // COMMENTO SINGOLO: Inizia con // e serve per brevi note su una riga.
        // questo e un commento
        
        // System.out.print: visualizza il testo tra virgolette nella console.
        // \n: è un carattere speciale chiamato "newline". Sposta il cursore a capo.
        System.out.print("ciao da main \n");
        System.out.print("ciao da seconda riga \n");

        System.out.print("ciao da seconda riga \n");
        
        // Qui non c'è il \n finale, quindi se aggiungessi altro testo dopo, 
        // verrebbe scritto sulla stessa riga di questo messaggio.
        System.out.print("ciao da seconda riga 2");

        /* COMMENTO MULTI-RIGA: 
           Inizia con /* e finisce con */ 
        /* commenti da 
           piu righe */
    } // Chiude il metodo main
} // Chiude la classe Lezione1