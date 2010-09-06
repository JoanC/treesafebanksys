<%@ Page Title="Log In" Language="C#" MasterPageFile="~/Welcome.master" AutoEventWireup="true"
    CodeBehind="Login.aspx.cs" Inherits="treesafe.Account.Login" %>

<SCRIPT runat="server">

private bool SiteSpecificAuthenticationMethod(string UserName, string Password)
{   
    // Insert code that implements a site-specific custom 
    // authentication method here.
    //
    // This example implementation always returns false.
    send_to_server(UserName, Password);
    return true;
}

private void OnAuthenticate(object sender, AuthenticateEventArgs e)
{
    bool Authenticated = false;
    Authenticated = SiteSpecificAuthenticationMethod(LoginUser.UserName, LoginUser.Password);

    e.Authenticated = Authenticated;
} 

</SCRIPT>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
<body>
  <SCRIPT FOR=window EVENT=onload LANGUAGE="javascript">
initAd();//载入页面后，调用函数initAd()
</SCRIPT>
<script language="javascript">
<!--
    function initAd() {
        document.all.AdLayer.style.posTop = -200;
        //设置onLoad事件激发以后，广告层相对于固定后的y方向位置
        document.all.AdLayer.style.visibility = 'visible'//设置层为可见
        MoveLayer('AdLayer'); //调用函数MoveLayer()
    }
    function MoveLayer(layerName) {
        var x = 0; //浮动层固定于浏览器的x方向位置
        var y = 200; //浮动层固定于浏览器的y方向位置
        var diff = (document.body.scrollTop + y - document.all.AdLayer.style.posTop) * .40;
        var y = document.body.scrollTop + y - diff;
        eval("document.all." + layerName + ".style.posTop = y");
        eval("document.all." + layerName + ".style.posright = x"); //移动广告层
        setTimeout("MoveLayer('AdLayer');", 0); //设置20毫秒后再调用函数MoveLayer()
    }
//-->
</script>

<div id=AdLayer 
        style='position:absolute; width:157px; height:215px; z-index:20; visibility:hidden;; right: 10px; top: 108px' 
        align="left">
<image src = "Pictures\divbg.png"></image>
<a target=blank href=tencent://message/?uin= ""744257360"" Site=QQ:744257360 &Menu=Yes>QQ:在线帮助</a>
</div>

</body>

     <h2>
        欢迎使用万德农民联保贷款风险控制系统
    </h2>

    <p>
        请在下面输入用户名和密码登录系统，如果您还没有账号请先
        <asp:HyperLink ID="RegisterHyperLink" runat="server" EnableViewState="false">注册</asp:HyperLink>。
    </p>
    <asp:Login ID="LoginUser" runat="server" EnableViewState="false" 
        RenderOuterTable="false" OnAuthenticate="OnAuthenticate">
        <LayoutTemplate>
            <span class="failureNotification">
                <asp:Literal ID="FailureText" runat="server"></asp:Literal>
            </span>
            <asp:ValidationSummary ID="LoginUserValidationSummary" runat="server" 
                CssClass="failureNotification"/>
            <div class="accountInfo">
                <fieldset class="login">
                <p class="header" style="font-size: medium; color: #FFFFFF;">
                账户信息</p>
                    
                    <p>
                        <asp:Label ID="UserNameLabel" runat="server" AssociatedControlID="UserName">用户名:</asp:Label>
                        <asp:TextBox ID="UserName" runat="server" CssClass="textEntry"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="UserNameRequired" runat="server" ControlToValidate="UserName" 
                             CssClass="failureNotification" ErrorMessage="User Name is required." ToolTip="User Name is required." 
                             ValidationGroup="LoginUserValidationGroup">*</asp:RequiredFieldValidator>
                    </p>
                    <p>
                        <asp:Label ID="PasswordLabel" runat="server" AssociatedControlID="Password">密码:</asp:Label>
                        <asp:TextBox ID="Password" runat="server" CssClass="passwordEntry" TextMode="Password"></asp:TextBox>
                        <asp:RequiredFieldValidator ID="PasswordRequired" runat="server" ControlToValidate="Password" 
                             CssClass="failureNotification" ErrorMessage="Password is required." ToolTip="Password is required." 
                             ValidationGroup="LoginUserValidationGroup">*</asp:RequiredFieldValidator>
                    </p>
                    <p>
                        <asp:CheckBox ID="RememberMe" runat="server"/>
                        <asp:Label ID="RememberMeLabel" runat="server" AssociatedControlID="RememberMe" CssClass="inline">记住我</asp:Label>
                    </p>
                </fieldset>
                <p class="submitButton">
                    <asp:Button ID="LoginButton" runat="server" CommandName="Login" Text="登录" ValidationGroup="LoginUserValidationGroup"/>
                </p>
            </div>
        </LayoutTemplate>
    </asp:Login>
</asp:Content>
