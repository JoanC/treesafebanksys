<%@ Page Title="" Language="C#" MasterPageFile="~/Worker.Master" AutoEventWireup="true" 
CodeBehind="WorkerFinishApplicationPage.aspx.cs" Inherits="treesafe.Workers.WorkerFinishApplicationPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        成功！
    </h2>

    <p>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Image ID="Image1" runat="server" ImageUrl="~/Pictures/ok.png" ImageAlign="Left"/>
    </p>

    <p style="font-size: large">
        恭喜您，已经成功提交申请。
        请等待审核。</p>
    <p>
    <br/>
    <br/>
    <br/>
    返回首页请点击
        <asp:HyperLink ID="RegisterHyperLink" runat="server" EnableViewState="false" NavigateUrl="~/Users/UserRootPage.aspx">
        这里</asp:HyperLink>
        </p>
</asp:Content>
