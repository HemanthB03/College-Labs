import javax.swing.*;
import java.awt.event.*;

public class NextAndPrevNumber extends JFrame implements ActionListener {
    JButton btn;
    JLabel l1, l2, l3;
    JTextField t1, t2, t3;

    public NextAndPrevNumber() {
        setSize(300, 300);
        setLayout(null);
        setLocationRelativeTo(null);
        setResizable(false);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        l1=new JLabel("Current");
        l1.setBounds(20, 20, 100, 20);
        l2=new JLabel("Previous");
        l2.setBounds(20, 60, 100, 20);
        l3=new JLabel("Next");
        l3.setBounds(20, 100, 100, 20);
        t1=new JTextField();
        t1.setBounds(100, 20, 100, 20);
        t2=new JTextField();
        t2.setBounds(100, 60, 100, 20);
        t3=new JTextField();
        t3.setBounds(100, 100, 100, 20);
        btn=new JButton("Show");
        btn.setBounds(110, 150, 80, 50);

        add(l1);
        add(l2);
        add(l3);
        add(t1);
        add(t2);
        add(t3);
        add(btn);

        btn.addActionListener(this);

        setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==btn) {
            int n=Integer.parseInt(t1.getText());
            t2.setText(String.valueOf(n-1));
            t3.setText(String.valueOf(n+1));
        }
    }

    public static void main(String[] args) {
        new NextAndPrevNumber();
    }
}
