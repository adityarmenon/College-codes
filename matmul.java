import java.util.*;
public class matmul{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int i, n, j, k, m;
        System.out.println("Enter the size of the matrix:");
        m = sc.nextInt();
        n = sc.nextInt();

        int a[][] = new int[m][n];
        int b[][] = new int[m][n];
        int c[][] = new int[m][n];

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                System.out.println("Enter the elements of the first matrix:");
                a[i][j] = sc.nextInt();
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                System.out.println("Enter the elements of the Second matrix:");
                b[i][j] = sc.nextInt();
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
            
                c[i][j] = c[i][j] + a[i][j] * b[i][j];
                System.out.println("Product of the matrices:" + c[i][j]);

            }
        }
    }    

}
