import java.util.Scanner;
class WrongAgeException extends Exception {
    public WrongAgeException(String message) {
        super(message);
    }
}

class Father {
    int fatherAge;

    Father(int age) throws WrongAgeException {
        if (age < 0) {
            throw new WrongAgeException("Father's age cannot be negative!");
        }
        fatherAge = age;
        System.out.println("Father's age is: " + fatherAge);
    }
}

class Son extends Father {
    int sonAge;

    Son(int fatherAge, int sonAge) throws WrongAgeException {
        super(fatherAge);
        if (sonAge < 0) {
            throw new WrongAgeException("Son's age cannot be negative!");
        }
        if (sonAge >= fatherAge) {
            throw new WrongAgeException("Son's age must be less than father's age!");
        }
        this.sonAge = sonAge;
        System.out.println("Son's age is: " + this.sonAge);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter father's age: ");
        int fatherAge = sc.nextInt();
        System.out.print("Enter son's age: ");
        int sonAge = sc.nextInt();
        try {
            Son s = new Son(fatherAge, sonAge);
        }
        catch (WrongAgeException e) {
            System.out.println("Exception Caught: " + e.getMessage());
        }
    }
}
