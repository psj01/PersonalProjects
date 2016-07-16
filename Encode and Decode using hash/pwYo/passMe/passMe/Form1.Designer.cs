namespace passMe
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tbUserInput = new System.Windows.Forms.TextBox();
            this.btnConvert = new System.Windows.Forms.Button();
            this.tbResult = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCopy = new System.Windows.Forms.Button();
            this.tbHashLoc = new System.Windows.Forms.TextBox();
            this.btnHashLocSubmit = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.btnNewHash = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // tbUserInput
            // 
            this.tbUserInput.Location = new System.Drawing.Point(302, 159);
            this.tbUserInput.Multiline = true;
            this.tbUserInput.Name = "tbUserInput";
            this.tbUserInput.Size = new System.Drawing.Size(142, 59);
            this.tbUserInput.TabIndex = 0;
            // 
            // btnConvert
            // 
            this.btnConvert.BackColor = System.Drawing.Color.DarkGreen;
            this.btnConvert.ForeColor = System.Drawing.SystemColors.MenuText;
            this.btnConvert.Location = new System.Drawing.Point(332, 242);
            this.btnConvert.Name = "btnConvert";
            this.btnConvert.Size = new System.Drawing.Size(75, 23);
            this.btnConvert.TabIndex = 1;
            this.btnConvert.Text = "Convert";
            this.btnConvert.UseVisualStyleBackColor = false;
            this.btnConvert.Click += new System.EventHandler(this.convert);
            // 
            // tbResult
            // 
            this.tbResult.Location = new System.Drawing.Point(302, 289);
            this.tbResult.Multiline = true;
            this.tbResult.Name = "tbResult";
            this.tbResult.ReadOnly = true;
            this.tbResult.Size = new System.Drawing.Size(142, 52);
            this.tbResult.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(247, 130);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(260, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Enter your phrase below and click the convert button.";
            // 
            // btnCopy
            // 
            this.btnCopy.BackColor = System.Drawing.Color.OliveDrab;
            this.btnCopy.ForeColor = System.Drawing.SystemColors.MenuText;
            this.btnCopy.Location = new System.Drawing.Point(332, 347);
            this.btnCopy.Name = "btnCopy";
            this.btnCopy.Size = new System.Drawing.Size(75, 23);
            this.btnCopy.TabIndex = 4;
            this.btnCopy.Text = "Copy";
            this.btnCopy.UseVisualStyleBackColor = false;
            this.btnCopy.Click += new System.EventHandler(this.copyText);
            // 
            // tbHashLoc
            // 
            this.tbHashLoc.Location = new System.Drawing.Point(194, 70);
            this.tbHashLoc.Name = "tbHashLoc";
            this.tbHashLoc.Size = new System.Drawing.Size(313, 20);
            this.tbHashLoc.TabIndex = 5;
            // 
            // btnHashLocSubmit
            // 
            this.btnHashLocSubmit.BackColor = System.Drawing.Color.YellowGreen;
            this.btnHashLocSubmit.ForeColor = System.Drawing.SystemColors.MenuText;
            this.btnHashLocSubmit.Location = new System.Drawing.Point(513, 70);
            this.btnHashLocSubmit.Name = "btnHashLocSubmit";
            this.btnHashLocSubmit.Size = new System.Drawing.Size(75, 23);
            this.btnHashLocSubmit.TabIndex = 6;
            this.btnHashLocSubmit.Text = "Submit";
            this.btnHashLocSubmit.UseVisualStyleBackColor = false;
            this.btnHashLocSubmit.Click += new System.EventHandler(this.locateHash);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(191, 54);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(397, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Please enter the full path of the hash file on your computer below and press subm" +
    "it:";
            // 
            // btnNewHash
            // 
            this.btnNewHash.BackColor = System.Drawing.Color.Tomato;
            this.btnNewHash.ForeColor = System.Drawing.SystemColors.MenuText;
            this.btnNewHash.Location = new System.Drawing.Point(594, 70);
            this.btnNewHash.Name = "btnNewHash";
            this.btnNewHash.Size = new System.Drawing.Size(76, 23);
            this.btnNewHash.TabIndex = 8;
            this.btnNewHash.Text = "new hash";
            this.btnNewHash.UseVisualStyleBackColor = false;
            this.btnNewHash.Click += new System.EventHandler(this.useNewHash);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(194, 97);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 13);
            this.label3.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Navy;
            this.ClientSize = new System.Drawing.Size(798, 441);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnNewHash);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btnHashLocSubmit);
            this.Controls.Add(this.tbHashLoc);
            this.Controls.Add(this.btnCopy);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbResult);
            this.Controls.Add(this.btnConvert);
            this.Controls.Add(this.tbUserInput);
            this.ForeColor = System.Drawing.SystemColors.Window;
            this.Name = "Form1";
            this.Text = "Encode - psj";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbUserInput;
        private System.Windows.Forms.Button btnConvert;
        private System.Windows.Forms.TextBox tbResult;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCopy;
        private System.Windows.Forms.TextBox tbHashLoc;
        private System.Windows.Forms.Button btnHashLocSubmit;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnNewHash;
        private System.Windows.Forms.Label label3;
    }
}

