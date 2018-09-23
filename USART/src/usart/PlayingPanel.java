package usart;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class PlayingPanel extends JPanel {
    private class SendListener implements ActionListener {
        
        private JComboBox allColourList;
        
        public SendListener(JComboBox allColourList)
        {
            this.allColourList = allColourList;
        }
        private int getColour(JComboBox comboBox)
        {
            String colour = comboBox.getSelectedItem().toString();
            switch(colour){
                case "Red":
                    return 1;
                case "Green":
                    return 2;
                case "Blue":
                    return 3;
                case "Pink":
                    return 4;
                case "Yellow":
                    return 5;
                case "Cyan":
                    return 6;
            }
            return 0;
        }
        @Override
        public void actionPerformed(ActionEvent e) {
           UsartController sender = new UsartController();
            try {
                sender.sendData("a");
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
            String x1 = Integer.toString(this.getColour(allColourList));
                        try {
                sender.sendData(x1);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    
    
    }
    private class ButtonListener implements ActionListener {

        public MainWindow window;
        public PlayingPanel playingPanel;
        public MainPanel mainPanel;

        public ButtonListener(MainWindow window, PlayingPanel playingPanel, MainPanel mainPanel) {
            this.window = window;
            this.playingPanel = playingPanel;
            this.mainPanel = mainPanel;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            window.remove(playingPanel);
            window.add(mainPanel);
            window.repaint();

        }
    }
    public PlayingPanel(MainWindow window, MainPanel mainPanel) 
    {
        String[] colourStrings = { "Red", "Green", "Blue", "Pink", "Yellow", "Cyan" };
        
        JComboBox allColourList = new JComboBox(colourStrings);
        allColourList.setSelectedIndex(0);
        allColourList.setAlignmentX(Component.CENTER_ALIGNMENT);
        allColourList.setPreferredSize(new Dimension(50, 40));
        
        JLabel allColourLabel = new JLabel("Select the colour of your keys!");
        allColourLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        allColourLabel.setFont(new Font("Arial", Font.PLAIN, 30));
        
        JButton sendButton = new JButton("Apply colour changes");
        sendButton.addActionListener(new SendListener(allColourList));
        sendButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        JButton backButton = new JButton("<--");
        backButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        backButton.addActionListener(new ButtonListener(window, this, mainPanel));
        
        Box box = Box.createVerticalBox();
        
        box.add(Box.createVerticalStrut(30));
        box.add(allColourLabel);
        box.add(Box.createVerticalStrut(30));
        
        box.add(allColourList);
        box.add(Box.createVerticalStrut(30));
        
        box.add(sendButton);
        box.add(Box.createVerticalStrut(80));
        box.add(backButton);
        this.add(box);
    }
}
