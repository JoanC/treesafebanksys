<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="db_data_structure.*"%>
<%@page import="object.DebugClass"%>

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
	<input type="submit" style="background: none; border: none"
		name="SelCrsSysPara" id="SelCrsMode" value= "ģʽȷ��"/>
</form>
