<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=GBK" />
		<title>同济大学选课系统</title>

		<style type="text/css">
body,html {
	margin: 0;
	padding: 0;
	font: 12px/ 1.5arial;
	height: 100%;
	background-image: url(images/LoginBK.jpg);
}

#container {
	min-height: 100%;
	position: relative;
}

#fotter {
	position: absolute;
	bottom: 0;
	padding: : 10px;
	background-image: url(images/Login_Grass.gif);
	background-repeat: repeat-x;
	width: 100%;
	height: 114px;
}

#topper {
	position: absolute;
	background-image: url(images/loginhead.png);
	background-repeat: repeat-x;
	width: 100%;
	height: 130px;
	padding-top:30px;
	padding-left:10px;
}

#board {
	position: absolute;
	width: 454px;
	height: 367px;
	z-index: 1;
	left: 500px;
	background-image: url(images/loginboard.png);
	top: 140px;
}

#inputarea {
	left: 0px;
	top: 48px;
	position: absolute;
	width: 100%;
	height: 55px;
}
#info{
   font-color:#FF0000;
   left:650px;
   top:300px;
   position:absolute;
   width:200px;
   heitht:100px;
}
</style>
	</head>
	<body>
		<div id="container">
		
			<div id="topper">
			<img src="images/title.png"></img>
			</div>
			<div id="fotter">
			</div>
			<div id="board">
				<div id="inputarea">
					<form id="login" name="login" method="post" action="/TJSelCrsSys/servlet/Loginservlet">
						<table width="100%" border="0" align="right">
							<tr>
								<td width="35%" align="right" >
									 学号：
								</td>
								<td width="38%" align="center">
									<input name="username" type="text" id="username"/>
								</td>
								<td width="27%" rowspan="2" align="left">
									<input type="image" name="LoginCommit" id="LoginCommit"
										value="提交" src="images/Button_Login.gif" />
								</td>
							</tr>
							<tr>
								<td align="right">
									密码：
								</td>
								<td width="40%" align="center">
									<input name="userpassword" type="password" id="userpassword"
										maxlength="15" />
								</td>
							</tr>
						</table>
						
					</form>
					
				</div>
				
			</div>
			
			
		</div>
<div id="info">
			
			<%
							String msg = (String)session.getAttribute("login_fail");
							if(msg != null && msg.equals("用户名或密码不正确，登录失败！"))
							{
								out.print("用户名或密码不正确，登录失败！");
							}
						%>
			</div>
	</body>
</html>
