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
     <tr>
    <td>1</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=2" id="coursetime1&gt;&lt;/td&gt;&lt;td align=3"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=2" id="coursetime1&gt;&lt;/td&gt;&lt;td align=3"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=2" id="coursetime1&gt;&lt;/td&gt;&lt;td align=3"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=2" id="coursetime1&gt;&lt;/td&gt;&lt;td align=3"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=2" id="coursetime1&gt;&lt;/td&gt;&lt;td align=3"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=2" id="coursetime1&gt;&lt;/td&gt;&lt;td align=3"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=2" id="coursetime1&gt;&lt;/td&gt;&lt;td align=3"center"></td>
  </tr>
  <tr>
    <td>2</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=" id="coursetime1&gt;&lt;/td&gt;&lt;td align=2"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=" id="coursetime1&gt;&lt;/td&gt;&lt;td align=2"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=" id="coursetime1&gt;&lt;/td&gt;&lt;td align=2"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=" id="coursetime1&gt;&lt;/td&gt;&lt;td align=2"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=" id="coursetime1&gt;&lt;/td&gt;&lt;td align=2"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=" id="coursetime1&gt;&lt;/td&gt;&lt;td align=2"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=" id="coursetime1&gt;&lt;/td&gt;&lt;td align=2"center"></td>
  </tr>
  <tr>
    <td>3</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=3" id="coursetime1&gt;&lt;/td&gt;&lt;td align=4"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=3" id="coursetime1&gt;&lt;/td&gt;&lt;td align=4"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=3" id="coursetime1&gt;&lt;/td&gt;&lt;td align=4"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=3" id="coursetime1&gt;&lt;/td&gt;&lt;td align=4"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=3" id="coursetime1&gt;&lt;/td&gt;&lt;td align=4"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=3" id="coursetime1&gt;&lt;/td&gt;&lt;td align=4"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=3" id="coursetime1&gt;&lt;/td&gt;&lt;td align=4"center"></td>
  </tr>
  <tr>
    <td>4</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=4" id="coursetime1&gt;&lt;/td&gt;&lt;td align=5"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=4" id="coursetime1&gt;&lt;/td&gt;&lt;td align=5"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=4" id="coursetime1&gt;&lt;/td&gt;&lt;td align=5"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=4" id="coursetime1&gt;&lt;/td&gt;&lt;td align=5"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=4" id="coursetime1&gt;&lt;/td&gt;&lt;td align=5"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=4" id="coursetime1&gt;&lt;/td&gt;&lt;td align=5"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=4" id="coursetime1&gt;&lt;/td&gt;&lt;td align=5"center"></td>
  </tr>
  <tr>
    <td>5</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=5" id="coursetime1&gt;&lt;/td&gt;&lt;td align=6"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=5" id="coursetime1&gt;&lt;/td&gt;&lt;td align=6"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=5" id="coursetime1&gt;&lt;/td&gt;&lt;td align=6"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=5" id="coursetime1&gt;&lt;/td&gt;&lt;td align=6"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=5" id="coursetime1&gt;&lt;/td&gt;&lt;td align=6"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=5" id="coursetime1&gt;&lt;/td&gt;&lt;td align=6"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=5" id="coursetime1&gt;&lt;/td&gt;&lt;td align=6"center"></td>
  </tr>
  <tr>
    <td>6</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=6" id="coursetime1&gt;&lt;/td&gt;&lt;td align=7"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=6" id="coursetime1&gt;&lt;/td&gt;&lt;td align=7"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=6" id="coursetime1&gt;&lt;/td&gt;&lt;td align=7"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=6" id="coursetime1&gt;&lt;/td&gt;&lt;td align=7"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=6" id="coursetime1&gt;&lt;/td&gt;&lt;td align=7"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=6" id="coursetime1&gt;&lt;/td&gt;&lt;td align=7"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=6" id="coursetime1&gt;&lt;/td&gt;&lt;td align=7"center"></td>
  </tr>
  <tr>
    <td>7</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=7" id="coursetime1&gt;&lt;/td&gt;&lt;td align=8"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=7" id="coursetime1&gt;&lt;/td&gt;&lt;td align=8"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=7" id="coursetime1&gt;&lt;/td&gt;&lt;td align=8"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=7" id="coursetime1&gt;&lt;/td&gt;&lt;td align=8"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=7" id="coursetime1&gt;&lt;/td&gt;&lt;td align=8"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=7" id="coursetime1&gt;&lt;/td&gt;&lt;td align=8"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=7" id="coursetime1&gt;&lt;/td&gt;&lt;td align=8"center"></td>
  </tr>
  <tr>
    <td>8</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=8" id="coursetime1&gt;&lt;/td&gt;&lt;td align=9"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=8" id="coursetime1&gt;&lt;/td&gt;&lt;td align=9"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=8" id="coursetime1&gt;&lt;/td&gt;&lt;td align=9"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=8" id="coursetime1&gt;&lt;/td&gt;&lt;td align=9"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=8" id="coursetime1&gt;&lt;/td&gt;&lt;td align=9"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=8" id="coursetime1&gt;&lt;/td&gt;&lt;td align=9"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=8" id="coursetime1&gt;&lt;/td&gt;&lt;td align=9"center"></td>
  </tr>
  <tr>
    <td>9</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=9" id="coursetime1&gt;&lt;/td&gt;&lt;td align=10"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=9" id="coursetime1&gt;&lt;/td&gt;&lt;td align=10"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=9" id="coursetime1&gt;&lt;/td&gt;&lt;td align=10"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=9" id="coursetime1&gt;&lt;/td&gt;&lt;td align=10"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=9" id="coursetime1&gt;&lt;/td&gt;&lt;td align=10"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=9" id="coursetime1&gt;&lt;/td&gt;&lt;td align=10"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=9" id="coursetime1&gt;&lt;/td&gt;&lt;td align=10"center"></td>
  </tr>
  <tr>
    <td>10</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=10" id="coursetime1&gt;&lt;/td&gt;&lt;td align=11"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=10" id="coursetime1&gt;&lt;/td&gt;&lt;td align=11"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=10" id="coursetime1&gt;&lt;/td&gt;&lt;td align=11"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=10" id="coursetime1&gt;&lt;/td&gt;&lt;td align=11"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=10" id="coursetime1&gt;&lt;/td&gt;&lt;td align=11"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=10" id="coursetime1&gt;&lt;/td&gt;&lt;td align=11"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=10" id="coursetime1&gt;&lt;/td&gt;&lt;td align=11"center"></td>
  </tr>
  <tr>
    <td>11</td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=11" id="coursetime1&gt;&lt;/td&gt;&lt;td align=12"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=11" id="coursetime1&gt;&lt;/td&gt;&lt;td align=12"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=11" id="coursetime1&gt;&lt;/td&gt;&lt;td align=12"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=11" id="coursetime1&gt;&lt;/td&gt;&lt;td align=12"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=11" id="coursetime1&gt;&lt;/td&gt;&lt;td align=12"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=11" id="coursetime1&gt;&lt;/td&gt;&lt;td align=12"center"></td>
    <td><input type="checkbox" name="coursetime1&gt;&lt;/td&gt;&lt;td align=11" id="coursetime1&gt;&lt;/td&gt;&lt;td align=12"center"></td>
  </tr>    
       
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