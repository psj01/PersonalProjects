

package meanalarm;


import java.awt.Toolkit;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.Time;
import java.text.DateFormat;
import java.text.Format;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;
import sun.audio.AudioData;
import sun.audio.AudioPlayer;
import sun.audio.AudioStream;
import sun.audio.ContinuousAudioDataStream;

/**
 *
 * @author Jobin
 */
public class MeanAlarm {
    
    

    
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


