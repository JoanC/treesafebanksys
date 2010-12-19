<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>student index</title>
<style type="text/css">
body{
	background-image:url(images/StuBK.jpg)
}
#StuBanner {
	position:absolute;
	width:100%;
	height:130px;
	left:0px;
	top:0px;
	z-index:1;
	background-image:url(images/StuBanner.png);
	background-repeat:repeat-x;
	backgrou
}
</style>
</head>

<body>
<div id="StuBanner">
<form id="selectcourse" name="selectcourse" method="post" action="/TJSelCrsSys/servlet/CourseListsServlet">
   <input type="image" name="SelectCrsCommit" id="SttSelCrs"
			value="SttSelCrs" src="images/Button_Login.gif" />
  </form>

</div>
</body>
</html>
