using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace rectangles
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            panel1.Refresh();

            String xval = textBox1.Text.ToString();
            String yval = textBox2.Text.ToString();

            int width = 0;
            Int32.TryParse(xval, out width);
            int height = 0;
            Int32.TryParse(yval, out height);

            Pen myPen = new Pen(System.Drawing.Color.Red, 5);
            panel1.CreateGraphics().DrawRectangle(myPen, 1, 1, width, height);
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        
    }
}
