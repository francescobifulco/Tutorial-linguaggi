import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Collection;
import java.util.regex.Pattern;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;

public class Lezione44_stream_api {
    public static void main(String[] args) {
        String[] nomi = new String[] { "Marco", "Luca", "Antonio" };
        Stream<String> nomiStream = java.util.Arrays.stream(nomi);

        Stream.of("Marco", "Luca", "Antonio");

        Collection<String> nomCollection = java.util.Arrays.asList(nomi);
        nomiStream = nomCollection.stream();

        nomiStream = Stream.empty();

        Stream.Builder<String> = Stream.builder();

        nomiStream = Stream<String> builder.add("Marco").add("Antonio").add("Luca").build();

        Stream<Integer> numeriPari = Stream.iterate(2, n-> n+2).limit(10);

        IntStream intStream = IntStream.range(1, 10);
        DoubleStream doubleStream = intStream.asDoubleStream();
        LongStream longStream = LongStream.range(1, 10);

        IntStream charsTStream = "pippo".chars();

        String string = "Marco/Antonio/Luca";
        nomiStream = Pattern.compile("/").splitAsStream(string);

        nomiStream = Files.lines(Paths.get("/path/prova.txt"));
        
        Stream<String> nomeStream = Stream.of("Marco", "Antonio", "Luca");
    }
}