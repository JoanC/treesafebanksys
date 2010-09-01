<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="ApplicationPageNext3.aspx.cs" Inherits="treesafe.Users.ApplicationPageNext3" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
    <style type="text/css">
        .textEntry
        {}
    </style>
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
          <p>
               <asp:Label ID="ApplicationExceptLoanSumLabel" runat="server" AssociatedControlID="ApplicationExceptLoanSum">
               1. 预计申请贷款金额：
               </asp:Label>
                  &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationExceptLoanSum" runat="server">
                     <asp:ListItem Value="0">无</asp:ListItem>
                     <asp:ListItem Value="1">2000元以下</asp:ListItem>
                     <asp:ListItem Value="2">2000~5000元</asp:ListItem>
                     <asp:ListItem Value="3">5000~8000元</asp:ListItem>
                     <asp:ListItem Value="4">8000~1万元</asp:ListItem>
                     <asp:ListItem Value="5">1~2万元</asp:ListItem>
                     <asp:ListItem Value="6">2~5万元</asp:ListItem>
                     <asp:ListItem Value="7">5万元以上</asp:ListItem>
                   </asp:DropDownList>
          </p>
          
          <p>
              <asp:Label ID="ApplicationLoanTimeLabel" runat="server" AssociatedControlID="ApplicationLoanTime">
              2. 预计还贷期限：
              </asp:Label>
              <br/>          
              <asp:TextBox ID="ApplicationLoanTime" runat="server" CssClass="textEntry" 
                  Width="129px"></asp:TextBox>
              个月
           </p>

          <p>
               <asp:Label ID="ApplicationLoanNumberLabel" runat="server" AssociatedControlID="ApplicationLoanNumber">
               3. 贷款次数：
               </asp:Label>
               <asp:RadioButtonList ID="ApplicationLoanNumber" runat="server" RepeatDirection="Horizontal">
                   <asp:ListItem Value="0">首次贷款</asp:ListItem> 
                   <asp:ListItem Value="1">非首次贷款</asp:ListItem>
               </asp:RadioButtonList> 
          </p>

          <p>
               <asp:Label ID="ApplicationLoanNoteLabel" runat="server" AssociatedControlID="ApplicationLoanNote">
               4. 申贷项目可行性说明：
               </asp:Label>
               <br/>
               <asp:TextBox ID="ApplicationLoanNote" runat="server" CssClass="textEntry" 
                   Height="80px" TextMode="MultiLine" Width="337px"></asp:TextBox>
          </p>

          <p>
               <asp:Label ID="ApplicationIsMessageLabel" runat="server" AssociatedControlID="ApplicationIsMessage">
               5. 是否希望接收我们的短信通知?
               <br/>
               （建议选择接收短信通知，这可以让您更方便的了解整个贷款及还贷过程）</asp:Label>
               <asp:RadioButtonList ID="ApplicationIsMessage" runat="server" RepeatDirection="Horizontal">
                   <asp:ListItem Value="1">是</asp:ListItem> 
                   <asp:ListItem Value="0">否</asp:ListItem>
               </asp:RadioButtonList>  
               <asp:RequiredFieldValidator ID="ApplicationIsMessageRequired" runat="server" ControlToValidate="ApplicationIsMessage"
                   CssClass="failureNotification" ErrorMessage="请填写：是否希望接收我们的短信通知?" ToolTip="请填写：是否希望接收我们的短信通知?"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           </fieldset>
           <p class="submitButton">
              <asp:Button ID="CreateApplicationButton" runat="server" CommandName="MoveNext" Text="完成，提交申请" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CreateApplicationButton_Click"/>
           </p>
        </div>
</asp:Content>
