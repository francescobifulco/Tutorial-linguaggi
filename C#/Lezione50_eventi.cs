using System;

namespace Lezione50 {

    // --- 1. CLASSE DATI DELL'EVENTO (EventArgs) ---
    // Contiene le informazioni che vogliamo inviare 
    // agli osservatori quando l'evento scatta
    public class AllarmeEventArgs : EventArgs {
        public double Temperatura { get; }
        public string Messaggio { get; }

        public AllarmeEventArgs(double temperatura, string messaggio) {
            Temperatura = temperatura;
            Messaggio = messaggio;
        }
    }

    // --- 2. EDITORE (PUBLISHER) ---
    // La classe che genera l'evento
    public class SensoreTemperatura {
        
        // Definiamo l'evento usando il delegate EventHandler<T>
        public event EventHandler<AllarmeEventArgs>? AllarmeTemperaturaSuperata;
        private double _temperaturaAttuale;
        public void ImpostaTemperatura(double nuovaTemperatura) {
            Console.WriteLine($"[Sensore] Nuova rilevazione: {nuovaTemperatura}°C");
            _temperaturaAttuale = nuovaTemperatura;

            // Se la temperatura supera i 70 gradi, scatena l'evento!
            if (_temperaturaAttuale > 70.0) {
                OnAllarmeTemperaturaSuperata(new AllarmeEventArgs(_temperaturaAttuale, "ATTENZIONE: Temperatura critica!"));
            }
        }

        // Metodo protetto virtuale per sollevare l'evento in sicurezza
        protected virtual void OnAllarmeTemperaturaSuperata(AllarmeEventArgs e) {
            // L'operatore '?.' assicura che ci sia almeno un iscritto prima di invocare l'evento
            AllarmeTemperaturaSuperata?.Invoke(this, e);
        }
    }

    // --- 3. ISCRITTI / OSSERVATORI (SUBSCRIBERS) ---
    
    public class SistemaAntincendio {
        // Gestore dell'evento (Handler)
        public void InviaNotificaPompieri(object? sender, AllarmeEventArgs e) {
            Console.WriteLine($"  🔥 [Sistema Antincendio] {e.Messaggio} Rilevati {e.Temperatura}°C. Avviso inviato!");
        }
    }

    public class DisplayDisplayVentole {
        public void AttivaVentoleRaffreddamento(object? sender, AllarmeEventArgs e) {
            Console.WriteLine($"  ❄️ [Ventole] Attivazione raffreddamento d'emergenza per temperatura a {e.Temperatura}°C.");
        }
    }

    public class Lezione50_eventi {
        static void Main(string[] args) {
            
            Console.WriteLine("--- 1. CREAZIONE DEL PUBLISHER E SUBSCRIBERS ---");

            SensoreTemperatura sensore = new SensoreTemperatura();
            SistemaAntincendio antincendio = new SistemaAntincendio();
            DisplayDisplayVentole ventole = new DisplayDisplayVentole();


            Console.WriteLine("\n--- 2. ISCRIZIONE AGLI EVENTI (Operatore +=) ---");

            // Ci iscriviamo all'evento del sensore usando l'operatore '+='
            sensore.AllarmeTemperaturaSuperata += antincendio.InviaNotificaPompieri;
            sensore.AllarmeTemperaturaSuperata += ventole.AttivaVentoleRaffreddamento;

            Console.WriteLine("Iscrizioni completate.");


            Console.WriteLine("\n--- 3. SIMULAZIONE RILEVAZIONI ---");

            sensore.ImpostaTemperatura(25.5); // Nella norma -> Nessun evento
            sensore.ImpostaTemperatura(50.0); // Nella norma -> Nessun evento

            Console.WriteLine();
            sensore.ImpostaTemperatura(85.0); // Supera i 70°C -> Scattano le notifiche automatiche!


            Console.WriteLine("\n--- 4. DISISCRIZIONE DA UN EVENTO (Operatore -=) ---");

            // Rimuoviamo il sistema ventole dagli iscritti
            sensore.AllarmeTemperaturaSuperata -= ventole.AttivaVentoleRaffreddamento;
            Console.WriteLine("Ventole disiscritte dall'evento.");

            Console.WriteLine();
            sensore.ImpostaTemperatura(92.0); // Ora risponderà solo il Sistema Antincendio!
        }
    }
}