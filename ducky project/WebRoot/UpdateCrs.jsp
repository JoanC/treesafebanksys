<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="object.DebugClass"%>
<%@page import="object.Course_Manager"%>
<%@page import="db_data_structure.Course"%>

    <form id="UpCrsInfoForm" name="UpCrsInfoForm" method="post"
					action="/TJSelCrsSys/servlet/UpdateCrsInfo">
<table align="center" width="100%" border="0" cellpadding="1" cellspacing="1" bordercolor="#003366" style="font-size:12px">
	<tr><td colspan="8" bgcolor="#003366" style="color:#FFF;font-weight:bold;">选择需要删除或修改的课程 </td></tr>
<%
Vector<Course> _all = Course_Manager.getAllCourseListOderbyID();
for(int i=0; i!=_all.size();i=i+4)
{
	out.println("<tr>");		
    out.println("<td><input type=\"radio\" name=\"course_id\" id=\"course_id\" value=\"" + _all.elementAt(i).getCourse_id() + "\">" + _all.elementAt(i).getCourse_id() + _all.elementAt(i).getCourse_name() + "</td>");
    if( i+1 >= _all.size()){break;}
    out.println("<td><input type=\"radio\" name=\"course_id\" id=\"course_id\" value=\"" + _all.elementAt(i+1).getCourse_id() + "\">" + _all.elementAt(i+1).getCourse_id() + _all.elementAt(i+1).getCourse_name() + "</td>");
    if( i+2 >= _all.size()){break;}
    out.println("<td><input type=\"radio\" name=\"course_id\" id=\"course_id\" value=\"" + _all.elementAt(i+2).getCourse_id() + "\">" + _all.elementAt(i+2).getCourse_id() + _all.elementAt(i+2).getCourse_name() + "</td>");
    if( i+3 >= _all.size()){break;}
    out.println("<td><input type=\"radio\" name=\"course_id\" id=\"course_id\" value=\"" + _all.elementAt(i+3).getCourse_id() + "\">" + _all.elementAt(i+3).getCourse_id() + _all.elementAt(i+3).getCourse_name() + "</td>");
      
out.println("</td></tr>");
}				
%>
</table>

<div style="background-image:url(images/AdmBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">	
    <input type="submit" class="MenuFont" 
    		style="width:79px;height:39px;background: none; border: none;color:#FFF;font-weight:bold;font-size:14px" name="UpdateCrsInfo"
			id="Tea_menu_1" value="确认修改"/> 
     
</div>
<div style="background-image:url(images/AdmBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">	

<input type="submit" class="MenuFont" 
    		style="width:79px;height:39px;background: none; border: none;color:#FFF;font-weight:bold;font-size:14px" name="UpdateCrsInfo"
			id="Tea_menu_1" value="确认删除"/>   
			</div>
</form>