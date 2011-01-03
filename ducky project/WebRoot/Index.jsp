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

<style type="text/css" media="screen">
.StuTable {
	font-size: 22px;
	font-family: "ºÚÌå";
	color: #063;
	background-color:"#DEFEE1";
	text-decoration: underline;
}
</style>
  </head>
  
<body style="background-image:url(images/<%=Permission%>Bck.jpg)" class="<%=Permission%>Table">
<div id="banner" style="background-image:url(images/<%=Permission%>Banner.png)">
<div id="title" style="background-image:url(images/<%=Permission%>TJWord.jpg)"> 

</div>
<div id="menu">  
<br /><br />
<table width="430" border="1" align="center">
<%
/*for(int i=0;i!=Query_Constant.;i++)
{
	out.print("<tr><td>");
	
	out.print("</td><tr>");
}*/
%>
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
