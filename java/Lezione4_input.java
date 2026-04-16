// IMPORT: Fondamentale! Java non carica tutto subito per risparmiare memoria. 
// Dobbiamo dire esplicitamente che vogliamo usare lo strumento Scanner.
import java.util.Scanner;

public class Lezione4_input {
    public static void main(String[] args){
        
        // CREAZIONE DELLO SCANNER: 
        // Creiamo un oggetto chiamato 'scan' che legge dall'ingresso standard (System.in, cioè la tastiera).
        Scanner scan = new Scanner(System.in);

        // INPUT STRINGA (Nome)
        System.out.println("Qual'è il tuo nome? ");
        String nome = scan.nextLine(); // Legge un'intera riga di testo

        // INPUT STRINGA (Cognome)
        System.out.println("Qual'è il tuo cognome? ");
        String cognome = scan.nextLine();

        // INPUT NUMERICO (Età)
        System.out.println("Qual'è la tua eta? ");
        int eta = scan.nextInt(); 
        
        /* 
         * IL TRUCCO DEL NEXTLINE VUOTO:
         * Quando premiamo "Invio" dopo un numero (nextInt), rimane un carattere di "a capo" (\n) nascosto.
         * Se non mettiamo questo scan.nextLine() a vuoto, il prossimo scan.nextLine() 
         * leggerebbe l'invio e non ci permetterebbe di scrivere la città.
         */
        scan.nextLine(); 
        
        // INPUT STRINGA (Città)
        System.out.println("dove abiti? ");
        String citta = scan.nextLine();

        // OUTPUT FINALE: Concatenazione di stringhe e variabili
        System.out.println("---------------------------");
        System.out.println("ciao " + nome + " " + cognome);
        System.out.println("Hai " + eta + " anni");
        System.out.println("Vivi a " + citta);
    }
}
