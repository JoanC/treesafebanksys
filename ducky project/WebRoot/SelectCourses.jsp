<%@ page language="java" import="object.Course_Manager"
	contentType="text/html; charset=gb2312"%>
<%@ page language="java" import="object.Course"
	contentType="text/html; charset=gb2312"%>
<%@ page language="java" import="java.util.*"
	contentType="text/html; charset=gb2312"%>
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
	out.print("<table width=\"1000\" border=\"1\">");
	Vector<Course> preCourses = Course_Manager.getAllCourseList();
	String[] checkv=(String[])request.getParameterValues("checkbox");
	for (int idx = 0; idx < checkv.length; idx++) {
		int courseid = Integer.parseInt(checkv[idx]);
		out.print("<tr>");
    	out.print("<td>");
    	out.print(preCourses.elementAt(courseid).getCourse_name());
    	out.print("</td>");
   		out.print("</tr>");		
	}
    out.print("</table>");
	 %>
	</body>
</html>
