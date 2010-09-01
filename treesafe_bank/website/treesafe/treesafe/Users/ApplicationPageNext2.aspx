<%@ Page Title="" Language="C#" MasterPageFile="~/User.Master" AutoEventWireup="true" 
CodeBehind="ApplicationPageNext2.aspx.cs" Inherits="treesafe.Users.ApplicationPageNext2" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        在线填写申请表
    </h2>
    <p>
        请确认您填写的信息真实有效（本社将对您填写的一切信息保密，请放心填写）</p>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        申请人家庭情况</p>
    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div class="accountInfo">
          <fieldset>
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
                7. 您配偶是否有已经申请的贷款?</asp:Label>
                <asp:RadioButtonList ID="ApplicationMateIsHaveDeposit" runat="server" RepeatDirection="Horizontal">
                    <asp:ListItem Value="1">有</asp:ListItem> 
                    <asp:ListItem Value="0">无</asp:ListItem>
                </asp:RadioButtonList> 
           </p>

           </fieldset>
           <p class="submitButton">
              <asp:Button ID="CreateApplicationButton" runat="server" CommandName="MoveNext" Text="确定，继续填写" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="CreateApplicationButton_Click"/>
           </p>
        </div>
</asp:Content>
