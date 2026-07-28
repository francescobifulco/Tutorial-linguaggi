using System;

namespace Lezione39 {
    public class Lezione39_nullable {
        static void Main(string[] args) {
            
            int? prova = null;
            int prova2 = 2;

            double? prova3 = new double?();

            bool? prova4 = new bool?();

            Console.WriteLine("intero nullo ", prova);
            Console.WriteLine("intero con valore ", prova2);
            Console.WriteLine("Double nullo ", prova3);
            Console.WriteLine("bool nullo ", prova4);

            bool? isMaschio = null;
            if(isMaschio == true){
                Console.WriteLine("sei maschio");
            }else if (isMaschio == false){
                Console.WriteLine("sei femmina");
            }else{
                Console.WriteLine("genere non specificato");
            }

            int? prova44 = prova;
            int prova5 = prova ?? 5;
            
        }
    }
}