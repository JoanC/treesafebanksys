<%@page pageEncoding="GBK"%>
<%@page import="object.DebugClass"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<title>管理员主界面</title>
		<style type="text/css" media="screen">
<!--
body {
	background-image: url(images/AdmBck.jpg);
	background-attachment: fixed;
	background-repeat: no-repeat;
	background-position: center;
	margin-top: 130px;
	background-color: #030;
}

#AdmBanner {
	position: absolute;
	width: 100%;
	height: 109px;
	left: 0px;
	top: 0px;
	z-index: 3;
	background-image: url(images/AdmBanner.jpg);
	background-repeat: repeat-x;
	margin-left: 0px;
}

#AdmMainBody {
	position: absolute;
	width: 100%;
	z-index: 1;
	text-align: center;
}

#AdmTJWord {
	position: absolute;
	height: 55px;
	width: 140px;
	left: 50px;
	top: 18px;
	background-image: url(images/AdmTJWord.png);
	background-repeat: no-repeat;
}

#Menu {
	position: absolute;
	height: 80px;
	width: 100%;
	background-image: url(images/MenuDecoration.png);
	background-repeat: no-repeat;
	background-position: center;
}

#TextArea {
	position: absoulute;
	width: 632px;
	z-index: 1;
	min-height: 500px;
}

#Tips {
	height: 268px;
	width: 268px;
	top: 100px;
	background-image: url(images/tips.png);
	z-index: 2;
	margin-top: 100px;
	text-align: left background-repeat : no-repeat;
}

.MenuFont {
	font-size: 22px;
	font-family: "黑体";
	color: #063;
	text-decoration: underline;
}

a {
	font-size: 22px;
	font-family: "黑体";
	color: #063;
	text-decoration: underline;
}

a:hover {
	font-size: 24px;
	font-weight: bold;
}

ibutton {
	height: 45px;
	background-image: url(gradVert.jpg);
	background-repeat: repeat-x;
	border-style: 0px solid #fff;
	display: block;
	cursor: pointer;
}

#level1 {
	display: none;
	width: 120px;
	border: 0px #3399FF solid;
	background: #ffffff;
}

#level2 {
	display: none;
	width: 120px;
	border: 0px #3399FF solid;
	background: #ffffff;
}
-->
</style>
	</head>
	<body>
		<div id="AdmBanner">
			<div id="AdmTJWord"></div>
			<div id="Menu">
				<br />
				<br />
				
					<table width="430" border="1" align="center">
						<tr>
							<td width="25%" class="MenuFont">
								<input type="button" class="MenuFont"
									style="background: none; border: none" name="SelCrsSysPara"
									id="Adm_menu_1" value="课程" onclick="show()"/>
							</td>
							<td width="25%" class="MenuFont">
								<input type="button" class="MenuFont"
									style="background: none; border: none" name="SelCrsSysPara"
									id="Adm_menu_2" value="系统" onclick="show2()"/>
							</td>
							<td width="25%" class="MenuFont">
							</td>
							<td width="25%"></td>
						</tr>
						<tr>
							<td>
								<div id="level1">
								<form id="SelCrsForm" name="SelCrsForm" method="post"
					action="/TJSelCrsSys/servlet/UpdateCrsInfo">
									<input type="submit" class="MenuFont"
										style="background: none; border: none;" name="UpdateCrsInfo"
										id="SttSelCrs" value="新增课程" />
									<input type="submit" class="MenuFont"
										style="background: none; border: none;" name="UpdateCrsInfo"
										id="SttSelCrs" value="修改课程" />
										<input type="submit" class="MenuFont"
										style="background: none; border: none;" name="UpdateCrsInfo"
										id="SttSelCrs" value="删除课程" />
										</form>
								</div>
								</td><td>
								<div id="level2">
								<form id="SelCrsForm" name="SelCrsForm" method="post"
					action="/TJSelCrsSys/servlet/SystemParaServelt">
									<input type="submit" class="MenuFont"
										style="background: none; border: none;" name="SelCrsSysPara"
										id="SttSelCrs" value="选课状态" />
									<input type="submit" class="MenuFont"
										style="background: none; border: none;" name="SelCrsSysPara"
										id="SttSelCrs" value="选课模式" />
										</form>
								</div>
								</td>
								<td>
							</td>
							<td>
							</td>
						</tr>

					</table>
				</form>
			</div>
		</div>
		<script language="JavaScript" type="text/javascript">
	//--><![CDATA[//><!--
		function show() {
		var tips = document.getElementById("level1");
		var button = document.getElementById("Adm_menu_1");
		if (tips.style.display == "block") {
			tips.style.cssText = "display: none;"
		} else {
			tips.style.cssText = "display: block;"
		}
	}
	//--><!]]>
</script>
		<script language="JavaScript" type="text/javascript">
	//--><![CDATA[//><!--
	function show2() {
		var tips = document.getElementById("level2");
	var button = document.getElementById("Adm_menu_2");
		if (tips.style.display == "block") {
			tips.style.cssText = "display: none;"
		} else {
			tips.style.cssText = "display: block;"
		}
	}
	//--><!]]>
</script>

		<div id="AdmMainBody">
			<table width="900" border="1" align="center" cellpadding="0"
				cellspacing="0">
				<tr>
					<td>
						<div id="Tips">
							<br />
							<br />
							<%
								out.print(session.getAttribute("info"));
							%>
						</div>
					</td>
					<td>
						<div id="TextArea">
							<table width="100%" border="5" align="right" bgcolor="#DEFEE1"
								bordercolor="#FFFFFF" style="border-collapse: collapse">
								<tr>
									<td>
									<%DebugClass.debug_info(this.toString(),"pages: " + session.getAttribute("pages")); %>
										<jsp:include page = "<%=session.getAttribute("pages").toString()%>" />
									</td>
								</tr>
							</table>
						</div>
					</td>
				</tr>
			</table>
		</div>

	</body>
</html>