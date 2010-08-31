<%@ Page Title="" Language="C#" MasterPageFile="~/Welcome.Master" AutoEventWireup="true" 
CodeBehind="AdmintratorLaborSelectPage.aspx.cs" Inherits="treesafe.Admintrators.AdmintratorLaborSelectPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="HeadContent" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <h2>
        雇员管理
    </h2>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
        请选择您需要的操作</p>
        <p>
                       请慎重操作
                    </p>

          <p>      
              如需删除此雇员资料，请点击：<asp:Button ID="DeleteButton" runat="server" Text="删除雇员" 
                  onclick="DeleteButton_Click" />
    </p>
    <p>
        如需修改此雇员资料，请点击：<asp:Button ID="EditButton" runat="server" Text="修改雇员资料" />
    </p>



</asp:Content>
