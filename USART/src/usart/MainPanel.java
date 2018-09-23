package usart;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MainPanel extends JPanel {

    private class ButtonListener implements ActionListener {

        public MainWindow window;
        public MainPanel mainPanel;
        public int whichPanel;

        public ButtonListener(MainWindow window, MainPanel jpanel, int whichPanel) {
            this.window = window;
            this.mainPanel = jpanel;
            this.whichPanel = whichPanel;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            window.remove(mainPanel);
            switch (whichPanel) {
                case 1:
                    window.add(new LearningPanel(window, mainPanel));
                    break;
                case 2:
                    window.add(new PlayingPanel(window, mainPanel));
                    break;
            }
            window.repaint();

        }
    }

    public MainPanel(MainWindow mainWindow) {
        JButton b1 = new JButton("Learning mode");
        JButton b2 = new JButton("Playing mode");

        JLabel title = new JLabel("Wrathfur E-69");
        title.setAlignmentX(Component.CENTER_ALIGNMENT);
        title.setFont(new Font("Arial", Font.PLAIN, 40));

        Box box = Box.createVerticalBox();
        box.add(title);
        box.add(Box.createVerticalStrut(60));
        box.add(b1);
        box.add(Box.createVerticalStrut(60));
        box.add(b2);
        box.add(Box.createVerticalStrut(50));

        b1.setPreferredSize(new Dimension(500, 500));
        b1.setMinimumSize(b1.getPreferredSize());
        b1.setFont(new Font("Arial", Font.PLAIN, 30));
        b1.setAlignmentX(Component.CENTER_ALIGNMENT);

        b2.setPreferredSize(new Dimension(500, 500));
        b2.setFont(new Font("Arial", Font.PLAIN, 30));
        b2.setMinimumSize(b1.getPreferredSize());
        b2.setAlignmentX(Component.CENTER_ALIGNMENT);

        this.add(box);
        b1.addActionListener(new ButtonListener(mainWindow, this, 1));
        b2.addActionListener(new ButtonListener(mainWindow, this, 2));
    }
}
