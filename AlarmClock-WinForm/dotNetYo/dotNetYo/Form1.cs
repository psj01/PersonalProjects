using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dotNetYo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            label5.Visible = false;
            this.BackColor = System.Drawing.Color.Red;
            button2.Enabled = false;
            button2.BackColor = Color.Gray;

            label2.Text = DateTime.Now.ToShortTimeString();
            label3.Text = " ";
            label4.Text = " ";
        }

        

        private void button1_Click(object sender, EventArgs e)
        {
            button2.Enabled = true;
            button1.Enabled = false;
            RadioButton rb = null;

            if (radioButton1.Checked == true)
            {
                rb = radioButton1;
            }
            else if (radioButton2.Checked == true)
            {
                rb = radioButton2;
            }


            if (comboBox1.SelectedIndex == -1) 
            {
                MessageBox.Show("Pick the hour!");
                button1.Enabled = true;
                button2.Enabled = false;
                
            }
            else if (comboBox2.SelectedIndex == -1)
            {
                MessageBox.Show("Pick the minutes!");
                button1.Enabled = true;
                button2.Enabled = false;
            }
            else
            {
                button1.BackColor = Color.Gray;
                button2.BackColor = Color.Yellow;
                label4.Text = "Alarm set for: ";
                label3.Text = comboBox1.Text + ":" + comboBox2.Text + " " +rb.Text;
            }
            
                   

        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            label2.Text = DateTime.Now.ToShortTimeString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            button2.Enabled = false;
            button1.Enabled = true;
            button1.BackColor = Color.YellowGreen;
            button2.BackColor = Color.Gray;
            label3.Text = " ";
            label4.Text = " ";
            label5.Visible = false;
            label3.Visible = true;
            label4.Visible = true;
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (label3.Text == label2.Text )
            {
               // AutoClosingMessageBox.Show("Wake Up!", "ALARM", 1000);
              //  MessageBox.Show("WAKE UP!");
                SystemSounds.Beep.Play();
                label3.Visible = false;
                label4.Visible = false;
                label5.Visible = true;
                label5.Font = new Font(label5.Font, FontStyle.Bold);
                label5.Text = "Wake Up!.....Wake Up!.....";

            }
        }

    }


    /*
    public class AutoClosingMessageBox
    {
        System.Threading.Timer _timeoutTimer;
        string _caption;
        AutoClosingMessageBox(string text, string caption, int timeout)
        {
            _caption = caption;
            _timeoutTimer = new System.Threading.Timer(OnTimerElapsed,
                null, timeout, System.Threading.Timeout.Infinite);
            MessageBox.Show(text, caption);
        }

        public static void Show(string text, string caption, int timeout)
        {
            new AutoClosingMessageBox(text, caption, timeout);
        }

        void OnTimerElapsed(object state)
        {
            IntPtr mbWnd = FindWindow(null, _caption);
            if (mbWnd != IntPtr.Zero)
                SendMessage(mbWnd, WM_CLOSE, IntPtr.Zero, IntPtr.Zero);
            _timeoutTimer.Dispose();
        }
        const int WM_CLOSE = 0x0010;
        [System.Runtime.InteropServices.DllImport("user32.dll", SetLastError = true)]
        static extern IntPtr FindWindow(string lpClassName, string lpWindowName);
        [System.Runtime.InteropServices.DllImport("user32.dll", CharSet = System.Runtime.InteropServices.CharSet.Auto)]
        static extern IntPtr SendMessage(IntPtr hWnd, UInt32 Msg, IntPtr wParam, IntPtr lParam);
    }
    */

}
