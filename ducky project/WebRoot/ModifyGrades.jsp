 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="varmap.Query_Constant"%>

<select name="course_place" id="courseplace">
    <option value="本部">软件学院</option>
</select>
<br />
 <%
	

 	for(int i=0;i!=Query_Constant.Grades.length;i++)
 	{
 		String tmp = Query_Constant.Grades[i % Query_Constant.Grades.length];
 		out.print(tmp + ":");
 		out.print("<input type=\"text\" name=\"" + tmp + "\" id=\"textfield\"/>");
		out.print("<br />");
 	}
 
 %>
  <form id="UpCrsInfoForm" name="UpCrsInfoForm" method="post"
					action="/TJSelCrsSys/servlet/UpdateGrades">
 <input type="submit" class="MenuFont" 	style="background: none; border: none" name="UpdateCrsInfo" id="Tea_menu_1" value="确认修改"/>
 </form>
