public class ControlloAccesso {
    // 'throws' avvisa il compilatore che questo metodo è pericoloso
    public static void verificaEta(int eta) throws EtaNonValidaException {
        if (eta < 18) {
            // 'throw' lancia effettivamente l'oggetto errore
            throw new EtaNonValidaException("Accesso negato: devi essere maggiorenne.", eta);
        }
        System.out.println("Accesso consentito!");
    }
}