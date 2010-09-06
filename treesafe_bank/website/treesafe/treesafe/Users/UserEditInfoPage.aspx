<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="UserEditInfoPage.aspx.cs" Inherits="treesafe.Users.UserEditInfoPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        修改个人资料
    </h2>
    <p>
        &nbsp;
    </p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        您的账户信息
    </p>
    <span class="failureNotification">
         <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="UserInfoValidationSummary" runat="server" CssClass="failureNotification" 
              ValidationGroup="UserInfoValidationGroup"/>
    <fieldset>
    <p>
          <asp:Label ID="UserNameLabel" runat="server" AssociatedControlID="UserName">
          姓名:
          </asp:Label>
          <asp:Label ID="UserName" runat="server" Text="姓名"></asp:Label>
          <br/>
          &nbsp;&nbsp;&nbsp;&nbsp;*不可更改*&nbsp;&nbsp;&nbsp;&nbsp;
    </p>

    <p>
          <asp:Label ID="UserIDLabel" runat="server" AssociatedControlID="UserID">
          身份证号:
          </asp:Label>
          <asp:Label ID="UserID" runat="server" Text="09908424932840294"></asp:Label>
          <br/>
          &nbsp;&nbsp;&nbsp;&nbsp;*不可更改*&nbsp;&nbsp;&nbsp;&nbsp;
    </p>

    <p>
        <asp:Label ID="UserPasswordLabel" runat="server" AssociatedControlID="UserPassword">
        密码:
        </asp:Label>
        <asp:Label ID="UserPassword" runat="server" Text="**********"></asp:Label> 
        <br/>
        &nbsp;&nbsp;&nbsp;&nbsp;*请点击“修改密码按钮”更改密码*&nbsp;&nbsp;&nbsp;&nbsp;
    </p>

    <p>
        <asp:Label ID="UserAddressLabel" runat="server" AssociatedControlID="UserAddress">
        家庭住址:
        </asp:Label>
        <asp:TextBox ID="UserAddress" runat="server" CssClass="textEntry" MaxLength="50"></asp:TextBox>
        <asp:RequiredFieldValidator ID="UserAddressRequire" runat="server" ControlToValidate="UserAddress" 
             CssClass="failureNotification" ErrorMessage="请输入您的家庭住址" ToolTip="请输入您的家庭住址" 
             ValidationGroup="UserInfoValidationGroup">*</asp:RequiredFieldValidator>
             <br/>
    </p>

    <p>
        <asp:Label ID="UserPhoneLabel" runat="server" AssociatedControlID="UserPhone">
        电话号码:
        </asp:Label>
        <asp:TextBox ID="UserPhone" runat="server" CssClass="textEntry"></asp:TextBox>
        <asp:RequiredFieldValidator ID="UserPhoneRequired" runat="server" ControlToValidate="UserPhone" 
             CssClass="failureNotification" ErrorMessage="请输入您的电话号码" ToolTip="请输入您的电话号码" 
             ValidationGroup="UserInfoValidationGroup">*</asp:RequiredFieldValidator>
             <asp:RegularExpressionValidator ID="UserPhoneRange" ControlToValidate="UserPhone" Display="Dynamic" 
                                     ValidationExpression="([\d\D]{7,11})" runat="server" ForeColor="Blue"
                                     ErrorMessage="请注意，电话号码最少7位，最高11位。">
                                </asp:RegularExpressionValidator>
             <br/>
    </p>

    <p>
        <asp:Label ID="UserEmailLabel" runat="server" AssociatedControlID="UserEmail">
        电子邮件:
        </asp:Label>
        <asp:TextBox ID="UserEmail" runat="server" CssClass="textEntry" MaxLength="50"></asp:TextBox>
    </p>
    </fieldset>

    <p class="submitButton">
        <asp:Button ID="ChangeUserInfoButton" runat="server" Text="确定，提交修改" ValidationGroup="UserInfoValidationGroup"
                  onclick="ChangeUserInfoButton_Click"/>
    </p>
</asp:Content>
