public class Auto {
    private String marca;
    private String modello;
    private int velocita;

    public Auto(String marca, String modello, int velocita) {
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

    public void accelera(int incremento) {
        this.velocita += incremento;
        System.out.println(marca + " " + modello + " accelera. Nuova velocità: " + velocita + " km/h");
    }

    public void frena() {
        this.velocita = 0;
        System.out.println(marca + " " + modello + " ha frenato. Velocità: " + velocita + " km/h");
    }
}
