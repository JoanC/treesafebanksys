<%@ Page Title="" Language="C#" MasterPageFile="~/Auditor.Master" AutoEventWireup="true" 
CodeBehind="AuditorListPage.aspx.cs" Inherits="treesafe.Auditors.AuditorListPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        审核申请人信息
    </h2>
       <div>
          <fieldset>
         <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人基本信息</p>
           <p>
           &nbsp;
           </p>
           <p>
              <asp:Label ID="ApplicationNameLabel" runat="server" AssociatedControlID="ApplicationName">
              1. 申请人姓名:</asp:Label>
               <asp:Label ID="ApplicationName" runat="server" Text="ApplicationName"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationAgeLabel" runat="server" AssociatedControlID="ApplicationAge">
              2. 申请人年龄:</asp:Label>
               <asp:Label ID="ApplicationAge" runat="server" Text="ApplicationAge"></asp:Label>         
           </p>
           
           <p>
              <asp:Label ID="ApplicationSexLabel" runat="server" AssociatedControlID="ApplicationSex">
              3. 申请人性别:</asp:Label>
               <asp:Label ID="ApplicationSex" runat="server" Text="ApplicationSex"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationIDTypeLabel" runat="server" AssociatedControlID="ApplicationIDType">
              4. 证件类型:</asp:Label>
               <asp:Label ID="ApplicationIDType" runat="server" Text="ApplicationIDType"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationIDNumberLabel" runat="server" AssociatedControlID="ApplicationIDNumber">
              5. 证件号码:</asp:Label>
               <asp:Label ID="ApplicationIDNumber" runat="server" Text="ApplicationIDNumber"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationAddressLabel" runat="server" AssociatedControlID="ApplicationAddress">
              6. 家庭住址：</asp:Label>
               <asp:Label ID="ApplicationAddress" runat="server" Text="ApplicationAddress"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationPostCodeLabel" runat="server" AssociatedControlID="ApplicationPostCode">
              7. 邮政编码：</asp:Label>
               <asp:Label ID="ApplicationPostCode" runat="server" Text="ApplicationPostCode"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationHouseTypeLabel" runat="server" AssociatedControlID="ApplicationHouseType">
              8. 住宅权属:</asp:Label>
               <asp:Label ID="ApplicationHouseType" runat="server" Text="ApplicationHouseType"></asp:Label>
           </p>

           <p>
               <asp:Label ID="ApplicationPhoneNumberLabel" runat="server" AssociatedControlID="ApplicationPhoneNumber">
               9. 联系电话：</asp:Label>
               <asp:Label ID="ApplicationPhoneNumber" runat="server" Text="ApplicationPhoneNumber"></asp:Label>
           </p>

           <p> 
              <asp:Label ID="ApplicationPhoneNumberLabel1" runat="server" AssociatedControlID="ApplicationPhoneNumber1">
              10. 其他联系电话：</asp:Label>
               <asp:Label ID="ApplicationPhoneNumber1" runat="server" Text="ApplicationPhoneNumber1"></asp:Label>           
           </p>

           <p>
               <asp:Label ID="ApplicationEducationLabel" runat="server" AssociatedControlID="ApplicationEducation">
               11. 受教育状况：</asp:Label>
               <asp:Label ID="ApplicationEducation" runat="server" Text="ApplicationEducation"></asp:Label>
           </p>
           <p>
               <asp:CheckBox ID="CheckBox1" runat="server" 
                   oncheckedchanged="CheckBox1_CheckedChanged"/>经核实，上述信息均正确无误（请慎重选择）
           </p>
           <p>
           &nbsp;
           </p>

           <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人经济情况</p>
          <p>
           &nbsp;
           </p>
           <p>
              <asp:Label ID="ApplicationPersonIncomeLabel" runat="server" AssociatedControlID="ApplicationPersonIncome">
              1. 个人年收入:</asp:Label>
               <asp:Label ID="ApplicationPersonIncome" runat="server" Text="ApplicationPersonIncome"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationHomeIncomeLabel" runat="server" AssociatedControlID="ApplicationHomeIncome">
              2. 家庭年收入:</asp:Label>
               <asp:Label ID="ApplicationHomeIncome" runat="server" Text="ApplicationHomeIncome"></asp:Label>
           </p>
           <p> 
                  <asp:Label ID="ApplicationIsHaveDepositLabel" runat="server" AssociatedControlID="ApplicationIsHaveDeposit">
                  3. 是否有存款?</asp:Label>
               <asp:Label ID="ApplicationIsHaveDeposit" runat="server" Text="ApplicationIsHaveDeposit"></asp:Label> 
              </p>

              <p>
                  <asp:Label ID="ApplicationDepositFixedLabel" runat="server" AssociatedControlID="ApplicationDepositFixed">
                  4. 其中，定期存款总金额为（无定期存款填0）：
                  </asp:Label>
                  <asp:Label ID="ApplicationDepositFixed" runat="server" Text="ApplicationDepositFixed"></asp:Label>
              </p>

              <p>
                  <asp:Label ID="ApplicationCurrentDepositLabel" runat="server" AssociatedControlID="ApplicationCurrentDeposit">
                  5. 其中，活期存款总金额为（无活期存款填0）：
                  </asp:Label>
                  <asp:Label ID="ApplicationCurrentDeposit" runat="server" Text="ApplicationCurrentDeposit"></asp:Label>
              </p>

              <p>
                  <asp:Label ID="ApplicationIsHaveLoanLabel" runat="server" AssociatedControlID="ApplicationIsHaveLoan">
                  6. 是否有贷款?</asp:Label>
                  <asp:Label ID="ApplicationIsHaveLoan" runat="server" Text="ApplicationIsHaveLoan"></asp:Label>
              </p>

              <p>
                  <asp:Label ID="ApplicationLoanSumLabel" runat="server" AssociatedControlID="ApplicationLoanSum">
                  7. 如果有贷款的话，贷款总金额为：</asp:Label>
                  <asp:Label ID="ApplicationLoanSum" runat="server" Text="ApplicationLoanSum"></asp:Label>
              </p>
              
              <p>
                  <asp:Label ID="ApplicationLoanDeadlineLabel" runat="server" AssociatedControlID="ApplicationLoanDeadline">
                  8. 预计还清贷款日期（年月日，例如：2012年2月2日）：
                  </asp:Label>
                  <asp:Label ID="ApplicationLoanDeadline" runat="server" Text="ApplicationLoanDeadline"></asp:Label>
              </p>

              <p>
                  <asp:Label ID="ApplicationIsMortgageLabel" runat="server" AssociatedControlID="ApplicationIsMortgage">
                  9. 是否有已抵押的固定资产：
                  </asp:Label>
                  <asp:Label ID="ApplicationIsMortgage" runat="server" Text="ApplicationIsMortgage"></asp:Label>
              </p>

              <p>
                  <asp:Label ID="ApplicationMortgageLabel" runat="server" AssociatedControlID="ApplicationMortgage">
                  10.未抵押的主要固定资产：
                  </asp:Label>
                  <asp:Label ID="ApplicationMortgage" runat="server" Text="ApplicationMortgage"></asp:Label>
              </p>
              <p>
                  <asp:Label ID="ApplicationIndustryLabel" runat="server" AssociatedControlID="ApplicationIndustry">
                  11.从事行业：
                  </asp:Label>
                  <asp:Label ID="ApplicationIndustry" runat="server" Text="ApplicationIndustry"></asp:Label>
              </p>

            <p> 
              <asp:Label ID="ApplicationWorkLabel" runat="server" AssociatedControlID="ApplicationWork">
              12. 工作单位或经营内容：</asp:Label>
                <asp:Label ID="ApplicationWork" runat="server" Text="ApplicationWork"></asp:Label>         
           </p>

           <p> 
              <asp:Label ID="ApplicationPositionLabel" runat="server" AssociatedControlID="ApplicationPosition">
              13. 职位：</asp:Label>
               <asp:Label ID="ApplicationPosition" runat="server" Text="ApplicationPosition"></asp:Label>         
           </p>
           <p>
               <asp:CheckBox ID="CheckBox2" runat="server" 
                   oncheckedchanged="CheckBox2_CheckedChanged"/>经核实，上述信息均正确无误（请慎重选择）
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
            <asp:Label ID="ApplicationMarrige" runat="server" Text="ApplicationMarrige"></asp:Label>
           </p>

           <p>
                <asp:Label ID="ApplicationChildrenNumberLabel" runat="server" AssociatedControlID="ApplicationChildrenNumber">
                2. 子女人数：
                </asp:Label>
               <asp:Label ID="ApplicationChildrenNumber" runat="server" Text="ApplicationChildrenNumber"></asp:Label>
           </p>

           <p>
                <asp:Label ID="ApplicationMateNameLabel" runat="server" AssociatedControlID="ApplicationMateName">
                3. 配偶姓名：
                </asp:Label>
               <asp:Label ID="ApplicationMateName" runat="server" Text="ApplicationMateName"></asp:Label>
           </p>

           <p>
              <asp:Label ID="ApplicationMateIDTypeLabel" runat="server" AssociatedControlID="ApplicationMateIDType">
              4. 配偶的证件类型:
              </asp:Label>
               <asp:Label ID="ApplicationMateIDType" runat="server" Text="ApplicationMateIDType"></asp:Label>
           </p>

           <p>
                <asp:Label ID="ApplicationMateIDNumberLabel" runat="server" AssociatedControlID="ApplicationMateIDNumber">
                5. 配偶证件号码：
                </asp:Label>
               <asp:Label ID="ApplicationMateIDNumber" runat="server" Text="ApplicationMateIDNumber"></asp:Label>
           </p>

           <p>
                <asp:Label ID="ApplicationMateWorkLabel" runat="server" AssociatedControlID="ApplicationMateWork">
                6. 配偶工作单位（工作情况）：
                </asp:Label>
               <asp:Label ID="ApplicationMateWork" runat="server" Text="ApplicationMateWork"></asp:Label>
           </p>

           <p>
               <asp:Label ID="ApplicationMateEducationLabel" runat="server" AssociatedControlID="ApplicationMateEducation">
               7. 配偶的受教育状况：</asp:Label>
               <asp:Label ID="ApplicationMateEducation" runat="server" Text="ApplicationMateEducation"></asp:Label>
           </p>

           <p> 
                <asp:Label ID="ApplicationMateIsHaveDepositLabel" runat="server" AssociatedControlID="ApplicationMateIsHaveDeposit">
                8. 配偶是否有已经申请的贷款?</asp:Label>
               <asp:Label ID="ApplicationMateIsHaveDeposit" runat="server" Text="ApplicationMateIsHaveDeposit"></asp:Label> 
           </p>

           <p>
               <asp:CheckBox ID="CheckBox3" runat="server" 
                   oncheckedchanged="CheckBox3_CheckedChanged"/>经核实，上述信息均正确无误（请慎重选择）
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
               <asp:Label ID="ApplicationExpectLoanSumLabel" runat="server" AssociatedControlID="ApplicationExpectLoanSum">
               1. 预计申请贷款金额：
               </asp:Label>
               <asp:Label ID="ApplicationExpectLoanSum" runat="server" Text="ApplicationExpectLoanSum"></asp:Label>
          </p>
          
          <p>
              <asp:Label ID="ApplicationLoanTimeLabel" runat="server" AssociatedControlID="ApplicationLoanTime">
              2. 预计还贷期限：
              </asp:Label>
              <asp:Label ID="ApplicationLoanTime" runat="server" Text="ApplicationLoanTime"></asp:Label>
           </p>

          <p>
               <asp:Label ID="ApplicationLoanNumberLabel" runat="server" AssociatedControlID="ApplicationLoanNumber">
               3. 贷款次数：
               </asp:Label>
              <asp:Label ID="ApplicationLoanNumber" runat="server" Text="ApplicationLoanNumber"></asp:Label> 
          </p>

          <p>
               <asp:Label ID="ApplicationLoanNoteLabel" runat="server" AssociatedControlID="ApplicationLoanNote">
               4. 申贷项目可行性说明：
               </asp:Label>
              <asp:Label ID="ApplicationLoanNote" runat="server" Text="ApplicationLoanNote"></asp:Label>
          </p>

          <p>
               <asp:Label ID="ApplicationIsMessageLabel" runat="server" AssociatedControlID="ApplicationIsMessage">
               5. 是否希望接收我们的短信通知?
               </asp:Label>
              <asp:Label ID="ApplicationIsMessage" runat="server" Text="ApplicationIsMessage"></asp:Label>
              
           </p>

            <p>
               <asp:CheckBox ID="CheckBox4" runat="server" 
                    oncheckedchanged="CheckBox4_CheckedChanged"/>经核实，上述信息均正确无误（请慎重选择）
           </p>
     
           </fieldset>
           <p style="color: #3366FF;">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        您的工作至关重要！请慎重。
        </p>
           <p class="submitButton">
              <asp:Button ID="CommitApplicationButton" runat="server" CommandName="MoveNext" Text="确定，提交审核" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CommitApplicationButton_Click"/>
           </p>
        </div>
</asp:Content>
