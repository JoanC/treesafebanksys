
<%@ Page Title="User Page" Language="C#" MasterPageFile="~/User.master" AutoEventWireup="true"
    CodeBehind="UserRootPage.aspx.cs" Inherits="treesafe.Users.UserRootPage" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        欢迎使用XX农民联保贷款风险控制系统
    </h2>
    <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
    1
    </p>
    <p class="leftpic">
        <asp:Image ID="Image1" runat="server" ImageUrl="~/Pictures/gesture1.png"/>   
    </p>
    <p class="rightinfo">
    1
    </p>
    </fieldset>
    
    
    <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
    2
    </p>
    <p class="leftpic">
        <asp:Image ID="Image2" runat="server" ImageUrl="~/Pictures/gesture2.png"/>
    </p>
    <p class="rightinfo">
    2
    </p>
    </fieldset>
    
    
    <fieldset>
    
    <p class="header" style="font-size: medium; color: #FFFFFF;">
    3
    </p>

    <p class="leftpic">
        <asp:Image ID="Image3" runat="server" ImageUrl="~/Pictures/gesture3.png"/>
    </p>
    <p class="rightinfo">
    3
    </p>
    </fieldset>
      
    <fieldset>
    <p class="header" style="font-size: medium; color: #FFFFFF;">
    4
    </p>

    <p class="leftpic">
        <asp:Image ID="Image4" runat="server" ImageUrl="~/Pictures/gesture4.png"/>
    </p>
    <p class="rightinfo">
    </p>
    </fieldset>

</asp:Content>
