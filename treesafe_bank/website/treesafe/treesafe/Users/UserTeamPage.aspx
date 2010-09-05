<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserTeamPage.aspx.cs" Inherits="treesafe.Users.UserTeamPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
<h2>
    联保小组信息
</h2>

    <asp:Panel ID="Panel1" runat="server" BackColor="#6699FF">
        &nbsp;&nbsp;&nbsp;&nbsp;
    </asp:Panel>

    <table style="width: 100%;" class="css_Grid" id="LaborTable" cellpadding="5" cellspacing="0" border="1" runat="server" >
    <tbody>
        <tr class="css_GridTR">
            <td>编号</td>
            <td>姓名</td>
            <td>证件号码</td>
            <td>性别</td>
            <td>年龄</td>
            <td>电话</td>
            <td>地址</td>
        </tr>

    </tbody>
    </table>

    
    
    <p><script type="text/jscript" language="javascript">
           var clickClass = "";
           var moveClass = "";
           var clickTR;
           var moveTR;
           function Move(me) {
               if (clickTR != me) {
                   if (moveTR != me) {
                       moveClass = me.className;
                       moveTR = me;
                       me.className = "css_TR_move";
                       //alert("a");
                   }
               }
           }

           function Out(me) {
               if (clickTR != me) {
                   moveTR = null;
                   me.className = moveClass;
               }
           }
           function Ck(me, dataID) {
               if (clickTR != me) {
                   if (clickTR) {
                       clickTR.className = clickClass;
                   }
                   clickTR = me;
                   clickClass = moveClass;
               }
               alert("您选择的记录ID：" + dataID);
               //ShowDialog("WorkerOneUserDataPage.aspx?id=" + dataID);
               me.className = "css_TR_CK";
           }
           function ShowDialog(url) {
               var iWidth = 960; //模态窗口宽度
               var iHeight = 540; //模态窗口高度
               var iTop = (window.screen.height - iHeight) / 2;
               var iLeft = (window.screen.width - iWidth) / 2;
               window.open(url, "", "Scrollbars=yes,Toolbar=no,Location=no,Direction=no,Resizeable=yes,   Width=" + iWidth + " ,Height=" + iHeight + ",top=" + iTop + ",left=" + iLeft)
           } 

    </script>
    </p>

</asp:Content>
