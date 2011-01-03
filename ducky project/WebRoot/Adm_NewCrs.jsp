 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="object.DebugClass"%>
<%@page import="db_data_structure.User"%>
<%@page import="object.User_Manager"%>
    <form id="UpCrsInfoForm" name="UpCrsInfoForm" method="post"
					action="/TJSelCrsSys/servlet/UpdateCrsInfo">
    <p>课程类型：
      <select name="course_type" id="coursetype">
        <option value="0">A1</option>
        <option value="1">A2</option>
        <option value="2">A3</option>
      </select>
    </p>
    <p>课名： 
      <input type="text" name="course_name" id="coursename">
    </p>
    <p>上课地点：
      <select name="course_place" id="courseplace">
        <option value="本部">本部</option>
        <option value="嘉定">嘉定</option>
      </select>
      <select name="course_building" id="courseplace">
        <option value="A">A</option>
        <option value="B">B</option>
      </select>
      <select name="course_class" id="courseplace">
        <option value="101">101</option>
        <option value="102">102</option>
      </select>
    </p>
    <p>授课教师：
    <select name="course_tea" id="course_tea">
    <%
    Vector<User> _all_tea = User_Manager.queryAllTea();
    for(int i=0;i!=_all_tea.size();i++)
    {
    	User tmp = _all_tea.elementAt(i);
    	out.print("<option value=\"" + tmp.getU_id() + "\">" + tmp.getU_id() + tmp.getU_name()+ "</option>");
    }
    %>
    </select>
    </p>
    <p>上课时间：</p>
    <table width="446" border="1">
      <tr>
        <td width="36" align="center"></td>
        <td width="55" align="center">星期一</td>
        <td width="53" align="center">星期二</td>
        <td width="51" align="center">星期三</td>
        <td width="52" align="center">星期四</td>
        <td width="50" align="center">星期五</td>
        <td width="48" align="center">星期六</td>
        <td width="49" align="center">星期日</td>
      </tr>
    

    <% 
    for(int i=1;i<=11;i++)
    {
    	out.print("<tr><td>" + i + "</td>");
    	for(int j=1;j<=7;j++)
    	{
    		out.print("<td>");
    		out.print("<input type=\"checkbox\" name=\"coursetime\" id=\"coursetime\"" + "value=\"" + Integer.toString((j-1)*11+i,10) + "\">");
    		out.print("</td>");
    	}    	
    	out.print("</tr>");
    }    
    %>
    <tr>
        <td align="center"></td>
        <td align="center"><select name="coursefre0" id="select2">
            <option value="1">全部</option>
            <option value="2">单周</option>
            <option value="3">双周</option>
          </select>
        </td>
        <td align="center"><select name="coursefre1" id="select3">
          <option value="1">全部</option>
          <option value="2">单周</option>
          <option value="3">双周</option>
        </select></td>
        <td align="center"><select name="coursefre2" id="select4">
          <option value="1">全部</option>
          <option value="2">单周</option>
          <option value="3">双周</option>
        </select></td>
        <td align="center"><select name="coursefre3" id="select5">
          <option value="1">全部</option>
          <option value="2">单周</option>
          <option value="3">双周</option>
        </select></td>
        <td align="center"><select name="coursefre4" id="select6">
          <option value="1">全部</option>
          <option value="2">单周</option>
          <option value="3">双周</option>
        </select></td>
        <td align="center"><select name="coursefre5" id="select7">
          <option value="1">全部</option>
          <option value="2">单周</option>
          <option value="3">双周</option>
        </select></td>
        <td align="center"><select name="coursefre6" id="select8">
          <option value="1">全部</option>
          <option value="2">单周</option>
          <option value="3">双周</option>
        </select></td>
      </tr>
    </table>
    <p></p>上课容量：<input name="course_column" type="text" id="coursecolumn" maxlength="6">
     学分：
    <select name="course_point_int" id="course_point_int">
        <option value="0">0</option>
        <option value="1">1</option>
        <option value="2">2</option>
        <option value="3">3</option>
        <option value="4">4</option>
        <option value="5">5</option>
      </select>
      .
      <select name="course_point_digit" id="ourse_point_digit">
        <option value="0">0</option>
        <option value="5">5</option>
      </select>
     <p> </p>
    <input type="submit" class="MenuFont" 
    		style="background: none; border: none" name="UpdateCrsInfo"
			id="Tea_menu_1" value="确认增加"/>    
    </form>