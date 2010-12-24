package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.sun.net.ssl.internal.ssl.Debug;

import object.DebugClass;

public class SystemParaServelt extends HttpServlet implements Servlet {

	/**
	 * Constructor of the object.
	 */
	public SystemParaServelt() {
		super();
	}

	/**
	 * Destruction of the servlet. <br>
	 */
	public void destroy() {
		super.destroy(); // Just puts "destroy" string in log
		// Put your code here
	}

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		processRequest(request, response);
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		processRequest(request, response);
	}

	/**
	 * Initialization of the servlet. <br>
	 *
	 * @throws ServletException if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
	}
	private void Request_SelCrsOnOff(HttpServletRequest request, HttpServletResponse response,String para)
	throws ServletException, IOException
	{
		DebugClass.debug_info(this.toString(), "para:" + para);
		String name = (String)request.getParameter(para);
		DebugClass.debug_info(this.toString(), "name: "+ name);
		if(para.equals("On"))
		{
			//开启选课操作
		}
		else {
			//关闭选课操作
		}
	}
	private void Request_SelCrsMode(HttpServletRequest request, HttpServletResponse response,String para)
	throws ServletException, IOException
	{
		String name = (String)request.getParameter(para);
		DebugClass.debug_info(this.toString(), "name: "+ name);
		if(para.equals("FCFS"))
		{
			//先到先得模式
		}
		else {
			//随机踢课模式
		}
	}
	public void processRequest(HttpServletRequest request, HttpServletResponse response)
	throws ServletException, IOException
	{
		DebugClass.debug_start();
		DebugClass.debug_info(this.toString(),"Adm Start");
		String value = (String) request.getAttribute("SelCrsSysPara");
		DebugClass.debug_info(this.toString(),value);
		if (value.equals("SelCrsOnOffCmt")) {
			Request_SelCrsOnOff(request,response,value);
		}
		else if(value.equals("SelCrsModeCmt"))
		{
			Request_SelCrsMode(request,response,value);
		}
	}
}
