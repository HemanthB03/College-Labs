import java.util.Scanner;

public class PrimeOrNot {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n=sc.nextInt();
        if(n==1) {
            System.out.println("1 is neither prime nor composite");
        }
        else {
            int flag=0;
            for(int i=2; i<=n/2; i++) {
                if(n%i==0) {
                    flag=1;
                }
            }
            if(flag==1) {
                System.out.println("Not prime");
            }
            else System.out.println("Is prime");
        }

        sc.close();
    }    
}
