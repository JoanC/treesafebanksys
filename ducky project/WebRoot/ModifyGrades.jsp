 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="varmap.Query_Constant"%>

<select name="course_place" id="courseplace">
    <option value="本部">软件学院</option>
</select>
 <%
	

 	for(int i=0;i!=Query_Constant.Grades.length;i++)
 	{
 		out.print(Query_Constant.Grades[i % Query_Constant.Grades.length] + ":");
 		
		out.print("<br />");
 	}
 
 %>

 

