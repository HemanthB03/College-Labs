import java.io.*;

public class CopyCharacters {
    public static void main(String[] args) {
        FileReader ins=null;
        FileWriter outs=null;

        try {
            ins=new FileReader("./input.txt");
            outs=new FileWriter("./output.txt");

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
