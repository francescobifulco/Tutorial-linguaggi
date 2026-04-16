import java.util.stream.Stream;

public class Lezione44_stream_api {
    public static void main(String[] args) {
        String[] nomi = new String[] { "Marco", "Luca", "Antonio" };
        Stream<String> nomiStream = java.util.Arrays.stream(nomi);
        
    }
}
