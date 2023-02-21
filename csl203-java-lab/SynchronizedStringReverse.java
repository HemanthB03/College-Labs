class SyncClass {
    public synchronized void reverseString(String msg) {
        StringBuffer sb=new StringBuffer(msg);
        sb.reverse();
        System.out.print("["+sb);
        try {
            Thread.sleep(1000);
        }
        catch(Exception e) {
            System.out.println(e);
        }
        System.out.print("]");
    }
}

class SyncedThread extends Thread {
    SyncClass sync;
    String msg;
    public SyncedThread(SyncClass sync, String msg) {
        this.sync=sync;
        this.msg=msg;
    }
    public void run() {
        sync.reverseString(msg);
    }
}

public class SynchronizedStringReverse {
    public static void main(String[] args) {
        SyncClass sync=new SyncClass();
        SyncedThread t1=new SyncedThread(sync, "Hello");
        SyncedThread t2=new SyncedThread(sync, "World");

        t1.start();
        t2.start();
    }
}
