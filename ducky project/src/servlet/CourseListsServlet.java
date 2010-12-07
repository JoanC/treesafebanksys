package servlet;

import java.io.IOException;

import java.io.PrintWriter;
import java.util.Vector;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.omg.CORBA.PRIVATE_MEMBER;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;


import object.*;

public class CourseListsServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	private CourseSelect_Manager courseselmgr;
	public CourseListsServlet() {
		super();
		courseselmgr = new CourseSelect_Manager();
		courseselmgr.setU_id("082901");
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

		/*response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out
				.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		out.println("<HTML>");
		out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		out.println("  <BODY>");
		out.print("    This is ");
		out.print(this.getClass());
		out.println(", using the GET method");
		out.println("  </BODY>");
		out.println("</HTML>");
		out.flush();
		out.close();*/
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
		processRequest(request,response);
		/*response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out
				.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		out.println("<HTML>");
		out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		out.println("  <BODY>");
		out.print("    This is ");
		out.print(this.getClass());
		out.println(", using the POST method");
		out.println("  </BODY>");
		out.println("</HTML>");
		out.flush();
		out.close();*/
	}

	/**
	 * Initialization of the servlet. <br>
	 *
	 * @throws ServletException if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
	}
	/*
	 * doprocess
	 * */
	public void processRequest(HttpServletRequest req,
			HttpServletResponse response) throws ServletException, IOException {
		RequestDispatcher rd = req.getRequestDispatcher("/SelectCourses.jsp");
        rd.forward(req,response);
        Vector<PreCourseTable> preCourseTables;
        Vector<Course> preCourses = Course_Manager.getAllCourseList();
        String[] checkv=(String[])req.getParameterValues("checkbox");
    	for (int idx = 0; idx < checkv.length; idx++) {
    		int courseid = Integer.parseInt(checkv[idx]);
    		preCourses.elementAt(courseid).getCourse_name();
    		//courseselmgr.SelectCourseToPreTab()
    	}
	}
	
	private Vector PreCourseData(Vector<PreCourseTable> _new_select){
		//首先从mgr中读取当前预选课表的初始信息
		Vector<PreCourseSelectInfo> _result = null;
		Vector<PreCourseSelectInfo> _init = courseselmgr.getPre_tab().get_course_list();
		//在将新的输入和初始数据相连,自动监测重复并排除重复
		_result = _new_select + _init;
		//返回新的列表数据
		return _result;
	} 
}
