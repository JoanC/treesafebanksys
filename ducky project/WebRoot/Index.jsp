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


  </head>
  
<body style="background-image:url(images/<%=Permission%>Bck.jpg)" class="<%=Permission%>Table">
<div id="banner" style="background-image:url(images/<%=Permission%>Banner.png)">
<div id="title" style="background-image:url(images/<%=Permission%>TJWord.jpg)"> 

</div>
<div id="menu">  
<br /><br />
<table width="430" border="1" align="center">
<tr>
<%
for(int i=0;i!=Query_VarString.User_Menu(Permission).length;i++)
{
	out.print("<td width=\"25%\">");
	out.print("<input type=\"button\" class=\"MenuFont\" style=\"background: none; border: none\" name=\"SelCrsSysPara\" id=\"stu_menu_1\" value=\"" + Query_VarString.User_Menu(Permission)[i] + "\" onclick=\"show()\"/>");
	out.print("</td>");
}
%>
</tr>
<tr>
<%
for(int i=0;i!=Query_VarString.User_Menu(Permission).length;i++)
{
	out.print("<td width=\"25%\">");
	for(int i=0;i!=Query_VarString.Menu_Levels().length;i++)
	{
		
		out.print("<div id=\"level2\">");
		out.print("<input type=\"submit\" style=\"background: none; border: none;\" name=\"QueryCrsTable\" id=\"SttSelCrs\" value=\"" + + "\" />");
		out.print("</div>");
		out.print("<\td>");
	}
	out.print("")
}
%>

	<form id="QueryCrsTableForm" name="QueryCrsTable" method="post" action="/TJSelCrsSys/servlet/QueryCrsTable">
	<input type="submit" class="MenuFont"
		style="background: none; border: none;" name="QueryCrsTable" id="SttSelCrs" value="²é¿´¿Î±í" />
	</form>

</tr>
</table>
</div>
</div>
<div id="mainbody">
<div id="validArea">
<div id="tips" style="background-image:url(images/tips.png)">
123
</div>
<div id="Text">
<table width="100%" border="5px" bordercolor="#FFFFFF" style="border-collapse: collapse" class="<%=Permission%>Table">
<tr>
 <td>
 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p>
  1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p>
   1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p> 1<p></p></td>
</tr>
</table>
</div>
</div>
</div>
</body>
</html>
