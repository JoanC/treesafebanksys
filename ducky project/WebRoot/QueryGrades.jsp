 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="varmap.Query_SessionVar"%>
<%@page import="varmap.Query_Constant"%>
 <%
 	Vector<Float> vecFlt = (Vector<Float>)session.getAttribute(Query_SessionVar.Stu_Grades());
 %>
 	<table width="100%" border="0" cellpadding="0" cellspacing="3" bordercolor="#000000" style="font-size:12px">
					<tr>
					<td colspan="4" bgcolor="#009966" style="color:#FFF;font-weight:bold;"> �ҵ�ѧ��ͳ�����
					</td>
					</tr>
  <tr>
    <td width="10%">����</td>
    <td width="30%">����</td>
    <td width="30%">δ��</td>
    <td width="30%">Ӧ��</td>
  </tr>
 <%
 	int j=0;
 	for(int i=0;i!=vecFlt.size();i=i+ vecFlt.size()/Query_Constant.Grades.length)
 	{
 	
 		out.print("<tr>");
 		out.print("<td>" + Query_Constant.Grades[j++] + "</td>");
		out.print("<td>" + vecFlt.elementAt(i) +  "</td>");
		out.print("<td>" + vecFlt.elementAt(i + 1)  + "</td>");
		out.print("<td>" + vecFlt.elementAt(i + 2) + "</td>");
		out.print("</tr>");
 	} 
 %>
</table>
