<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserHelpPage.aspx.cs" Inherits="treesafe.Users.UserHelpPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
   <h2>
        系统帮助信息
    </h2>
    <p>
     &nbsp;&nbsp; &nbsp;&nbsp;
        欢迎使用农民联保贷款风险控制系统
    </p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        系统简介</p>

        <p>
        &nbsp;&nbsp;
        本系统是一个基于农村信用合作社的农民联保贷款风险控制系统，我们对农民联保贷款风险进行评估，并全程监控还贷过程。
        同时，我们帮助农民更方便组建低风险的联保小组，并在还贷过程中自动向农民告知整个还贷情况。
        </p>
        <p>
        &nbsp;&nbsp;
        获取更详细的信息请点击：<asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Users/UserSystemIntro.aspx">这里</asp:HyperLink>
    </p>
        <p class="header" style="font-size: medium; color: #FFFFFF;">
        使用说明</p>
    <p style="color: #3366FF;">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        作为贷款申请人，如果您还不是我们的会员，那么您必须注册成为我们的会员才可以使用本在线服务系统。
        <br/>
        <br/>
         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        您登陆本系统后，您可以在线填写申请表完成贷款的申请，同时我们的系统也将对您个人进行信用评估。
         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        当您完成申请之后，我们会有专人审核您填写的信息，如果您填写的信息真实有效，那么您的个人信息则通过审核，您便可以与其他人组成联保小组进行贷款。
        在您与其他人自愿组成小组进行联保贷款后，本系统会为您实时监控小组中其他成员的还贷情况，从而规避还贷过程中的风险，提高小组联保贷款的成功率。
         <br/>
         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        您亦可修改在本系统中的个人信息，查看您的小组中其他成员的信用评级。
        </p>
    <p style="color: #3366FF;">
        &nbsp;</p>





</asp:Content>
