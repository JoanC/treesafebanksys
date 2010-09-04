<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserFinishApplicationPage.aspx.cs" Inherits="treesafe.Users.UserFinishApplicationPage" %>

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
        <br/>
        请耐心等待审核，这将需要5个左右工作日。</p>
    <p>
    <br/>
        如果5个工作日后，您的申请还没有得到处理，请及时与我们联系。
    </p>
    <p style="font-size: large">
        &nbsp;</p>
        <p>
    返回首页请点击
        <asp:HyperLink ID="RegisterHyperLink" runat="server" EnableViewState="false" NavigateUrl="~/Users/UserRootPage.aspx">
        这里</asp:HyperLink>
        </p>
</asp:Content>
