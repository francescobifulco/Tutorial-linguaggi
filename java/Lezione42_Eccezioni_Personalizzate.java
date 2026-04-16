public class Lezione42_Eccezioni_Personalizzate {
    public static void main(String[] args) {
        try {
            ControlloAccesso.verificaEta(15);
        } catch (EtaNonValidaException e) {
            System.out.println("ERRORE: " + e.getMessage());
            System.out.println("Hai inserito: " + e.getEtaErrata() + " anni.");
        }
    }
}
