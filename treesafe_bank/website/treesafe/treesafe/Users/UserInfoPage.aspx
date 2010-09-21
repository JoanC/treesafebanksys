<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="UserInfoPage.aspx.cs" Inherits="treesafe.Users.UserInfoPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        个人资料
    </h2>
    <p>
        &nbsp;
    </p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        您的账户信息
    </p>
    <fieldset>
    <p>
          <asp:Label ID="UserNameLabel" runat="server" AssociatedControlID="UserName">
          姓名:
          </asp:Label>
          <asp:Label ID="UserName" runat="server" Text="张军"></asp:Label>
    </p>

    <p>
          <asp:Label ID="UserIDLabel" runat="server" AssociatedControlID="UserID">
          身份证号:
          </asp:Label>
          <asp:Label ID="UserID" runat="server" Text="09908424932840294"></asp:Label>
    </p>

    <p>
        <asp:Label ID="UserPasswordLabel" runat="server" AssociatedControlID="UserPassword">
        密码:
        </asp:Label>
        <asp:Label ID="UserPassword" runat="server" Text="3441223esfd"></asp:Label> 
    </p>

    <p>
        <asp:Label ID="UserAddressLabel" runat="server" AssociatedControlID="UserAddress">
        家庭住址:
        </asp:Label>
        <asp:Label ID="UserAddress" runat="server" Text="xx街"></asp:Label>
    </p>

    <p>
        <asp:Label ID="UserPhoneLabel" runat="server" AssociatedControlID="UserPhone">
        电话号码:
        </asp:Label>
        <asp:Label ID="UserPhone" runat="server" Text="1334xxxxxxx"></asp:Label>
    </p>

    </fieldset>

    <p class="submitButton">
        <asp:Button ID="ChangeUserInfoButton" runat="server" Text="编辑，更改信息" 
                  onclick="ChangeUserInfoButton_Click"/>
                  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Button ID="ChangePasswordButton" runat="server" Text="更改登录密码" 
            onclick="ChangePasswordButton_Click" />
    </p>


</asp:Content>
