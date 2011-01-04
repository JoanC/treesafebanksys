<%@ page language="java" pageEncoding="GBK"%>
<%@ page import="java.util.*"%>
<%@page import="varmap.Query_VarString"%>
<%@page import="varmap.Query_SessionVar"%>
<%@page import="object.User_Manager"%>
<%@page import="object.DebugClass"%>
<%@page import="varmap.Query_Constant"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
String Permission = Query_VarString.User_Permission((String)session.getAttribute(Query_SessionVar.User_Type()));
DebugClass.debug_info(this.toString(),Permission);
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'Index.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<link href="CSS/index.css" rel="stylesheet" type="text/css" />
	<link href="CSS/text_area.css" rel="stylesheet" type="text/css" />
	<link href="CSS/menu_level.css" rel="stylesheet" type="text/css" />

  </head>
  
<body style="background-image:url(images/<%=Permission%>Bck.jpg)" class="<%=Permission%>Table">
<div id="banner" style="background-image:url(images/<%=Permission%>Banner.png)">
<div id="title" style="background-image:url(images/<%=Permission%>TJWord.jpg)"> 

</div>
<div id="menu">  
<table width="430" border="1" align="center">
<tr>
<%
for(int i=0;i!=Query_VarString.User_Menu(Permission).length;i++)
{
	DebugClass.debug_info(this.toString(),"Ò»¼¶²Ëµ¥");
	out.print("<td width=\"25%\">");
	out.print("<input type=\"button\" class=\"MenuFont\" style=\"background: none; border: none\" name=\"SelCrsSysPara\" id=\"stu_menu_1\" value=\"" + Query_VarString.User_Menu(Permission)[i] + "\" onclick=\"show" + (i+1) +  "()\"/>");
	out.print("</td>");
}
%>
</tr>
<tr>
<td width="25%">
<div id="level1">
<% String tmp_menulevel = Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[0])[0];%>
<form id="formid" name="formname" method="post" action="/TJSelCrsSys/servlet/<%=Query_VarString.InputElemtAction(tmp_menulevel) %>">
<% for(int i=0;i!=Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[0]).length;i++)
{
	String tmp = Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[0])[i];
	out.print("<input type=\"submit\" style=\"background: none; border: none;\" name=\"" + Query_VarString.InputElemtName(tmp) + "\" id=\"menu_1\" value=\"" + tmp + "\"/>");
}
%>
</form>
</div>
</td>
<td width="25%">
<div id="level2">
<%tmp_menulevel = Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[1])[0];%>
<form id="formid" name="formname" method="post" action="/TJSelCrsSys/servlet/<%=Query_VarString.InputElemtAction(tmp_menulevel) %>">
<% for(int i=0;i!=Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[1]).length;i++)
{
	String tmp = Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[1])[i];
	out.print("<input type=\"submit\" style=\"background: none; border: none;\" name=\"" + Query_VarString.InputElemtName(tmp) + "\" id=\"menu_2\" value=\"" + Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[1])[i] + "\"/>");
}
%>
</form>
</div>
</td>
<td width="25%">
<div id="level3">
<%tmp_menulevel = Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[2])[0];%>
<form id="formid" name="formname" method="post" action="/TJSelCrsSys/servlet/<%=Query_VarString.InputElemtAction(tmp_menulevel) %>">
<% for(int i=0;i!=Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[2]).length;i++)
{
	String tmp = Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[2])[i];
	out.print("<input type=\"submit\" style=\"background: none; border: none;\" name=\"" + Query_VarString.InputElemtName(tmp) + "\" id=\"menu_3\" value=\"" + Query_VarString.Menu_Levels(Permission,Query_VarString.User_Menu(Permission)[2])[i] + "\"/>");
}
%>
</form>
</div>
</td>
<td width="25%">
</td>
</tr>
</table>
</div>
</div>
<div id="mainbody">
<div id="validArea">
<div id="tips" style="background-image:url(images/tips.png)">
<%out.print(session.getAttribute(Query_SessionVar.User_Info()));%>
</div>
<div id="Text">
<table width="100%" border="5px" bordercolor="#FFFFFF" style="border-collapse: collapse" class="<%=Permission%>Table">
<tr>
<td>
 <jsp:include page = "<%=session.getAttribute(Query_SessionVar.User_Pages()).toString()%>" />
</td>
</tr>
</table>
</div>
</div>
</div>
<script language="JavaScript" type="text/javascript">
	//--><![CDATA[//><!--
	function show1() {
	var tips = document.getElementById("level1");
	var button = document.getElementById("menu_1");
		if (tips.style.display == "block") {
			tips.style.cssText = "display: none;"
		} else {
			tips.style.cssText = "display: block;"
		}
	}
	function show2() {
	var tips = document.getElementById("level2");
	var button = document.getElementById("menu_2");
		if (tips.style.display == "block") {
			tips.style.cssText = "display: none;"
		} else {
			tips.style.cssText = "display: block;"
		}
	}
	function show3() {
	var tips = document.getElementById("level3");
	var button = document.getElementById("menu_3");
		if (tips.style.display == "block") {
			tips.style.cssText = "display: none;"
		} else {
			tips.style.cssText = "display: block;"
		}
	}
	//--><!]]>
</script>
</body>
</html>
