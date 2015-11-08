/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tiledesigner;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Random;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JToolBar;

/**
 *
 * @author Jobin
 */
public class TileDesignerLayout extends JPanel
{
    String[] imageStringNameA ={"pat1.gif","pat2.gif","pat3.gif","pat4.gif","pat5.gif"};	
    Image[] imageA = new Image[5];	 //image array to hold 5 images that are loaded
    
    JButton patch1btn = new JButton();
    JButton patch2btn = new JButton();
    JButton patch3btn = new JButton();
    JButton patch4btn = new JButton();
    
    
        
    public TileDesignerLayout()
    {
        setLayout(new BorderLayout());
        final TileCanvas centerPanel1ptr = new TileCanvas(); //call class to make center grid
        add(centerPanel1ptr, BorderLayout.CENTER); //Adding centerPanel to outerFrame.
        centerPanel1ptr.ResetGridTile(); //call methods in other class to set stuff up		
        centerPanel1ptr.LoadImageArray();         
        centerPanel1ptr.CreateMouseListener();	//<----------------- mouse stuff
        
         // (also add panel with reset button to SOUTH)
        
        
        
        JToolBar tileToolBar = new JToolBar();	//add buttons to toolbar							
        //JButton patch1btn = new JButton(); 


        //ADD IMAGES TO BUTTONS
        ImageIcon pat1 = new ImageIcon("pat1.gif");
        JButton patch1btn = new JButton(pat1);
        tileToolBar.add(patch1btn);
        patch1btn.addActionListener(new ActionListener()
        {public void actionPerformed(ActionEvent e){centerPanel1ptr.selectedTile = 0;}});
        
        ImageIcon pat2 = new ImageIcon("pat2.gif");
        JButton patch2btn = new JButton(pat2);
        tileToolBar.add(patch2btn);
        patch2btn.addActionListener(new ActionListener()
        {public void actionPerformed(ActionEvent e){centerPanel1ptr.selectedTile = 1;}});
        

        ImageIcon pat3 = new ImageIcon("pat3.gif");
        JButton patch3btn = new JButton(pat3);
        tileToolBar.add(patch3btn);
        patch3btn.addActionListener(new ActionListener()
        {public void actionPerformed(ActionEvent e){centerPanel1ptr.selectedTile = 2;}});
        

        ImageIcon pat4 = new ImageIcon("pat4.gif");
        JButton patch4btn = new JButton(pat4);
        tileToolBar.add(patch4btn);
        patch4btn.addActionListener(new ActionListener()
        {public void actionPerformed(ActionEvent e){centerPanel1ptr.selectedTile = 3;}});
        
        tileToolBar.setBorder(BorderFactory.createLineBorder(Color.blue));
        add(tileToolBar,BorderLayout.NORTH);
        
        
        JPanel southPanel = new JPanel();
        southPanel.setLayout(new FlowLayout());
        
        JButton randomButton = new JButton("Random");
        randomButton.setPreferredSize(new Dimension(150,50));
        randomButton.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e){if(e.getSource()==randomButton){centerPanel1ptr.RandomTile();}}});
        southPanel.add(randomButton); 
        
        
        
        
        JButton resetButton  = new JButton("Reset");
        resetButton.setPreferredSize(new Dimension(150,50));
        resetButton.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e){if(e.getSource()==resetButton){centerPanel1ptr.ResetGridTile();}}});
        southPanel.add(resetButton);        
        southPanel.setBorder(BorderFactory.createLineBorder(Color.blue));
        add(southPanel, BorderLayout.SOUTH);
    }



    
    class TileCanvas extends JPanel implements MouseListener
    {
        static final int squareSide = 50; 
        int GridRow=5;
        int GridCol = 5;						
        int[][] tilesArray = new int[GridRow][GridCol];  //row is y, col is x
        public int selectedTile = -1;
        String[] stringImageName = {"pat1.gif","pat2.gif","pat3.gif","pat4.gif","pat5.gif"};
        Image[] imageA = new Image[5]; //hold 5 gifs
        
        Image[][] gif2dArray = new Image[GridRow][GridCol];

        //gifArry[Xindex, YIndex] = TileDesignerLayout.imageArray;
        
        
         
        public void LoadImageArray()
        {         
            for(int i=0; i < 5 ;i++)
            {
                imageA[i] = (Image) Toolkit.getDefaultToolkit().getImage(imageStringNameA[i]);
                
            }
        }
                
        public void ResetGridTile()
        {
            
            for(int row = 0; row<5; row++)
            {
                for (int col = 0; col < 5; col++)  
                {
                    //copy gif image array over to the drawing grid with inner outer loop
                    gif2dArray[row][col]=null;
                    //g.drawImage(imageA[0], startX+(squareSide*row), startY+(squareSide*col), this);
                }
            }
            
            
            //picImageArray[row][col] = null;
            //use in/out loop   
            this.repaint();  //draw empty grid
        }
        
        public void RandomTile()
        {
            for(int row = 0; row<5; row++)
            {
                for (int col = 0; col < 5; col++)  
                {
                    Random random = new Random();
                    int Low = -1;
                    int High = 4;
                    int randomNum = random.nextInt(High-Low)+Low;
                    if(randomNum!=-1)
                    {                        
                        gif2dArray[row][col]=imageA[randomNum];
                    }
                    else
                    {
                        gif2dArray[row][col]=null;
                    }
                }
            }            
            this.repaint();  //draw empty grid
        }
        
        
        public void CreateMouseListener()//Add mouselistener to Center panel..need mouse methods at bottom
        { 
            addMouseListener(this);
        }

        //user has clicked a tile on panel, now has clicked in the 5 x 5 grid
        @Override
        public void mouseClicked(MouseEvent e) 
        {
         //here we get  a position of the click of mouse –x,y

                          //if it was a valid click in grid
            int x = e.getX();
            int y = e.getY();
            
            
            int gridWidth = GridCol*squareSide;
            int gridHeight = GridRow*squareSide;
            int panelWidth = getWidth();
            int panelHeight = getHeight();
            int startX = (panelWidth-gridWidth)/2; //get starting point to draw grid based 
            int startY = (panelHeight - gridHeight)/2;
            
         if(x >= startX && x <= startX+gridWidth && y >= startY && y <= startY+gridWidth)
         {
           int xIndex = (x-startX)/squareSide; //will be an integer of square clicked
           int yIndex = (y-startY)/squareSide; //wil be an integer of squear clicked
           //System.out.println(xIndex);
           //System.out.println(yIndex);
           //            col      row   
           if(selectedTile!=-1)
           {
               gif2dArray[xIndex][yIndex] = imageA[selectedTile];
           }
            this.repaint();  //show new grid
         }
        }

        
        
        @Override
        public void paintComponent(Graphics g)	//Implementing paint component
        { 
            super.paintComponent(g);
            int gridWidth = GridCol*squareSide;
            int gridHeight = GridRow*squareSide;
            int panelWidth = getWidth();
            int panelHeight = getHeight();
            int startX = (panelWidth-gridWidth)/2; //get starting point to draw grid based 
            int startY = (panelHeight - gridHeight)/2;

           
             
            for(int row = 0; row<5; row++)
            {
                for (int col = 0; col < 5; col++)  
                {
                    //Drawing empty grid of 5*5 with an inner outer loop
                    g.drawRect(startX+(squareSide*row), startY+(squareSide*col), squareSide, squareSide);
                    
                }
            }
            
            
            for(int row = 0; row<5; row++)
            {
                for (int col = 0; col < 5; col++)  
                {
                    //copy gif image array over to the drawing grid with inner outer loop
                    g.drawImage(gif2dArray[row][col], startX+(squareSide*row), startY+(squareSide*col),squareSide, squareSide, this);
                    
                }
            }
          
            
        }

        @Override
        public void mousePressed(MouseEvent e) {
            
        }

        @Override
        public void mouseReleased(MouseEvent e) {
            
        }

        @Override
        public void mouseEntered(MouseEvent e) {
            
        }

        @Override
        public void mouseExited(MouseEvent e) {
            
        }
        
        
    }
    
}


