<%@ Page Title="" Language="C#" MasterPageFile="~/Worker.Master" AutoEventWireup="true" 
CodeBehind="WorkerFinishApplicationPage.aspx.cs" Inherits="treesafe.Workers.WorkerFinishApplicationPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        成功！
    </h2>

    <p style="font-size: large">
        恭喜您，已经成功提交申请。
        请等待审核。</p>
    <p style="font-size: large" align="left">
        <asp:Button ID="ButtonFinishApplication" runat="server" Text="确定，返回首页" 
            onclick="ButtonFinishApplication_Click" />
    </p>
</asp:Content>
