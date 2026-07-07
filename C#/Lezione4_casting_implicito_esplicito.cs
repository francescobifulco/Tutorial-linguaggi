using System;

namespace Lezione4
{
    public class Lezione4_casting_implicito_esplicito
    {
        static void Main(string[] args)
        {

            // --- 1. CASTING IMPLICITO (Widening) ---
            float prova = 3.54f;
            // Il float (32 bit) viene promosso a double (64 bit) 
            // automaticamente senza perdita di dati.
            double prova2 = prova;

            // --- 2. CASTING ESPLICITO (Narrowing) ---
            double esempo = 35.43;
            // Forziamo il double dentro un int. 
            // ATTENZIONE: Il casting esplicito (int) TRONCA il numero, 
            // elimina i decimali. 'qwerty' diventa 35.
            int qwerty = (int)esempo;

            // --- 3. METODI DI CONVERSIONE (Classe Convert) ---
            bool sino = true;
            // Convert.ToString trasforma qualsiasi tipo di dato in testo. 
            // In questo caso converte il float 3.54 nella stringa "3.54".

           // --- STAMPE OTTIMIZZATE ---
           Console.WriteLine("=== RISULTATI CONVERSIONI ===");
           Console.WriteLine("Convert.ToInt32(prova2) [Arrotondato]: {Convert.ToInt32(prova2)}");
           Console.WriteLine("Valore originale di prova2 (double): {prova2}");
           Console.WriteLine("Casting esplicito (int)esempo [Troncato]: {qwerty}");
           Console.WriteLine("Stringa creata da Convert: {strhga}");
           Console.WriteLine("Variabile booleana: {sino}");
           
           Console.ReadLine();
        }
    }
}