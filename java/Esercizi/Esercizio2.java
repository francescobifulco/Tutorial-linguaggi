/*Esercizio 2 (Casting e Precisione): Crea una variabile int e una double. 
Prova a dividerle tra loro. Cosa succede se dividi due int che dovrebbero 
dare un decimale? Sperimenta il casting (double) */

public class Esercizio2 {
    public static void main(String[] args) {
        int num1 = 34;
        int num2 = 40;
        
        int risulto = num1 / num2;
        System.out.println("Divisione intera (34/40): " + risulto);

        double divDecimale = (double) num1 / num2;
        System.out.println("Divisione con casting (34/40): " + divDecimale);

        System.out.println("La divisione tra due numeri");
        System.err.println("Il numero " + num1 + " diviso " + num2);

        double risultatoVero = num1 / num2; 
        System.out.println("Risultato preciso di (34/40): " + risultatoVero);
    }
}
