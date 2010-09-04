<%@ Page Title="" Language="C#" MasterPageFile="~/Worker.Master" AutoEventWireup="true" 
CodeBehind="WorkerTeamPage.aspx.cs" Inherits="treesafe.Workers.WorkerTeamPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
<style type="text/css"> 
.css_Grid1
{
padding:3px;
border:1px;
border-width:1px;
border-color:#ffee00;
width:100%;
border-collapse:collapse;
}
.css_Grid
{
color:Black;
background-color:#ffffee;
border-color:#5D7B9D;
border-width:1px;
border-style:solid;
width:450px;
}
.css_GridTR
{
color:White;
background-color:#5D7B9D;
}
td
{
font-size: 9pt;
padding:3px;
}
.css_TR_c1
{
background-color:#ffffee ;
color:#000000;
}
.css_TR_c2
{
background-color:#ffffaa ;
color:#993300;
}
.css_TR_move
{
background-color:#3366FF ;
color:#123456;
}
.css_TR_CK
{
background-color:#6699FF ;
color:#333333;
}
</style>


    <h2>
        联保小组列表
    </h2>
        <asp:Panel ID="Panel1" runat="server" BackColor="#6699FF">
        &nbsp;&nbsp;&nbsp;&nbsp;
    </asp:Panel>

    <table style="width: 100%;" class="css_Grid" id="LaborTable" cellpadding="5" cellspacing="0" border="1" runat="server" >
    <tbody>
        <tr class="css_GridTR">
            <td>编号</td>
            <td>组长</td>
            <td>性别</td>
            <td>电话</td>
            <td>地址</td>
            <td>还贷能力评级</td>
            <td>个人信誉评级</td>
            <td>还贷风险评级</td>
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
               //alert("您选择的记录ID：" + dataID);
               ShowDialog("WorkerOneUserDataPage.aspx?id=" + dataID);
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
