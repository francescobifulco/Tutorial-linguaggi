public class Lezione6_classe_mathe {
    public static void main(String[] args) {
        
        // Math.abs (Absolute): Restituisce il valore assoluto (toglie il segno meno).
        // Se scrivi -55, ti restituirà comunque 55.
        System.out.println("Valore assoluto: " + Math.abs(55));

        // Math.min: Confronta due numeri e ti restituisce il più PICCOLO.
        System.out.println("Il minore tra 55 e 2 è: " + Math.min(55, 2));

        // Math.max: Confronta due numeri e ti restituisce il più GRANDE.
        System.out.println("Il maggiore tra 55 e 2 è: " + Math.max(55, 2));

        // Math.pow (Power): Elevamento a potenza. 
        // Qui calcola 5 alla terza (5 * 5 * 5). Restituisce sempre un double.
        System.out.println("5 elevato a 3: " + Math.pow(5, 3));

        // Math.sqrt (Square Root): Calcola la radice quadrata del numero.
        System.out.println("Radice quadrata di 25: " + Math.sqrt(25));

        // Math.PI: Non è una funzione, ma una COSTANTE che contiene il valore del Pi greco.
        System.out.println("Valore del Pi greco: " + Math.PI);
    }
}