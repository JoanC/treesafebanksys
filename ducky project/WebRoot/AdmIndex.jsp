<%@ page pageEncoding="UTF-8"%>
<%@ page language="java" import="db_data_structure.SysParam"%>
<%@ page language="java" import="object.SystemParameter_Manager"%>

<%@page import="object.DebugClass"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>管理员主界面</title>
		<style type="text/css">
body {
	background-image: url(images/StuBK.jpg)
}

#AdmBanner {
	position: absolute;
	width: 100%;
	height: 130px;
	left: 0px;
	top: 0px;
	z-index: 1;
	background-image: url(images/StuBanner.png);
	background-repeat: repeat-x;
}

#SelCrsSysOnOff {
	position: absolute;
	width: 400px;
	height: 400px;
	left: 200px;
	top: 200px;
	z-index: 1;
}

#SelCrsMode {
	position: absolute;
	width: 400px;
	height: 400px;
	left: 650px;
	top: 200px;
	z-index: 1;
}
</style>
	</head>

	<body>
		<div id="AdmBanner">
		</div>
		<div id="SelCrsSysOnOff">
			<form id="SelCrsStatusForm" name="SelCrsStatusForm" method="post"
				action="/TJSelCrsSys/servlet/SystemParaServelt">
				<table width="200">
					<tr>
						<td>
							<label>
								<%
									SysParam sys = (SysParam)session.getAttribute("SystemPara");
									DebugClass.debug_info(this.toString(),"sys: " + sys);
									if (sys.isCourseSelOpened()) {
										out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\" checked/>开启选课");
									} else {
										out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"on\" id=\"SelCrsSysOnOff_0\"/>开启选课");
									}
								%>
							</label>
						</td>
					</tr>
					<tr>
						<td>
							<label>
								<%
									if (sys.isCourseSelOpened()) {
										out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\"/>关闭选课");
									} else {
										out.println("<input type=\"radio\" name=\"SelCrsOnOffCmt\" value=\"off\" id=\"SelCrsSysOnOff_0\" checked/>关闭选课");
									}
								%>
							</label>
						</td>
					</tr>
				</table>
				<input type="image" name="SelCrsSysPara" id="SelCrsOnOff"
					value="SelCrsOnOffCmt" src="images/Button_Login.gif" />
			</form>
		</div>

		<div id="SelCrsMode">
			<form id="SelCrsModeForm" name="SelCrsModeForm" method="post"
				action="/TJSelCrsSys/servlet/SystemParaServelt">
				<select name="SelCrsModeCmt">
					<%
						int type = sys.getCourseSelType();
						if (type == 1) {
							out.println("<option value=\"FCFS\">先到先得</option>");
						} else if (type == 2) {
							out.println("<option value=\"Random\">随机选课</option>");
						}
					%>
					<option value="FCFS">
						先到先得
					</option>
					<option value="Random">
						随机选课
					</option>

				</select>
				<p></p>
				<input type="image" name="SelCrsSysPara" id="SelCrsModeCmt"
					value="SelCrsModeCmt" src="images/Button_Login.gif" />
			</form>
		</div>
	</body>
</html>
