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

public class LearningPanel extends JPanel {
     private class SendListener implements ActionListener {
        
        private JComboBox allSongsList;
        
        public SendListener(JComboBox allSongsList)
        {
            this.allSongsList = allSongsList;
        }
        private int getColour(JComboBox comboBox)
        {
            String colour = comboBox.getSelectedItem().toString();
            switch(colour){
                case "Wlazł kotek na płotek":
                    return 1;
                case "Kokokoko Euro Spoko":
                    return 2;
                case "Cicha noc":
                    return 3;
                case "Sto lat":
                    return 4;
                case "Sweet Child O' Mine intro":
                    return 5;
            }
            return 0;
        }
        @Override
        public void actionPerformed(ActionEvent e) {
           UsartController sender = new UsartController();
            try {
                sender.sendData("c");
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
            String x1 = Integer.toString(this.getColour(allSongsList));
                        try {
                sender.sendData(x1);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    
    
    }
     private class ButtonListener implements ActionListener {

        public MainWindow window;
        public LearningPanel learningPanel;
        public MainPanel mainPanel;

        public ButtonListener(MainWindow window, LearningPanel learningPanel, MainPanel mainPanel) {
            this.window = window;
            this.learningPanel = learningPanel;
            this.mainPanel = mainPanel;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            window.remove(learningPanel);
            window.add(mainPanel);
            window.repaint();

        }
    }
    public LearningPanel(MainWindow window, MainPanel mainPanel) 
    {
        String[] songStrings = { "Wlazł kotek na płotek", "Kokokoko Euro Spoko", "Cicha noc", "Sto lat", "Sweet Child O' Mine intro" };
        
        JComboBox allsongsList = new JComboBox(songStrings);
        allsongsList.setSelectedIndex(0);
        allsongsList.setAlignmentX(Component.CENTER_ALIGNMENT);
        allsongsList.setPreferredSize(new Dimension(50, 40));
        
        JLabel songsLabel = new JLabel("Select the song you want to learn!");
        songsLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        songsLabel.setFont(new Font("Arial", Font.PLAIN, 25));
        
        JButton sendButton = new JButton("Start learning/reset the song");
        sendButton.addActionListener(new SendListener(allsongsList));
        sendButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        
        JButton backButton = new JButton("<--");
        backButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        backButton.addActionListener(new ButtonListener(window, this, mainPanel));
        
        Box box = Box.createVerticalBox();
        box.add(Box.createVerticalStrut(30));
        box.add(songsLabel);
        box.add(Box.createVerticalStrut(30));
        
        box.add(allsongsList);
        box.add(Box.createVerticalStrut(30));
        box.add(sendButton);
        
        box.add(Box.createVerticalStrut(80));
        box.add(backButton);
        this.add(box);

    }
}
