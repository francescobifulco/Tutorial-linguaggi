public class Pizza {
    String impasto, salsa, formaggio, extra, extra2;

    // Costruttore con 5 ingredienti
    Pizza(String impasto, String salsa, String formaggio, String extra, String extra2) {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
        this.extra = extra;
        this.extra2 = extra2;
    }

    // Costruttore con 4 ingredienti
    Pizza(String impasto, String salsa, String formaggio, String extra) {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
        this.extra = extra;
    }

    // Costruttore con 3 ingredienti (es. Margherita)
    Pizza(String impasto, String salsa, String formaggio) {
        this.impasto = impasto;
        this.salsa = salsa;
        this.formaggio = formaggio;
    }

    // Costruttore con 2 ingredienti
    Pizza(String impasto, String salsa) {
        this.impasto = impasto;
        this.salsa = salsa;
    }

    // Costruttore base (solo impasto)
    Pizza(String impasto) {
        this.impasto = impasto;
    }

    // Metodo per stampare il riepilogo in modo pulito
    void mostraPizza() {
        System.out.print("Pizza ordinata -> Impasto: " + impasto);
        if (salsa != null) System.out.print(", Salsa: " + salsa);
        if (formaggio != null) System.out.print(", Formaggio: " + formaggio);
        if (extra != null) System.out.print(", Extra: " + extra);
        if (extra2 != null) System.out.print(", Extra 2: " + extra2);
        System.out.println(); // Va a capo
    }
}