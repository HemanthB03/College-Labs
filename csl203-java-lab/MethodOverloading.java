class Shape {
    void calcArea(int a, int b) {
        System.out.println("Area of rectangle is "+(a*b));
    }
    void calcArea(double r) {
        System.out.println("Area of cicle is "+(r*r*3.14));
    }
    void calcArea(int a, int b, int c) {
        double s=(a+b+c)/2.0;
        double area=Math.sqrt((s*(s-a)*(s-b)*(s-c)));
        System.out.println("Area of triangle is "+area);
    }
}

public class MethodOverloading {
    public static void main(String[] args) {
        Shape s=new Shape();
        s.calcArea(10.0);
        s.calcArea(3, 2);
        s.calcArea(4, 13, 15);
    }
}
