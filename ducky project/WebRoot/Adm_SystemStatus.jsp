<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="object.*"%>
<%@ page language="java" import="db_data_structure.*"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<table align="center" width="100%" border="0" cellpadding="1" cellspacing="1" bordercolor="#003366" style="font-size:12px">
	<tr><td colspan="8" bgcolor="#003366" style="color:#FFF;font-weight:bold;">选课状态系统状态</td></tr>
	<tr><td>
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
		<div style="background-image:url(images/AdmBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">	
    	<input type="submit" class="MenuFont" 
    		style="width:79px;height:39px;background: none; border: none;color:#FFF;font-weight:bold;font-size:14px" name="SelCrsSysPara"
			id="Tea_menu_1" value="状态确定""/> 
     	</div>
</form>
</td></tr>
</table>