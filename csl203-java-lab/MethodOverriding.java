class A {
    void show() {
        System.out.println("Inside A");
    }
}

class B extends A {
    void show() {
        System.out.println("Inside B");
    }
}

//name of netbeans project should be MethodOverriding
public class MethodOverriding {
    public static void main(String[] args) {
        // A a = new A();
        B b = new B();
        // a.show();
        b.show();
    }
}
