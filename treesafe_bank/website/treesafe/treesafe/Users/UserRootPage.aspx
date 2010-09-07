
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
    <br/>
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    当您成为我们的注册会员之后，您就可以在线填写贷款申请表了。
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    请仔细填写您的个人信息。同时您必须对申请表内填写资料的真实性负责。本社将对您填写的一切信息保密，请放心填写。
    <br/>
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    当您顺利填写完在线贷款申请表后，您就可以静心等待，我们会有专门的审核人员对您填写的信息进行实地考察探访。
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    若您的信息真实有效，那么您的申请将通过审核，我们将以短信形式通知您，您就可以继续进行联保贷款的下一步了。
    若您的信息与实际情况存在出入，那么您的申请将不能通过审核，我们同样将以短信形式通知您。
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    届时您可以再行登陆本系统，自行修改，重新提交；或者前往本社柜台，由柜台操作员为您进行修改。
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
    <br/>
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    当您已经加入联保贷款小组后，柜台操作员将会您所在小组的信息录入本系统，并与您个人的信息相关联。
    
    <br/>
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    届时您就可以自行登陆本系统查看您所在联保小组的信息。
    <br/>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    您可以查看您所在联保小组内其他成员的编号、姓名等基本信息，可以查看其他成员的个人信用评级，
    更关键的是您还可以关注其他成员的还贷情况，一旦其他成员还贷情况出现问题，您也会收到本社的短信通知。

    </p>
    </fieldset>

</asp:Content>
