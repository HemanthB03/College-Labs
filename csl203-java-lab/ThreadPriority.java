class A extends Thread {
    public void run() {
        for(int i=0; i<=10; i++) {
            System.out.println("ThreadA: "+i);
        }
    }
}

class B extends Thread {
    public void run() {
        for(int i=0; i<=10; i++) {
            System.out.println("ThreadB: "+i);
        }
    }
}

class C extends Thread {
    public void run() {
        for(int i=0; i<=10; i++) {
            System.out.println("ThreadC: "+i);
        }
    }
}


public class ThreadPriority {
    public static void main(String[] args) {
        A a=new A();
        a.setPriority(Thread.MIN_PRIORITY);
        B b=new B();
        b.setPriority(a.getPriority()+1);
        C c=new C();
        c.setPriority(Thread.MAX_PRIORITY);

        a.start();
        b.start();
        c.start();
    }
}
