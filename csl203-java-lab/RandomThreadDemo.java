import java.util.Random;

class RandThread extends Thread {
    public void run() {
        Random rd=new Random();
        for(int i=0; i<10; i++) {
            int n=rd.nextInt(0, 100);
            if(n%2==0) {
                new EvenThread(n).start();
            }
            else {
                new OddThread(n).start();
            }
        }
    }
}

class EvenThread extends Thread {
    int n;
    public EvenThread(int n) {
        this.n=n;
    }
    public void run() {
        System.out.println("Number: "+n+" Even-Square: "+(n*n));
    }
}

class OddThread extends Thread {
    int n;
    public OddThread(int n) {
        this.n=n;
    }
    public void run() {
        System.out.println("Number: "+n+" Odd-Cube: "+(n*n*n));
    }
}

public class RandomThreadDemo {
    public static void main(String[] args) {
        RandThread rdthrd=new RandThread();
        rdthrd.start();
    }
}
