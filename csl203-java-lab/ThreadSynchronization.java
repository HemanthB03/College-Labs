class Display {
    public synchronized void printWord(String msg) {
        System.out.print("["+msg);
        try {
            Thread.sleep(1000);
        }
        catch(Exception e) {
            System.out.println(e.getMessage());
        }
        System.out.print("]");
    }
}

class SyncThread extends Thread {
    private Display d;
    private String msg;

    public SyncThread(Display d, String msg) {
        this.d=d;
        this.msg=msg;
    }
    public void run() {
        d.printWord(msg);
    }
}

public class ThreadSynchronization {
    public static void main(String[] args) {
        Display d=new Display();
        SyncThread t1=new SyncThread(d, "Hello");
        SyncThread t2=new SyncThread(d, "world");
        t1.start();
        t2.start();
    }
}
