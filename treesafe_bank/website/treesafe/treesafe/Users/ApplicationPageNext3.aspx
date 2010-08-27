<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="ApplicationPageNext3.aspx.cs" Inherits="treesafe.Users.ApplicationPageNext3" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        在线填写申请表
    </h2>
    <p>
        请确认您填写的信息真实有效（本社将对您填写的一切信息保密，请放心填写）</p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请贷款情况调查
    </p>
    <p>
        为了更有效的为您服务，下面，我们将对您所期望申请的贷款进行一个调查。
    </p>

    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div class="accountInfo">
          <fieldset>

  
     
           </fieldset>
           <p class="submitButton">
              <asp:Button ID="CreateApplicationButton" runat="server" CommandName="MoveNext" Text="完成，提交申请" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CreateApplicationButton_Click"/>
           </p>
        </div>
</asp:Content>
