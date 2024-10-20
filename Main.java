import java.util.Scanner;

// Base class Person
class Person {
    String name;
    int age;

    // Constructor for Person
    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Method to display information
    void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

// Derived class Student
class Student extends Person {
    String grade;

    // Constructor for Student
    Student(String name, int age, String grade) {
        super(name, age); // Call to base class constructor
        this.grade = grade;
    }

    // Override method to display additional information
    /**
     * Overrides the displayInfo method to include additional information.
     * Calls the superclass's displayInfo method to retain base class behavior,
     * and then prints the grade of the student.
     */
    @Override
    void displayInfo() {
        super.displayInfo(); // Call to base class method
        System.out.println("Grade: " + grade);
    }
} 

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking user input
        System.out.print("Enter name: ");
        String name = sc.nextLine();

        System.out.print("Enter age: ");
        int age = sc.nextInt();
        sc.nextLine(); // Consume newline

        System.out.print("Enter grade: ");
        String grade = sc.nextLine();

        // Create a Student object and display info
        Student student = new Student(name, age, grade);
        student.displayInfo();
    }
}