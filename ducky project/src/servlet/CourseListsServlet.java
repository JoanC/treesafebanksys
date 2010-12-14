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
import javax.servlet.http.HttpSession;

import org.omg.CORBA.PRIVATE_MEMBER;

import com.sun.mail.iap.Response;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;

import object.*;
import sun.io.Converters;

public class CourseListsServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	private CourseSelect_Manager courseselmgr;
	private HttpServletRequest iRequest;
	private HttpServletResponse iResponse;

	public CourseListsServlet() {
		super();
		courseselmgr = new CourseSelect_Manager("082901");
		// courseselmgr.setU_id();
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
	 * @param request
	 *            the request send by the client to the server
	 * @param response
	 *            the response send by the server to the client
	 * @throws ServletException
	 *             if an error occurred
	 * @throws IOException
	 *             if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		/*
		 * response.setContentType("text/html"); PrintWriter out =
		 * response.getWriter(); out.println(
		 * "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		 * out.println("<HTML>");
		 * out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		 * out.println("  <BODY>"); out.print("    This is ");
		 * out.print(this.getClass()); out.println(", using the GET method");
		 * out.println("  </BODY>"); out.println("</HTML>"); out.flush();
		 * out.close();
		 */
		processRequest(request, response);
	}

	/**
	 * The doPost method of the servlet. <br>
	 * 
	 * This method is called when a form has its tag value method equals to
	 * post.
	 * 
	 * @param request
	 *            the request send by the client to the server
	 * @param response
	 *            the response send by the server to the client
	 * @throws ServletException
	 *             if an error occurred
	 * @throws IOException
	 *             if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		processRequest(request, response);
		/*
		 * response.setContentType("text/html"); PrintWriter out =
		 * response.getWriter(); out.println(
		 * "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		 * out.println("<HTML>");
		 * out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		 * out.println("  <BODY>"); out.print("    This is ");
		 * out.print(this.getClass()); out.println(", using the POST method");
		 * out.println("  </BODY>"); out.println("</HTML>"); out.flush();
		 * out.close();
		 */
	}

	/**
	 * Initialization of the servlet. <br>
	 * 
	 * @throws ServletException
	 *             if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
	}

	/*
	 * doprocess
	 */
	private Vector PreCourseData(Vector<PreCourseSelectInfo> _new_select) {
		// 首先从mgr中读取当前预选课表的初始信息
		DebugClass.debug_info("CouseSelectModle", "start to add two info...");
		Vector<PreCourseSelectInfo> _init = courseselmgr.getPre_tab().get_course_list();
		Vector<PreCourseSelectInfo> _result = new Vector<PreCourseSelectInfo>();
		// 在将新的输入和初始数据相连,自动监测重复并排除重复
		for (int i = 0; i < _init.size(); i++) {
			_result.add(_init.elementAt(i));
		}
		// 返回新的列表数据
		DebugClass.debug_info("CouseSelectModle", "add end...");
		DebugClass.debug_info("CouseSelectModle", "add course : "
				+ _result.size());
		return _result;
	}

	private void Request_PreSelCrs() throws ServletException, IOException {
		Vector<PreCourseSelectInfo> preCourseInfos = new Vector<PreCourseSelectInfo>();
		Vector<Course> preCourses = courseselmgr.getListData();
		DebugClass.debug_info(this.toString(), "所有课表" + preCourses.size());
		for (int i = 0; i < preCourses.size(); i++) {
			DebugClass.debug_info("processRequet.for", preCourses.elementAt(i)
					.getCourse_name());
		}
		String[] checkv = (String[]) iRequest.getParameterValues("checkbox");
		if (checkv == null) {
			DebugClass.debug_info(this.toString(), "NULL");
		} else {

			DebugClass.debug_info("CouseSelectModle",
					"start to convert from course to preCourseInfo..");
			DebugClass.debug_info("CouseSelectModle", "checkv.legth" + checkv);
			for (int idx = 0; idx < checkv.length; idx++) {
				int courseid = Integer.parseInt(checkv[idx]);
				// preCourses.elementAt(courseid).getCourse_name())
				PreCourseSelectInfo _info = new PreCourseSelectInfo();

				_info.setUid(courseselmgr.getU_id());
				_info.setCourse_name(preCourses.elementAt(courseid)
						.getCourse_name());
				preCourseInfos.add(_info);
				// courseselmgr.SelectCourseToPreTab()
			}
			DebugClass.debug_info("CouseSelectModle", "convert end....");
			courseselmgr.SelectCourseToPreTab(preCourseInfos);
		}
		Vector<PreCourseSelectInfo> _result = this.PreCourseData(preCourseInfos);

		DebugClass.debug_info("CouseSelectModle", "the final result size : "
				+ _result.size());
		HttpSession session = iRequest.getSession();
	    session.setAttribute("precrslist", _result);
	    iResponse.sendRedirect("/TJSelCrsSys/SelectCourses.jsp?userid=" + session.getAttribute("userid"));
	}

	private void Request_StartSelCrs() throws ServletException, IOException {
		DebugClass.debug_info(this.toString(), "get the course list...");
		Vector<Course> courses = courseselmgr.getListData();
		// Vector<Course> courses = Course_Manager.getAllCourseList();
		DebugClass.debug_info(this.toString(), "size: " + courses.size());
		HttpSession session = iRequest.getSession();
		session.setAttribute("CourseList",courses);
		iResponse.sendRedirect("/TJSelCrsSys/CourseLists.jsp?userid=" + session.getAttribute("userid"));
	}
	private void Request_DelPrsCrs()throws ServletException, IOException 
	{
		DebugClass.debug_info(this.toString(), "del start...");
		String value = (String)iRequest.getParameter("SelectCrsCommit");
		int id = Integer.parseInt(value.substring("DelPrsCrs".length()));
		DebugClass.debug_info(this.toString(), "Select Index: " + id);
		Vector<PreCourseSelectInfo> predel = new Vector<PreCourseSelectInfo>();
		predel.add((PreCourseSelectInfo) courseselmgr.getPre_tab()
				.get_course_list().elementAt(id));
		courseselmgr.RemoveCourseFromPreTab(predel);
		DebugClass.debug_info(this.toString(), "Select Course Name : "
				+ predel.elementAt(0).getCourse_name());
	    Vector<PreCourseSelectInfo> course = courseselmgr.getPre_tab().get_course_list();
	    HttpSession session = iRequest.getSession();
	    session.setAttribute("precrslist", course);
	    iResponse.sendRedirect("/TJSelCrsSys/SelectCourses.jsp?userid=" + session.getAttribute("userid"));
	    
	}
	public void processRequest(HttpServletRequest req,
			HttpServletResponse response) throws ServletException, IOException {
		DebugClass.debug_info(this.toString(), "get request!");
		iRequest = req;
		iResponse = response;
		String value = (String) req.getParameter("SelectCrsCommit");
		String para = value.substring(0, "DelPrsCrs".length());
		DebugClass.debug_info(this.toString(), "value" + value);
		if (para.equals("SttSelCrs")) {
			Request_StartSelCrs();
		} else if (para.equals("PreSelCrs")) {
			Request_PreSelCrs();
		} else if (para.equals("DelPrsCrs")) {
			Request_DelPrsCrs();
		}
	}
}
