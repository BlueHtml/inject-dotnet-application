using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        private string[] _args;

        public Form1(string[] args)
        {
            InitializeComponent();
            _args = args;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(AppDomain.CurrentDomain.BaseDirectory, "路径");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            foreach (var item in _args)
            {
                MessageBox.Show(item, "参数");
            }
        }
    }
}
