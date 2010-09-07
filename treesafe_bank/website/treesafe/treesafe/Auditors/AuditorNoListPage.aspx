<%@ Page Title="" Language="C#" MasterPageFile="~/Auditor.Master" AutoEventWireup="true"
 CodeBehind="AuditorNoListPage.aspx.cs" Inherits="treesafe.Auditors.AuditorNoListPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
<h2>
        没有带审核的申请！
    </h2>
    <fieldset>
    <fieldset>
    <div class="leftpic">
        <asp:Image ID="Image2" runat="server" ImageUrl="~/Auditors/Pictures/lure.png"/>   
    </div>
    <div class="rightinfo">
    <br/>
    <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
       您好，系统中并没有找到待审核的申请!
       <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
       
       <br/>
       <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
       请您尽情享受这难得的闲暇时光吧~
        <br/>
        <br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </div>
  
    </fieldset>
</asp:Content>
