

package meanalarm;


import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.PopupMenu;
import java.awt.TextField;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Scanner;
import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import static javax.swing.JFrame.EXIT_ON_CLOSE;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.Timer;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import sun.audio.AudioData;
import sun.audio.AudioPlayer;
import sun.audio.AudioStream;
import sun.audio.ContinuousAudioDataStream;

/**
 *
 * @author Jobin
 */



public class MeanAlarm extends JFrame  {    
    
    
    private final JButton setAlarm = new JButton("SET ALARM");
    
    
    JTextArea label1 = new JTextArea("Current time : ");
    JTextField hr = new JTextField(2);
    JTextArea semi1 = new JTextArea(":");
    JTextField min = new JTextField(2);    
    JTextArea semi2 = new JTextArea(":");
    JTextField sec = new JTextField(2);
    JRadioButton am = new JRadioButton("AM");
    JRadioButton pm = new JRadioButton("PM");
    
    
    JRadioButton am2 = new JRadioButton("AM");
    JRadioButton pm2 = new JRadioButton("PM");
    
    JTextArea label2 = new JTextArea();
    
    
    JTextField ahr = new JTextField(2);
    
    JTextField amin = new JTextField(2);
    
    JTextField asec = new JTextField(2);

    
    private MeanAlarm current = null;  
    
    String hrs,mins;
    
    String a;
    

    public static void main(String[] args)
    {
        createAndShowGUI();
    }

    public static void createAndShowGUI() 
    {
        MeanAlarm frame1 = new MeanAlarm();
        frame1.setDefaultCloseOperation(EXIT_ON_CLOSE);
        frame1.pack();
        frame1.setSize(500, 500);
        frame1.setVisible(true);
        frame1.setResizable(false);
    }

    public MeanAlarm()
    {
        
        super("WAKE UP YO!");
        setLayout(new BorderLayout()); 
        //current = new MeanAlarm(); 
        
        JPanel top = new JPanel();
        top.setLayout(new FlowLayout());
        hr.setEditable(false);
        min.setEditable(false);
        sec.setEditable(false);
        label1.setEditable(false);
        top.add(label1);
        top.add(hr);
        top.add(semi1);
        top.add(min);
        top.add(semi2);        
        top.add(sec);
        top.add(am);
        top.add(pm);
        add(top,BorderLayout.NORTH);
        
        
        JPanel center = new JPanel();
        
        center.setLayout(new FlowLayout());
        center.setBackground(Color.red);
        
        label2.setBackground(Color.red);
        center.add(label2);
        
        add(center, BorderLayout.CENTER);
        
        JPanel south = new JPanel();
        south.setLayout(new FlowLayout());
        south.add(ahr);
        south.add(amin);
        south.add(am2);
        south.add(pm2);
        south.add(setAlarm);
        
        add(south, BorderLayout.SOUTH);
        label2.setText(new Date().toString()); 
        
        Timer t = new Timer(1000, updateClockAction);
        t.start();
        
        a = "39";
        
       
        
        
    }
    
            
    
    
   
        ActionListener updateClockAction = new ActionListener(){
        @Override
        public void actionPerformed(ActionEvent e) 
        {
            //label2.setText(new Date().toString()); 
            Date today = Calendar.getInstance().getTime();
            String x = today.toString();
            label2.setText(today.toString());
            
            hrs = x.substring(11,13);
       System.out.println(hrs);
       
       mins = x.substring(14,16);
       System.out.println(mins);
       
       if(a.equalsIgnoreCase(mins))
       {
           try
           {
               soundAlarm();
           }
           catch (Exception msg)
           {
               System.out.println(msg);
           }
       }
       
       
        }
       
    

};  
        
        
        public static void soundAlarm() throws IOException
	{
            
            ContinuousAudioDataStream loop = null;
            AudioPlayer play = AudioPlayer.player;
            AudioStream sound;
            AudioData soundData;
            sound = new AudioStream(new FileInputStream("bark.wav"));
            soundData = sound.getData();
            loop = new ContinuousAudioDataStream(soundData);
            
            play.start(loop);
              Scanner cin = new Scanner(System.in);
            
            System.out.println("what is 5*2 : ");
       String ans = cin.nextLine();
       while(ans.equals("10") == false)
       {
           System.out.println("WRONG!!! TRY AGAIN!");
           ans = cin.nextLine();
       }
       // STOP ALARM
       play.stop(loop);
       System.out.println("UR AWAKE!");
		
        }

}




















/*
public class MeanAlarm extends JFrame {
    
    public static void main(String[] args) throws IOException {
        
       
                
       Date today = Calendar.getInstance().getTime(); 
      
       
       String x = today.toString();
       
       System.out.println(x);
       
       String day = x.substring(0, 3);
       System.out.println(day);
       
       String month = x.substring(4, 7);
       System.out.println(month);
       
       String date = x.substring(8,11);
       System.out.println(date);
       
       String hr = x.substring(11,13);
       System.out.println(hr);
       
       String min = x.substring(14,16);
       System.out.println(min);
       
       String sec = x.substring(17,19);
       System.out.println(sec);
       
       String timeZone = x.substring(20,23);
       System.out.println(timeZone);
       
       
       String year = x.substring(24,28);
       System.out.println(year);
       
       Scanner cin = new Scanner(System.in);
       
       String go = cin.nextLine();
       
       System.out.println("U entered : " + go);
       
       while(go.equals(min) == false)           
       {
           System.out.println("min is : " + min + " go is : " + go +" So... NOT YET....");
           Date yo = Calendar.getInstance().getTime(); 
      
       
            String y = yo.toString();
            
            min = y.substring(14,16);
       
       
       }
       //ALARM!!
       soundAlarm();
       
      
       
    }
    
    
    
    public static void soundAlarm() throws IOException
	{
            
            ContinuousAudioDataStream loop = null;
            AudioPlayer play = AudioPlayer.player;
            AudioStream sound;
            AudioData soundData;
            sound = new AudioStream(new FileInputStream("bark.wav"));
            soundData = sound.getData();
            loop = new ContinuousAudioDataStream(soundData);
            
            play.start(loop);
              Scanner cin = new Scanner(System.in);
            
            System.out.println("what is 5*2 : ");
       String ans = cin.nextLine();
       while(ans.equals("10") == false)
       {
           System.out.println("WRONG!!! TRY AGAIN!");
           ans = cin.nextLine();
       }
       // STOP ALARM
       play.stop(loop);
       System.out.println("UR AWAKE!");
		
        }
    
}


*/