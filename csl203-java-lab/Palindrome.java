import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a word: ");
        String word=sc.next();
        int n=word.length();
        int flag=0;
        for(int i=0, j=n-1; i<n/2; i++, j--) {
            if(word.charAt(i)!=word.charAt(j)) {
                flag=1;
            }
        }

        if(flag==1) {
            System.out.println("Not Palindrome");
        }
        else {
            System.out.println("Is Palindrome");
        }

        sc.close();
    }
}
