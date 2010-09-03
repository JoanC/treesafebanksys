<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserNoRiskEvaluationPage.aspx.cs" Inherits="treesafe.Users.UserNoRiskEvaluationPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        没有风险评估信息！
    </h2>

    <p style="font-size: large">
        您好，系统中并没有找到您的风险评估信息。
        <br/>
        <br/>
        如果您已经提交了申请表，请耐心等待审核，我们将会尽快为您处理。
        <br/>
        如果您还没有提交申请表，请点击
        <asp:HyperLink ID="ApplicationHyperLink" runat="server" EnableViewState="false" NavigateUrl="~/Users/UserApplicationPage.aspx">这里</asp:HyperLink>。
    </p>
    <p>
    <br/>
    <br/>
        如果5个工作日后，您的申请还没有得到处理，请及时与我们联系。
    </p>

</asp:Content>
