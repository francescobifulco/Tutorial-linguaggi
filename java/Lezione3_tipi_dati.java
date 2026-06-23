public class Lezione3_tipi_dati {
    public static void main(String[] args){
       // BOOLEAN: Può essere solo true (vero) o false (falso). Ideale per interruttori.
        boolean luce = true;
        System.out.println("Stato della luce: " + luce);

        // BYTE: Occupa pochissimo spazio (8 bit). Valori da -128 a 127.
        byte ilByte = 64;
        System.out.println("Valore byte: " + ilByte);

        // SHORT: Un po' più grande del byte (16 bit). Arriva fino a circa 32.000.
        short loShort = 325;
        System.out.println("Valore short: " + loShort);

        // INT: Il tipo standard per i numeri interi (32 bit). Arriva a circa 2 miliardi.
        int ilInt = 20000;
        System.out.println("Valore int: " + ilInt);

        // LONG: Per numeri interi enormi (64 bit).
        // Nota: si mette la 'L' alla fine per dire a Java che è un Long.
        long ilLong = 20000000L;
        System.out.println("Valore long: " + ilLong);

        // FLOAT: Numeri decimali a "singola precisione".
        // Nota: obbligatoria la 'f' alla fine.
        float ilFloat = 5.3445f;
        System.out.println("Valore float: " + ilFloat);

        // DOUBLE: Numeri decimali a "doppia precisione" (64 bit). Più preciso del float.
        // La 'd' alla fine è opzionale ma utile per chiarezza.
        double ilDouble = 5.6775453d;
        System.out.println("Valore double: " + ilDouble);

        // CHAR: Contiene un singolo carattere. Usa gli apici singoli (' ').
        char ilChar = 'f';
        System.out.println("Carattere singolo: " + ilChar);

        // STRING: Non è un tipo primitivo, ma un "Oggetto". Sequenza di caratteri.
        String laStringa = "ciao a tutti";
        System.out.println("Testo originale: " + laStringa);

        // METODO toUpperCase(): Essendo String un oggetto, ha delle funzioni integrate.
        // Questa trasforma tutto il testo in MAIUSCOLO.
        System.out.println("Testo in maiuscolo: " + laStringa.toUpperCase());

        // Il metodo del casting
        int num1 = 34;
        double num2 = 40;
        double risulto;

        risulto = (int) (num1 / num2);
        System.out.println(risulto);


    }
}
