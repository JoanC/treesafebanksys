<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="WorkerOneUserDataPage.aspx.cs" Inherits="treesafe.Workers.WorkerOneUserDataPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
      该用户的风险评估结果
    </h2>     
     <div>
          <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        还贷能力部分
        </p>
        <p>
        *此部分主要描述该用户的经济实力*
        </p>
          <p>
              <asp:Label ID="WeightIncomeLabel" runat="server" AssociatedControlID="WeightIncome">
              1. 该用户的收入:</asp:Label>
               <asp:Label ID="WeightIncome" runat="server" Text="20"></asp:Label>
           </p>
            <p>
              <asp:Label ID="WeightDepositLabel" runat="server" AssociatedControlID="WeightDeposit">
              2. 该用户的存款:</asp:Label>
               <asp:Label ID="WeightDeposit" runat="server" Text="8"></asp:Label>
           </p>
            <p>
              <asp:Label ID="WeightLoanLabel" runat="server" AssociatedControlID="WeightLoan">
              3. 该用户的负债:</asp:Label>
               <asp:Label ID="WeightLoan" runat="server" Text="12"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightMortagageLabel" runat="server" AssociatedControlID="WeightMortagage">
              4. 该用户未抵押的主要固定资产:</asp:Label>
               <asp:Label ID="WeightMortagage" runat="server" Text="15"></asp:Label>
           </p>

            <p class="header" style="font-size: medium; color: #FFFFFF;">
        个人信誉部分
        </p>
        <p>
        *此部分主要描述该用户的社会记录，包括个人社会地位，声誉等*
        </p>
           <p>
              <asp:Label ID="WeightIDLabel" runat="server" AssociatedControlID="WeightID">
              5. 该用户的证件类型（系统自动给予现役军人更高的分值）:</asp:Label>
               <asp:Label ID="WeightID" runat="server" Text="10"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightEducationLabel" runat="server" AssociatedControlID="WeightEducation">
              6. 该用户的受教育情况:</asp:Label>
               <asp:Label ID="WeightEducation" runat="server" Text="10"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightHomeLabel" runat="server" AssociatedControlID="WeightHome">
              7. 该用户的家庭状况:</asp:Label>
               <asp:Label ID="WeightHome" runat="server" Text="10"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightLoanRecordLabel" runat="server" AssociatedControlID="WeightLoanRecord">
              8. 该用户的以往贷款记录:</asp:Label>
               <asp:Label ID="WeightLoanRecord" runat="server" Text="10"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightSocietyRecordLabel" runat="server" AssociatedControlID="WeightSocietyRecord">
              9. 该用户的不良社会记录:</asp:Label>
               <asp:Label ID="WeightSocietyRecord" runat="server" Text="10"></asp:Label>
           </p>

           <p class="header" style="font-size: medium; color: #FFFFFF;">
        还贷风险部分
        </p>
        <p>
        *此部分主要描述申请人收入稳定程度*
        </p>
         
          <p>
              <asp:Label ID="WeightWorkLabel" runat="server" AssociatedControlID="WeightWork">
              10. 该用户的行业风险:</asp:Label>
               <asp:Label ID="WeightWork" runat="server" Text="10"></asp:Label>
           </p>
           </fieldset>
        </div>

</asp:Content>
