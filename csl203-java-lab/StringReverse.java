import java.util.Scanner;

public class StringReverse {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str=sc.next();
        System.out.print("Reverse is: ");
        for(int i=str.length()-1; i>=0; i--) {
            System.out.print(str.charAt(i));
        }
        System.out.println();
        sc.close();
    }
}