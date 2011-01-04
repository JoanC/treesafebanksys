<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@ page language="java" import="db_data_structure.*"%>
<%@page import="object.DebugClass"%>
<table align="center" width="100%" border="0" cellpadding="1" cellspacing="1" bordercolor="#003366" style="font-size:12px">
	<tr><td colspan="8" bgcolor="#003366" style="color:#FFF;font-weight:bold;">选课模式</td></tr>
	<tr><td>
<form id="SelCrsModeForm" name="SelCrsModeForm" method="post"
	action="/TJSelCrsSys/servlet/SystemParaServelt">
	<%		
					SysParam sys = (SysParam)session.getAttribute("SystemPara");
						int type = sys.getCourseSelType();
						DebugClass.debug_info(this.toString(),"type = " + type);
						if (type == 1) {
							out.print("目前选课状态 ：先到先得</br>");
						} else if (type == 2) {
							out.print("目前选课状态：随机选课</br>");
						} else 
						{
								out.print("模式未知中");
						}
		%>
	<select name="SelCrsModeCmt">
		
		<option value="FCFS">
			先到先得
		</option>
		<option value="Random">
			随机选课
		</option>
	</select>
<div style="background-image:url(images/AdmBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">	
    	<input type="submit" class="MenuFont" 
    		style="width:79px;height:39px;background: none; border: none;color:#FFF;font-weight:bold;font-size:14px" name="SelCrsSysPara"
			id="Tea_menu_1" value="模式确定""/> 
     	</div>
</form>
</td></tr>
</table>