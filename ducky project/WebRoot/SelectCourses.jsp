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
	boolean iConflict = false;
	Vector<String> _check = (Vector<String>)session.getAttribute("coursetable");
	for(int i = 0 ; i < _check.size() ; ++i){
		if(_check.elementAt(i).equals("课程冲突!")){
		iConflict = true;
		}
	}
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
		out.print("<input type=\"image\" name=\"SelectCrsCommit\" id=\"CourseClear\" value=\"DelPrsCrs" + i + "\" src=\"images/Button_Login.gif\" >退课");
		if(iConflict)
		{
			out.print("<image src=\"images/Button_Login.gif\" >无效");
		}
		else
		{
			out.print("<input type=\"image\" name=\"SelectCrsCommit\" id=\"CourseClear\" value=\"SelCrsTea" + i + "\" src=\"images/Button_Login.gif\" >选择");
		}		
		out.print("<input type=\"image\" name=\"SelectCrsCommit\" id=\"CourseClear\" value=\"DelFmlCrs" + i + "\" src=\"images/Button_Login.gif\" >清除" );
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
		  //DebugClass.debug_info(this.toString(),"_current size:" + _current.size());
		  //DebugClass.debug_info(this.toString(),"_current size:" + _current.elementAt(0).getCourse_name());
		  out.print("<tr>");
		 // DebugClass.debug_info(this.toString(),"teachername:" + User_Manager.queryUserInfo(_current.elementAt(i).getU_id()).getU_name());
		  out.print("<td>" + User_Manager.queryUserInfo(_current.elementAt(i).getU_id()).getU_name());
  		  out.print("<td>" + _current.elementAt(i).getCourse_place());
  		  //out.print("<td>" + _current.elementAt(i).getCourse_time());
  		  out.print("<td>" + _current.elementAt(i).getCourse_current_seleted_num() + "/"
  		                   + _current.elementAt(i).getCourse_volume());
  		  out.print("<td>" + _current.elementAt(i).getCourse_exam_type());
  		  out.print("<td>" + _current.elementAt(i).getCourse_point());
		  out.print("</tr><tr>");
  		  out.print(" <td colspan=\"7\">");
 		  out.print(_current.elementAt(i).getCourse_comment());
 		  out.print("</td>");
 		  out.print("<td><input type=\"image\" name=\"SelectCrsCommit\" id=\"selcourse\" value=\"SelFmlCrs" + i + "\" src=\"images/Button_Login.gif\"</td>");
 		  out.print("</tr>");
  		}	
  		//session.removeAttribute("coursestea");
  		} 
	  %>
	  </table>
	<table width="555" border="1">
  <tr>
    <td width="16">&nbsp;</td>
    <td width="75">星期一</td>
    <td width="75">星期二</td>
    <td width="75">星期三</td>
    <td width="75">星期四</td>
    <td width="75">星期五</td>
    <td width="75">星期六</td>
    <td width="75">星期日</td>
  </tr>
  <%
  	//DebugClass.debug_start();
    Vector<String> crstable = (Vector<String>)session.getAttribute("coursetable");
    int weekdays = 7;
    //DebugClass.debug_info(this.toString(),"课表大小" + crstable.size());
  	for(int i=0;i < crstable.size()/weekdays;i++)
  	{
  		out.println("<tr>");
  		out.println("<td>" + (i+1) + "</td>");
  		for(int j=0;j!=weekdays;j++)
  		{
  			  //DebugClass.debug_info(this.toString(),"i,j" + i + "," + j + crstable.elementAt(i * weekdays + j));
  			  out.println("<td width=\"75\">" + crstable.elementAt(i * weekdays + j) + "</td>");  			  		 
  		}
  		out.println("</tr>");
  	}
  %>
</table>
	 </form>
	</body>
</html>
