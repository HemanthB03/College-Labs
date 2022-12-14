import java.util.*;

public class StringTokenizerDemo {
    public static void main(String[] args) {
        int n;
        int sum=0;

        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the integers with one space gap: ");
        String s=sc.nextLine();
        StringTokenizer st=new StringTokenizer(s, " ");
        System.out.println("The integers are: ");
        while(st.hasMoreTokens()){
            String temp=st.nextToken();
            n=Integer.parseInt(temp);
            System.out.print(n+", ");
            sum+=n;
        }
        System.out.println("\nSum of integers is "+sum);
        sc.close();
    }
}