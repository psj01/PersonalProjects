using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace passMe
{
    public partial class Form1 : Form
    {
        string[] lines;

        public Form1()
        {
            InitializeComponent();
            btnConvert.Visible = false;
            btnCopy.Visible = false;
            tbUserInput.Visible = false;
            tbResult.Visible = false;
            label1.Visible = false;
            tbResult.Text = " ";
        }

        private void convert(object sender, EventArgs e)
        {
            string result = tbUserInput.Text.ToString();            

            string x = "";
            Hashtable ht = new Hashtable();

            for (int i = 0; i < lines.Length; i++)
            {
                string[] xx = lines[i].Split('=');
                ht.Add(xx[0], xx[1]);
            }


            string userInput = tbUserInput.Text;
            string ans = "";

            for (int i = 0; i < userInput.Length; i++)
            {
                if (ht.ContainsKey(userInput[i].ToString()))
                {
                    if (ht[userInput[i].ToString()].ToString().Length != 0)
                    {
                        ans += ht[userInput[i].ToString()].ToString();
                    }
                    else
                    {
                        ans += userInput[i];
                    }        
                }
                else
                {
                    ans += userInput[i];
                }
            }

            tbResult.Text = ans;
                
        }

        private void copyText(object sender, System.EventArgs e)
        {

            System.Windows.Forms.Clipboard.SetText(tbResult.Text);
        }

        private void locateHash(object sender, System.EventArgs e)
        {
            try
            {
                lines = System.IO.File.ReadAllLines(@""+tbHashLoc.Text+@"");
                btnConvert.Visible = true;
                btnCopy.Visible = true;
                tbHashLoc.Enabled = false;
                label3.Text = "";
                tbUserInput.Visible = true;
                tbResult.Visible = true;
                label1.Visible = true;

            }
            catch (Exception ex)
            {
                label3.Text = "*Unable to open hash file.";
                label3.ForeColor = Color.Red;
                btnConvert.Visible = false;
                btnCopy.Visible = false;
                tbUserInput.Visible = false;
                label1.Visible = false;
                tbResult.Visible = false;
                return;
            }
        }

        private void useNewHash(object sender, System.EventArgs e)
        {
            tbHashLoc.Enabled = true;
            btnConvert.Visible = false;
            btnCopy.Visible = false;
            tbUserInput.Visible = false;
            tbResult.Visible = false;
            label3.Text = "";
            label1.Visible = false;
        }

    }
}

// C:\Users\Jobin\Desktop\pwYo\hash.txt
