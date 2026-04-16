public class Lezione24_metodo_toString {
    public static void main(String[] args) {
        Informazione persona = new Informazione("Luca", "Rossi", 25, "blu");

        // TRUCCO: Non è obbligatorio scrivere .toString()
        // Quando passi un oggetto a System.out.println, Java chiama .toString() da solo!
        System.out.println(persona); 
        
        System.out.println("\nEsempio di chiamata esplicita:");
        String info = persona.toString();
        System.out.println(info);
    }
}