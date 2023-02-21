class OddThread extends Thread {
    public void run() {
        for(int i=0; i<=100; i++) {
            if(i%2!=0) {
                System.out.println("Odd Thread: "+i);
            }
        }
    }
}

class EvenThread extends Thread {
    public void run() {
        for(int i=0; i<=100; i++) {
            if(i%2==0) {
                System.out.println("Even Thread: "+i);
            }
        }
    }
}

public class OddAndEvenThreads {
    public static void main(String[] args) {
        OddThread o=new OddThread();
        EvenThread e=new EvenThread();

        o.start();
        e.start();
    }
}
