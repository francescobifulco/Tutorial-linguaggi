public class Lezione43_espressioni_lambda {
    public static void main(String[] args) {
        Lezione43_espressioni_lambda app = new Lezione43_espressioni_lambda();

        System.out.println("--- 1. METODO CLASSICO (Classe Esterna) ---");
        // Usiamo la classe SpaventaUsignoli che implementa l'interfaccia
        SpaventoUsignoli classico = new SpaventoUsignoli();
        app.eseguiSpavento(classico);

        System.out.println("\n--- 2. CLASSE ANONIMA (Codice ingombrante) ---");
        // Creiamo un oggetto "al volo" senza nome
        Spavento anonimo = new Spavento() {
            @Override
            public void spaventa() {
                System.out.println("Buuu! (Gridato da una classe anonima)");
            }
        };
        app.eseguiSpavento(anonimo);

        System.out.println("\n--- 3. ESPRESSIONE LAMBDA (Sintesi pura) ---");
        // Qui passiamo direttamente il comportamento. 
        // Nota: Funziona solo se l'interfaccia ha UN SOLO metodo!
        Spavento lambda = () -> System.out.println("Sciò sciòooo! (Gridato da una Lambda)");
        app.eseguiSpavento(lambda);

        System.out.println("\n--- 4. LAMBDA CON PARAMETRI ---");
        // Se avessimo un'interfaccia con parametri (es. SpaventoDinamico)
        SpaventoDinamico lambdaDinamica = (f, a) -> System.out.printf("%s %s!%n", f, a);
        lambdaDinamica.spaventaDinamico("Andate via maledetti", "Usignoli");
    }

    // Metodi per eseguire il comportamento
    public void eseguiSpavento(Spavento s) {
        s.spaventa();
    }
}

