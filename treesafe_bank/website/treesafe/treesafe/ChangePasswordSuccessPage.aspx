<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="ChangePasswordSuccessPage.aspx.cs" Inherits="treesafe.ChangePasswordSuccessPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
<h2>
    修改密码成功！
</h2>
<p>
&nbsp;
</p>

   <p>
        重新登录系统请点击
        <asp:HyperLink ID="ChangePasswordSuccessHyperLink" runat="server" EnableViewState="false" 
        NavigateUrl="~/Account/Login.aspx">这里</asp:HyperLink>。
    </p>

</asp:Content>
