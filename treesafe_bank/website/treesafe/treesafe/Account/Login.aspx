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
            <div class="accountAd">
            <br/>
            <br/>
            <br/>
            <br/>
            <br/>
            <br/>
            <br/>
            <br/>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                  <a target=blank href=tencent://message/?uin= ""744257360"" Site=QQ:744257360 &Menu=Yes>QQ:在线帮助</a>
            </div>
        </LayoutTemplate>
    </asp:Login>
</asp:Content>
