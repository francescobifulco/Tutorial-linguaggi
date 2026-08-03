using System;
using System.Collections.Generic;

namespace Lezione48 {

    // --- 1. CLASSE GENERICA (Class<T>) ---
    // La 'T' rappresenta un tipo generico che verrà 
    // specificato al momento dell'istanziamento
    public class Contenitore<T> {
        private T _valore;

        public Contenitore(T valore) {
            _valore = valore;
        }

        public T OttieniValore() {
            return _valore;
        }

        public void StampaDettagli() {
            Console.WriteLine($"[Contenitore] Tipo: {typeof(T).Name} | Valore: {_valore}");
        }
    }


    // --- 2. CLASSE GENERICA CON VINCOLI (Constraints: where T : struct/class/new()) ---
    // Il vincolo 'where T : IComparable' impone che T debba implementare l'interfaccia IComparable (per poter fare confronti)
    public class Confrontatore<T> where T : IComparable<T> {
        public T CalcolaMassimo(T a, T b) {
            // CompareTo restituisce > 0 se 'a' è maggiore di 'b'
            return a.CompareTo(b) > 0 ? a : b;
        }
    }


    public class Lezione48_generics {
        
        // --- 3. METODO GENERICO ---
        // Un metodo generico definisce il proprio tipo <T> indipendente dalla classe in cui si trova
        public static void Scambia<T>(ref T a, ref T b) {
            T temp = a;
            a = b;
            b = temp;
        }

        static void Main(string[] args) {
            
            Console.WriteLine("--- 1. UTILIZZO DELLA CLASSE GENERICA Contenitore<T> ---");

            // Possiamo usare la stessa identica classe per tipi diversi!
            Contenitore<int> contenitoreIntero = new Contenitore<int>(100);
            contenitoreIntero.StampaDettagli();

            Contenitore<string> contenitoreTesto = new Contenitore<string>("Ciao Generics!");
            contenitoreTesto.StampaDettagli();

            Contenitore<DateTime> contenitoreData = new Contenitore<DateTime>(DateTime.Now);
            contenitoreData.StampaDettagli();


            Console.WriteLine("\n--- 2. UTILIZZO DEL METODO GENERICO Scambia<T> ---");

            // Scambio tra interi
            int x = 5, y = 20;
            Console.WriteLine($"Prima dello scambio: x = {x}, y = {y}");
            Scambia<int>(ref x, ref y); // C# può anche inferire il tipo: Scambia(ref x, ref y);
            Console.WriteLine($"Dopo lo scambio: x = {x}, y = {y}");

            // Scambio tra stringhe usando lo stesso metodo!
            string str1 = "Mondo", str2 = "Ciao";
            Console.WriteLine($"\nPrima dello scambio: str1 = '{str1}', str2 = '{str2}'");
            Scambia(ref str1, ref str2);
            Console.WriteLine($"Dopo lo scambio: str1 = '{str1}', str2 = '{str2}'");


            Console.WriteLine("\n--- 3. UTILIZZO DI CLASSI GENERICHE CON VINCOLI (where T : ...) ---");

            Confrontatore<double> confrontatoreDouble = new Confrontatore<double>();
            double maxDouble = confrontatoreDouble.CalcolaMassimo(14.5, 29.8);
            Console.WriteLine($"Il massimo tra 14.5 e 29.8 è: {maxDouble}");

            Confrontatore<string> confrontatoreStringa = new Confrontatore<string>();
            string maxStringa = confrontatoreStringa.CalcolaMassimo("Mela", "Pera");
            Console.WriteLine($"Tra 'Mela' e 'Pera' viene dopo in ordine alfabetico: {maxStringa}");
        }
    }
}