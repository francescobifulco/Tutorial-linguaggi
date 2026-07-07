using System;

namespace Lezione3
{
    class Lezione3_tipi_dati
    {
        static void Main(string[] args)
        {
            // --- TIPI DI DATO TESTUALI ---

            // "string" memorizza una sequenza di caratteri (testo libero). 
            // Richiede i doppi apici "".
            string testo = "ciao";

            // "char" memorizza un SINGOLO carattere Unicode. 
            // Richiede gli apici singoli ''.
            char carattere = 'c';

            // --- TIPI DI DATO INTERI ---

            // "int" (32 bit) memorizza numeri interi senza virgola. 
            // È il più usato per i numeri standard.
            int intero = 2000;

            // "long" (64 bit) memorizza numeri interi molto grandi, 
            // occupando il doppio della memoria di un int.
            long lungo = 20000;

            // --- TIPI DI DATO DECIMALI (CON VIRGOLA) ---

            // "float" (precisione singola, 32 bit). 
            // Richiede il suffisso 'f' o 'F' alla fine del numero.
            float virgola = 3.5f;

            // "double" (precisione doppia, 64 bit). 
            // È il tipo predefinito in C# per i numeri con la virgola.
            double virgolaPreciso = 4.54;

            // "decimal" (altissima precisione, 128 bit). 
            // Usato specificamente per calcoli finanziari o monetari 
            // per evitare errori di arrotondamento. 
            // Richiede il suffisso 'm' o 'M'.
            decimal decimale = 30.432m;

            // --- TIPO DI DATO BOOLEANO ---

            // "bool" può assumere solo due valori: 
            // true (vero) o false (falso). Fondamentale 
            // per la logica di controllo.
            bool sino = false;

            // --- STAMPE SULLA CONSOLE ---

            // Usiamo la string interpolation per rendere 
            // l'output leggibile e capire cosa stiamo stampando
            Console.WriteLine($"Stringa: {testo}");
            Console.WriteLine($"Carattere: {carattere}");
            Console.WriteLine($"Intero (int): {intero}");
            Console.WriteLine($"Intero lungo (long): {lungo}");
            Console.WriteLine($"Double (default): {virgolaPreciso}");
            Console.WriteLine($"Float: {virgola}");
            Console.WriteLine($"Decimal (finanziario): {decimale}");
            Console.WriteLine($"Booleano: {sino}");

            Console.ReadLine();
        }
    }
}