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
	<input type="submit" style="background: none; border: none"
		name="SelCrsSysPara" id="SelCrsMode" value= "模式确定"/>
</form>
