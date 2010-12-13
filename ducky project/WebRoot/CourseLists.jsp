<%@ page language="java" import="object.*"
	contentType="text/html; charset=gb2312"%>
<%@ page language="java" import="db_data_structure.Course"
	contentType="text/html; charset=gb2312"%>
<%@ page language="java" import="java.util.*"
	contentType="text/html; charset=gb2312"%>
<%@page import="object.CourseSelect_Manager"%>
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
		<form id="CourseSel" name="CourseSel" method="post"
			action="/TJSelCrsSys/servlet/CourseListsServlet">
			<%
				//Vector<Course> course = Course_Manager.getAllCourseList();
				//调用sevelet中的取得列表函数
				Vector<Course> course = (Vector<Course>)request.getAttribute("CoursesList");
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
				for (int idx = 0; idx != course.size(); idx++) {
					tempcourse = course.elementAt(idx);
					if (tempcourse.getCourse_type() != type) {
						for (; cursor != 5; cursor++) {
							out.print("<td width=\"20%\">  ");
							out.print("</td>");
						}
						type = tempcourse.getCourse_type();
						out.print("<tr>");
						out.print("<td colspan=\"" + cols_num + "\">");
						out.print(type);
						out.print("</td>");
						out.print("</tr>");
					}
					if (cursor == 0) {
						out.print("<tr>");
					}
					out.print("<td width=\"20%\">");
					out.print("<input type=\"checkbox\" name=\"checkbox\" value=" + idx +  " id=\"course"
									+ idx + "\">");
					out.print(tempcourse.getCourse_name());
					out.print("</td>");
					cursor = (cursor + 1) % cols_num;
					if (cursor == 0) {
						out.print("</tr>");
					}
				}
				for (; cursor != 5; cursor++) {
					out.print("<td width=\"20%\">");
					out.print("</td>");
				}
				out.print("</table>");
			%>
			<input type="image" name="SelectCrsCommit" id="PreSelCrs"
			value="PreSelCrs" src="images/Button_Login.gif" />开始选课
		</form>
	</body>
</html>
