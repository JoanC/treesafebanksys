<%@ page language="java" import="object.*"
	contentType="text/html; charset=gb2312"%>
<%@ page language="java" import="db_data_structure.*"
	contentType="text/html; charset=gb2312"%> 
<%@ page language="java" import="java.util.*"
	contentType="text/html; charset=gb2312"%>
<%@page import="object.DebugClass"%>
<%@page import="java.io.IOException"%>
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
	<form id="SelectCourse" name="SelectCourse" method="post"
			action="/TJSelCrsSys/servlet/CourseListsServlet">	
	<%
	Vector<PreCourseSelectInfo> pcourses = (Vector<PreCourseSelectInfo>)session.getAttribute("precrslist");
	DebugClass.debug_info("selecting courses module", "the final result size : " + pcourses.size());
	out.print("<table width = \"1000\"border = \"1\">");
	for(int i =0 ;i!=pcourses.size();i++)
	{
		String name = pcourses.elementAt(i).getCourse_name();
		out.print("<tr>");
		out.print("<td>");
		out.print(name);
		out.print("<td>");
		out.print("<input type=\"image\" name=\"SelectCrsCommit\" id=\"CourseClear\" value=\"DelPrsCrs" + i + "\" src=\"images/Button_Login.gif\" >");
		out.print("<input type=\"image\" name=\"SelectCrsCommit\" id=\"CourseClear\" value=\"SelCrsTea" + i + "\" src=\"images/Button_Login.gif\" >");
		out.print("</td>");
		out.print("</tr>");
	}
    out.print("</table>");
	 %>
	  <table width="1000" border="1">
	 <%
	 	Vector<Course> _current;
	 	_current = (Vector<Course>)session.getAttribute("coursestea");
	 	if(_current != null)
	 	{
		for(int i = 0;i!=_current.size();i++)
		{
		  DebugClass.debug_info(this.toString(),"_current size:" + _current.size());
		  DebugClass.debug_info(this.toString(),"_current size:" + _current.elementAt(0).getCourse_name());
		  out.print("<tr>");
		  DebugClass.debug_info(this.toString(),"teachername:" + User_Manager.queryUserInfo(_current.elementAt(i).getU_id()).getU_name());
		  out.print("<td>" + User_Manager.queryUserInfo(_current.elementAt(i).getU_id()).getU_name());
  		  out.print("<td>" + _current.elementAt(i).getCourse_place());
  		  //out.print("<td>" + _current.elementAt(i).getCourse_time());
  		  out.print("<td>" + _current.elementAt(i).getCourse_current_seleted_num() + "/"
  		                   + _current.elementAt(i).getCourse_current_seleted_num());
  		  out.print("<td>" + _current.elementAt(i).getCourse_exam_type());
  		  out.print("<td>" + _current.elementAt(i).getCourse_point());
		  out.print("</tr><tr>");
  		  out.print(" <td colspan=\"7\">");
 		  out.print(_current.elementAt(i).getCourse_comment());
 		  out.print("</td></tr>");
  		}	
  		session.removeAttribute("coursestea");
  		} 
	  %>
	  </table>
	<table width="555" border="1">
  <tr>
    <td width="16">&nbsp;</td>
    <td width="75">����һ</td>
    <td width="75">���ڶ�</td>
    <td width="75">������</td>
    <td width="75">������</td>
    <td width="75">������</td>
    <td width="75">������</td>
    <td width="75">������</td>
  </tr>
  <tr>
    <td>1</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>2</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>3</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>4</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>5</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>6</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>7</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>8</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>9</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>10</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
  <tr>
    <td>11</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
    <td width="75">&nbsp;</td>
  </tr>
</table>
	 </form>
	</body>
</html>