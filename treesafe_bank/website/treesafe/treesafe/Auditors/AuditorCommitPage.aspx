<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="AuditorCommitPage.aspx.cs" Inherits="treesafe.Auditors.AuditorCommitPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        审核信息提交成功！
    </h2>

    <p>
    &nbsp;
    </p>

    <p>
        继续审核下一个申请请点击
        <asp:HyperLink ID="RegisterHyperLink" runat="server" EnableViewState="false" NavigateUrl="~/Auditors/AuditorListPage.aspx">
        这里</asp:HyperLink>
    </p>


</asp:Content>
