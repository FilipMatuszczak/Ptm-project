package usart;

import java.awt.Dimension;
import javax.swing.JFrame;

public class MainWindow extends JFrame {

    public MainWindow() {

        this.setLocationRelativeTo(null);
        this.setSize(new Dimension(450, 400));
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        MainPanel mainPanel = new MainPanel(this);
        this.add(mainPanel);
        this.setVisible(true);
    }
}
