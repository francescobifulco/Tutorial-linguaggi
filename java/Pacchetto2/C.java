package Pacchetto2;
import Pacchetto1.A;

public class C extends A {
    public void provaAccesso() {
        // Posso accedere a 'nome' perché è protected e C è figlia di A
        System.out.println("Classe C accede a variabile ereditata: " + this.nome);
        
        // System.out.println(this.nomeSegreto); // ERRORE! private non si eredita.
    }
}