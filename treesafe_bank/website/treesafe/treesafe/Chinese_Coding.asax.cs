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
using System.Runtime.InteropServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;
using ClientNet;


namespace Chinese_Encode
{
    class Chinese_Encode_Mgr 
    {
        public static string utf7_convert(string _src) 
        {
            byte[] bytes = System.Text.Encoding.UTF7.GetBytes(_src);
            _src = System.Text.Encoding.ASCII.GetString(bytes);
            return _src;
        }
    };
}
