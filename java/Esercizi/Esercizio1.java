/*Esercizio 1 (Il Calcolatore di Area): Scrivi un programma che dichiari 
le variabili per la base e l'altezza di un rettangolo e ne calcoli l'area.*/

import java.util.Scanner;

public class Esercizio1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String scelta;
        float area, lato, base, altezza, diagonale_MAG, diagonale_MIN, base_MAG, base_MIN;

        System.out.println("Inserire la figura geometrica (Quadrato, Rettangolo, Triangolo, Parallelogramma, Rombo, Trapezio): ");
        scelta = scan.nextLine().toLowerCase();

        switch (scelta) {
            case "quadrato":
                System.out.println("Inserisci il lato: ");
                lato = scan.nextFloat();

                area = lato * lato;
                System.out.println("L' area del quadrato è: " + area);
                break;

            case "rettangolo":
                System.out.println("Inserisci la base: ");
                base = scan.nextFloat();

                System.out.println("Inserisci l'altezza: ");
                altezza = scan.nextFloat();

                area = base * altezza;
                System.out.println("L' area del rettangolo è: " + area);
                break;
            
            case "triangolo":
                System.out.println("Inserisci la base: ");
                base = scan.nextFloat();

                System.out.println("Inserisci l' altezza: ");
                altezza = scan.nextFloat();

                area = (base * altezza) / 2;
                System.out.println("L' area del triangolo è: " + area);
                break;
            
            case "parallelogramma":
                System.out.println("Inserisci la base: ");
                base = scan.nextFloat();

                System.out.println("Inserisci l' altezza: ");
                altezza = scan.nextFloat();

                area = base * altezza;
                System.out.println("L' area del parallelogramma è: " + area);
                break;
            
            case "rombo":
                System.out.println("Inserisci la diagonale maggiore: ");
                diagonale_MAG = scan.nextFloat();

                System.out.println("Inserisci la diagonale minore: ");
                diagonale_MIN = scan.nextFloat();

                area = (diagonale_MAG * diagonale_MIN) / 2;
                System.out.println("L' area del rombo è: " + area);
                break;
            
            case "trapezio":
                System.out.println("Inserisci la base maggiore: ");
                base_MAG = scan.nextFloat();

                System.out.println("Inserisci la base minore: ");
                base_MIN = scan.nextFloat();

                System.out.println("Inserisci l' altezza: ");
                altezza = scan.nextFloat();

                area = ((base_MAG + base_MIN) * altezza) / 2;
                System.out.println("L' area del trapezio è: " + area);
                break;

            default:
                System.out.println("ERRORE: La figura geometrica '" + scelta + "' non esiste o non è gestita.");
                break;
        }

        scan.close();
    }
}