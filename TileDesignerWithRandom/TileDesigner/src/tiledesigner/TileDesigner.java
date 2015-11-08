/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tiledesigner;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JToolBar;

/**
 *
 * @author Jobin
 */
public class TileDesigner extends JFrame {

    
    public static void main(String[] args)
    {
        createAndShowGUI();    
    }
    
    public static void createAndShowGUI() 
    {
        
        
        TileDesigner frame1 = new TileDesigner();
        frame1.setDefaultCloseOperation(EXIT_ON_CLOSE);
        frame1.pack();
        frame1.setSize(new Dimension(500,500));
        frame1.setResizable(false);
        frame1.setVisible(true);
        
        
        
        
    }
    
    public TileDesigner()
    {
        super("TILE DESIGNER");
        // call a class to design the GUI 
        setLayout(new BorderLayout());
        
        TileDesignerLayout tiledesign = new TileDesignerLayout();
        tiledesign.setBorder(BorderFactory.createLineBorder(Color.blue));
        add(tiledesign,BorderLayout.CENTER);
     
        
        
    }
   
    
    
}
