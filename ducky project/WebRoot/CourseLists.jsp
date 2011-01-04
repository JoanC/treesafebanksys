<%@ page language="java" import="object.*"
	contentType="text/html; charset=GBK"%>
<%@ page language="java" import="db_data_structure.Course"
	contentType="text/html; charset=GBK"%>
<%@ page language="java" import="java.util.*"
	contentType="text/html; charset=GBK"%>
<%@page import="object.CourseSelect_Manager"%>
<%@page import="varmap.Query_VarString"%>
<%@page import="varmap.Query_Constant"%>
<form id="CourseSel" name="CourseSel" method="post"
	action="/TJSelCrsSys/servlet/CourseListsServlet">
	<%
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
					out.print("<table width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"3\" bordercolor=\"#000000\" style=\"font-size:12px\">");
					out.print("<tr>");
					out.print("<td colspan=\"" + cols_num + "\" bgcolor=\"#009966\" style=\"color:#FFF;font-weight:bold;\">");
					out.print(Query_Constant.Grades[type]);
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
							out.print("<td colspan=\"" + cols_num + "\" bgcolor=\"#009966\" style=\"color:#FFF;font-weight:bold;\">");
							out.print(Query_Constant.Grades[type]);
							out.print("</td>");  
							out.print("</tr>");
						}
						if (cursor == 0) {
							out.print("<tr>");
						}
						out.print("<td width=\"20%\">");
						out.print("<input type=\"checkbox\" name=\"checkbox\" value="
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
				
			%>
			<br>
			<div style="background-image:url(images/StuBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">
			<input type="submit" style="left:10px;width:79px;height:39px;background:none;border:none;color:#FFF;font-weight:bold;font-size:14px" name="SelectCrsCommit" id="PreSelCrs" value="预选课程"/>;
			</div>
</form>