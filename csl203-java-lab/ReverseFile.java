import java.io.*;
import java.util.Scanner;

public class ReverseFile {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        FileReader ins=null;
        System.out.print("Enter limit: ");
        int n=sc.nextInt();
        StringBuffer sb=new StringBuffer("");
        try {
            ins=new FileReader("./input.txt");
            int ch;
            for(int i=0; i<n; i++) {
                ch=ins.read();
                if(ch==-1) {
                    System.out.println("Ran out of characters in file");
                    break;
                }
                sb.append((char)ch);
            }
            sb.reverse();
            System.out.println(sb);
        }
        catch(IOException e) {
            System.out.println(e);
        }
        finally {
            try {
                ins.close();
            }
            catch(IOException e) {}
        }
        sc.close();
    }
}
