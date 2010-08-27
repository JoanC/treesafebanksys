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
              <asp:Label ID="ApplicationNameLabel" runat="server" AssociatedControlID="ApplicationName">
              1. 申请人姓名:</asp:Label>
              <asp:TextBox ID="ApplicationName" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationNameRequired" runat="server" ControlToValidate="ApplicationName"
                   CssClass="failureNotification" ErrorMessage="请输入申请人姓名" ToolTip="请输入申请人姓名"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="ApplicationAgeLabel" runat="server" AssociatedControlID="ApplicationAge">
              2. 申请人年龄:</asp:Label>
              <asp:TextBox ID="ApplicationAge" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationAgeRequired" runat="server" ControlToValidate="ApplicationAge"
                   CssClass="failureNotification" ErrorMessage="请输入申请人年龄" ToolTip="请输入申请人年龄"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>
           
           <p>
              <asp:Label ID="ApplicationSexLabel" runat="server" AssociatedControlID="ApplicationSex">
              3. 申请人性别:</asp:Label>
              <asp:RadioButtonList ID="ApplicationSex" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="1">男</asp:ListItem> 
                      <asp:ListItem Value="0">女</asp:ListItem>
                  </asp:RadioButtonList>
              <asp:RequiredFieldValidator ID="ApplicationSexRequired" runat="server" ControlToValidate="ApplicationSex"
                   CssClass="failureNotification" ErrorMessage="请输入申请人性别" ToolTip="请输入申请人性别"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="ApplicationIDTypeLabel" runat="server" AssociatedControlID="ApplicationIDType">
              4. 证件类型:</asp:Label>
              &nbsp;&nbsp;
              <asp:DropDownList ID="ApplicationIDType" runat="server">
                 <asp:ListItem Value="0">身份证</asp:ListItem>
                 <asp:ListItem Value="1">军人证</asp:ListItem>
              </asp:DropDownList>
           </p>

           <p>
              <asp:Label ID="ApplicationIDNumberLabel" runat="server" AssociatedControlID="ApplicationIDNumber">
              5. 证件号码:</asp:Label>
              <asp:TextBox ID="ApplicationIDNumber" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationIDNumberRequired" runat="server" ControlToValidate="ApplicationIDNumber"
                   CssClass="failureNotification" ErrorMessage="请输入证件号码" ToolTip="请输入证件号码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>
              <p>
                  &nbsp;</p>

           <p>
              <asp:Label ID="ApplicationAddressLabel" runat="server" AssociatedControlID="ApplicationAddress">
              6. 家庭住址：</asp:Label>
              <asp:TextBox ID="ApplicationAddress" runat="server" Width="300px" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationAddressRequired" runat="server" ControlToValidate="ApplicationAddress"
                   CssClass="failureNotification" ErrorMessage="请输入家庭住址" ToolTip="请输入家庭住址"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="ApplicationPostCodeLabel" runat="server" AssociatedControlID="ApplicationPostCode">
              7. 邮政编码：</asp:Label>
              <asp:TextBox ID="ApplicationPostCode" runat="server" Width="300px" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="ApplicationPostCodeRequired" runat="server" ControlToValidate="ApplicationPostCode"
                   CssClass="failureNotification" ErrorMessage="请输入邮政编码" ToolTip="请输入邮政编码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="ApplicationHouseTypeLabel" runat="server" AssociatedControlID="ApplicationHouseType">
              8. 住宅权属:</asp:Label>
              <asp:RadioButtonList ID="ApplicationHouseType" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="0">自有</asp:ListItem> 
                      <asp:ListItem Value="1">租赁</asp:ListItem>
                      <asp:ListItem Value="2">其他</asp:ListItem>
                  </asp:RadioButtonList>
              <asp:RequiredFieldValidator ID="ApplicationHouseTypeRequired" runat="server" ControlToValidate="ApplicationHouseType"
                   CssClass="failureNotification" ErrorMessage="请输入住宅权属" ToolTip="请输入住宅权属"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
               <asp:Label ID="ApplicationPhoneNumberLabel" runat="server" AssociatedControlID="ApplicationPhoneNumber">
               9. 联系电话：</asp:Label>
               <asp:TextBox ID="ApplicationPhoneNumber" runat="server" CssClass="textEntry"></asp:TextBox>
               <asp:RequiredFieldValidator ID="ApplicationPhoneNumberRequired1" runat="server" ControlToValidate="ApplicationPhoneNumber"
                   CssClass="failureNotification" ErrorMessage="请至少输入1个联系电话" ToolTip="请至少输入1个联系电话"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p> 
              <asp:Label ID="ApplicationPhoneNumberLabel1" runat="server" AssociatedControlID="ApplicationPhoneNumber1">
              10. 其他联系电话：</asp:Label>
              <asp:TextBox ID="ApplicationPhoneNumber1" runat="server" CssClass="textEntry"></asp:TextBox>            
           </p>

           <p>
               <asp:Label ID="ApplicationEducationLabel" runat="server" AssociatedControlID="ApplicationEducation">
               11. 受教育状况：</asp:Label>
               &nbsp;&nbsp;
               <asp:DropDownList ID="ApplicationEducation" runat="server">
                     <asp:ListItem Value="0">初中及以下</asp:ListItem>
                     <asp:ListItem Value="1">高中及职业技术学校</asp:ListItem>
                     <asp:ListItem Value="2">本科及大专院校</asp:ListItem>
                     <asp:ListItem Value="3">研究生及以上</asp:ListItem>
               </asp:DropDownList>
           </p>

  
     
           </fieldset>
           <p class="submitButton">
              <asp:Button ID="CreateApplicationButton" runat="server" CommandName="MoveNext" Text="确定，继续填写" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CreateApplicationButton_Click"/>
           </p>
        </div>
</asp:Content>
