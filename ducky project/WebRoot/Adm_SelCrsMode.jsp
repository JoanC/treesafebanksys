<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="db_data_structure.*"%>
<%@page import="object.DebugClass"%>
<table align="center" width="100%" border="0" cellpadding="1" cellspacing="1" bordercolor="#003366" style="font-size:12px">
	<tr><td colspan="8" bgcolor="#003366" style="color:#FFF;font-weight:bold;">ѡ��ģʽ</td></tr>
	<tr><td>
<form id="SelCrsModeForm" name="SelCrsModeForm" method="post"
	action="/TJSelCrsSys/servlet/SystemParaServelt">
	<%		
					SysParam sys = (SysParam)session.getAttribute("SystemPara");
						int type = sys.getCourseSelType();
						DebugClass.debug_info(this.toString(),"type = " + type);
						if (type == 1) {
							out.print("Ŀǰѡ��״̬ ���ȵ��ȵ�</br>");
						} else if (type == 2) {
							out.print("Ŀǰѡ��״̬�����ѡ��</br>");
						} else 
						{
								out.print("ģʽδ֪��");
						}
		%>
	<select name="SelCrsModeCmt">
		
		<option value="FCFS">
			�ȵ��ȵ�
		</option>
		<option value="Random">
			���ѡ��
		</option>
	</select>
<div style="background-image:url(images/AdmBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">	
    	<input type="submit" class="MenuFont" 
    		style="width:79px;height:39px;background: none; border: none;color:#FFF;font-weight:bold;font-size:14px" name="SelCrsSysPara"
			id="Tea_menu_1" value="ģʽȷ��""/> 
     	</div>
</form>
</td></tr>
</table>