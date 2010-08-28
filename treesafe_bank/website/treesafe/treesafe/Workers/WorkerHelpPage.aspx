<%@ Page Title="" Language="C#" MasterPageFile="~/Worker.Master" AutoEventWireup="true" 
CodeBehind="WorkerHelpPage.aspx.cs" Inherits="treesafe.Workers.WorkerHelpPage" %>

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
        获取更详细的信息请点击：<asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Workers/WorkerSystemIntro.aspx">这里</asp:HyperLink>
    </p>
        <p class="header" style="font-size: medium; color: #FFFFFF;">
        使用说明</p>

        <p>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        本系统共包含4个使用权限：用户权限（农民），操作员权限，审核员权限，管理员。
        <br/>
         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
         农民可以注册成为系统用户（用户权限）。
         在成为会员后，农民可在线填写申请表进入联保风险控制系统；查看信用评级；查看推荐联保小组；查看联保组内风险评估；实时获知还贷情况（通过手机短信）等。
         <br/>
         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
         操作员（权限）是农信社前台工作人员，一方面负责申请表录入，联保小组组建工作；另一方面可查看各人各组风险评估详细资料。
         <br/>
         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
         审核员（权限）是系统中非常重要的一部分，他们核实农民资料的真实可靠度，保证系统的真实可靠。
         <br/>
         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
         管理员（权限）是控制系统的最主要力量。一方面，管理员可以控制修改风险评估中各项目所占权重，达到对风险评估的动态管理；
         另一方面，控制农信社员工的人事调动。
        </p>
    <p style="color: #3366FF;">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        操作员，您必须登陆本系统才可以使用本在线服务系统。
        <br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
        当您登陆本系统之后，您可以为从柜台进行贷款申请的客户在线填写申请信息；
        在有新的联保小组成立的情况下，为联保小组填写其组员信息。
        在有联保小组解散的情况下，您可以从本系统中删除该小组；有客户在本行销户时，您亦可从本系统中删除该客户的账号。
        </p>
    <p style="color: #3366FF;">
        &nbsp;</p>








</asp:Content>
