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
                 <asp:ListItem Value="0">2000元以下</asp:ListItem>
                 <asp:ListItem Value="1">2000~5000元</asp:ListItem>
                 <asp:ListItem Value="2">5000~8000元</asp:ListItem>
                 <asp:ListItem Value="3">8000元~10000元</asp:ListItem>
                 <asp:ListItem Value="4">10000~15000元</asp:ListItem>
                 <asp:ListItem Value="5">15000~20000元</asp:ListItem>
                 <asp:ListItem Value="6">2万元以上</asp:ListItem>
              </asp:DropDownList>
           </p>

           <p>
              <asp:Label ID="ApplicationHomeIncomeLabel" runat="server" AssociatedControlID="ApplicationHomeIncome">
              2. 家庭年收入:</asp:Label>
              &nbsp;&nbsp;
              <asp:DropDownList ID="ApplicationHomeIncome" runat="server">
                 <asp:ListItem Value="0">2000元以下</asp:ListItem>
                 <asp:ListItem Value="1">2000~5000元</asp:ListItem>
                 <asp:ListItem Value="2">5000~1万元</asp:ListItem>
                 <asp:ListItem Value="3">1~3万元</asp:ListItem>
                 <asp:ListItem Value="4">3~5万元</asp:ListItem>
                 <asp:ListItem Value="5">5~10万元</asp:ListItem>
                 <asp:ListItem Value="6">10万元以上</asp:ListItem>
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
                  4. 其中，定期存款总金额为：
                  </asp:Label>
                  &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationDepositFixed" runat="server">
                     <asp:ListItem Value="0">无存款</asp:ListItem>
                     <asp:ListItem Value="1">2000元以下</asp:ListItem>
                     <asp:ListItem Value="2">2000~5000元</asp:ListItem>
                     <asp:ListItem Value="3">5000~8000元</asp:ListItem>
                     <asp:ListItem Value="4">8000~1万元</asp:ListItem>
                     <asp:ListItem Value="5">1万~2万元</asp:ListItem>
                     <asp:ListItem Value="6">2万~5万元</asp:ListItem>
                     <asp:ListItem Value="7">5万元以上</asp:ListItem>
                   </asp:DropDownList>
              </p>

              <p>
                  <asp:Label ID="ApplicationCurrentDepositLabel" runat="server" AssociatedControlID="ApplicationCurrentDeposit">
                  5. 其中，活期存款总金额为：
                  </asp:Label>
                  &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationCurrentDeposit" runat="server">
                     <asp:ListItem Value="0">无存款</asp:ListItem>
                     <asp:ListItem Value="1">2000元以下</asp:ListItem>
                     <asp:ListItem Value="2">2000~5000元</asp:ListItem>
                     <asp:ListItem Value="3">5000~8000元</asp:ListItem>
                     <asp:ListItem Value="4">8000~1万元</asp:ListItem>
                     <asp:ListItem Value="5">1万~2万元</asp:ListItem>
                     <asp:ListItem Value="6">2万~5万元</asp:ListItem>
                     <asp:ListItem Value="7">5万元以上</asp:ListItem>
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
                  <asp:Label ID="ApplicationLoanDeadlineLabel" runat="server" AssociatedControlID="ApplicationLoanDeadline">
                  8. 预计还清贷款日期（剩余时间）：
                  </asp:Label>
                   &nbsp;&nbsp;
                  <asp:DropDownList ID="ApplicationLoanDeadline" runat="server">
                     <asp:ListItem Value="0">无</asp:ListItem>
                     <asp:ListItem Value="1">6个月内</asp:ListItem>
                     <asp:ListItem Value="2">6个月~12个月</asp:ListItem>
                     <asp:ListItem Value="3">12个月~24个月</asp:ListItem>
                     <asp:ListItem Value="4">24个月以上</asp:ListItem>
                   </asp:DropDownList>
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
                  <asp:RadioButtonList ID="ApplicationMortgage" runat="server">
                   <asp:ListItem Value="0">住宅</asp:ListItem>
                      <asp:ListItem Value="1">工作建筑（厂房）</asp:ListItem>
                      <asp:ListItem Value="2">个人交通工具</asp:ListItem>
                      <asp:ListItem Value="3">运输工具</asp:ListItem>
                      <asp:ListItem Value="4">生产设备</asp:ListItem>
                      <asp:ListItem Value="5">其他</asp:ListItem>
                  </asp:RadioButtonList>
              </p>
              <p>
                  &nbsp;</p>

              <p>
                  <asp:Label ID="ApplicationIndustryLabel" runat="server" AssociatedControlID="ApplicationIndustry">
                  11.从事行业：
                  </asp:Label>
                  <asp:RadioButtonList ID="ApplicationIndustry" runat="server">
                      <asp:ListItem Value="0">作物种植</asp:ListItem>
                      <asp:ListItem Value="1">水产渔业</asp:ListItem>
                      <asp:ListItem Value="2">林业苗木</asp:ListItem>
                      <asp:ListItem Value="3">畜牧养殖</asp:ListItem>
                      <asp:ListItem Value="4">果树蔬菜</asp:ListItem>
                      <asp:ListItem Value="5">观赏园艺</asp:ListItem>
                      <asp:ListItem Value="6">农资企业</asp:ListItem>
                      <asp:ListItem Value="7">农业机械</asp:ListItem>
                      <asp:ListItem Value="8">加工贮藏</asp:ListItem>
                      <asp:ListItem Value="9">粮油食品</asp:ListItem>
                      <asp:ListItem Value="10">交通运输</asp:ListItem>
                      <asp:ListItem Value="11">生物技术</asp:ListItem>
                      <asp:ListItem Value="12">遗传育种</asp:ListItem>
                      <asp:ListItem Value="13">其他</asp:ListItem>
                  </asp:RadioButtonList>
              </p>

            <p> 
              <asp:Label ID="ApplicationWorkLabel" runat="server" AssociatedControlID="ApplicationWork">
              12. 工作单位或经营内容：</asp:Label>
              <asp:TextBox ID="ApplicationWork" runat="server" CssClass="textEntry" MaxLength="50"></asp:TextBox>  
              <asp:RequiredFieldValidator ID="ApplicationWorkRequired" runat="server" ControlToValidate="ApplicationWork"
                   CssClass="failureNotification" ErrorMessage="请输入工作单位或经营内容" ToolTip="请输入工作单位或经营内容"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>          
           </p>

           <p> 
              <asp:Label ID="ApplicationPositionLabel" runat="server" AssociatedControlID="ApplicationPosition">
              13. 职位：</asp:Label>
              <asp:TextBox ID="ApplicationPosition" runat="server" CssClass="textEntry" MaxLength="50"></asp:TextBox>  
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
