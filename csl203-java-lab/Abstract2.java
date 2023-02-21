import java.util.Scanner;

abstract class Shape {
    abstract void areaOfFigure(Scanner sc);
}

class Triangle extends Shape {
    void areaOfFigure(Scanner sc) {
        System.out.print("Enter base and height of triangle: ");
        double b=sc.nextDouble();
        double h=sc.nextDouble();
        double area=0.5*b*h;
        System.out.println("Area of triangle is "+area);
    }
}

class Rectangle extends Shape {
    void areaOfFigure(Scanner sc) {
        System.out.print("Enter lenght and breadth of rectanle: ");
        double b=sc.nextDouble();
        double h=sc.nextDouble();
        double area=b*h;
        System.out.println("Area of rectangle is "+area);
    }
}

class Square extends Shape {
    void areaOfFigure(Scanner sc) {
        System.out.print("Enter size of square: ");
        double a=sc.nextDouble();
        double area=a*a;
        System.out.println("Area of square is "+area);
    }
}

public class Abstract2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        new Triangle().areaOfFigure(sc);
        new Rectangle().areaOfFigure(sc);
        new Square().areaOfFigure(sc);
        sc.close();
    }
}
