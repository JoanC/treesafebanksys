<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="object.*"%>
<%@ page language="java" import="db_data_structure.*"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<form id="SelCrsStatusForm" name="SelCrsStatusForm" method="post"
	action="/TJSelCrsSys/servlet/SystemParaServelt">
	<%
	if(session.getAttribute("pages").equals("Adm_SystemStatus.jsp"))
	{
		out.print("<table><tr><td><label>");
		SysParam sys = (SysParam)session.getAttribute("SystemPara");
		DebugClass.debug_info(this.toString(),"sys: " + sys);
		if (sys.isCourseSelOpened()) {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\" checked/>����ѡ��");
		} else {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\"/>����ѡ��");
		}
		out.print("</label></td></tr><tr><td><label>");				
		
		if (sys.isCourseSelOpened()) {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\"/>�ر�ѡ��");
		} else {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\" checked/>�ر�ѡ��");
		}
		out.print("</label></td></tr></table>");				
		out.print("<input type=\"submit\" style=\"background:none;border:none\" name=\"SelCrsSysPara\" id=\"SelCrsSysPara\" value=\"״̬ȷ��\"/>");
	}
	%>
</form>