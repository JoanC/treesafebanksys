<%@ page language="java" import="object.*"
	contentType="text/html; charset=GBK"%>
<%@ page language="java" import="db_data_structure.Course"
	contentType="text/html; charset=GBK"%>
<%@ page language="java" import="java.util.*"
	contentType="text/html; charset=GBK"%>
<%@page import="object.CourseSelect_Manager"%>
		<form id="CourseSel" name="CourseSel" method="post"
			action="/TJSelCrsSys/servlet/CourseListsServlet">
			<%
			if(session.getAttribute("pages").equals("CourseLists.jsp"))
			{
			DebugClass.debug_info(this.toString(),"嵌入 网页成功");
				//Vector<Course> course = Course_Manager.getAllCourseList();
				//调用sevelet中的取得列表函数
				Vector<Course> course = (Vector<Course>) session.getAttribute("CourseList");
				DebugClass.debug_info(this.toString(),"读取session？");
				if (course.size() != 0) {
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
						out
								.print("<input type=\"checkbox\" name=\"checkbox\" value="
										+ idx + " id=\"course" + idx + "\">");
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
				}
				out.print("<input type=\"submit\" style=\"background:none;border:none\" name=\"SelectCrsCommit\" id=\"PreSelCrs\" value=\"预选\"/>");
			}			
			%>			
		</form>