import java.io.*;

public class CopyBytes {
    public static void main(String[] args) {
        FileInputStream ins=null;
        FileOutputStream outs=null;

        try {
            ins=new FileInputStream("./input.txt");
            outs=new FileOutputStream("./output.txt");

            int ch;
            while((ch=ins.read())!=-1) {
                outs.write(ch);
            }
        }
        catch(IOException e) {
            System.out.println(e);
        }
        finally {
            try{
                ins.close();
                outs.close();
            }
            catch(IOException e) {}
        }
    }
}
