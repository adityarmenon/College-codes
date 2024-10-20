import java.util.Scanner;
public class frequency{
    public static void main(String[] args) {
        int i;
        Scanner sc = new Scanner(System.in);
        System.out.println ("Enter a string:");
        String a = sc.nextLine();
        System.out.println("Enter a character:");
        char b = sc.next().charAt(0);
        int c = 0;
        for(i=0;i<a.length();i++){
            if(a.charAt(i) == b){
                c++;    
            }
        }
        System.out.println("The frequency of the character is:" + c);
}}
   