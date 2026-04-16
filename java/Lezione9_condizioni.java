public class Lezione9_condizioni {
    public static void main(String[] args) {
        boolean isOnline = true;
        String nome = "Marco";

        // --- IF ANNIDATI (Nested If) ---
        // Il programma entra nel secondo IF solo se il primo è vero.
        if (nome.equals("Marco")) { // NOTA: Per le Stringhe si usa .equals() invece di ==
            if (isOnline) {
                System.out.println("Marco è online");
            } else {
                System.out.println("Marco è offline");
            }
        } else if (nome.equals("Luca")) {
            System.out.println("L'utente è Luca");
        } else {
            System.out.println("Utente sconosciuto");
        }

        // --- CONDIZIONI ANNIDATE CON NUMERI ---
        int num = 4; // Cambiato a 4 per vedere l'effetto "pari"
        if (num < 10) {
            System.out.println(num + " è minore di 10");
            if (num % 2 == 0) {
                System.out.println("...ed è anche un numero pari");
            }
        }

        // --- CONDIZIONE COMPOSTA (Più pulita dell'annidata) ---
        // Fa la stessa cosa di sopra ma in una riga sola usando && (AND)
        if (num < 10 && num % 2 == 0) {
            System.out.println("Verifica rapida: il numero è minore di 10 e pari.");
        }

        // --- OPERATORE TERNARIO ---
        // È un modo compresso per scrivere un IF/ELSE.
        // Struttura: (condizione) ? valore_se_vero : valore_se_falso;
        String saluto = (num < 10) ? "Numero piccolo" : "Numero grande";
        System.out.println("Risultato ternario: " + saluto);
    }
}