<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="db_data_structure.*"%>

<form id="SelCrsModeForm" name="SelCrsModeForm" method="post"
				action="/TJSelCrsSys/servlet/SystemParaServelt">
				<%
				if(session.getAttribute("pages").equals("Adm_SelCrsMode.jsp"))
				{
				out.print("<select name=\"SelCrsModeCmt\">");
					
					SysParam sys = (SysParam)session.getAttribute("SystemPara");
						int type = sys.getCourseSelType();
						if (type == 1) {
							out.println("目前选课状态 ：先到先得");
						} else if (type == 2) {
							out.println("目前选课状态：随机选课");
						}
				out.print("<option value=\"FCFS\">先到先得</option><option value=\"Random\">随机选课</option></select>");
				out.print("<input type=\"submit\" style=\"background:none;border:none\" name=\"SelCrsSysPara\" id=\"SelCrsMode\" value=\"模式确定\"/>");
				}
			%>
			</form>
