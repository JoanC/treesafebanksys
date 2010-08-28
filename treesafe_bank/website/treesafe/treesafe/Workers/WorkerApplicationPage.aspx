<%@ Page Title="" Language="C#" MasterPageFile="~/Worker.Master" AutoEventWireup="true" 
CodeBehind="WorkerApplicationPage.aspx.cs" Inherits="treesafe.Workers.WorkerApplicationPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
<h2>
        在线填写申请表
    </h2>
    <p>
        &nbsp;</p>
    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div class="accountInfo">
          <fieldset>
         <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人基本信息</p>
           <p>
           &nbsp;
           </p>
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
           <p>
           &nbsp;
           </p>

           <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人经济情况</p>
          <p>
          <p>
           &nbsp;
           </p>
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

           <p>
           &nbsp;
           </p>
           <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人家庭情况</p>
        <p>
           &nbsp;
           </p>
        <p>
              <asp:Label ID="ApplicationMarrigeLabel" runat="server" AssociatedControlID="ApplicationMarrige">
              1. 婚姻状况:</asp:Label>
              <asp:RadioButtonList ID="ApplicationMarrige" runat="server" RepeatDirection="Horizontal">
                      <asp:ListItem Value="0">未婚</asp:ListItem> 
                      <asp:ListItem Value="1">已婚</asp:ListItem>
                      <asp:ListItem Value="2">离异</asp:ListItem> 
                      <asp:ListItem Value="3">丧偶</asp:ListItem>
                  </asp:RadioButtonList>
              <asp:RequiredFieldValidator ID="ApplicationMarrigeRequired" runat="server" ControlToValidate="ApplicationMarrige"
                   CssClass="failureNotification" ErrorMessage="请输入婚姻状况" ToolTip="请输入婚姻状况"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
               如果您未婚，以下信息可略过不填。
           </p>

           <p>
                <asp:Label ID="ApplicationChildrenNumberLabel" runat="server" AssociatedControlID="ApplicationChildrenNumber">
                2. 您的子女人数：
                </asp:Label>
                <asp:TextBox ID="ApplicationChildrenNumber" runat="server" CssClass="textEntry"></asp:TextBox>
           </p>

           <p>
                <asp:Label ID="ApplicationMateNameLabel" runat="server" AssociatedControlID="ApplicationMateName">
                3. 您的配偶姓名：
                </asp:Label>
                <asp:TextBox ID="ApplicationMateName" runat="server" CssClass="textEntry"></asp:TextBox>
           </p>

           <p>
                <asp:Label ID="ApplicationMateIDNumberLabel" runat="server" AssociatedControlID="ApplicationMateIDNumber">
                4. 您的配偶身份证号：
                </asp:Label>
                <asp:TextBox ID="ApplicationMateIDNumber" runat="server" CssClass="textEntry"></asp:TextBox>
           </p>

           <p>
                <asp:Label ID="ApplicationMateWorkLabel" runat="server" AssociatedControlID="ApplicationMateWork">
                5. 您的配偶工作单位（工作情况）：
                </asp:Label>
                <asp:TextBox ID="ApplicationMateWork" runat="server" CssClass="textEntry"></asp:TextBox>
           </p>

           <p>
               <asp:Label ID="ApplicationMateEducationLabel" runat="server" AssociatedControlID="ApplicationMateEducation">
               6. 您配偶的受教育状况：</asp:Label>
               &nbsp;&nbsp;
               <asp:DropDownList ID="ApplicationMateEducation" runat="server">
                     <asp:ListItem Value="0">初中及以下</asp:ListItem>
                     <asp:ListItem Value="1">高中及职业技术学校</asp:ListItem>
                     <asp:ListItem Value="2">本科及大专院校</asp:ListItem>
                     <asp:ListItem Value="3">研究生及以上</asp:ListItem>
               </asp:DropDownList>
           </p>

           <p> 
                <asp:Label ID="ApplicationMateIsHaveDepositLabel" runat="server" AssociatedControlID="ApplicationMateIsHaveDeposit">
                3. 您配偶是否有已经申请的贷款?</asp:Label>
                <asp:RadioButtonList ID="ApplicationMateIsHaveDeposit" runat="server" RepeatDirection="Horizontal">
                    <asp:ListItem Value="1">有</asp:ListItem> 
                    <asp:ListItem Value="0">无</asp:ListItem>
                </asp:RadioButtonList> 
           </p>

           <p>
           &nbsp;
           </p>

           <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请贷款情况调查
        </p>

           <p>
           &nbsp;
           </p>

           <p>
               <asp:Label ID="Label1" runat="server" AssociatedControlID="ApplicationLoanSum">
               1. 预计申请贷款金额：
               </asp:Label>
               <asp:TextBox ID="TextBox1" runat="server" CssClass="textEntry"></asp:TextBox>
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
               <asp:Label ID="ApplicationUseLabel" runat="server" AssociatedControlID="ApplicationUse">
               3. 贷款用途：
               </asp:Label>
               <asp:TextBox ID="ApplicationUse" runat="server" CssClass="textEntry"></asp:TextBox>
          </p>

          <p>
               <asp:Label ID="ApplicationLoanNumberLabel" runat="server" AssociatedControlID="ApplicationLoanNumber">
               4. 贷款次数：
               </asp:Label>
               <asp:RadioButtonList ID="ApplicationLoanNumber" runat="server" RepeatDirection="Horizontal">
                   <asp:ListItem Value="0">首次贷款</asp:ListItem> 
                   <asp:ListItem Value="1">非首次贷款</asp:ListItem>
               </asp:RadioButtonList> 
          </p>

          <p>
               <asp:Label ID="ApplicationLoanNoteLabel" runat="server" AssociatedControlID="ApplicationLoanNote">
               5. 申贷项目可行性说明：
               </asp:Label>
               <br/>
               <asp:TextBox ID="ApplicationLoanNote" runat="server" CssClass="textEntry" 
                   Height="80px" TextMode="MultiLine" Width="337px"></asp:TextBox>
          </p>

          <p>
               <asp:Label ID="ApplicationIsMessageLabel" runat="server" AssociatedControlID="ApplicationIsMessage">
               6. 是否希望接收我们的短信通知?
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
              <asp:Button ID="CreateApplicationButton" runat="server" CommandName="MoveNext" Text="确定，提交申请" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CreateApplicationButton_Click"/>
           </p>
        </div>
</asp:Content>
