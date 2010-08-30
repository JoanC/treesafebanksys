<%@ Page Title="" Language="C#" MasterPageFile="~/Admintrator.Master" AutoEventWireup="true" 
CodeBehind="AdmintratorLaborManagementPage.aspx.cs" Inherits="treesafe.Admintrotors.AdmintratorLaborManagementPage" %>

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
background-color:#eaa ;
color:#123456;
}
.css_TR_CK
{
background-color:#ee0 ;
color:#333333;
}
</style>


    <h2>
        员工信息列表
    </h2>
        <asp:Panel ID="Panel1" runat="server" BackColor="#6699FF">
        &nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Button ID="ButtonAddWorker" runat="server" Text="增加雇员" 
            onclick="ButtonAddWorker_Click" />
    </asp:Panel>

    <table style="width: 100%;" class="css_Grid" id="LaborTable" cellpadding="5" cellspacing="0" border="1" runat="server" >
    <tbody>
        <tr class="css_GridTR">
            <td>雇员工号</td>
            <td>雇员类型</td>
            <td>雇员姓名</td>
            <td>雇员身份证号</td>
            <td>雇员性别</td>
            <td>雇员年龄</td>
            <td>雇员地址</td>
            <td>雇员电子邮件</td>
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
               me.className = "css_TR_CK";
           }
    </script></p>
</asp:Content>
