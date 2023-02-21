import java.util.*;

public class StringTokenizerDemo {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter integers with one space gap");
        String str=sc.nextLine();
        StringTokenizer st=new StringTokenizer(str, " ");
        int sum=0;
        System.out.println("The Integers are");
        while(st.hasMoreTokens()) {
            String temp=st.nextToken();
            int n=Integer.parseInt(temp);
            sum+=n;
            System.out.print(n+", ");
        }
        System.out.println("\nSum is "+sum);

        sc.close();
    }
}
