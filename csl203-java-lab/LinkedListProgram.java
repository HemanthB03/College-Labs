import java.util.Scanner;

class Node {
    public int data;
    public Node link;
}

public class LinkedListProgram {
    static Node head=null, ptr=null, temp=null;
    public static void insertFirst(int n) {
        temp=new Node();
        temp.data=n;
        temp.link=head;
        head=temp;
        display();
    }
    public static void insertLast(int n) {
        temp=new Node();
        temp.data=n;
        if(head==null) {
            temp.link=head;
            head=temp;
        }
        else {
            ptr=head;
            while(ptr.link!=null) {
                ptr=ptr.link;
            }
            temp.link=null;
            ptr.link=temp;
        }
        display();
    }
    public static void insertAfter(int n, int key) {
        temp=new Node();
        temp.data=n;
        ptr=head;
        while(ptr.data!=key && ptr!=null) {
            ptr=ptr.link;
        }
        if(ptr==null) {
            System.out.println("Key not in list");
        }
        else {
            temp.link=ptr.link;
            ptr.link=temp;
        }
        display();
    }
    public static void deleteFirst() {
        if(head==null) {
            System.out.println("List empty");
            return;
        }
        System.out.println(head.data+" was deleted");
        head=head.link;
        display();
    }
    public static void deleteLast() {
        if(head==null) {
            System.out.println("List empty");
            return;
        }
        ptr=head;
        Node prev=head;
        while(ptr.link!=null) {
            prev=ptr;
            ptr=ptr.link;
        }
        prev.link=null;
        display();
    }
    public static void deleteKey(int key) {
        if(head==null) {
            System.out.println("List empty");
            return;
        }
        ptr=head;
        Node prev=head;
        while(ptr.data!=key && ptr!=null) {
            prev=ptr;
            ptr=ptr.link;
        }
        if(ptr==null) {
            System.out.println("Key not in list");
        }
        else {
            prev.link=ptr.link;
        }
        display();
    }
    public static void display() {
        if(head==null) {
            System.out.println("List is empty");
            return;
        }
        ptr=head;
        System.out.print("List is: ");
        while(ptr!=null) {
            System.out.print(ptr.data+", ");
            ptr=ptr.link;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("\n----Menu----");
        System.out.println("1.Insert First\n2.Insert Last\n3.Insert After a Key");
        System.out.println("4.Delete First\n5.Delete Last\n6.Delete Key");
        System.out.println("7.Display\n8.Exit");

        int ch, x, key;
        do {
            System.out.print("Enter your choice: ");
            ch=sc.nextInt();
            
            switch(ch) {
                case 1:
                    System.out.print("Enter data: ");
                    x=sc.nextInt();
                    insertFirst(x);
                    break;
                case 2:
                    System.out.print("Enter data: ");
                    x=sc.nextInt();
                    insertLast(x);
                    break;
                case 3:
                    System.out.print("Enter data: ");
                    x=sc.nextInt();
                    System.out.print("Enter key to insert after: ");
                    key=sc.nextInt();
                    insertAfter(x, key);
                    break;
                case 4:
                    deleteFirst();
                    break;
                case 5:
                    deleteLast();
                    break;
                case 6:
                    System.out.print("Enter key to delete: ");
                    key=sc.nextInt();
                    deleteKey(key);
                    break;
                case 7:
                    display();
                    break;
                case 8:
                    System.out.println("Exiting program");
                    break;
                default:
                    System.out.println("Option not in menu");
            }
        }
        while(ch!=8);
        sc.close();
    }
}
