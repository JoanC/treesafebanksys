<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserNoTeamPage.aspx.cs" Inherits="treesafe.Users.UserNoTeamPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        您还没有联保小组！
    </h2>

    <p style="font-size: large">
        您好，系统中并没有找到您的联保小组信息。
        <br/>
        <br/>
        如果您已经提交了申请，请耐心等待审核，我们将会尽快为您处理。
        <br/>
        如果您还没有提交申请表，请和农信社工作人员联系沟通。
    </p>
    <p>
    <br/>
    <br/>
        小提示：农信社工作人员大概需要5个工作日来处理您的申请，请安心等待。
    </p>
</asp:Content>
