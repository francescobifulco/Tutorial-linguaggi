/*Crea due variabili stringa: username e password. Usa un blocco 
if per stampare "Accesso consentito" solo se corrispondono a 
valori predefiniti (es. "admin" e "1234").*/

import java.util.Scanner;

public class Esercizio3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String username, password;

        System.out.println("Inserisci la tua username: ");
        username = scan.nextLine();

        System.out.println("Inserisci la tua password: ");
        password = scan.nextLine();

        if (username.equals("admin") && password.equals("1234")) {
            System.out.println("I tuoi dati sono corretti.");
        }else{
            System.out.println("L' username o la password sono errati");
        }

        scan.close();
    }
}
