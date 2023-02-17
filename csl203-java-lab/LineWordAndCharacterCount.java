import java.io.*;

public class LineWordAndCharacterCount {
    public static void main(String[] args) {
        int charCount=0, wordCount=1, lineCount=1;
        FileReader ins=null;
        try {
            ins=new FileReader("./input.txt");
            int ch;
            while((ch=ins.read())!=-1) {
                //assuming that a space or newline is not considered a character
                if(ch==(int)' ' || ch==(int)'\n') {
                    wordCount++;
                }
                else {
                    charCount++;
                }
                if(ch==(int)'\n') {
                    lineCount++;
                }
            }
            System.out.println("Characters="+charCount);
            System.out.println("Words="+wordCount);
            System.out.println("Lines="+lineCount);
        }
        catch(IOException e) {
            System.out.println(e);
        }
        finally {
            try {
                ins.close();
            }
            catch(IOException e){}
        }
    }
}