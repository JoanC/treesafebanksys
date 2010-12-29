<%@ page pageEncoding="GBK"%>
<%@page import="object.DebugClass"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" " http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=GBK" />
<title>管理员主界面</title>
<style type="text/css">
body{
	background-image:url(images/AdmBck.jpg);
	background-attachment:fixed;
	background-repeat: no-repeat;
	background-position:center;
	margin-top: 130px;
	background-color:#003
}
#AdmBanner {
	position:absolute;
	width:100%;
	height:109px;
	left:0px;
	top:0px;
	z-index:3;
	background-image:url(images/AdmBanner.jpg);
	background-repeat:repeat-x;	
}
#AdmMainBody {
	position:absolute;
	width:100%;
	z-index:1;
	text-align:center;
}
#AdmTJWord{
	position:absolute;
	height:55px;
	width:140px;
	left:50px;
	top:18px;
	background-image:url(images/AdmTJWord.png);
	background-repeat:no-repeat;
}
#Menu{
	position:absolute;
	height:80px;
	width:100%;
	background-image:url(images/MenuDecoration.png);
	background-repeat:no-repeat;
	background-position:center;	
}
#TextArea
{
	position:relative;
	width:950px;
	z-index:1;
	min-height:500px;
}
#Tips
{
	position:absolute;
	height:268px;
	width:271px;
	background-image:url(images/tips.png);
	z-index:2;
	text-align:left
	left:0px;
	background-repeat:no-repeat;
}
.MenuFont {
	font-size: 22px;
	font-family: "黑体";
	color:#13969E;
	text-decoration:underline;
}
a
{
	font-size: 22px;
	font-family: "黑体";
	color: #13969E;
	text-decoration:underline;
}
a:hover
{
	font-size:24px;
	font-weight:bold;
}
</style>

</head>

<body>
<div id="AdmBanner">
<div id="AdmTJWord"></div>
<div id="Menu">
  <br /><br />
  <form id="SelCrsForm" name="SelCrsForm" method="post" action="/TJSelCrsSys/servlet/CourseListsServlet">
  <table width="430" border="0" align="center">
    <tr>
      <td width="25%"><input type="submit" class="MenuFont" style="background:none;border:none" name="SelCrsSysPara" id="AddSelCrs"
			value="课程"/></td>
      <td width="25%"><input type="submit"  class="MenuFont" style="background:none;border:none" name="SelCrsSysPara" id="SttSelCrs"
			value="系统" /></td>
      <td width="25%">&nbsp;</td>
      <td width="25%">&nbsp;</td>
    </tr>
  </table>
  </form>
</div>
</div>
<div id="AdmMainBody">
<div id="TextArea">
<table width="1000" border="0" align="center" cellpadding="0" cellspacing="0">
<tr>
     <td>
     <div id="Tips"></div>
     </td>
<td>
<table width="729" border="5" align="right" bgcolor="#DEFEE1" bordercolor="#FFFFFF" style="border-collapse:collapse">
  <tr>
    <td>    
    <jsp:include page="Adm_SelCrsMode.jsp"/>
    <jsp:include page="Adm_SystemStatus.jsp"/>
    </br></br></br></br></br></br></br></br></br></br></br></br></br></br></br></br>
    </td>
  </tr>
</table>
</td>
</tr>
</table>

</div>
</div>
</html>
</body>