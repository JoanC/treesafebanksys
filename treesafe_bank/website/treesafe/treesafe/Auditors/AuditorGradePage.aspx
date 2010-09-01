<%@ Page Title="" Language="C#" MasterPageFile="~/Auditor.Master" AutoEventWireup="true" 
CodeBehind="AuditorGradePage.aspx.cs" Inherits="treesafe.Auditors.AuditorGradePage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        为下列申请信息打分
    </h2>
    <p>
        &nbsp;&nbsp;&nbsp;&nbsp;
        请您根据审核中获得的信息，为用户
        <asp:Label ID="UserID" runat="server" ForeColor="Blue"></asp:Label>
        打分。您给出的分值将用于系统的风险评估，请慎重。
        <br/>
        <br/>
         &nbsp;&nbsp;&nbsp;&nbsp;
        *每一项的分值介于0~10*
    </p>
    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div>
          <fieldset>
         <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人信息部分</p>

        <p>
            <asp:Label ID="ApplicationMortgageLabel" runat="server" AssociatedControlID="ApplicationMortgage">
            1.未抵押的主要固定资产：
            </asp:Label>
            <asp:Label ID="ApplicationMortgage" runat="server" Text="ApplicationMortgage"></asp:Label>
            </p>
            <p>
            <asp:RadioButtonList ID="ApplicationMortgageGrade" runat="server" 
                RepeatDirection="Horizontal">
                <asp:ListItem Value="0"></asp:ListItem>
                <asp:ListItem Value="1"></asp:ListItem>
                <asp:ListItem Value="2"></asp:ListItem>
                <asp:ListItem Value="3"></asp:ListItem>
                <asp:ListItem Value="4"></asp:ListItem>
                <asp:ListItem Value="5"></asp:ListItem>
                <asp:ListItem Value="6"></asp:ListItem>
                <asp:ListItem Value="7"></asp:ListItem>
                <asp:ListItem Value="8"></asp:ListItem>
                <asp:ListItem Value="9"></asp:ListItem>
                <asp:ListItem Value="10"></asp:ListItem>
            </asp:RadioButtonList>
            <asp:RequiredFieldValidator ID="ApplicationMortgageGradeRequired" runat="server" ControlToValidate="ApplicationMortgageGrade"
                   CssClass="failureNotification" ErrorMessage="请为申请人固定资产打分" ToolTip="请为申请人固定资产打分"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
       </p>
       <p>
       &nbsp;
       </p>

        <p>2.请综合以下3项信息给出分值，以评估申请人工作稳定及收入稳定程度
        </p>
        <p>
            <asp:Label ID="ApplicationIndustryLabel" runat="server" AssociatedControlID="ApplicationIndustry">
            从事行业：
            </asp:Label>
            <asp:Label ID="ApplicationIndustry" runat="server" Text="ApplicationIndustry"></asp:Label>
         </p>
         <p>
            <asp:Label ID="ApplicationWorkLabel" runat="server" AssociatedControlID="ApplicationWork">
            工作单位或经营内容：</asp:Label>
            <asp:Label ID="ApplicationWork" runat="server" Text="ApplicationWork"></asp:Label>         
         </p>
         <p>
            <asp:Label ID="ApplicationPositionLabel" runat="server" AssociatedControlID="ApplicationPosition">
            职位：</asp:Label>
            <asp:Label ID="ApplicationPosition" runat="server" Text="ApplicationPosition"></asp:Label> 
          </p>
          <p>  
             <asp:RadioButtonList ID="ApplicationWorkGrade" runat="server" 
                RepeatDirection="Horizontal">
                <asp:ListItem Value="0"></asp:ListItem>
                <asp:ListItem Value="1"></asp:ListItem>
                <asp:ListItem Value="2"></asp:ListItem>
                <asp:ListItem Value="3"></asp:ListItem>
                <asp:ListItem Value="4"></asp:ListItem>
                <asp:ListItem Value="5"></asp:ListItem>
                <asp:ListItem Value="6"></asp:ListItem>
                <asp:ListItem Value="7"></asp:ListItem>
                <asp:ListItem Value="8"></asp:ListItem>
                <asp:ListItem Value="9"></asp:ListItem>
                <asp:ListItem Value="10"></asp:ListItem>
            </asp:RadioButtonList>  
            <asp:RequiredFieldValidator ID="ApplicationWorkGradeRequired" runat="server" ControlToValidate="ApplicationWorkGrade"
                   CssClass="failureNotification" ErrorMessage="请为申请人工作情况打分" ToolTip="请为申请人工作情况打分"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>     
       </p>
       <p>
       &nbsp;
       </p>

        <p class="header" style="font-size: medium; color: #FFFFFF;">
        预计申请贷款部分</p>
        <p>请综合以下信息给出分值，以评估该笔贷款合理性，可行性
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
             <asp:RadioButtonList ID="ApplicationLoanGrade" runat="server" 
                RepeatDirection="Horizontal">
                <asp:ListItem Value="0"></asp:ListItem>
                <asp:ListItem Value="1"></asp:ListItem>
                <asp:ListItem Value="2"></asp:ListItem>
                <asp:ListItem Value="3"></asp:ListItem>
                <asp:ListItem Value="4"></asp:ListItem>
                <asp:ListItem Value="5"></asp:ListItem>
                <asp:ListItem Value="6"></asp:ListItem>
                <asp:ListItem Value="7"></asp:ListItem>
                <asp:ListItem Value="8"></asp:ListItem>
                <asp:ListItem Value="9"></asp:ListItem>
                <asp:ListItem Value="10"></asp:ListItem>
            </asp:RadioButtonList>
            
            <asp:RequiredFieldValidator ID="ApplicationLoanGradeRequired" runat="server" ControlToValidate="ApplicationLoanGrade"
                   CssClass="failureNotification" ErrorMessage="请为申请人预计贷款项目打分" ToolTip="请为申请人预计贷款项目打分"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>       
       </p>
        </fieldset>
       </div>

       <p style="color: #3366FF;">
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        您的工作至关重要！请慎重。
        </p>
           <p class="submitButton">
              <asp:Button ID="CommitApplicationGradeButton" runat="server" 
                   CommandName="MoveNext" Text="确定，提交评分" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CommitApplicationGradeButton_Click"/>
           </p>

</asp:Content>
