/*Crea una classe Auto con attributi marca, modello e velocità. 
Aggiungi un metodo accelera() e frena(). Istanzia due oggetti 
auto diverse e falle "correre".*/

import java.util.Scanner;

public class Esercizio9 {
    public static void main(String[] args) {
        Auoto auto = new Auoto("FIAT", "Motornet", 120);

        auto.accelera();
        auto.frena();
    }
}
