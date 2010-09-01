<%@ Page Title="Register" Language="C#" MasterPageFile="~/Welcome.master" AutoEventWireup="true"
    CodeBehind="Register.aspx.cs" Inherits="treesafe.Account.Register" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
                    <h2>
                        注册
                    </h2>
                    <p>
                       请认真填写下表，创建新账号
                    </p>
                    <p>
                        *密码至少需要 <%= Membership.MinRequiredPasswordLength %> 位数*
                    </p>
                    <span class="failureNotification">
                        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
                    </span>
                    <asp:ValidationSummary ID="RegisterUserValidationSummary" runat="server" CssClass="failureNotification" 
                         ValidationGroup="RegisterUserValidationGroup"/>
                    
                        <fieldset class="register">
                            <legend>账户信息</legend>
                            <p>
                                <asp:Label ID="UserNameLabel" runat="server" AssociatedControlID="UserName">姓名:</asp:Label>
                                <asp:TextBox ID="UserName" runat="server" CssClass="textEntry"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="UserNameRequired" runat="server" ControlToValidate="UserName" 
                                     CssClass="failureNotification" ErrorMessage="请输入您的姓名" ToolTip="请输入您的姓名" 
                                     ValidationGroup="RegisterUserValidationGroup">*</asp:RequiredFieldValidator>
                            </p>
                            <p>
                                <asp:Label ID="UserSexLabel" runat="server" AssociatedControlID="UserSex">性别:</asp:Label>
                                <asp:RadioButtonList ID="UserSex" runat="server" RepeatDirection="Horizontal">
                                   <asp:ListItem Value="0">男</asp:ListItem> 
                                   <asp:ListItem Value="1">女</asp:ListItem>
                                </asp:RadioButtonList>
                                <asp:RequiredFieldValidator ID="UserSexRequired" runat="server" ControlToValidate="UserSex" 
                                     CssClass="failureNotification" ErrorMessage="请输入您的性别" ToolTip="请输入您的性别" 
                                     ValidationGroup="RegisterUserValidationGroup">*</asp:RequiredFieldValidator>
                            </p>
                            <p>
                                <asp:Label ID="UserIDLabel" runat="server" AssociatedControlID="UserID">身份证号:</asp:Label>
                                <asp:TextBox ID="UserId" runat="server" CssClass="textEntry"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="UserIDRequired" runat="server" ControlToValidate="UserID" 
                                     CssClass="failureNotification" ErrorMessage="请输入您的身份证号" ToolTip="请输入您的身份证号" 
                                     ValidationGroup="RegisterUserValidationGroup">*</asp:RequiredFieldValidator>
                            </p>
                            <p>
                                <asp:Label ID="PasswordLabel" runat="server" AssociatedControlID="Password">密码:</asp:Label>
                                <asp:TextBox ID="Password" runat="server" CssClass="passwordEntry" TextMode="Password"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="PasswordRequired" runat="server" ControlToValidate="Password" 
                                     CssClass="failureNotification" ErrorMessage="请输入您的密码" ToolTip="请输入您的密码" 
                                     ValidationGroup="RegisterUserValidationGroup">*</asp:RequiredFieldValidator>
                            </p>
                            <p>
                                <asp:Label ID="ConfirmPasswordLabel" runat="server" AssociatedControlID="ConfirmPassword">确认密码:</asp:Label>
                                <asp:TextBox ID="ConfirmPassword" runat="server" CssClass="passwordEntry" TextMode="Password"></asp:TextBox>
                                <asp:RequiredFieldValidator ControlToValidate="ConfirmPassword" CssClass="failureNotification" Display="Dynamic" 
                                     ErrorMessage="请输入您的确认密码" ID="ConfirmPasswordRequired" runat="server" 
                                     ToolTip="请输入您的确认密码" ValidationGroup="RegisterUserValidationGroup">*</asp:RequiredFieldValidator>
                                <asp:CompareValidator ID="PasswordCompare" runat="server" ControlToCompare="Password" ControlToValidate="ConfirmPassword" 
                                     CssClass="failureNotification" Display="Dynamic" ErrorMessage="密码和确认密码必须一致"
                                     ValidationGroup="RegisterUserValidationGroup">*</asp:CompareValidator>
                            </p>
                             <p>
                                <asp:Label ID="PhoneNumberLabel" runat="server" AssociatedControlID="PhoneNumber">联系电话:</asp:Label>
                                <asp:TextBox ID="PhoneNumber" runat="server" CssClass="textEntry"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="PhoneNumberRequire" runat="server" ControlToValidate="PhoneNumber" 
                                     CssClass="failureNotification" ErrorMessage="请输入您的联系电话" ToolTip="请输入您的联系电话" 
                                     ValidationGroup="RegisterUserValidationGroup">*</asp:RequiredFieldValidator>
                            </p>
                             <p>
                                <asp:Label ID="HomeAddressLabel" runat="server" AssociatedControlID="HomeAddress">家庭住址:</asp:Label>
                                <asp:TextBox ID="HomeAddress" runat="server" CssClass="textEntry"></asp:TextBox>
                                <asp:RequiredFieldValidator ID="HomeAddressRequire" runat="server" ControlToValidate="HomeAddress"  
                                     CssClass="failureNotification" ErrorMessage="请输入您的家庭住址" ToolTip="请输入您的家庭住址" 
                                     ValidationGroup="RegisterUserValidationGroup">*</asp:RequiredFieldValidator>
                            </p>
                             <p>
                                <asp:Label ID="EmailLabel" runat="server" AssociatedControlID="Email">电子邮件（选填）:</asp:Label>
                                <asp:TextBox ID="Email" runat="server" CssClass="textEntry"></asp:TextBox>
                 
                            </p>
                        </fieldset>
                        <p class="submitButton">
                            <asp:Button ID="CreateUserButton" runat="server" CommandName="MoveNext" Text="确定，创建新账号" 
                                 ValidationGroup="RegisterUserValidationGroup" 
                                onclick="CreateUserButton_Click"/>
                        </p>
                    
</asp:Content>
