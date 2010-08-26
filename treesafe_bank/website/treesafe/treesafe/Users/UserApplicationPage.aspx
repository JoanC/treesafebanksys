<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserApplicationPage.aspx.cs" Inherits="treesafe.Users.UserApplicationPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
     <h2>
        在线申请声明
    </h2>
     <p>
        本系统是一个怎样的系统。
        <br/>
        在线申请的注意事项。声明各种风险合约等等。
     </p>
     <p>
         <asp:Button ID="BeginApplication" runat="server" Text="接受声明，开始申请" 
             onclick="BeginApplication_Click"/>
     </p>

</asp:Content>
