<%@ page language="java" pageEncoding="GBK"%>
<%@ page import="java.util.*"%>
<%@page import="varmap.Query_VarString"%>
<%@page import="varmap.Query_SessionVar"%>
<%@page import="object.User_Manager"%>
<%@page import="object.DebugClass"%>
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


  </head>
  
  <body>
<div id="banner" style="background-image:url(images/<%=Permission%>Banner.png)">
<div id="title" style="background-image:url(images/<%=Permission%>TJWord.jpg)"> 

</div>
<div id="menu">
  
</div>
</div>
<div id="mainbody">
<div id="validArea">
<div id="tips">
1
</div>
<div id="Text">
1234
</div>
</div>
</div>
</body>
</html>
