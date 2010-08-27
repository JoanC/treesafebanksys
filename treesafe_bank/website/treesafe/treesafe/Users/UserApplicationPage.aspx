<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserApplicationPage.aspx.cs" Inherits="treesafe.Users.UserApplicationPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
     <h2>
        在线申请声明
    </h2>
     <p style="font-size: medium">
        欢迎使用农民联保贷款在线申请业务。
     </p>

     <p>
     &nbsp;&nbsp;
     在您填写《网上贷款申请表》之前，请务必阅读此《声明》。本在线申请服务都应是按本声明的条款而为您提供的。您一旦使用本服务，即表示您同意接受本《声明》各项条款的约束。
     <br/>
     </p>
     <p>
     一.	系统声明:
     <br/>
     &nbsp;&nbsp;
     本系统是我行借助于互联网技术提供联保贷款服务及风险评估控制的网络自动服务系统。客户可以登录本系统进行贷款申请、查看个人信用评级、关注小组还贷风险等各种金融服务。本系统拥有操作简单、功能齐备、安全方便等特点。使用本在线服务系统可以
     <br/>
     </p>
     <p>
     二.	用户的帐号，密码和安全性
     <br/>
     &nbsp;&nbsp;
     用户一旦注册成功，成为贷款通的注册会员，将得到一个密码和用户帐号。用户将对用户帐号和密码安全负全部责任。另外，每个用户都要对以其用户帐号进行的所有活动和事件负全责。您可改变您的密码。您若发现任何非法使用用户帐号或存在安全漏洞的情况，请立即通告贷款通。
     <br/>
     </p>
     <p>
     三.	免责声明
     <br/>
     &nbsp;&nbsp;
     对于贷款在线申请业务的客户，应了解并同意以下免责条款：
     <br/>
     &nbsp;&nbsp;&nbsp;&nbsp;
     1.您在填写申请表之前，请务必认真阅读填写说明并按照有关要求正确操作，确保在我社网站贷款申请平台自主操作行为（如：填写个人信息等）的真实性及准确性，以免因操作不当等原因造成损失，我社对此类原因造成的损失将不承担任何责任。
     <br/>
     &nbsp;&nbsp;&nbsp;&nbsp;
     2.本系统通过互联网络为注册会员提供服务。基于本系统所提供的网络服务的专业重要性，您应同意：
     <br/>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
       (1)提供详尽、准确的个人资料。
     <br/>
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
       (2)不断更新注册资料，符合及时、详尽、准确的要求。
       <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;
     您必须对申请表内填写资料的真实性负责。如果您提供的资料包含有不正确的信息，本系统保留结束您使用网络服务资格的权利。
     <br/>
     &nbsp;&nbsp;&nbsp;&nbsp;
     3.本服务涉及到Internet服务，可能会受到各个环节不稳定因素的影响。因此，服务存在因不可抗力、计算机病毒或黑客攻击、系统不稳定、用户所在位置、用户关机以及其他任何技术、互联网络、通信线路原因等造成的服务中断或不能收到《贷款网上申请表》或申请回复结果等的风险，对由此类原因造成的损失我社将不承担任何责任。
     <br/>
     &nbsp;&nbsp;&nbsp;&nbsp;
     4.经我社审查，申请人不符合贷款规定的借款条件而未受理申请时，我社将不承担任何责任。
     <br/>
     &nbsp;&nbsp;&nbsp;&nbsp;
     5. 我社有权在必要时修改本声明，声明一旦发生变动，将会在重要页面上提示修改内容。如果不同意所改动的内容，用户可以主动取消其获得的注册会员资格。如果用户继续享用网络服务，则视为接受声明的变动。

     </p>


     <p>
         <asp:Button ID="BeginApplication" runat="server" Text="接受声明，开始申请" 
             onclick="BeginApplication_Click"/>
     </p>

</asp:Content>
