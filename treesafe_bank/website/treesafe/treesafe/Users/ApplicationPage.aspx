<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="ApplicationPage.aspx.cs" Inherits="treesafe.Users.ApplicationPage" %>


<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        在线填写申请表
    </h2>
    <p>
        请确认您填写的信息真实有效（本社将对您填写的一切信息保密，请放心填写）</p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人基本信息</p>
    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div class="accountInfo">
          <fieldset>
         
           <p>
              <asp:Label ID="ApplicationNameLabel" runat="server" AssociatedControlID="ApplicationName">申请人姓名:</asp:Label>
              <asp:TextBox ID="ApplicationName" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationNameRequired" runat="server" ControlToValidate="ApplicationName"
                   CssClass="failureNotification" ErrorMessage="请输入申请人姓名" ToolTip="请输入申请人姓名"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="ApplicationIDTypeLabel" runat="server" AssociatedControlID="ApplicationIDType">证件类型:</asp:Label>
              &nbsp;&nbsp;
              <asp:DropDownList ID="ApplicationIDType" runat="server">
                 <asp:ListItem Value="0">身份证</asp:ListItem>
                 <asp:ListItem Value="1">军人证</asp:ListItem>
              </asp:DropDownList>
           </p>

           <p>
              <asp:Label ID="ApplicationIDNumberLabel" runat="server" AssociatedControlID="ApplicationIDNumber">证件号码:</asp:Label>
              <asp:TextBox ID="ApplicationIDNumber" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationIDNumberRequired" runat="server" ControlToValidate="ApplicationIDNumber"
                   CssClass="failureNotification" ErrorMessage="请输入证件号码" ToolTip="请输入证件号码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="ApplicationAddressLabel" runat="server" AssociatedControlID="ApplicationAddress">家庭住址：</asp:Label>
              <asp:TextBox ID="ApplicationAddress" runat="server" Width="300px" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationAddressRequired" runat="server" ControlToValidate="ApplicationAddress"
                   CssClass="failureNotification" ErrorMessage="请输入家庭住址" ToolTip="请输入家庭住址"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
               <asp:Label ID="ApplicationPhoneNumberLabel" runat="server" AssociatedControlID="ApplicationPhoneNumber">联系电话：</asp:Label>
               <asp:TextBox ID="ApplicationPhoneNumber" runat="server" CssClass="textEntry"></asp:TextBox>
               <asp:RequiredFieldValidator ID="ApplicationPhoneNumberRequired1" runat="server" ControlToValidate="ApplicationPhoneNumber"
                   CssClass="failureNotification" ErrorMessage="请至少输入1个联系电话" ToolTip="请至少输入1个联系电话"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p> 
              <asp:Label ID="ApplicationPhoneNumberLabel1" runat="server" AssociatedControlID="ApplicationPhoneNumber1">其他联系电话：</asp:Label>
              <asp:TextBox ID="ApplicationPhoneNumber1" runat="server" CssClass="textEntry"></asp:TextBox>            
           </p>

           <p> 
              <asp:Label ID="ApplicationWorkLabel" runat="server" AssociatedControlID="ApplicationWork">工作单位或经营内容：</asp:Label>
              <asp:TextBox ID="ApplicationWork" runat="server" CssClass="textEntry"></asp:TextBox>  
              <asp:RequiredFieldValidator ID="ApplicationWorkRequired" runat="server" ControlToValidate="ApplicationWork"
                   CssClass="failureNotification" ErrorMessage="请输入工作单位或经营内容" ToolTip="请输入工作单位或经营内容"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>          
           </p>

           <p> 
              <asp:Label ID="ApplicationPositionLabel" runat="server" AssociatedControlID="ApplicationPosition">职位：</asp:Label>
              <asp:TextBox ID="ApplicationPosition" runat="server" CssClass="textEntry"></asp:TextBox>  
              <asp:RequiredFieldValidator ID="ApplicationPositionRequired" runat="server" ControlToValidate="ApplicationPosition"
                   CssClass="failureNotification" ErrorMessage="请输入您的职位" ToolTip="请输入您的职位"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>          
           </p>

  
     
           </fieldset>
           <p class="submitButton">
              <asp:Button ID="CreateApplicationButton" runat="server" CommandName="MoveNext" Text="确定，继续填写" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CreateApplicationButton_Click"/>
           </p>
        </div>
</asp:Content>
