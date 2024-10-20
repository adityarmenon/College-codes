import java.util.Scanner;

public class tos {

    // Arrays to store words for digits
    private static final String[] ones = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
        "Seventeen", "Eighteen", "Nineteen"
    };

    private static final String[] tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    // Method to convert number to words
    public static String convertToWords(int number) {
        if (number == 0) {
            return "Zero";
        } else if (number < 20) {
            return ones[number];
        } else if (number < 100) {
            return tens[number / 10] + " " + ones[number % 10];
        } else {
            return ones[number / 100] + " Hundred " + convertToWords(number % 100);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Get user input
        System.out.print("Enter a number between 0 and 999: ");
        int number = scanner.nextInt();
        
        // Validate input range
        if (number < 0 || number > 999) {
            System.out.println("Please enter a number between 0 and 999.");
        } else {
            // Convert number to words and display
            System.out.println("Number in words: " + convertToWords(number));
        }
    }
}
