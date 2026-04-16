public class Lezione11_ciclo_while {
    public static void main(String[] args) {
        
        // --- IL CICLO WHILE ---
        // Funziona come un "Se... allora ripeti". 
        // Controlla la condizione ALL'INIZIO. Se è falsa da subito, non entra mai.
        int i = 0;
        while(i < 5) {
            System.out.println("while " + i);
            i++; // Fondamentale! Se non incrementi 'i', il ciclo non finisce mai (loop infinito).
        }

        // --- IL CICLO DO-WHILE ---
        // La differenza è che controlla la condizione ALLA FINE.
        // Questo garantisce che il codice venga eseguito ALMENO UNA VOLTA,
        // anche se la condizione è falsa fin dall'inizio.
        do {
            System.out.println("dowhile " + i);
            i++;
        } while (i < 0); 
        // In questo caso, i è 5 (dopo il ciclo precedente). 
        // 5 < 0 è FALSO, ma il programma stampa comunque "dowhile 5" prima di fermarsi.
    }
}