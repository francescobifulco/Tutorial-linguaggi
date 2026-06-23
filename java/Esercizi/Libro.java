public class Libro {
    private int ID;
    private String Titolo, Autore;

    public Libro(int ID, String Titolo, String Autore){
        this.ID = ID;
        this.Titolo = Titolo;
        this.Autore = Autore;
    }

    public int getID() {
        return ID;
    }

    public void setID(int iD) {
        ID = iD;
    }

    public String getTitolo() {
        return Titolo;
    }

    public void setTitolo(String titolo) {
        Titolo = titolo;
    }

    public String getAutore() {
        return Autore;
    }

    public void setAutore(String autore) {
        Autore = autore;
    }
}
