<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%  	 
	
	out.print("<table border=\"1\"><tr><td width=\"16\">&nbsp;</td><td width=\"75\">����һ</td><td width=\"75\">���ڶ�</td><td width=\"75\">������</td><td width=\"75\">������</td><td width=\"75\">������</td><td width=\"75\">������</td><td width=\"75\">������</td></tr>");
  	//DebugClass.debug_start();
    Vector<String> crstable = (Vector<String>)session.getAttribute("coursetable");
    int weekdays = 7;
    //DebugClass.debug_info(this.toString(),"�α��С" + crstable.size());
  	for(int i=0;i < crstable.size()/weekdays;i++)
  	{
  		out.println("<tr>"); 
  		out.println("<td>" + (i+1) + "</td>");
  		for(int j=0;j!=weekdays;j++)
  		{
  			  //DebugClass.debug_info(this.toString(),"i,j" + i + "," + j + crstable.elementAt(i * weekdays + j));
  			  out.println("<td width=\"75\">" + crstable.elementAt(i * weekdays + j) + "</td>");  			  		 
  		}
  		out.println("</tr>");
  	}
  %>