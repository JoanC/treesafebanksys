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
using System.Threading;

namespace QQNet
{
   public partial class QQLogin : System.Web.UI.Page
   {
     public string showQQnet()
     {
         string str = "<a class='c'target=blank href='tencent://message/?uin=744257360>&amp;Site=744257360'>在线解答</a>";
         return str;
     }
   }
 
}
