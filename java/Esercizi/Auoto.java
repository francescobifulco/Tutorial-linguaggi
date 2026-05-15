public class Auoto {
    String marca;
    String modello;
    int velocita;

    public Auoto(String marca, String modello, int velocita){
        this.marca = marca;
        this.modello = modello;
        this.velocita = velocita;
    }

    public String getMarca() {
        return marca;
    }

    public String getModello() {
        return modello;
    }

    public int getVelocita() {
        return velocita;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModello(String modello) {
        this.modello = modello;
    }

    public void setVelocita(int velocita) {
        this.velocita = velocita;
    }

    public void accelera(){
        System.out.println("L' auto sta correntendo ha una velocita a: " + getVelocita());
    }

    public void frena(){
        System.out.println("L' auto sta frendo");
    }
}
