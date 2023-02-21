import java.io.*;

public class LineWordAndCharacterCount {
    public static void main(String[] args) {
        FileReader ins=null;
        try {
            ins=new FileReader("./input.txt");
            int ch, charCount=0, wordCount=1, lineCount=1;
            while((ch=ins.read())!=-1) {
                if(ch==(int)'\n') {
                    lineCount++;
                    wordCount++;
                }
                else if(ch==(int)' ') {
                    wordCount++;
                }
                charCount++;
            }
            System.out.println("Line Count: "+lineCount);
            System.out.println("Word Count: "+wordCount);
            System.out.println("Character Count: "+charCount);
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
