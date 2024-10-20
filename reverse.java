import java.util.Scanner;

public class reverse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String a = sc.nextLine();
        int b = a.length();
        String c = "";

        // Convert the string into a character array and reverse it
        char[] array = a.toCharArray();
        for (int i = b - 1; i >= 0; i--) {
            c += array[i];
        }

        System.out.println("Reversed string: " + c);
    }
}
