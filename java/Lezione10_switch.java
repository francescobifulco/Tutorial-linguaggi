public class Lezione10_switch {
    public static void main(String[] args) {
        String nome = "Luca";

        // Lo switch "esamina" il contenuto della variabile tra parentesi.
        switch (nome) {
            
            // Caso in cui la variabile sia esattamente "Luca"
            case "Luca":
                System.out.println("ciao " + nome);
                break; // FONDAMENTALE: esce dallo switch. Senza questo, eseguirebbe anche i casi successivi!

            case "Marco":
                System.out.println("ciao " + nome);
                break;

            case "Anna":
                System.out.println("ciao " + nome);
                break;

            case "Antonio":
                System.out.println("ciao " + nome);
                break;

            case "Edoardo":
                System.out.println("ciao " + nome);
                break;

            // DEFAULT: viene eseguito se nessuno dei casi precedenti corrisponde.
            // È come l'ultimo "else" in una catena di if.
            default:
                System.out.println("ciao chiunque tu sia");
                break;
        }
    }
}