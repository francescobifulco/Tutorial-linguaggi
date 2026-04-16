public class Lezione7_operatori_comparazione {
    public static void main(String[] args) {
        
        // MAGGIORE (>): Controlla se il primo numero è più grande del secondo.
        // 3 è maggiore di 10? No.
        boolean risultato = 3 > 10;
        System.out.println("3 > 10 è: " + risultato); // Stampa false

        // MAGGIORE O UGUALE (>=): Vero se il numero è più grande o esattamente uguale.
        // 33 è maggiore o uguale a 10? Sì.
        risultato = 33 >= 10;
        System.out.println("33 >= 10 è: " + risultato); // Stampa true
        
        // MINORE O UGUALE (<=): Vero se il numero è più piccolo o esattamente uguale.
        // 9 è minore o uguale a 10? Sì.
        risultato = 9 <= 10;
        System.out.println("9 <= 10 è: " + risultato); // Stampa true

        // UGUAGLIANZA (==): ATTENZIONE! Si usano due simboli uguale. 
        // Un solo '=' serve ad assegnare un valore, due '==' servono a confrontare.
        // 11 è uguale a 10? No.
        risultato = 11 == 10;
        System.out.println("11 == 10 è: " + risultato); // Stampa false

        // DIVERSO (!=): Il punto esclamativo in Java spesso significa "NOT" (non).
        // 11 è diverso da 10? Sì.
        risultato = 11 != 10;
        System.out.println("11 != 10 è: " + risultato); // Stampa true
    }
}