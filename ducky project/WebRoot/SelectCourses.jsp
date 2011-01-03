<%@ page language="java" import="object.*"
	contentType="text/html; charset=gb2312"%>
<%@ page language="java" import="db_data_structure.*"
	contentType="text/html; charset=gb2312"%> 
<%@ page language="java" import="java.util.*"
	contentType="text/html; charset=gb2312"%>
<%@page import="object.DebugClass"%>
<%@page import="java.io.IOException"%>
	<form id="SelectCourse" name="SelectCourse" method="post"
			action="/TJSelCrsSys/servlet/CourseListsServlet">	
	<% 

	DebugClass.debug_info(this.toString(),"嵌入选课网页");
	boolean iConflict = false;
	Vector<String> _check = (Vector<String>)session.getAttribute("coursetable");
	for(int i = 0 ; i < _check.size() ; ++i){
		if(_check.elementAt(i).equals("课程冲突")){
		iConflict = true;
		}
	}
	Vector<PreCourseSelectInfo> pcourses = (Vector<PreCourseSelectInfo>)session.getAttribute("precrslist");
	DebugClass.debug_info("selecting courses module", "the final result size : " + pcourses.size());
	out.print("<table align=\"center\" width=\"100%\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\" bordercolor=\"##009966\" style=\"font-size:12px\">");
	for(int i =0 ;i!=pcourses.size();i++)
	{
		String name = pcourses.elementAt(i).getCourse_name();
		out.print("<tr>");
		out.print("<td>");
		out.print(name);
		out.print("<td>");
		out.print("<div style=\"background-image:url(images/StuBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px\">");
		out.print("<input type=\"submit\" style=\"left:10px;width:79px;height:39px;background:none;border:none\" name=\"SelectCrsCommit\" id=\"DelPreCrs\" value=\"清除课程" + i + "\"/>");
		out.print("</div></td>");
		if(iConflict)
		{
			out.print("<td>无效按钮</td>");
		}
		else
		{
		out.print("<td><div style=\"background-image:url(images/StuBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px\">");
			out.print("<input type=\"submit\" style=\"left:10px;width:79px;height:39px;background:none;border:none\" name=\"SelectCrsCommit\" id=\"SelFmlCrs\" value=\"选择老师" + i + "\"/>");
			out.print("</div></td>");
		}		
		out.print("<td><div style=\"background-image:url(images/StuBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px\">");
		out.print("<input type=\"submit\" style=\"left:10px;width:79px;height:39px;background:none;border:none\" name=\"SelectCrsCommit\" id=\"DelPreCrs\" value=\"退该课程" + i + "\"/>");
		out.print("</div></td>");
		out.print("</tr>");
	}
    out.print("</table>");

	 %>	  
	 <%	
		 out.print("<table width=\"100%\" border=\"1\">");
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
  		  out.print("<td>" + Float.toString(_current.elementAt(i).getCourse_point()));
		  out.print("</tr><tr>");
  		  out.print(" <td colspan=\"7\">");
 		  out.print(_current.elementAt(i).getCourse_comment());
 		  out.print("</td>");
 		  out.print("<input type=\"submit\" style=\"background:none;border:none\" name=\"SelectCrsCommit\" id=\"DelPreCrs\" value=\"正选课程" + i + "\"/>");
 		  out.print("</tr>");
  		}	
  		//session.removeAttribute("coursestea");
  		} 
  		out.print("</table>");
  		
	  %>
  <%  	 
	
	out.print("<table border=\"1\"><tr><td width=\"16\">&nbsp;</td><td width=\"75\">星期一</td><td width=\"75\">星期二</td><td width=\"75\">星期三</td><td width=\"75\">星期四</td><td width=\"75\">星期五</td><td width=\"75\">星期六</td><td width=\"75\">星期日</td></tr>");
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
</form>

