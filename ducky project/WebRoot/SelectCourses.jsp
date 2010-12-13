<%@ page language="java" import="object.Course_Manager"
	contentType="text/html; charset=gb2312"%>
<%@ page language="java" import="db_data_structure.*"
	contentType="text/html; charset=gb2312"%> 
<%@ page language="java" import="java.util.*"
	contentType="text/html; charset=gb2312"%>
<%@page import="object.DebugClass"%>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>course list</title>

		<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
		<meta http-equiv="description" content="this is my page">
		<meta http-equiv="content-type" content="text/html; charset=UTF-8">

		<!--<link rel="stylesheet" type="text/css" href="./styles.css">-->

	</head>

	<body>		
	<%
	Vector<PreCourseSelectInfo> pcourses = (Vector<PreCourseSelectInfo>)request.getAttribute("PreCrsList");
	DebugClass.debug_info("selecting courses module", "the final result size : " + pcourses.size());
	out.print("<table width = \"1000\"border = \"1\">");
	for(int i =0 ;i!=pcourses.size();i++)
	{
		String name = pcourses.elementAt(i).getCourse_name();
		out.print("<tr>");
		out.print("<td>");
		out.print(name);
		out.print("<td>");
		out.print("<input type=\"image\" name=\"CourseClear " + i + " id=\"CourseClear\" value=\"Del\" src=\"images/Button_Login.gif\" />");
		out.print("</td>");
		out.print("</tr>");
	}
    out.print("</table>");
	 %>
	</body>
</html>
