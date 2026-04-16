package Pacchetto1;
import Pacchetto2.*;

public class Lezione30_modificatore_accesso {
    public static void main(String[] args) {
        
        // Accesso a B (Public)
        B provaB = new B();
        System.out.println("Accesso a B: " + provaB.nome);

        // Accesso ad A (Protected)
        // Funziona perché Lezione30 e A sono nello STESSO pacchetto (Pacchetto1)
        A provaA = new A();
        System.out.println("Accesso ad A: " + provaA.nome);

        // Test della classe C (Eredità tra pacchetti)
        C provaC = new C();
        System.out.println("\n--- Test Classe C ---");
        provaC.provaAccesso();
    }
}