public class Lezione5_operazioni_aritmetiche {
    public static void main(String[] args) {
        int x = 10;
        int y = 2;
        int z;

        // --- OPERATORI ARITMETICI CLASSICI ---
        z = x + y; // ADDIZIONE: 10 + 2 = 12
        System.out.println("Somma: " + z);

        z = x - y; // SOTTRAZIONE: 10 - 2 = 8
        System.out.println("Sottrazione: " + z);

        z = x / y; // DIVISIONE: 10 / 2 = 5
        System.out.println("Divisione: " + z);

        z = x * y; // MOLTIPLICAZIONE: 10 * 2 = 20
        System.out.println("Moltiplicazione: " + z);

        z = x % y; // MODULO: Resto della divisione (10 diviso 2 fa 5 con resto 0)
        System.out.println("Resto (Modulo): " + z);

        // --- OPERATORI DI ASSEGNAZIONE COMPOSTA ---
        // Questi sono scorciatoie per modificare il valore di una variabile esistente.
        x += 3; // Equivalente a: x = x + 3 (10 + 3 = 13)
        System.out.println("x incrementato di 3: " + x);

        x -= 3; // Equivalente a: x = x - 3 (13 - 3 = 10)
        System.out.println("x decrementato di 3: " + x);

        x /= 3; // Equivalente a: x = x / 3 (10 / 3 = 3 in divisione intera)
        System.out.println("x diviso 3: " + x);

        x *= 3; // Equivalente a: x = x * 3 (3 * 3 = 9)
        System.out.println("x moltiplicato per 3: " + x);

        x %= 3; // Equivalente a: x = x % 3 (9 / 3 fa 3 con resto 0)
        System.out.println("x modulo 3: " + x);

        // --- OPERATORI DI INCREMENTO E DECREMENTO ---
        x++; // Incremento unitario: x = x + 1 (0 + 1 = 1)
        System.out.println("x + 1: " + x);

        x--; // Decremento unitario: x = x - 1 (1 - 1 = 0)
        System.out.println("x - 1: " + x);

        // --- ESPRESSIONI COMPLESSE ---
        z = 5;
        // Java segue le regole matematiche (PEMDAS): parentesi, poi moltiplicazioni,
        // poi somme.
        int risultato = ((3 + x) * y + (4 - 2)) * z;
        // Calcolo: ((3 + 0) * 2 + (2)) * 5 -> (3 * 2 + 2) * 5 -> (6 + 2) * 5 -> 8 * 5 =
        // 40
        System.out.println("Risultato espressione: " + risultato);
    }
}
