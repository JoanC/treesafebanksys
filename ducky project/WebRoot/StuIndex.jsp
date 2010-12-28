<%@ page pageEncoding="GBK"%>
<%@page import="object.DebugClass"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" " http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=GBK" />
<title>学生主界面</title>
<style type="text/css">
body{
	background-image:url(images/StuBck.jpg);
	background-attachment:fixed;
	background-repeat: no-repeat;
	background-position:center;
	margin-top: 130px;
	background-color:#030;
}
#StuBanner {
	position:absolute;
	width:100%;
	height:109px;
	left:0px;
	top:0px;
	z-index:3;
	background-image:url(images/StuBanner.png);
	background-repeat:repeat-x;	
}
#StuMainBody {
	position:absolute;
	width:100%;
	z-index:1;
	text-align:center;
}
#StuTJWord{
	position:absolute;
	height:55px;
	width:140px;
	left:50px;
	top:18px;
	background-image:url(images/StuTJWord.png);
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
	height:268px;
	width:268px;
	top:100px;
	background-image:url(images/tips.png);
	z-index:2;
	margin-top:100px;
	text-align:left
	background-repeat:no-repeat;
}
.MenuFont {
	font-size: 22px;
	font-family: "黑体";
	color: #063;
	text-decoration:underline;
}
a
{
	font-size: 22px;
	font-family: "黑体";
	color: #063;
	text-decoration:underline;
}
a:hover
{
	font-size:24px;
	font-weight:bold;
}
ibutton
{
	height: 45px;
	background-image: url(gradVert.jpg);
	background-repeat: repeat-x;
	border-style: 0px solid #fff;
	display: block;
	cursor: pointer;
}
</style>
<script>
function showLayer(layerid){   
	document.getElementById("StuMenu1").style.display = true; 
}   
</script>  
</head>

<body>
<div id="StuBanner">
<div id="StuTJWord"></div>
<div id="Menu">
  <br /><br />
  <form id="SelCrsForm" name="SelCrsForm" method="post" action="/TJSelCrsSys/servlet/CourseListsServlet">
  <table width="430" border="0" align="center">
    <tr>
      <td width="25%"><input type="submit" class="MenuFont" style="background:none;border:none" name="SelectCrsCommit" id="SttSelCrs"
			value="选课"/></td>
      <td width="25%" class="MenuFont"><input type="image" name="SelectCrsCommit" id="SttSelCrs"
			value="课表" src="images/StuMenuBT.png" /></td>
      <td width="25%" class="MenuFont"><input type="image" name="SelectCrsCommit" id="SttSelCrs"
			value="学分" src="images/StuMenuBT.png" /></td>
      <td width="25%">&nbsp;</td>
    </tr>
  </table>
  </form>
</div>
</div>
<div id="StuMainBody">
<div id="TextArea">
<table width="730" border="5" align="right" bgcolor="#DEFEE1" bordercolor="#FFFFFF" style="border-collapse:collapse">
  <tr>
    <td>    
    <jsp:include page="CourseLists.jsp"/>
    </td>
  </tr>
</table>
<div id="Tips">
<br/><br/>
<% 
  String info = (String)session.getAttribute("info");
  DebugClass.debug_info(this.toString(),"info" + info);
  if(info != null)
  {  	
  		out.println(info);
  }
%>
</div>
</div></div>
</body>
</html>