import java.util.Optional;

public class Lezione45_NullPointerException {

    public static void main(String[] args) {
        String nomeInput = null; // Simuliamo un dato mancante

        // Creiamo l'optional
        Optional<String> optNome = Optional.ofNullable(nomeInput);

        System.out.println("--- GESTIONE OPTIONAL ---");

        // Gestione con valore di default
        System.out.println("Risultato: " + optNome.orElse("Nome non pervenuto"));

        // Gestione con logica lambda
        optNome.ifPresentOrElse(
                n -> System.out.println("Nome trovato: " + n),
                () -> System.out.println("Attenzione: La scatola è vuota!"));
    }
}