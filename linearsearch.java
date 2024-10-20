import java.util.*;
public class linearsearch {
    public static void main(String[]args){
    int key, i, n, flag = 0;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of elements in the array");
    n = sc.nextInt();

    int[] a = new int[ n ];

    for(i=0; i<n; i++){
        System.out.println("Enter the elements :");
        a[i] = sc.nextInt();
    }

    System.out.println("Enter the element to search");
    key = sc.nextInt();
    for(i=0; i<n; i++){
       
        if(a[i] == key){
            flag = 1;
        }
        else{
            flag = 0;
            break;
        }
    }

    if( flag == 1){
        System.out.println("Element not found");
    }
    else {
        System.out.println("Element found at position : " + (i + 1));
    }
    }
}
