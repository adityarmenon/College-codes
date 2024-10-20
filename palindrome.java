import java.util.*;
public class palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String a = sc.nextLine();
        int b = a.length();
        String c = "";

        char[] arr = a.toCharArray();
        for (int i = b - 1; i >= 0; i--){
            c += arr[i];
        }
        if(c.equals(a)){
            System.out.println("The string is a palindrome");
        } else {
            System.out.println("The string is not a palindrome");
        }
    }
}
