import java.util.*;
class Person{
    String name;

    void updatename(String newName){
        this.name = newName;
    }
    void displayname(){
        System.out.println("New Name: " + name);
    }
}
public class persond{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        Person p = new Person();
        System.out.println("Enter the name of the person:");
        p.name = sc.nextLine();
        System.out.println("Enter the new name of the person:");
        String newName = sc.nextLine();
        System.out.println("Old of the person: " + p.name);
        p.updatename(newName);
        p.displayname();
      
    }
}