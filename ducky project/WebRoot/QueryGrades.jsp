 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="varmap.Query_SessionVar"%>
<%@page import="varmap.Query_Constant"%>


 
 
 <%
 	for(int i=0;i!=vecFlt.size();i=i+ vecFlt.size()/Query_Constant.Grades.length)
 	{
 		out.print(Query_Constant.Grades[i % Query_Constant.Grades.length] + ":");
		out.print(vecFlt.elementAt(i));
		out.print(vecFlt.elementAt(i + 1));
		out.print(vecFlt.elementAt(i + 2));
		out.print("<br />");
 	} 
 %>

