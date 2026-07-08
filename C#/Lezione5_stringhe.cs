using System;

namespace Lezione{
    public class Lezione5_stringhe{
        static void Main(string[] args){

            // ==========================================
            // 1. CARATTERI DI ESCAPE (Sequenze speciali)
            // ==========================================

            // Il carattere \" serve per inserire le virgolette 
            // dentro una stringa senza chiuderla
            string stringa = "citazione: \"si vive una volta sola\"";

            // Il carattere \n serve per forzare un ritorno a capo (New Line)
            string stringa1 = "citazione: \n\"si vive una volta sola\"";

            // ==========================================
            // 2. FORMATTAZIONE E CONCATENAZIONE
            // ==========================================

            string nome = "Luca";
            string cognome = "Rossi";

            // Approccio A: Concatenazione classica con il '+'
            string conta = "ciao sono " + nome +" " + cognome;

            // Approccio B: string.Format composito 
            // (usa i segnaposto numerati {0}, {1}...)
            string formo = string.Format("Buongiorno sono {0} {1}", nome, cognome);

            // Approccio C: String Interpolation diretta 
            // (il modo più moderno ed elegante, senza string.Format)
            string metodo = string.Format($"Buongiorno sono {nome} {cognome}");

            // ==========================================
            // STAMPE DI VERIFICA (FORMATTAZIONE)
            // ==========================================
            Console.WriteLine("--- Esempi di Formattazione ---");
            Console.WriteLine(stringa);
            Console.WriteLine(stringa1);
            Console.WriteLine(conta);
            
            // Anche Console.WriteLine accetta i segnaposto direttamente, 
            // come string.Format!
            Console.WriteLine("Buongiorno sono {0} {1}", nome, cognome); 
            Console.WriteLine(formo);
            Console.WriteLine(metodo);
            Console.WriteLine($"Buongiorno sono {nome} {cognome}");

            // ==========================================
            // 3. METODI E PROPRIETÀ DELLE STRINGHE
            // ==========================================
            Console.WriteLine("\n--- Metodi di Manipolazione ---");

            // .ToUpper() e .ToLower() richiedono le parentesi () perché sono metodi!
            string funzione = nome.ToUpper(); // Trasforma in tutto MAIUSCOLO -> "LUCA"
            string lower = nome.ToLower();   // Trasforma in tutto minuscolo -> "luca"
            
            // .Length restituisce un INT, quindi la variabile deve essere di tipo int!
            int lenghet = nome.Length;       // Conta i caratteri del nome -> 4

            Console.WriteLine($"Maiuscolo: {funzione} | Minuscolo: {lower} | Lunghezza: {lenghet}");


            // ==========================================
            // 4. INDICIZZAZIONE E SOTTOSTRINGHE (Substring)
            // ==========================================
            Console.WriteLine("\n--- Gestione Indici e Substring ---");

            // Le stringhe sono array di caratteri (partono da indice 0). 
            // In "Luca": L=0, u=1, c=2, a=3. Quindi nome[1] stamperà 'u'.
            Console.WriteLine($"Il secondo carattere di {nome} è: {nome[1]}");

            // .IndexOf() cerca una lettera o parola. Se NON la trova, restituisce -1.
            // Nella stringa "Rossi" la "u" non esiste, quindi stamperà -1.
            Console.WriteLine($"Indice della lettera 'u' in {cognome}: {cognome.IndexOf("u")}");
            
            // Cerca invece la 'o' in "Rossi" (R=0, o=1, s=2...) -> restituirà 1
            Console.WriteLine($"Indice della lettera 'o' in {cognome}: {cognome.IndexOf("o")}");

            // .Substring(inizio) taglia la stringa partendo dall'indice indicato fino alla fine.
            // In "Rossi" (lunghezza 5, indici da 0 a 4), partiamo dall'indice 2 (la prima 's') -> stamperà "ssi"
            Console.WriteLine($"Taglio dall'indice 2 in poi di {cognome}: {cognome.Substring(2)}");
            
            // .Substring con lunghezza dinamica: cognome.Length è 5. 5 - 3 = 2.
            // Partirà dall'indice 2 e prenderà tutto fino alla fine -> stamperà gli ultimi 3 caratteri ("ssi")
            Console.WriteLine($"Ultimi 3 caratteri di {cognome}: {cognome.Substring(cognome.Length - 3)}");

            Console.ReadLine();
        }
    }
}