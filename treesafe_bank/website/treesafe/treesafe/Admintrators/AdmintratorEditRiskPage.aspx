﻿<%@ Page Title="" Language="C#" MasterPageFile="~/Admintrator.Master" AutoEventWireup="true" 
CodeBehind="AdmintratorEditRiskPage.aspx.cs" Inherits="treesafe.Admintrators.AdmintratorEditRiskPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
       修改风险评估权重
    </h2>
    <p>
    *建议从上到下修改*
    <br/>
    当您对其中一项作出修改时，我们会动态调整其下项目的百分比。
    </p>
     <div>
          <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        还贷能力部分
        </p>
        <p>
        *此部分主要描述申请人的经济实力*
        </p>
          <p>
              <asp:Label ID="WeightIncomeLabel" runat="server" AssociatedControlID="WeightIncome">
              1. 申请人收入:</asp:Label>
              <br/>
               <asp:Label ID="WeightIncome" runat="server" Text="WeightIncome"></asp:Label>

           </p>
            <p>
              <asp:Label ID="WeightDepositLabel" runat="server" AssociatedControlID="WeightDeposit">
              2. 申请人存款:</asp:Label>
               <asp:Label ID="WeightDeposit" runat="server" Text="WeightDeposit"></asp:Label>
           </p>
            <p>
              <asp:Label ID="WeightLoanLabel" runat="server" AssociatedControlID="WeightLoan">
              3. 申请人负债:</asp:Label>
               <asp:Label ID="WeightLoan" runat="server" Text="WeightLoan"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightMortagageLabel" runat="server" AssociatedControlID="WeightMortagage">
              4. 申请人未抵押的主要固定资产:</asp:Label>
               <asp:Label ID="WeightMortagage" runat="server" Text="WeightMortagage"></asp:Label>
           </p>

            <p class="header" style="font-size: medium; color: #FFFFFF;">
        个人信誉部分
        </p>
        <p>
        *此部分主要描述申请人的社会记录，包括个人社会地位，声誉等*
        </p>
           <p>
              <asp:Label ID="WeightIDLabel" runat="server" AssociatedControlID="WeightID">
              5. 申请人证件类型（系统自动给予现役军人更高的分值）:</asp:Label>
               <asp:Label ID="WeightID" runat="server" Text="WeightID"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightEducationLabel" runat="server" AssociatedControlID="WeightEducation">
              6. 申请人受教育情况:</asp:Label>
               <asp:Label ID="WeightEducation" runat="server" Text="WeightEducation"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightHomeLabel" runat="server" AssociatedControlID="WeightHome">
              7. 申请人家庭状况:</asp:Label>
               <asp:Label ID="WeightHome" runat="server" Text="WeightHome"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightLoanRecordLabel" runat="server" AssociatedControlID="WeightLoanRecord">
              8. 申请人以往贷款记录:</asp:Label>
               <asp:Label ID="WeightLoanRecord" runat="server" Text="WeightLoanRecord"></asp:Label>
           </p>
           <p>
              <asp:Label ID="WeightSocietyRecordLabel" runat="server" AssociatedControlID="WeightSocietyRecord">
              8. 申请人不良社会记录:</asp:Label>
               <asp:Label ID="WeightSocietyRecord" runat="server" Text="WeightSocietyRecord"></asp:Label>
           </p>

           <p class="header" style="font-size: medium; color: #FFFFFF;">
        还贷风险部分
        </p>
        <p>
        *此部分主要描述申请人收入稳定程度*
        </p>
          <p>
              <asp:Label ID="WeightWorkLabel" runat="server" AssociatedControlID="WeightWork">
              9. 申请人行业风险:</asp:Label>
               <asp:Label ID="WeightWork" runat="server" Text="WeightWork"></asp:Label>
           </p>
           </fieldset>

           <p class="submitButton">
              <asp:Button ID="FinishEditWeightButton" runat="server" CommandName="MoveNext" Text="完成权重设定" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="FinishEditWeightButton_Click"/>
           </p>
        </div>
</asp:Content>