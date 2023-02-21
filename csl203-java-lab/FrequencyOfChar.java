import java.util.Scanner;

public class FrequencyOfChar {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str=sc.next();
        System.out.print("Enter a character to count: ");
        char ch=sc.next().charAt(0);

        int count=0, n=str.length();
        for(int i=0; i<n; i++) {
            if(str.charAt(i)==ch) {
                count++;
            }
        }
        if(count==0) {
            System.out.println("Character not in string");
        }
        else {
            System.out.println("Frequency of "+ch+" in "+str+" is: "+count);
        }

        sc.close();
    }
}
