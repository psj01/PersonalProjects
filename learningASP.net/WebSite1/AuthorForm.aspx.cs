using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class AuthorForm : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (IsPostBack)
        {
            fnamelabel.Text = fnameInput.Text;
            lnamelabel.Text = lnameInput.Text;
            doblabel.Text = dobInput.Text;
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        /*
        fnamelabel.Text = fnameInput.Text;
        lnamelabel.Text = lnameInput.Text;
        doblabel.Text = dobInput.Text;
        */

    }
}