<%@ page  pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>student index</title>
		<style type="text/css">
body {
	background-image: url(images/StuBK.jpg)
}

#StuBanner {
	position: absolute;
	width: 100%;
	height: 130px;
	left: 0px;
	top: 0px;
	z-index: 1;
	background-image: url(images/StuBanner.png);
	background-repeat: repeat-x;
	backgrou
}

#Menu {
	font:"华文细黑";
	font-weight:bold;
	font-size:20px;
	color:#377B2F;
	position:absolute;
	width: 84px;
	height: 32px;
	left: 400px;
	top: 50px;
}


</style>
	</head>
	<body>
		<div id="StuBanner">
		<div id="Menu">
		<a href="javascript:showMenu();void(0);">课程</a>
		</div>
		<div  style="border:#555 2px outset;padding:10px;display:none;" id="menu1" tabIndex=0>
<form id="selectcourse" name="selectcourse" method="post"
				action="/TJSelCrsSys/servlet/CourseListsServlet">
				<input type="image" name="SelectCrsCommit" id="SttSelCrs"
					value="SttSelCrs" src="images/Button_Login.gif" />
			</form>

</div>
<script>
function showMenu(){
 document.getElementById("menu1").style.display="";
 document.getElementById("menu1").focus();
}
function hideMenu(){
 document.getElementById("menu1").style.display="none";
}
</script>
		
		
		</div>		
			
	</body>
</html>
