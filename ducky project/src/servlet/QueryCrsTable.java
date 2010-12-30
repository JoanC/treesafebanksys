package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Vector;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;
import db_data_structure.User;

import object.CourseTable;
import object.Course_Manager;
import object.DebugClass;
import object.EncodeTool;
import object.FmlCourseTable;
import object.User_Manager;

public class QueryCrsTable extends HttpServlet implements Servlet {

	/**
	 * Constructor of the object.
	 */
	public QueryCrsTable() {
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
	private void Request_QueryCrsTable(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException 
	{
		HttpSession session = request.getSession();
		//查看课表
		String _id = (String)session.getAttribute("userid");
		FmlCourseTable _table = new FmlCourseTable(_id);
		Vector<String> _list = CourseTable.convertFmlTabFormat(_table.get_course_list());
		User _current = User_Manager.queryUserInfo(_id);
	    
		session.setAttribute("crstable",_list);
		session.setAttribute("pages", "CrsTable.jsp");
		if(_current.getU_type() == 1)
		{
			response.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));
		}
		else if(_current.getU_type() == 2)
		{
			response.sendRedirect("/TJSelCrsSys/TeaIndex.jsp?userid=" + session.getAttribute("userid"));
		}
	}

	public void processRequest(HttpServletRequest req,
			HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = req.getSession();
		String value = EncodeTool.ByteToISO((String)req.getParameter("QueryCrsTable"));
		String para = value.substring(0, "查看课表".length());
		
		if (para.equals("查看课表")){
			Request_QueryCrsTable(req,response);
		} 
	}

}
