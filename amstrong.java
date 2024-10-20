import java.util.Scanner;
public class amstrong{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number, digit, result = 0, original;
        System.out.println("Enter the number to check if it is an amstrong number or not");
        number = sc.nextInt();

        original = number ;
        while(original != 0){
            digit = original%10 ;
            result+= digit*digit*digit;
            original /= 10;
        }

            if( result == number){
                System.out.println("The number is an amstrong number");
            }
            else{
                System.out.println("The number is not an amstrong number");
            }

    
    }}
