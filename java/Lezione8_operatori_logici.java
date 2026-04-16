public class Lezione8_operatori_logici {
    public static void main(String[] args) {
        
        // AND (&&): Entrambe le condizioni devono essere VERE.
        // (3 < 10) è TRUE, ma (3 % 2 == 0) è FALSE (3 è dispari).
        // TRUE && FALSE -> Risultato: false.
        boolean x = 3 < 10 && 3 % 2 == 0;
        System.out.println("AND (&&): " + x);

        // OR (||): Basta che ALMENO UNA delle due condizioni sia VERA.
        // (3 < 10) è TRUE. Poiché la prima è vera, il risultato è TRUE 
        // a prescindere dalla seconda.
        boolean y = 3 < 10 || 3 % 2 == 0;
        System.out.println("OR (||): " + y);

        // NOT (!): Inverte il risultato. Trasforma TRUE in FALSE e viceversa.
        // (3 < 10) sarebbe TRUE, ma il '!' lo trasforma in FALSE.
        System.out.println("NOT (!): " + !(3 < 10));

        // ESPRESSIONI COMBINATE:
        // Prima parentesi: (TRUE && FALSE) -> false
        // Seconda parentesi: (TRUE && TRUE) -> true (perché 6 è minore di 10 e pari)
        // Risultato finale: false || true -> TRUE.
        boolean z = (3 < 10 && 3 % 2 == 0) || (6 < 10 && 6 % 2 == 0);
        System.out.println("Espressione complessa: " + z);
    }
}