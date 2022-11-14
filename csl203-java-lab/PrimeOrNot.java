import java.util.Scanner;

public class PrimeOrNot {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a no: ");
        int n=sc.nextInt();
        if(n==1) {
            System.out.println("1 is not prime or composite");
        }
        else {
            int i, flag = 0;
            for(i=2; i<=n/2; i++) {
                if(n%2==0) {
                    flag=1;
                    break;
                }
            }
            if(flag==1) {
                System.out.println("Not prime");
            }
            else {
                System.out.println("Is prime");
            }
        }
        sc.close();//not needed in lab, this is to stop warning in my system
    }
}