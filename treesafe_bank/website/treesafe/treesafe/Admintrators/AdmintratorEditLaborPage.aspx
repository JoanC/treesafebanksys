﻿<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="AdmintratorEditLaborPage.aspx.cs" Inherits="treesafe.Admintrators.AdmintratorEditLaborPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">    
    <h2>
        修改雇员信息
    </h2>
    <p>
        请在下面输入新的雇员信息
    </p>
    
    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div>
          <fieldset>
           <p>
              <asp:Label ID="LaborIDLabel" runat="server" AssociatedControlID="LaborID">
              1. 雇员工号:</asp:Label>
              <asp:TextBox ID="LaborID" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="LaborIDRequired" runat="server" ControlToValidate="LaborID"
                   CssClass="failureNotification" ErrorMessage="请输入雇员工号" ToolTip="请输入雇员工号"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="LaborTypeLabel" runat="server" AssociatedControlID="LaborType">
              2. 雇员类型:</asp:Label>
               <asp:RadioButtonList ID="LaborType" runat="server" RepeatDirection="Horizontal">
                   <asp:ListItem Value="0">操作员</asp:ListItem>
                   <asp:ListItem Value="1">审核员</asp:ListItem>
               </asp:RadioButtonList>     
              <asp:RequiredFieldValidator ID="LaborTypeRequired" runat="server" ControlToValidate="LaborType"
                   CssClass="failureNotification" ErrorMessage="请输入雇员类型" ToolTip="请输入雇员类型"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>
           
           <p>
              <asp:Label ID="LaborNameLabel" runat="server" AssociatedControlID="LaborName">
              3. 雇员姓名:</asp:Label>
               <asp:TextBox ID="LaborName" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="LaborNameRequired" runat="server" ControlToValidate="LaborName"
                   CssClass="failureNotification" ErrorMessage="请输入雇员姓名" ToolTip="请输入雇员姓名"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="LaborIDNumberLabel" runat="server" AssociatedControlID="LaborIDNumber">
              4. 雇员证件号码:</asp:Label>
               <asp:TextBox ID="LaborIDNumber" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="LaborIDNumberRequired" runat="server" ControlToValidate="LaborIDNumber"
                   CssClass="failureNotification" ErrorMessage="请输入雇员证件号码" ToolTip="请输入雇员证件号码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="LaborSexLabel" runat="server" AssociatedControlID="LaborSex">
              5. 雇员性别:</asp:Label>
               <asp:RadioButtonList ID="LaborSex" runat="server" RepeatDirection="Horizontal">
                   <asp:ListItem Value="0">男</asp:ListItem>
                   <asp:ListItem Value="1">女</asp:ListItem>
               </asp:RadioButtonList>            
              <asp:RequiredFieldValidator ID="LaborSexRequired" runat="server" ControlToValidate="LaborSex"
                   CssClass="failureNotification" ErrorMessage="请输入雇员性别" ToolTip="请输入雇员性别"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="LaborAgeLabel" runat="server" AssociatedControlID="LaborAge">
              6. 雇员年龄：</asp:Label>
              <asp:TextBox ID="LaborAge" runat="server" Width="300px" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="LaborAgeRequired" runat="server" ControlToValidate="LaborAge"
                   CssClass="failureNotification" ErrorMessage="请输入雇员年龄" ToolTip="请输入雇员年龄"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="LaborAddressLabel" runat="server" AssociatedControlID="LaborAddress">
              7. 雇员地址：</asp:Label>
              <asp:TextBox ID="LaborAddress" runat="server" Width="300px" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="LaborAddressRequired" runat="server" ControlToValidate="LaborAddress"
                   CssClass="failureNotification" ErrorMessage="请输入雇员地址" ToolTip="请输入雇员地址"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="LaborEmailLabel" runat="server" AssociatedControlID="LaborEmail">
              8. 雇员电子邮件:</asp:Label>
               <asp:TextBox ID="LaborEmail" runat="server" CssClass="textEntry"></asp:TextBox>
              <asp:RequiredFieldValidator ID="LaborEmailRequired" runat="server" ControlToValidate="LaborEmail"
                   CssClass="failureNotification" ErrorMessage="请输入雇员的电子邮件" ToolTip="请输入雇员的电子邮件"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
               <asp:Label ID="LaborPhoneNumberLabel" runat="server" AssociatedControlID="LaborPhoneNumber">
               9. 雇员联系电话：</asp:Label>
               <asp:TextBox ID="LaborPhoneNumber" runat="server" CssClass="textEntry"></asp:TextBox>
               <asp:RequiredFieldValidator ID="LaborPhoneNumberRequired" runat="server" ControlToValidate="LaborPhoneNumber"
                   CssClass="failureNotification" ErrorMessage="请输入雇员联系电话" ToolTip="请输入雇员联系电话"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>
           <p>
               <asp:Label ID="LaborNotesLabel" runat="server" AssociatedControlID="LaborNotes">
               10. 备注：</asp:Label>
               <br/>
               <asp:TextBox ID="LaborNotes" runat="server" CssClass="textEntry" 
                   TextMode="MultiLine" Height="81px" Width="374px"></asp:TextBox>
           </p>

           </fieldset>
           <p class="submitButton">
              <asp:Button ID="NewLaborButton" runat="server" CommandName="MoveNext" Text="确定，修改雇员信息" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="NewLaborButton_Click"/>
           </p>
        </div>

</asp:Content>