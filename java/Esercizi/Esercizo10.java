/*Crea una classe base Animale con un metodo faiVerso(). 
Crea le sottoclassi Cane e Gatto che sovrascrivono il metodo. 
Crea una lista di Animale che contenga sia cani che gatti e 
invoca il metodo in un ciclo.*/

import java.util.ArrayList;
import java.util.List;

public class Esercizo10 {
    public static void main(String[] args) {
        List<Animale> listaAnimali = new ArrayList<>();

        listaAnimali.add(new Cane());
        listaAnimali.add(new Gatto());
        listaAnimali.add(new Cane());

        System.out.println("--- Concerto degli Animali ---");

        for (Animale a : listaAnimali) {
            a.faiVerso(); 
        }
    }
}
