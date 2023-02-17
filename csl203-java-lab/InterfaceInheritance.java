interface A {
    public void printA();
}

interface B {
    public void printB();
}

class C implements A, B {
    public void printA() {
        System.out.println("Print of A");
    }

    public void printB() {
        System.out.println("Print of B");
    }
}

public class InterfaceInheritance {
    public static void main(String[] args) {
        C c=new C();
        c.printA();
        c.printB();
    }
}