<%@ Page Title="" Language="C#" MasterPageFile="~/Admintrator.Master" AutoEventWireup="true" 
CodeBehind="AdmintratorLaborManagementPage.aspx.cs" Inherits="treesafe.Admintrotors.AdmintratorLaborManagementPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        员工信息列表
    </h2>
        <asp:Panel ID="Panel1" runat="server" BackColor="#6699FF">
        &nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Button ID="ButtonAddWorker" runat="server" Text="增加雇员" 
            onclick="ButtonAddWorker_Click" />
        &nbsp;&nbsp;
        <asp:Button ID="ButtonDeleteWorker" runat="server" Text="删除雇员" 
            onclick="ButtonDeleteWorker_Click" />
    </asp:Panel>
    
    <asp:GridView ID="GridView1" runat="server" Width="100%">
    </asp:GridView>

    

    
</asp:Content>
