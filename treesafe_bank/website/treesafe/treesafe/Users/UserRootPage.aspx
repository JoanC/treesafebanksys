
<%@ Page Title="User Page" Language="C#" MasterPageFile="~/User.master" AutoEventWireup="true"
    CodeBehind="UserRootPage.aspx.cs" Inherits="treesafe.Users.UserRootPage" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        欢迎使用农民联保贷款风险控制系统！
    </h2>
    <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
    简要系统介绍
    </p>
    <p class="leftpic">
        <asp:Image ID="Image1" runat="server" ImageUrl="~/Pictures/gesture1.png"/>   
    </p>
    <p class="rightinfo">
    <br/>
    <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
       万德 农民联保贷款风险控制系统是一个基于农信社主系统的农民联保贷款风险控制系统，是提供联保风险控制评估的辅助管理平台。系统严格监管每一步的风险，实时对贷款风险进行评估，并提出降低风险的方案。
       <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
       系统覆盖了农民联保贷款的整个过程：从联保贷款开始的农民个人信用风险评估，到推荐适合成员组成联保小组，再到对还贷过程的追踪，及同步的动态风险评估。
       <br/>
       <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        万德 农民联保贷款风险控制系统为农民提供了用户权限，农民可以利用本系统完成贷款风险评估申请表，查看个人信用评级和联保组内成员风险评级等。
        <br/>
        <br/>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        获取更详细信息请点击
        <asp:HyperLink ID="HyperLink1" runat="server" EnableViewState="false" NavigateUrl="~/Users/UserHelpPage.aspx">这里</asp:HyperLink>。
    </p>


    </fieldset>
    
    
    <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
    关于在线申请
    </p>
    <p class="leftpic">
        <asp:Image ID="Image2" runat="server" ImageUrl="~/Pictures/gesture2.png"/>
    </p>
    <p class="rightinfo">
    2
    </p>
    </fieldset>
    
    
    <fieldset>
    
    <p class="header" style="font-size: medium; color: #FFFFFF;">
    查看联保小组信息
    </p>

    <p class="leftpic">
        <asp:Image ID="Image3" runat="server" ImageUrl="~/Pictures/gesture3.png"/>
    </p>
    <p class="rightinfo">
    3
    </p>
    </fieldset>

</asp:Content>
