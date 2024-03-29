abstract class Shape {
    abstract void numberOfSides();
}

class Triangle extends Shape {
    void numberOfSides() {
        System.out.println("Triangle has 3 sides");
    }
}

class Rectangle extends Shape {
    void numberOfSides() {
        System.out.println("Rectangle has 4 sides");
    }
}

class Hexagon extends Shape {
    void numberOfSides() {
        System.out.println("Hexagon has 6 sides");
    }
}

public class AbstractClass {
    public static void main(String[] args) {
        Triangle t=new Triangle();
        t.numberOfSides();

        Rectangle r=new Rectangle();
        r.numberOfSides();

        Hexagon h=new Hexagon();
        h.numberOfSides();
    }
}
