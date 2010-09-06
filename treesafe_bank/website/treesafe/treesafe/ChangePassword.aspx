<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="ChangePassword.aspx.cs" Inherits="treesafe.ChangePassword" %>
<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        修改个人密码
    </h2>
    <p>
        &nbsp;
    </p>
    <span class="failureNotification">
         <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="UserInfoValidationSummary" runat="server" CssClass="failureNotification" 
              ValidationGroup="UserInfoValidationGroup"/>
              <div>
    <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        您的账户信息
    </p>
    <p>
          <asp:Label ID="UserNameLabel" runat="server" AssociatedControlID="UserName">
          您好，
          </asp:Label>
          <asp:Label ID="UserName" runat="server" Text="姓名"></asp:Label>
    </p>
    <p>
        <asp:Label ID="UserOldPasswordLabel" runat="server" AssociatedControlID="UserOldPassword">
        您的旧密码:
        </asp:Label>
        <asp:TextBox ID="UserOldPassword" runat="server" CssClass="textEntry"></asp:TextBox>
        <asp:RequiredFieldValidator ID="UserOldPasswordRequire" runat="server" ControlToValidate="UserOldPassword" 
             CssClass="failureNotification" ErrorMessage="请输入您现在的密码" ToolTip="请输入您现在的密码" 
             ValidationGroup="UserInfoValidationGroup">*</asp:RequiredFieldValidator>
        <asp:RegularExpressionValidator ID="UserOldPasswordRange" runat="server" ControlToValidate="UserOldPassword" 
             ErrorMessage="请将密码长度控制在6~15个字符之间" ValidationExpression="([\s\S]{6,15})" ForeColor="Blue">
        </asp:RegularExpressionValidator>
    </p>

    <p>
        <asp:Label ID="UserPasswordLabel" runat="server" AssociatedControlID="UserPassword">
        您的新密码:
        </asp:Label>
        <asp:TextBox ID="UserPassword" runat="server" CssClass="textEntry"></asp:TextBox>
        <asp:RequiredFieldValidator ID="UserPasswordRequired" runat="server" ControlToValidate="UserPassword" 
             CssClass="failureNotification" ErrorMessage="请输入您的新密码" ToolTip="请输入您的新密码" 
             ValidationGroup="UserInfoValidationGroup">*</asp:RequiredFieldValidator>
        <asp:RegularExpressionValidator ID="UserPasswordRange" runat="server" ControlToValidate="UserPassword" 
             ErrorMessage="请将密码长度控制在6~15个字符之间" ValidationExpression="([\s\S]{6,15})" ForeColor="Blue">
        </asp:RegularExpressionValidator>
    </p>

   <p>
        <asp:Label ID="ConfirmPasswordLabel" runat="server" AssociatedControlID="ConfirmPassword">
        确认您的新密码:</asp:Label>
        <asp:TextBox ID="ConfirmPassword" runat="server" CssClass="passwordEntry" TextMode="Password"></asp:TextBox>
        <asp:RequiredFieldValidator ControlToValidate="ConfirmPassword" CssClass="failureNotification" Display="Dynamic" 
             ErrorMessage="请输入您的确认密码" ID="ConfirmPasswordRequired" runat="server" 
             ToolTip="请输入您的确认密码" ValidationGroup="UserInfoValidationGroup">*</asp:RequiredFieldValidator>
        <asp:CompareValidator ID="PasswordCompare" runat="server" ControlToCompare="UserPassword" ControlToValidate="ConfirmPassword" 
             CssClass="failureNotification" Display="Dynamic" ErrorMessage="密码和确认密码必须一致"
             ValidationGroup="UserInfoValidationGroup">*</asp:CompareValidator>
   </p>

    </fieldset>
    <p class="submitButton">
        <asp:Button ID="ChangeUserPasswordButton" runat="server" Text="修改密码" 
            ValidationGroup="UserInfoValidationGroup" 
            onclick="ChangeUserPasswordButton_Click"/>
    </p>
    </div>
</asp:Content>
