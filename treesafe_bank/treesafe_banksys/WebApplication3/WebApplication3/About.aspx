<%@ Page Title="About Us" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="About.aspx.cs" Inherits="WebApplication3.About" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
    <script language="javascript" type="text/javascript">
// <![CDATA[

        function submitSaveEdit_onclick() {
            SaveNewPass();
        }

// ]]>
    </script>
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        About
    </h2>
    <p>
       <input name="submitSaveEdit" type="submit" class="button"  id="submitSaveEdit" value="发送消息" style="WIDTH: 60;" onclick="return submitSaveEdit_onclick()"></input>
    </p>
    <asp:Button ID="Button1" runat="server" onclick="Button1_Click" 
        style="height: 26px; width: 46px" Text="Send" />
</asp:Content>