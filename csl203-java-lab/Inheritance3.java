class A {
    int x=3;
    void sayHello() {
        System.out.println("Hello");
    }
}

class B extends A {
    int y=9;
    void printXandY() {
        System.out.println("x="+x+", y="+y);
    }
}

public class Inheritance3 {
    public static void main(String[] args) {
        B b=new B();
        b.sayHello();
        b.printXandY();
    }
}
