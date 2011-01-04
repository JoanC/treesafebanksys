 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="varmap.Query_Constant"%>
<%@page import="object.DebugClass"%>
<%@page import="db_data_structure.PointGoal"%>

<table align="center" width="100%" border="0" cellpadding="1" cellspacing="1" bordercolor="#003366" style="font-size:12px">
	<tr><td colspan="8" bgcolor="#003366" style="color:#FFF;font-weight:bold;">修改培养计划 </td></tr>
	<tr><td>				
<select name="course_place" id="courseplace">
    <option value="本部">软件学院</option>
</select>
<br />
 <form id="UpCrsInfoForm" name="UpCrsInfoForm" method="post"
					action="/TJSelCrsSys/servlet/UpdateGrades" onsubmit="return judge()" >
		
 <%
	PointGoal old = (PointGoal)session.getAttribute("old_point_goal_info");
	
 	for(int i=0;i!=Query_Constant.Grades.length;i++)
 	{
 		String tmp = Query_Constant.Grades[i]; 
 		out.print(tmp + ":");
 		out.print("<input type=\"text\" name=\"" + tmp + "\" id=\"textfield" + i + "\" value=\"" + old.getData(i) + "\"/>");
 		out.print("<br />");
 	}
 
 %>
<div style="background-image:url(images/AdmBT.png);background-repeat:no-repeat;color:#FFF;font-size:14px">	

<input type="submit" class="MenuFont" 
    		style="width:79px;height:39px;background: none; border: none;color:#FFF;font-weight:bold;font-size:14px" name="UpdateCrsInfo"
			id="Tea_menu_1" value="确认修改 "/>   
			</div>
 </form>
 </td></tr>
<script language="javascript" type="text/javascript">
//点击按钮触发的js代码，用html控件的onclick事件触发
function judge()
{
	 if(document.getElementById("textfield0").value=="" ||
	 	document.getElementById("textfield1").value=="" ||
	 	document.getElementById("textfield2").value=="" ||
	 	document.getElementById("textfield3").value=="" ||
	 	document.getElementById("textfield4").value=="" ||
	 	document.getElementById("textfield5").value=="" ||
	 	document.getElementById("textfield6").value=="" ||
	 	document.getElementById("textfield7").value=="" ||
	 	document.getElementById("textfield8").value=="" ||
	 	document.getElementById("textfield9").value=="" ||
	 	document.getElementById("textfield10").value=="" ||
	 	document.getElementById("textfield11").value=="" ||
	 	document.getElementById("textfield12").value=="" ||
	 	document.getElementById("textfield13").value=="" ||
	 	document.getElementById("textfield14").value=="" ||
	 	document.getElementById("textfield15").value=="" ||
	 	document.getElementById("textfield16").value=="" ||
	 	document.getElementById("textfield17").value=="")
	 {
	    alert("信息填写不完整");
	    return false;
	 }
}	
}
</script>
</table>