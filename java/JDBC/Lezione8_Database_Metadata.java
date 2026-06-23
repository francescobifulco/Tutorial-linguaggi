import java.sql.*;

public class Lezione8_Database_Metadata {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS)) {

            // 1. Otteniamo i Metadata del Database
            DatabaseMetaData dbmd = conn.getMetaData();

            System.out.println("--- INFO DATABASE ---");
            System.out.println("Prodotto: " + dbmd.getDatabaseProductName());
            System.out.println("Versione: " + dbmd.getDatabaseProductVersion());
            System.out.println("Driver: " + dbmd.getDriverName());
            System.out.println("----------------------\n");

            // 2. Recuperiamo l'elenco delle tabelle
            // Parametri di getTables: (catalog, schemaPattern, tableNamePattern, types)
            // Usiamo null per i primi tre per avere "tutto", e "TABLE" per ignorare le Viste di sistema.
            String[] types = {"TABLE"};
            try (ResultSet rsTabelle = dbmd.getTables("prova_db", null, "%", types)) {

                System.out.println("TABELLE TROVATE NEL DATABASE:");

                while (rsTabelle.next()) {
                    String nomeTabella = rsTabelle.getString("TABLE_NAME");
                    System.out.println("\n> TABELLA: " + nomeTabella);

                    // 3. Per ogni tabella, scopriamo le sue colonne
                    try (ResultSet rsColonne = dbmd.getColumns("prova_db", null, nomeTabella, "%")) {
                        while (rsColonne.next()) {
                            String nomeColonna = rsColonne.getString("COLUMN_NAME");
                            String tipoColonna = rsColonne.getString("TYPE_NAME");
                            int dimensione = rsColonne.getInt("COLUMN_SIZE");

                            System.out.println("  - " + nomeColonna + " (" + tipoColonna + ", size: " + dimensione + ")");
                        }
                    }
                }
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}