import java.io.*;

public class LineNumber {
    public static void main(String[] args) {
        FileReader ins=null;
        try {
            ins=new FileReader("./LineNumber.java");
            int ch, count=1;
            System.out.print(count+" ");
            while((ch=ins.read())!=-1) {
                if(ch=='\n') {
                    count++;
                    System.out.print("\n"+count+" ");
                }
                else {
                    System.out.print((char)ch);
                }
            }
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
    }
}
