package Pacchetto1;

public class A {
    // PROTECTED: Visibile nello stesso pacchetto e dalle sottoclassi (anche in altri pacchetti)
    protected String nome = "Luca (Protected)";
    
    // PRIVATE: Visibile SOLO dentro questa classe. Nessun altro può vederla.
    private String nomeSegreto = "Password123";
    public void stampa(){
        System.out.println(nomeSegreto);
    }
}