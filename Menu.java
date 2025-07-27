import java.util.Scanner;

public class CipherDemo {

    // Caesar Cipher
    public static String caesarCipherEncrypt(String text, int shift) {
        StringBuilder result = new StringBuilder();
        shift = shift % 26;
        for (char c : text.toCharArray()) {
            if (Character.isUpperCase(c)) {
                result.append((char) ((c + shift - 'A') % 26 + 'A'));
            } else if (Character.isLowerCase(c)) {
                result.append((char) ((c + shift - 'a') % 26 + 'a'));
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }

    public static String caesarCipherDecrypt(String text, int shift) {
        return caesarCipherEncrypt(text, 26 - (shift % 26));
    }

    // Substitution Cipher
    public static String substitutionCipherEncrypt(String text, String key) {
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        text = text.toUpperCase();
        StringBuilder result = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                int index = alphabet.indexOf(c);
                result.append(key.charAt(index));
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }

    public static String substitutionCipherDecrypt(String text, String key) {
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder result = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                int index = key.indexOf(c);
                result.append(alphabet.charAt(index));
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }

    // Hill Cipher
    public static String hillCipherEncrypt(String plaintext, int[][] keyMatrix) {
        char[] plainTextChars = plaintext.toUpperCase().toCharArray();
        int[] plainVector = new int[3];
        for (int i = 0; i < 3; i++) {
            plainVector[i] = plainTextChars[i] - 'A';
        }

        int[] cipherVector = new int[3];
        for (int i = 0; i < 3; i++) {
            cipherVector[i] = 0;
            for (int j = 0; j < 3; j++) {
                cipherVector[i] += keyMatrix[i][j] * plainVector[j];
            }
            cipherVector[i] %= 26;
        }

        StringBuilder cipherText = new StringBuilder();
        for (int i = 0; i < 3; i++) {
            cipherText.append((char) (cipherVector[i] + 'A'));
        }
        return cipherText.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Caesar Cipher
        System.out.println("Caesar Cipher:");
        System.out.print("Enter text: ");
        String caesarText = scanner.nextLine();
        System.out.print("Enter shift value: ");
        int shift = scanner.nextInt();
        scanner.nextLine(); // Clear the buffer
        String caesarEncrypted = caesarCipherEncrypt(caesarText, shift);
        System.out.println("Encrypted: " + caesarEncrypted);
        System.out.println("Decrypted: " + caesarCipherDecrypt(caesarEncrypted, shift));

        // Substitution Cipher
        System.out.println("\nSubstitution Cipher:");
        System.out.print("Enter text: ");
        String substitutionText = scanner.nextLine();
        System.out.print("Enter 26-letter key: ");
        String substitutionKey = scanner.nextLine().toUpperCase();
        String substitutionEncrypted = substitutionCipherEncrypt(substitutionText, substitutionKey);
        System.out.println("Encrypted: " + substitutionEncrypted);
        System.out.println("Decrypted: " + substitutionCipherDecrypt(substitutionEncrypted, substitutionKey));

        // Hill Cipher
        System.out.println("\nHill Cipher:");
        System.out.print("Enter 9-letter key (for 3x3 matrix): ");
        String hillKey = scanner.nextLine().toUpperCase();
        int[][] keyMatrix = new int[3][3];
        for (int i = 0; i < 9; i++) {
            keyMatrix[i / 3][i % 3] = hillKey.charAt(i) - 'A';
        }
        System.out.print("Enter 3-letter plaintext: ");
        String hillPlaintext = scanner.nextLine();
        String hillEncrypted = hillCipherEncrypt(hillPlaintext, keyMatrix);
        System.out.println("Encrypted: " + hillEncrypted);
        // Decryption for Hill Cipher would require matrix inversion, which is not implemented here for simplicity.

        scanner.close();
    }
}