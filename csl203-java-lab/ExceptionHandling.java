public class ExceptionHandling {
    public static void check() throws ArithmeticException {
        System.out.println("Inside check method");
        throw new ArithmeticException("Demo");
    }
    public static void main(String[] args) {
        try {
            check();
        }
        catch (ArithmeticException e) {
            System.out.println(e);
        }
        finally {
            System.out.println("Inside finally block");
        }
    }
}
