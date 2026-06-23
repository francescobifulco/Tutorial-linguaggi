/*Crea una classe Auto con attributi marca, modello e velocità. 
Aggiungi un metodo accelera() e frena(). Istanzia due oggetti 
auto diverse e falle "correre".*/

import java.util.Scanner;

public class Esercizio9 {
    public static void main(String[] args) {
        Auto auto1 = new Auto("Fiat", "500", 60);

        Auto auto2 = new Auto("Tesla", "Model 3", 0);

        System.out.println("--- Inizio gara ---");

        auto1.accelera(20);
        auto2.accelera(100);

        auto1.frena();
        auto2.accelera(50);
    }
}
