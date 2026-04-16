public class Lezione29_astratta {
    public static void main(String[] args) {
        System.out.println("--- TEST VEICOLO ---");

        // Veicolo v = new Veicolo(); // ERRORE! Non puoi istanziare una classe astratta.
        
        Macchina miaAuto = new Macchina();
        
        miaAuto.accendiMotore(); // Usa il metodo ereditato
        miaAuto.muovi();         // Usa il metodo obbligatorio implementato
        miaAuto.frena();         // Usa il metodo obbligatorio implementato

        System.out.println("--- FINE TEST ---");
    }
}