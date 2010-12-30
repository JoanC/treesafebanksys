<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="object.*"%>
<%@ page language="java" import="db_data_structure.*"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<form id="SelCrsStatusForm" name="SelCrsStatusForm" method="post"
	action="/TJSelCrsSys/servlet/SystemParaServelt">
			<table><tr><td><label>
	<%

		SysParam sys = (SysParam)session.getAttribute("SystemPara");
		DebugClass.debug_info(this.toString(),"sys: " + sys);
		if (sys.isCourseSelOpened()) {
			out.println("当前系统选课状态为：选课开启中</br>");
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\" checked/>开启选课");
		} else {
			out.println("当前系统选课状态为：选课关闭中</br>");
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\"/>开启选课");
		}
		out.print("</label></td></tr><tr><td><label>");				
		
		if (sys.isCourseSelOpened()) {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\"/>关闭选课");
		} else {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\" checked/>关闭选课");
		}
		%>
		</label></td></tr></table>				
		<input type="submit" style="background:none;border:none" name="SelCrsSysPara" id="SelCrsSysPara" value="状态确定"/>
		
</form>