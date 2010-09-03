<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="WrongPage.aspx.cs" Inherits="treesafe.WrongPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
 <h2>
        提示信息
    </h2>
    <p>
    &nbsp;
    </p>
    <p>
        <asp:Label ID="WrongMsg" runat="server" Text="WrongMsg"></asp:Label>
    </p>

    <p>
        请点击浏览器的退后按钮回到原界面尝试修改.
    </p>
</asp:Content>
