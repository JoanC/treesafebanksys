 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="varmap.Query_Constant"%>
<%@page import="object.DebugClass"%>

<select name="course_place" id="courseplace">
    <option value="本部">软件学院</option>
</select>
<br />
 <form id="UpCrsInfoForm" name="UpCrsInfoForm" method="post"
					action="/TJSelCrsSys/servlet/UpdateGrades">
 <%
	

 	for(int i=0;i!=Query_Constant.Grades.length;i++)
 	{
 		String tmp = Query_Constant.Grades[i];
 		out.print(tmp + ":");
 		out.print("<input type=\"text\" name=\"" + tmp + "\" id=\"textfield\"/>");
 		DebugClass.debug_info(this.toString(),"<input type=\"text\" name=\"" + tmp + "\" id=\"textfield\" + i/>");
		out.print("<br />");
 	}
 
 %>
 
 <input type="submit" class="MenuFont" 	style="background: none; border: none" name="UpdateCrsInfo" id="Tea_menu_1" value="确认修改"/>
 </form>
