class MyException extends Exception {
    public MyException(String name) {
        super(name);
        System.out.println("MyException type thrown");
    }
}

public class UserDefinedException {
    static void check() throws MyException {
        System.out.println("Inside check function");
        throw new MyException("Test Exception");
    }

    public static void main(String[] args) {
        try {
            check();
        }
        catch(MyException e) {
            System.out.println(e);
        }
        finally {
            System.out.println("Inside finally block");
        }
    }
}
