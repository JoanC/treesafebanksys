 <%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="object.DebugClass"%>

�κţ�
      <input name="course_id" type="text" id="courseid" maxlength="6">
    </p>
    <p>�γ����ͣ�
      <select name="course_type" id="coursetype">
        <option value="0">A1</option>
        <option value="1">A2</option>
        <option value="2">A3</option>
      </select>
    </p>
    <p>������
      <input type="text" name="course_name" id="coursename">
    </p>
    <p>�Ͽεص㣺
      <select name="course_place" id="courseplace">
        <option value="����">����</option>
        <option value="�ζ�">�ζ�</option>
        <option value="����">����</option>
      </select>
      <input type="text" name="course_classroom" id="courseclassroom">
    </p>
    <p>�Ͽ�ʱ�䣺</p>
    <table width="446" border="1">
      <tr>
        <td width="36" align="center"></td>
        <td width="55" align="center">����һ</td>
        <td width="53" align="center">���ڶ�</td>
        <td width="51" align="center">������</td>
        <td width="52" align="center">������</td>
        <td width="50" align="center">������</td>
        <td width="48" align="center">������</td>
        <td width="49" align="center">������</td>
      </tr>
      <%
      for(int i=1;i<=11;i++)
	  {
	   out.print("<tr><td align=\"center\">" + i + "</td>");
	      for(int j=1;i<=7;j++)
	      {
	      	out.print("<td align=\"center\"><input type=\"checkbox\" name=\"coursetime\" id=\"coursetime" + ((i-1)*11 + j) + "></td>");
	      }
	     out.print("</tr>");
      }
      
      %>       
       
      <tr>
        <td align="center"></td>
        <td align="center"><select name="coursefre0" id="select2">
            <option value="ȫ��">ȫ��</option>
            <option value="����">����</option>
            <option value="˫��">˫��</option>
          </select>
        </td>
        <td align="center"><select name="coursefre1" id="select3">
          <option value="ȫ��">ȫ��</option>
          <option value="����">����</option>
          <option value="˫��">˫��</option>
        </select></td>
        <td align="center"><select name="coursefre2" id="select4">
          <option value="ȫ��">ȫ��</option>
          <option value="����">����</option>
          <option value="˫��">˫��</option>
        </select></td>
        <td align="center"><select name="coursefre3" id="select5">
          <option value="ȫ��">ȫ��</option>
          <option value="����">����</option>
          <option value="˫��">˫��</option>
        </select></td>
        <td align="center"><select name="coursefre4" id="select6">
          <option value="ȫ��">ȫ��</option>
          <option value="����">����</option>
          <option value="˫��">˫��</option>
        </select></td>
        <td align="center"><select name="coursefre5" id="select7">
          <option value="ȫ��">ȫ��</option>
          <option value="����">����</option>
          <option value="˫��">˫��</option>
        </select></td>
        <td align="center"><select name="coursefre6" id="select8">
          <option value="ȫ��">ȫ��</option>
          <option value="����">����</option>
          <option value="˫��">˫��</option>
        </select></td>
      </tr>
    </table>
    </div>