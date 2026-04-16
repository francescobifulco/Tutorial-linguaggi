public class Lezione16_wrapper_classes {
    public static void main(String[] args) {
        
        // --- WRAPPER CLASSES (Oggetti) ---
        // Notare la lettera maiuscola. Questi non sono semplici dati, 
        // ma "oggetti" che possono contenere metodi utili.
        Boolean vero = true;
        Character carattere = 'a';
        Integer numero = 5;
        Double virgola = 5.34;
        String stringa = "bel corso"; // String è già un oggetto

        // --- TIPI PRIMITIVI ---
        // Notare la lettera minuscola. Sono i dati puri, più efficienti in memoria.
        boolean a = true;
        char b = 'a';
        int c = 5;
        double d = 5.34;

        // --- AUTOBOXING E UNBOXING ---
        /* * Java permette di confrontare un oggetto (Integer) con un primitivo (int).
         * Questo processo si chiama "Unboxing": Java estrae il valore dall'oggetto 
         * per confrontarlo con il primitivo.
         */
        
        if(vero == a) {
            System.out.println("Boolean e boolean sono compatibili");
        }
        
        if(carattere == b) {
            System.out.println("Character e char sono compatibili");
        }
        
        if(numero == c) {
            System.out.println("Integer e int sono compatibili");
        }
        
        if(virgola == d) {
            System.out.println("Double e double sono compatibili");
        }

        System.out.println(stringa);
    }
}