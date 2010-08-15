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
            string _serverip = "127.0.0.1";
            int _port = 4999;

            client = new TcpClient(_serverip, _port);
            netstream = client.GetStream();

            byte[] data = Encoding.UTF8.GetBytes("Hello world!");
            byte[] resultData = new byte[8 + data.Length];
            BitConverter.GetBytes(data.Length).CopyTo(resultData, 0);
            data.CopyTo(resultData, 8);

            netstream.Write(resultData, 0, resultData.Length);

            client.Close();
        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            SaveNewPass();
        }
    }
}
