<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="AdmintratorLaborSelectPage.aspx.cs" Inherits="treesafe.Admintrators.AdmintratorLaborSelectPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        雇员管理
    </h2>

     <p>
    &nbsp;
    </p>

    <p class="header" style="font-size: medium; color: #FFFFFF;">
        请选择您需要的操作</p>
        <p>
                       请慎重操作
                    </p>

          <p>      
              如需删除此雇员资料，请点击：<asp:Button ID="Button1" runat="server" Text="删除雇员" 
                  onclick="DeleteButton_Click" />
    </p>
    <p>
        如需修改此雇员资料，请点击：<asp:Button ID="Button2" runat="server" Text="修改雇员资料" 
            onclick="Button2_Click" />
    </p>
     <p class="header" style="font-size: medium; color: #FFFFFF;">
        雇员信息</p>
        <div>
          <fieldset>
    <p>
          <asp:Label ID="LaborIDLabel" runat="server" AssociatedControlID="LaborID">
          雇员工号:
          </asp:Label>
          <asp:Label ID="LaborID" runat="server" Text="LaborID"></asp:Label>
    </p>

    <p>
        <asp:Label ID="LaborTypeLabel" runat="server" AssociatedControlID="LaborType">
        雇员类型:
        </asp:Label>
        <asp:Label ID="LaborType" runat="server" Text="LaborType"></asp:Label>
    </p>

    <p>
          <asp:Label ID="LaborNameLabel" runat="server" AssociatedControlID="LaborName">
          雇员姓名:
          </asp:Label>
          <asp:Label ID="LaborName" runat="server" Text="LaborName"></asp:Label>
    </p>

    <p>
        <asp:Label ID="LaborIDNumberLabel" runat="server" AssociatedControlID="LaborIDNumber">
        雇员证件号码:
        </asp:Label>
        <asp:Label ID="LaborIDNumber" runat="server" Text="LaborIDNumber"></asp:Label>
    </p>

    <p>
        <asp:Label ID="LaborSexLabel" runat="server" AssociatedControlID="LaborSex">
        雇员性别:
        </asp:Label>
        <asp:Label ID="LaborSex" runat="server" Text="LaborSex"></asp:Label> 
    </p>

    <p>
        <asp:Label ID="LaborAgeLabel" runat="server" AssociatedControlID="LaborAge">
        雇员年龄:
        </asp:Label>
        <asp:Label ID="LaborAge" runat="server" Text="LaborAge"></asp:Label>
    </p>

    <p>
        <asp:Label ID="LaborAddressLabel" runat="server" AssociatedControlID="LaborAddress">
        雇员地址:
        </asp:Label>
        <asp:Label ID="LaborAddress" runat="server" Text="LaborAddress"></asp:Label>
    </p>

    <p>
        <asp:Label ID="LaborEmailLabel" runat="server" AssociatedControlID="LaborEmail">
        雇员电子邮件:
        </asp:Label>
        <asp:Label ID="LaborEmail" runat="server" Text="LaborEmail"></asp:Label>
    </p>

    <p>
        <asp:Label ID="LaborPhoneNumberLabel" runat="server" AssociatedControlID="LaborPhoneNumber">
        雇员电话:
        </asp:Label>
        <asp:Label ID="LaborPhoneNumber" runat="server" Text="LaborPhoneNumber"></asp:Label>
    </p>

    <p>
        <asp:Label ID="LaborNotesLabel" runat="server" AssociatedControlID="LaborNotes">
        备注:
        </asp:Label>
        <asp:Label ID="LaborNotes" runat="server" Text="LaborNotes"></asp:Label>
    </p>
    </fieldset>
    </div>

</asp:Content>
