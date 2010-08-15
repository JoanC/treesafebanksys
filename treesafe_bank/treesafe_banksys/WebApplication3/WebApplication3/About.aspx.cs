using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;


namespace WebApplication3
{
    public partial class About : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
             
        }
        protected void SaveNewPass()
        {
            TcpClient client;
            NetworkStream netstream;
            string _serverip = "10.60.37.19";
            int _port = 4999;

            client = new TcpClient(_serverip, _port);
            netstream = client.GetStream();

            byte[] data = Encoding.UTF8.GetBytes("Hello world!");
            netstream.Write(data, 0, data.Length);

            client.Close();
        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            SaveNewPass();
        }
    }
}
