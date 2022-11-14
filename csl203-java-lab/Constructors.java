class Box {
    int width;
    int height;
    int depth;

    Box() {
        width=10;
        height=10;
        depth=10;
    }
    Box(int w, int h, int d) {
        width = w;
        height = h;
        depth =d;
    }

    void printVol() {
        System.out.println("Volume of box is " + (width*height*depth));
    }
}

//name of netbeans project should be Constructors
public class Constructors {
    public static void main(String[] args) {
        Box b1 = new Box();
        Box b2 = new Box(5, 10, 15);

        System.out.println("box1");
        b1.printVol();
        System.out.println("box2");
        b2.printVol();
    }
}
