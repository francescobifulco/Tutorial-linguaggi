/*Crea un array di 10 numeri interi. Scrivi un ciclo che trovi e 
stampi il valore più grande e quello più piccolo.*/

public class Esercizio7 {
    public static void main(String[] args) {
        int[] numeri = {5, 2, 8, 1, 9, 3, 7, 4, 10, 6};

        int min = numeri[0];
        int max = numeri[0];

        for (int i = 0; i < numeri.length; i++) {
            
            // Logica per il Massimo
            if (numeri[i] > max) {
                max = numeri[i];
            }
            
            // Logica per il Minimo
            if (numeri[i] < min) {
                min = numeri[i];
            }
        }

        System.out.println("Il numero massimo è: " + max);
        System.out.println("Il numero minimo è: " + min); 
    }
}
