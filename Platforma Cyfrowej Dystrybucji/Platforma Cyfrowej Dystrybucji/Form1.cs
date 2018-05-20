using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Platforma_Cyfrowej_Dystrybucji
{
    public partial class Form1 : Form
    {
        ServerConnection server;
        public Form1()
        {
            InitializeComponent();
            server = new ServerConnection();
        }

        private void ServerConnectionButton_Click(object sender, EventArgs e)
        {
            
        }
    }
}
