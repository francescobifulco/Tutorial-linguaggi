import java.util.InputMismatchException;
import java.util.Scanner;

public class Lezione35_gestione_eccezione {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);

        try {
            System.out.print("Inserisci il primo numero (dividendo): ");
            int x = sca.nextInt();

            System.out.print("Inserisci il secondo numero (divisore): ");
            int y = sca.nextInt();

            int risultato = x / y;
            System.out.println("\n[Successo] Il risultato della divisione è: " + risultato);

        } catch (ArithmeticException e) {
            // Scatta se provi a dividere per zero
            System.out.println("\n[Errore Matematico]: Non è possibile dividere un numero per zero.");
        } catch (InputMismatchException e) {
            // Scatta se inserisci testo invece di numeri
            System.out.println("\n[Errore Input]: Hai inserito un carattere non valido. Inserisci solo numeri interi.");
        } catch (Exception e) {
            // Scatta per qualsiasi altro errore non previsto
            System.out.println("\n[Errore Generico]: Si è verificato un problema imprevisto: " + e.getMessage());
        } finally {
            // Questo codice viene eseguito in ogni caso
            System.out.println("\n[Sistema]: Pulizia risorse in corso...");
            sca.close(); // È buona norma chiudere lo scanner
            System.out.println("[Sistema]: Chiusura programma terminata.");
        }
    }
}