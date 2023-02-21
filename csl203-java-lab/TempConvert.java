import javax.swing.*;
import java.awt.event.*;

public class TempConvert extends JFrame implements ActionListener {
    JButton btn;
    JLabel l1, l2;
    JTextField t1, t2;

    public TempConvert() {
        setSize(300, 300);
        setLayout(null);
        setLocationRelativeTo(null);
        setResizable(false);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        l1=new JLabel("Celsius");
        l1.setBounds(20, 20, 100, 20);
        l2=new JLabel("Farenheit");
        l2.setBounds(20, 60, 100, 20);
        t1=new JTextField();
        t1.setBounds(100, 20, 100, 20);
        t2=new JTextField();
        t2.setBounds(100, 60, 100, 20);
        btn=new JButton("Convert");
        btn.setBounds(110, 125, 80, 50);

        add(l1);
        add(l2);
        add(t1);
        add(t2);
        add(btn);

        btn.addActionListener(this);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==btn) {
            String temp=t1.getText();
            double celsius=Double.parseDouble(temp);
            double farenheit=(celsius*9/5)+32;
            t2.setText(String.valueOf(farenheit));
        }
    }

    public static void main(String[] args) {
        new TempConvert();
    }
}
