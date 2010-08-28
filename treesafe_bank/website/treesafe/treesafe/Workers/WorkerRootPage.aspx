
<%@ Page Title="User Page" Language="C#" MasterPageFile="~/Worker.master" AutoEventWireup="true"
    CodeBehind="WorkerRootPage.aspx.cs" Inherits="treesafe.Workers.WorkerRootPage" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        欢迎使用农民联保风险控制系统
    </h2>
    <p>
        &nbsp;
    </p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        您的工作信息
    </p>
    <fieldset>
    <p>
          <asp:Label ID="WorkerIDLabel" runat="server" AssociatedControlID="WorkerID">
          工号:
          </asp:Label>
          <asp:Label ID="WorkerID" runat="server" Text="093523"></asp:Label>
    </p>

    <p>
          <asp:Label ID="WorkerNameLabel" runat="server" AssociatedControlID="WorkerName">
          姓名:
          </asp:Label>
          <asp:Label ID="WorkerName" runat="server" Text="xxx"></asp:Label>
    </p>

    <p>
        <asp:Label ID="WorkerSexLabel" runat="server" AssociatedControlID="WorkerSex">
        性别:
        </asp:Label>
        <asp:Label ID="WorkerSex" runat="server" Text="女"></asp:Label> 
    </p>

    <p>
        <asp:Label ID="WorkerAgeLabel" runat="server" AssociatedControlID="WorkerAge">
        年龄:
        </asp:Label>
        <asp:Label ID="WorkerAge" runat="server" Text="36"></asp:Label>
    </p>

    <p>
        <asp:Label ID="WorkerPositionLabel" runat="server" AssociatedControlID="WorkerPosition">
        职位:
        </asp:Label>
        <asp:Label ID="WorkerPosition" runat="server" Text="操作员"></asp:Label>
    </p>

    <p>
        <asp:Label ID="WorkerEmailLabel" runat="server" AssociatedControlID="WorkerEmail">
        电子邮件:
        </asp:Label>
        <asp:Label ID="WorkerEmail" runat="server" Text="xxx#@SFDF.COM"></asp:Label>
    </p>
    </fieldset>
    <p>
        &nbsp;</p>
        <p>

    祝您工作顺利！
    </p>

</asp:Content>
