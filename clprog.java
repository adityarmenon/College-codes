import java.util.*;

class Box{
    double width;
    double height;
    double depth;

    double volume(){
        return width * height * depth;
    }
}
public class clprog {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Box A = new Box();
        Box B = new Box();

        System.out.println("Enter the width of the box A:");
        A.width = sc.nextInt();
        System.out.println("Enter the height of the box A:");
        A.height = sc.nextInt();
        System.out.println("Enter the depth of the box A:");
        A.depth = sc.nextInt();

         System.out.println("Enter the width of the box B:");
        B.width = sc.nextInt();
        System.out.println("Enter the height of the box B:");
        B.height = sc.nextInt();
        System.out.println("Enter the depth of the box B:");
        B.depth = sc.nextInt();

        System.out.println(" Volume of A:" + A.volume());
        System.out.println("Volume of B: " + B.volume());
    }
}