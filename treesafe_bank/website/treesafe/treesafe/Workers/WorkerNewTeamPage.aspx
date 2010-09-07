<%@ Page Title="" Language="C#" MasterPageFile="~/Worker.Master" AutoEventWireup="true" 
CodeBehind="WorkerNewTeamPage.aspx.cs" Inherits="treesafe.Workers.WorkerNewTeamPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
     <h2>
        新增联保小组
    </h2>
    <p>
    <br/>
        请在下面输入联保小组组内成员的证件号码
    </p>

    <span class="failureNotification">
        <asp:Literal ID="ErrorMessage" runat="server"></asp:Literal>
    </span>
    <asp:ValidationSummary ID="ApplicationValidationSummary" runat="server" CssClass="failureNotification" 
    ValidationGroup="ApplicationValidationGroup"/>
       <div>
          <fieldset>
           <p>
              <asp:Label ID="TeamLeaderLabel" runat="server" AssociatedControlID="TeamLeader">
              1. 组长证件号码:</asp:Label>
              <asp:TextBox ID="TeamLeader" runat="server" CssClass="textEntry" MaxLength="18"></asp:TextBox>
              <asp:RequiredFieldValidator ID="TeamLeaderRequired" runat="server" ControlToValidate="TeamLeader"
                   CssClass="failureNotification" ErrorMessage="请输入组长证件号码" ToolTip="请输入组长证件号码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>
           
           <p>
              <asp:Label ID="TeamMember1Label" runat="server" AssociatedControlID="TeamMember1">
              2.组员1证件号码:</asp:Label>
               <asp:TextBox ID="TeamMember1" runat="server" CssClass="textEntry" MaxLength="18"></asp:TextBox>
              <asp:RequiredFieldValidator ID="TeamMember1Required" runat="server" ControlToValidate="TeamMember1"
                   CssClass="failureNotification" ErrorMessage="请输入组员1证件号码" ToolTip="请输入组员1证件号码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="TeamMember2Label" runat="server" AssociatedControlID="TeamMember2">
              3. 组员2证件号码:</asp:Label>
               <asp:TextBox ID="TeamMember2" runat="server" CssClass="textEntry" MaxLength="18"></asp:TextBox>
              <asp:RequiredFieldValidator ID="TeamMember2Required" runat="server" ControlToValidate="TeamMember2"
                   CssClass="failureNotification" ErrorMessage="请输入组员2证件号码" ToolTip="请输入组员2证件号码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>

           <p>
              <asp:Label ID="TeamMember3Label" runat="server" AssociatedControlID="TeamMember3">
              4. 组员3证件号码：</asp:Label>
              <asp:TextBox ID="TeamMember3" runat="server" CssClass="textEntry" MaxLength="18"></asp:TextBox>
              <asp:RequiredFieldValidator ID="TeamMember3Required" runat="server" ControlToValidate="TeamMember3"
                   CssClass="failureNotification" ErrorMessage="请输入组员3证件号码" ToolTip="请输入组员3证件号码"
                    ValidationGroup="ApplicationValidationGroup">*</asp:RequiredFieldValidator>
           </p>


           <p>
              <asp:Label ID="TeamMember4Label" runat="server" AssociatedControlID="TeamMember4">
              5. 组员4证件号码：</asp:Label>
              <asp:TextBox ID="TeamMember4" runat="server" CssClass="textEntry" MaxLength="18"></asp:TextBox>
           </p>

           <p>
              <asp:Label ID="TeamMember5Label" runat="server" AssociatedControlID="TeamMember5">
              6. 组员5证件号码:</asp:Label>
               <asp:TextBox ID="TeamMember5" runat="server" CssClass="textEntry" MaxLength="18"></asp:TextBox>
           </p>

           <p>
               <asp:Label ID="TeamMember6Label" runat="server" AssociatedControlID="TeamMember6">
               7. 组员6证件号码：</asp:Label>
               <asp:TextBox ID="TeamMember6" runat="server" CssClass="textEntry" MaxLength="18"></asp:TextBox>
           </p>

           </fieldset>
           <p class="submitButton">
              <asp:Button ID="NewTeamButton" runat="server" CommandName="MoveNext" Text="确定，创建联保小组" 
                          ValidationGroup="ApplicationValidationGroup" 
                   onclick="NewTeamButton_Click"/>
           </p>
        </div>
</asp:Content>
