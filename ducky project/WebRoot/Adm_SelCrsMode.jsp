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
							out.println("Ŀǰѡ��״̬ ���ȵ��ȵ�");
						} else if (type == 2) {
							out.println("Ŀǰѡ��״̬�����ѡ��");
						}
				out.print("<option value=\"FCFS\">�ȵ��ȵ�</option><option value=\"Random\">���ѡ��</option></select>");
				out.print("<input type=\"submit\" style=\"background:none;border:none\" name=\"SelCrsSysPara\" id=\"SelCrsMode\" value=\"ģʽȷ��\"/>");
				}
			%>
			</form>
