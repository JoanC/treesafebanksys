<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
    CodeBehind="ApplicationPageNext1.aspx.cs" Inherits="treesafe.Users.ApplicationPageNext1" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        在线填写申请表
    </h2>
    <p>
        请确认您填写的信息真实有效（本社将对您填写的一切信息保密，请放心填写）</p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人经济情况</p>
    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div class="accountInfo">
          <fieldset>

          <p>
              <asp:Label ID="ApplicationPersonIncomeLabel" runat="server" AssociatedControlID="ApplicationPersonIncome">个人年收入:</asp:Label>
              &nbsp;&nbsp;
              <asp:DropDownList ID="ApplicationPersonIncome" runat="server">
                 <asp:ListItem Value="0">5万元以下</asp:ListItem>
                 <asp:ListItem Value="1">5~10万元</asp:ListItem>
                 <asp:ListItem Value="2">10~15万元</asp:ListItem>
                 <asp:ListItem Value="3">15~20万元</asp:ListItem>
                 <asp:ListItem Value="4">20~25万元</asp:ListItem>
                 <asp:ListItem Value="5">25~30万元</asp:ListItem>
                 <asp:ListItem Value="6">30~40万元</asp:ListItem>
                 <asp:ListItem Value="7">40~50万元</asp:ListItem>
                 <asp:ListItem Value="8">50~60万元</asp:ListItem>
                 <asp:ListItem Value="9">60~70万元</asp:ListItem>
                 <asp:ListItem Value="10">70~100万元</asp:ListItem>
                 <asp:ListItem Value="11">100万元以上</asp:ListItem>
              </asp:DropDownList>
           </p>

           <p>
              <asp:Label ID="ApplicationHomeIncomeLabel" runat="server" AssociatedControlID="ApplicationHomeIncome">家庭年收入:</asp:Label>
              &nbsp;&nbsp;
              <asp:DropDownList ID="ApplicationHomeIncome" runat="server">
                 <asp:ListItem Value="0">5万元以下</asp:ListItem>
                 <asp:ListItem Value="1">5~10万元</asp:ListItem>
                 <asp:ListItem Value="2">10~15万元</asp:ListItem>
                 <asp:ListItem Value="3">15~20万元</asp:ListItem>
                 <asp:ListItem Value="4">20~25万元</asp:ListItem>
                 <asp:ListItem Value="5">25~30万元</asp:ListItem>
                 <asp:ListItem Value="6">30~40万元</asp:ListItem>
                 <asp:ListItem Value="7">40~50万元</asp:ListItem>
                 <asp:ListItem Value="8">50~60万元</asp:ListItem>
                 <asp:ListItem Value="9">60~70万元</asp:ListItem>
                 <asp:ListItem Value="10">70~100万元</asp:ListItem>
                 <asp:ListItem Value="11">100万元以上</asp:ListItem>
              </asp:DropDownList>
           </p>
              <p>
                  &nbsp;</p>
              <p> 
                  <asp:Label ID="ApplicationIsHaveDepositLabel" runat="server" AssociatedControlID="ApplicationIsHaveDeposit">是否有存款?</asp:Label>
                  <asp:RadioButtonList ID="ApplicationIsHaveDeposit" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="1">有</asp:ListItem> 
                      <asp:ListItem Value="0">无</asp:ListItem>
                  </asp:RadioButtonList>
                  <asp:RequiredFieldValidator ID="ApplicationIsHaveDepositRequired" runat="server" ControlToValidate="ApplicationIsHaveDeposit"
                   CssClass="failureNotification" ErrorMessage="请填写：是否有存款?" ToolTip="请填写：是否有存款?"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>  
              </p>

              <p>
                  <asp:Label ID="ApplicationDepositSumLabel" runat="server" AssociatedControlID="ApplicationDepositSum">如果有存款的话，存款总金额为：</asp:Label>
                  &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationDepositSum" runat="server">
                     <asp:ListItem Value="0">5万元以下</asp:ListItem>
                     <asp:ListItem Value="1">5~10万元</asp:ListItem>
                     <asp:ListItem Value="2">10~20万元</asp:ListItem>
                     <asp:ListItem Value="3">20~30万元</asp:ListItem>
                     <asp:ListItem Value="4">30~50万元</asp:ListItem>
                     <asp:ListItem Value="5">50~70万元</asp:ListItem>
                     <asp:ListItem Value="6">70~100万元</asp:ListItem>
                     <asp:ListItem Value="7">100~150万元</asp:ListItem>
                     <asp:ListItem Value="8">150~200万元</asp:ListItem>
                     <asp:ListItem Value="9">200万元以上</asp:ListItem>
                   </asp:DropDownList>
              </p>

              <p>
                  <asp:Label ID="ApplicationFixedDepositLabel" runat="server" AssociatedControlID="ApplicationFixedDeposit">其中，定期存款金额有：</asp:Label>
                  <asp:TextBox ID="ApplicationFixedDeposit" runat="server" CssClass="textEntry"></asp:TextBox>
              </p>
              <p>
                  &nbsp;
              </p>
              <p>
                  <asp:Label ID="ApplicationIsHaveLoanLabel" runat="server" AssociatedControlID="ApplicationIsHaveLoan">是否有贷款?</asp:Label>
                  <asp:RadioButtonList ID="ApplicationIsHaveLoan" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="1">有</asp:ListItem> 
                      <asp:ListItem Value="0">无</asp:ListItem>
                  </asp:RadioButtonList>  
                  <asp:RequiredFieldValidator ID="ApplicationIsHaveLoanRequired" runat="server" ControlToValidate="ApplicationIsHaveLoan"
                   CssClass="failureNotification" ErrorMessage="请填写：是否有贷款?" ToolTip="请填写：是否有贷款?"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator> 
              </p>

              <p>
                  <asp:Label ID="ApplicationLoanSumLabel" runat="server" AssociatedControlID="ApplicationLoanSum">如果有贷款的话，贷款总金额为：</asp:Label>
                  &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationLoanSum" runat="server">
                     <asp:ListItem Value="0">5万元以下</asp:ListItem>
                     <asp:ListItem Value="1">5~10万元</asp:ListItem>
                     <asp:ListItem Value="2">10~20万元</asp:ListItem>
                     <asp:ListItem Value="3">20~30万元</asp:ListItem>
                     <asp:ListItem Value="4">30~50万元</asp:ListItem>
                     <asp:ListItem Value="5">50~70万元</asp:ListItem>
                     <asp:ListItem Value="6">70~100万元</asp:ListItem>
                     <asp:ListItem Value="7">100~150万元</asp:ListItem>
                     <asp:ListItem Value="8">150~200万元</asp:ListItem>
                     <asp:ListItem Value="9">200万元以上</asp:ListItem>
                   </asp:DropDownList>
              </p>
              <p>
                  <asp:Label ID="ApplicationLoanDeadlineLabel" runat="server" AssociatedControlID="ApplicationLoanDeadline">剩余还贷年限（年月日，例如：2012年2月2日）：</asp:Label>
                  <asp:TextBox ID="ApplicationLoanDeadline" runat="server" CssClass="textEntry"></asp:TextBox>
              </p>


     
          </fieldset>
          <p class="submitButton">
              <asp:Button ID="CreateApplicationButton" runat="server" CommandName="MoveNext" Text="确定，继续填写" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CreateApplicationButton_Click"/>
          </p>
        </div>

</asp:Content>
