import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;
import java.util.regex.Pattern;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;
import java.io.IOException;

public class Lezione44_stream_api {
    public static void main(String[] args) {
        System.out.println("--- CREAZIONE STREAM ---");
        
        // Diversi modi per creare uno Stream
        String[] nomi = new String[] { "Marco", "Luca", "Antonio" };
        Stream<String> nomiStream = Arrays.stream(nomi);

        Collection<String> nomCollection = Arrays.asList(nomi);
        nomiStream = nomCollection.stream();

        // Builder pattern
        Stream.Builder<String> builder = Stream.builder();
        nomiStream = builder.add("Marco").add("Antonio").add("Luca").build();

        // Iterazione infinita limitata
        System.out.print("Numeri Pari: ");
        Stream<Integer> numeriPari = Stream.iterate(2, n -> n + 2).limit(5);
        numeriPari.forEach(n -> System.out.print(n + " "));
        System.out.println();

        // Stream Primitivi (più efficienti)
        IntStream intStream = IntStream.range(1, 5);
        LongStream longStream = LongStream.range(1, 5);
        System.out.println("Range Int: " + intStream.count());

        // Regex e Stringhe
        String string = "Marco/Antonio/Luca";
        System.out.print("Split via Regex: ");
        Pattern.compile("/").splitAsStream(string).forEach(s -> System.out.print(s + " "));
        System.out.println("\n");

        // --- OPERAZIONI INTERMEDIE E TERMINALI ---
        System.out.println("--- ELABORAZIONE DATI ---");

        // 1. Distinct, Sorted e Collect
        List<String> collect = Stream.of("Marco", "Antonio", "Luca", "Marco")
                .distinct() // Rimuove i duplicati
                .sorted()   // Ordine alfabetico
                .collect(Collectors.toList());
        System.out.println("Lista pulita e ordinata: " + collect);

        // 2. Map (Trasformazione)
        System.out.print("Nomi in maiuscolo: ");
        List<String> nomii = Arrays.asList("marco", "antonio", "luca");
        nomii.stream()
                .map(String::toUpperCase) // Trasforma ogni stringa
                .forEach(s -> System.out.print(s + " "));
        System.out.println();

        // 3. Filter (Selezione)
        System.out.print("Nomi che iniziano con 'A': ");
        List<String> nomi2List = Arrays.asList("Marco", "Antonio", "Luca");
        nomi2List.stream()
                .filter(s -> s.startsWith("A"))
                .forEach(System.out::print);
        System.out.println();

        // 4. Match (Verifica)
        List<Integer> numeri = Arrays.asList(5, -3, 2, 8, 10);
        boolean haNegativi = numeri.stream().anyMatch(numero -> numero < 0);
        System.out.println("La lista contiene numeri negativi? " + (haNegativi ? "Sì" : "No"));

        // Nota sulla lettura file (commentata per evitare crash se il file manca)
        /*
        try {
            Stream<String> righeFile = Files.lines(Paths.get("prova.txt"));
            righeFile.forEach(System.out::println);
        } catch (IOException e) {
            System.err.println("Errore lettura file");
        }
        */
    }
}