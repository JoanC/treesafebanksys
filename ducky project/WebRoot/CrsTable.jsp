<%@ page language="java" import="java.util.*" pageEncoding="GBK"%>
<%@page import="object.DebugClass"%>
<%  	 
	out.print("<table align=\"center\" width=\"100%\" border=\"0\" cellpadding=\"1\" cellspacing=\"1\" bordercolor=\"##009966\" style=\"font-size:12px\">");
	out.print("<tr><td colspan=\"" + 8 + "\" bgcolor=\"#009966\" style=\"color:#FFF;font-weight:bold;\">" + "�ҵĿα�" + "</td></tr>");
	out.print("<tr><td width=\"16\">&nbsp;</td><td width=\"75\">����һ</td><td width=\"75\">���ڶ�</td><td width=\"75\">������</td><td width=\"75\">������</td><td width=\"75\">������</td><td width=\"75\">������</td><td width=\"75\">������</td></tr>");
  	//DebugClass.debug_start();
    Vector<String> crstable = new Vector<String>();
    DebugClass.debug_info(this.toString(),"�α��С" + crstable.size());
    crstable = (Vector<String>)session.getAttribute("coursetable");
    int weekdays = 7;
   
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