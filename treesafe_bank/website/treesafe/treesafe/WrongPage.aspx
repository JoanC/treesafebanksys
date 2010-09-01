<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="WrongPage.aspx.cs" Inherits="treesafe.WrongPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
 <h2>
        错误
    </h2>
    <p>
    &nbsp;
    </p>
    <p>
        <asp:Label ID="WrongMsg" runat="server" Text="WrongMsg"></asp:Label>
    </p>

    <p>
        请先登录系统
        <asp:HyperLink ID="RegisterHyperLink" runat="server" EnableViewState="false" NavigateUrl="~/Account/Login.aspx">登录</asp:HyperLink>。
    </p>
</asp:Content>
