<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="object.*"%>
<%@ page language="java" import="db_data_structure.*"%>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<table align="center" width="100%" border="0" cellpadding="1" cellspacing="1" bordercolor="#003366" style="font-size:12px">
	<tr><td colspan="8" bgcolor="#003366" style="color:#FFF;font-weight:bold;">ѡ��״̬ϵͳ״̬</td></tr>
	<tr><td>
<form id="SelCrsStatusForm" name="SelCrsStatusForm" method="post"
	action="/TJSelCrsSys/servlet/SystemParaServelt">
			<table><tr><td><label>
	<%

		SysParam sys = (SysParam)session.getAttribute("SystemPara");
		DebugClass.debug_info(this.toString(),"sys: " + sys);
		if (sys.isCourseSelOpened()) {
			out.println("��ǰϵͳѡ��״̬Ϊ��ѡ�ο�����</br>");
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\" checked/>����ѡ��");
		} else {
			out.println("��ǰϵͳѡ��״̬Ϊ��ѡ�ιر���</br>");
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\"/>����ѡ��");
		}
		out.print("</label></td></tr><tr><td><label>");				
		
		if (sys.isCourseSelOpened()) {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\"/>�ر�ѡ��");
		} else {
			out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\" checked/>�ر�ѡ��");
		}
		%>
		</label></td></tr></table>	
		<div style="background-image:url(images/AdmBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">	
    	<input type="submit" class="MenuFont" 
    		style="width:79px;height:39px;background: none; border: none;color:#FFF;font-weight:bold;font-size:14px" name="SelCrsSysPara"
			id="Tea_menu_1" value="״̬ȷ��""/> 
     	</div>
</form>
</td></tr>
</table>