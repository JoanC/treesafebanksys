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
    Vector<Course> course = Course_Manager.getAllCourseList();
    Course tempcourse = course.elementAt(0);
    int type = tempcourse.getCourse_type();
    int cols_num = 5;
    int cursor = 0;
    out.print("<table width=\"100%\" border=\"1\">");
	out.print("<tr>");
    out.print("<td colspan=\"" + cols_num + "\">");
    out.print(type);
    out.print("</td>");
  	out.print("</tr>");
    for(int idx=1;idx!=course.size();idx++)
    {
        tempcourse = course.elementAt(idx);
    	if(tempcourse.getCourse_type() != type)
    	{
    	   type = tempcourse.getCourse_type();
    		out.print("<tr>");
   			out.print("<td colspan=\"" + cols_num + "\">");
    		out.print(type);
    		out.print("</td>");
  			out.print("</tr>");
    	}
    	if(cursor == 0)
    	{
    		out.print("<tr>");
    	}
       	out.print("<td>");
    	out.print(tempcourse.getCourse_name());
    	out.print("</td>");
    	cursor = (cursor + 1) % cols_num;
    	if(cursor == 0)
    	{
    		out.print("</tr>");
    	}
    }  
	out.print("abc");
	out.print("</table>");
	%>
	</body>
</html>
