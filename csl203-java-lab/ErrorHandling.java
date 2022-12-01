public class ErrorHandling {
    static void check() throws ArithmeticException {
        System.out.println("Inside check method");
        throw new ArithmeticException("demo");
    }

    public static void main(String[] args) {
        try {
            check();
        }
        catch(ArithmeticException e) {
            System.out.println("caught: "+e);
        }
        finally {
            System.out.println("Inside finally block");
        }
    }
}
