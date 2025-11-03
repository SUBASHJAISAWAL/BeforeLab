import java.util.*;

abstract class Shape {
    int a, b;
    abstract void printArea();
}

class Rectangle extends Shape {
    void input(Scanner sc) {
        System.out.print("Enter length and breadth of rectangle: ");
        a = sc.nextInt();
        b = sc.nextInt();
    }

    void printArea() {
        System.out.println("Area of Rectangle: " + (a * b));
    }
}

class Triangle extends Shape {
    void input(Scanner sc) {
        System.out.print("Enter base and height of triangle: ");
        a = sc.nextInt();
        b = sc.nextInt();
    }

    void printArea() {
        System.out.println("Area of Triangle: " + (0.5 * a * b));
    }
}

class Circle extends Shape {
    void input(Scanner sc) {
        System.out.print("Enter radius of circle: ");
        a = sc.nextInt();
    }

    void printArea() {
        System.out.println("Area of Circle: " + (3.14 * a * a));
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Rectangle r = new Rectangle();
        r.input(sc);
        r.printArea();

        Triangle t = new Triangle();
        t.input(sc);
        t.printArea();

        Circle c = new Circle();
        c.input(sc);
        c.printArea();

        sc.close();  
    }
}
