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
              <asp:Label ID="ApplicationPersonIncomeLabel" runat="server" AssociatedControlID="ApplicationPersonIncome">
              1. 个人年收入:</asp:Label>
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
              <asp:Label ID="ApplicationHomeIncomeLabel" runat="server" AssociatedControlID="ApplicationHomeIncome">
              2. 家庭年收入:</asp:Label>
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
                  <asp:Label ID="ApplicationIsHaveDepositLabel" runat="server" AssociatedControlID="ApplicationIsHaveDeposit">
                  3. 是否有存款?</asp:Label>
                  <asp:RadioButtonList ID="ApplicationIsHaveDeposit" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="1">有</asp:ListItem> 
                      <asp:ListItem Value="0">无</asp:ListItem>
                  </asp:RadioButtonList>
                  <asp:RequiredFieldValidator ID="ApplicationIsHaveDepositRequired" runat="server" ControlToValidate="ApplicationIsHaveDeposit"
                   CssClass="failureNotification" ErrorMessage="请填写：是否有存款?" ToolTip="请填写：是否有存款?"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>  
              </p>

              <p>
                  <asp:Label ID="ApplicationDepositFixedLabel" runat="server" AssociatedControlID="ApplicationDepositFixed">
                  4. 其中，定期存款总金额为（无定期存款填0）：
                  </asp:Label>
                  &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationDepositFixed" runat="server">
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
                  <asp:Label ID="ApplicationCurrentDepositLabel" runat="server" AssociatedControlID="ApplicationCurrentDeposit">
                  5. 其中，活期存款总金额为（无活期存款填0）：
                  </asp:Label>
                  &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationCurrentDeposit" runat="server">
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
                  &nbsp;
              </p>
              <p>
                  <asp:Label ID="ApplicationIsHaveLoanLabel" runat="server" AssociatedControlID="ApplicationIsHaveLoan">
                  6. 是否有贷款?</asp:Label>
                  <asp:RadioButtonList ID="ApplicationIsHaveLoan" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="1">有</asp:ListItem> 
                      <asp:ListItem Value="0">无</asp:ListItem>
                  </asp:RadioButtonList>  
                  <asp:RequiredFieldValidator ID="ApplicationIsHaveLoanRequired" runat="server" ControlToValidate="ApplicationIsHaveLoan"
                   CssClass="failureNotification" ErrorMessage="请填写：是否有贷款?" ToolTip="请填写：是否有贷款?"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator> 
              </p>

              <p>
                  <asp:Label ID="ApplicationLoanSumLabel" runat="server" AssociatedControlID="ApplicationLoanSum">
                  7. 如果有贷款的话，贷款总金额为：</asp:Label>
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
                  <asp:Label ID="ApplicationLoanDeadlineLabel" runat="server" AssociatedControlID="ApplicationLoanDeadline">
                  8. 预计还清贷款日期（年月日，例如：2012年2月2日）：
                  </asp:Label>
                  <asp:TextBox ID="ApplicationLoanDeadline" runat="server" CssClass="textEntry"></asp:TextBox>
              </p>

              <p>
                  <asp:Label ID="ApplicationIsMortgageLabel" runat="server" AssociatedControlID="ApplicationIsMortgage">
                  9. 是否有已抵押的固定资产：
                  </asp:Label>
                  <asp:RadioButtonList ID="ApplicationIsMortgage" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="1">有</asp:ListItem> 
                      <asp:ListItem Value="0">无</asp:ListItem>
                  </asp:RadioButtonList>
              <asp:RequiredFieldValidator ID="ApplicationIsMortgageRequired" runat="server" ControlToValidate="ApplicationIsMortgage"
                   CssClass="failureNotification" ErrorMessage="请填写：是否有已抵押的固定资产" ToolTip="请填写：是否有已抵押的固定资产"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
              </p>

              <p>
                  <asp:Label ID="ApplicationMortgageLabel" runat="server" AssociatedControlID="ApplicationMortgage">
                  10.未抵押的主要固定资产：
                  </asp:Label>
                  <asp:CheckBoxList ID="ApplicationMortgage" runat="server">
                      <asp:ListItem Value="0">房地产</asp:ListItem>
                      <asp:ListItem Value="1">交通工具</asp:ListItem>
                      <asp:ListItem Value="2">生产设备</asp:ListItem>
                      <asp:ListItem Value="3">其他</asp:ListItem>
                  </asp:CheckBoxList>
              </p>
              <p>
                  &nbsp;</p>

              <p>
                  <asp:Label ID="ApplicationIndustryLabel" runat="server" AssociatedControlID="ApplicationIndustry">
                  11.从事行业：
                  </asp:Label>
                  <asp:CheckBoxList ID="ApplicationIndustry" runat="server">
                      <asp:ListItem Value="0">种植业</asp:ListItem>
                      <asp:ListItem Value="1">林业</asp:ListItem>
                      <asp:ListItem Value="2">畜牧业</asp:ListItem>
                      <asp:ListItem Value="3">渔业</asp:ListItem>
                      <asp:ListItem Value="4">农、林、牧、渔服务业</asp:ListItem>
                      <asp:ListItem Value="5">其他</asp:ListItem>
                  </asp:CheckBoxList>
              </p>

            <p> 
              <asp:Label ID="ApplicationWorkLabel" runat="server" AssociatedControlID="ApplicationWork">
              12. 工作单位或经营内容：</asp:Label>
              <asp:TextBox ID="ApplicationWork" runat="server" CssClass="textEntry"></asp:TextBox>  
              <asp:RequiredFieldValidator ID="ApplicationWorkRequired" runat="server" ControlToValidate="ApplicationWork"
                   CssClass="failureNotification" ErrorMessage="请输入工作单位或经营内容" ToolTip="请输入工作单位或经营内容"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>          
           </p>

           <p> 
              <asp:Label ID="ApplicationPositionLabel" runat="server" AssociatedControlID="ApplicationPosition">
              13. 职位：</asp:Label>
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
