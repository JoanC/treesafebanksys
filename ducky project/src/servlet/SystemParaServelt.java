package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.sun.mail.iap.Response;
import com.sun.net.ssl.internal.ssl.Debug;

import db_data_structure.SysParam;
import db_data_structure.enCourseSelType;

import object.DebugClass;
import object.SystemParameter_Manager;

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
		
		SysParam _update = SystemParameter_Manager.getSystemParameter();
		if(para.equals("On"))
		{
			//开启选课操作
			_update.setCourseSelOpened(true);
		}
		else {
			//关闭选课操作
			_update.setCourseSelOpened(false);
		}
		//更新数据库
		SystemParameter_Manager.editSystemParameter(_update);
		
	}
	private void Request_SelCrsMode(HttpServletRequest request, HttpServletResponse response,String para)
	throws ServletException, IOException
	{
		String name = (String)request.getParameter(para);
		DebugClass.debug_info(this.toString(), "name: "+ name);
		
		SysParam _update = SystemParameter_Manager.getSystemParameter();
		DebugClass.debug_info(this.toString(), "open ? " + _update.isCourseSelOpened() + "select? " + _update.getCourseSelType());
		if(para.equals("FCFS"))
		{
			//先到先得模式
			_update.setCourseSelType(enCourseSelType.CST_FSFG);
		}
		else {
			//随机踢课模式
			_update.setCourseSelType(enCourseSelType.CST_RANDOUT);
		}
		//更新数据库
		DebugClass.debug_info(this.toString(), "update ? " + _update.isCourseSelOpened() + "select? " + _update.getCourseSelType());
		SystemParameter_Manager.editSystemParameter(_update);
		
	}
	private void Request_Init(HttpServletRequest request, HttpServletResponse response,String para)
	throws ServletException, IOException
	{
		HttpSession session = request.getSession();
	    session.setAttribute("SystemPara", para);
	    //系统参数
	    
	    response.sendRedirect("/TJSelCrsSys/AdmIndex.jsp");
	}
	public void processRequest(HttpServletRequest request, HttpServletResponse response)
	throws ServletException, IOException
	{
		DebugClass.debug_start();
		DebugClass.debug_info(this.toString(),"Adm Start");
		String value = (String) request.getParameter("SelCrsSysPara");
		if (value.equals("SelCrsOnOffCmt")) {
			Request_SelCrsOnOff(request,response,value);
		}
		else if(value.equals("SelCrsModeCmt"))
		{
			Request_SelCrsMode(request,response,value);
		}
		else if(value.equals(null))
		{
			Request_Init(request,response,value);
		}
	}
}
