public class Lezione25_array_oggetto {
    public static void main(String[] args) {
        
        // --- METODO 1: Dichiarazione e poi assegnazione ---
        // Creiamo un contenitore (array) capace di ospitare 3 oggetti di tipo Informazione
        Informazione[] listaPersone = new Informazione[3];
        
        Informazione persona1 = new Informazione("Luca", "Rossi", 25, "blu");
        Informazione persona2 = new Informazione("Marco", "Verdi", 36, "rosso");
        Informazione persona3 = new Informazione("Anna", "Esposito", 20, "giallo");

        // Inseriamo gli oggetti nei "cassetti" dell'array
        listaPersone[0] = persona1;
        listaPersone[1] = persona2;
        listaPersone[2] = persona3;

        System.out.println("--- STAMPA SINGOLO ELEMENTO (Indice 1) ---");
        // Grazie al metodo toString() della lezione 24, questo stampa i dettagli di Marco
        System.out.println(listaPersone[1]);

        // --- METODO 2: Inizializzazione rapida (Inline) ---
        Informazione[] archivioRapido = {persona1, persona2, persona3};

        System.out.println("\n--- CICLO DI STAMPA DI TUTTO L'ARRAY ---");
        for (int i = 0; i < archivioRapido.length; i++) {
            System.out.println("Posizione " + i + ":");
            System.out.println(archivioRapido[i]);
        }
    }
}