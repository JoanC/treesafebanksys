package servlet;

import java.io.IOException;

import java.io.PrintWriter;
import java.util.Vector;

import javax.servlet.FilterChain;
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
		//courseselmgr = new CourseSelect_Manager("");
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
		if(courseselmgr == null)
		{
			courseselmgr = new CourseSelect_Manager((String)request.getSession().getAttribute("userid"));
		}		
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
		DebugClass.debug_start();
		DebugClass.debug_info(this.toString(), "doPost");
		if(courseselmgr == null)
		{
			DebugClass.debug_info(this.toString(), "ID: " + (String)request.getSession().getAttribute("userid"));
			courseselmgr = new CourseSelect_Manager((String)request.getSession().getAttribute("userid"));
			DebugClass.debug_info(this.toString(), "new finish!");
		}
		processRequest(request, response);
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
		Vector<PreCourseSelectInfo> _init = courseselmgr.getPre_tab().get_course_list();
		Vector<PreCourseSelectInfo> _result = new Vector<PreCourseSelectInfo>();
		for (int i = 0; i < _init.size(); i++) {
			_result.add(_init.elementAt(i));
		}
		return _result;
	}

	private void Request_PreSelCrs() throws ServletException, IOException {
		Vector<PreCourseSelectInfo> preCourseInfos = new Vector<PreCourseSelectInfo>();
		Vector<Course> preCourses = courseselmgr.getListData();
		DebugClass.debug_info(this.toString(), "���пα�" + preCourses.size());
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
	    session.setAttribute("pages", "SelectCourses.jsp");
	    if(courseselmgr != null) {
	    	courseselmgr.setU_id((String)session.getAttribute("userid"));
	    }
	    iResponse.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));
	}

	private void Request_StartSelCrs() throws ServletException, IOException {
		DebugClass.debug_info(this.toString(), "get the course list...");
		//�ж�ѡ���Ƿ�����
		HttpSession session = iRequest.getSession();
		if(!SystemParameter_Manager.getSystemParameter().isCourseSelOpened()){
			session.setAttribute("info", "选课未开启");
			session.setAttribute("pages", "welcome.jsp");
			iResponse.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));
		}
		else {
			Vector<Course> courses = courseselmgr.getListData();
			session.setAttribute("CourseList",courses);
			session.setAttribute("pages", "CourseLists.jsp");
			iResponse.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));
		}
	}		
		
	private void Request_DelPrsCrs()throws ServletException, IOException 
	{
		DebugClass.debug_info(this.toString(), "del start...");
		String value = EncodeTool.ByteToISO((String)iRequest.getParameter("SelectCrsCommit"));
		int id = Integer.parseInt(value.substring("选择课程".length()));
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
	    session.setAttribute("pages", "SelectCourses.jsp");
	    iResponse.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));
	    
	}
	private void Request_SelFmlCrs()throws ServletException, IOException 
	{
		HttpSession session = iRequest.getSession();
		Vector<Course> _old = (Vector<Course>)session.getAttribute("coursestea");
		DebugClass.debug_info(this.toString(), "课表大小：" + _old.size());
		String value = EncodeTool.ByteToISO((String)iRequest.getParameter("SelectCrsCommit"));
		int id = Integer.parseInt(value.substring("选择课程".length()));
		DebugClass.debug_info(this.toString(), "id:" + id);
		Vector<Course> _new = new Vector<Course>();
		_new.add(_old.elementAt(id));
		courseselmgr.SelectCourseToFmlTab(_new);
		getCourseTables();
		session.removeAttribute("coursestea");
		session.setAttribute("pages", "SelectCourses.jsp");
		iResponse.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));				
	}
	private void Request_SelCrsTea()throws ServletException, IOException 
	{
		HttpSession session = iRequest.getSession();
		Vector<PreCourseSelectInfo> precrs = (Vector<PreCourseSelectInfo>)session.getAttribute("precrslist");
		String value = EncodeTool.ByteToISO((String)iRequest.getParameter("SelectCrsCommit"));
		int id = Integer.parseInt(value.substring("选择课程".length()));
		Vector<Course> _detail = Course_Manager.getCourseListByName(precrs.elementAt(id).getCourse_name());	 
		/*Vector<String> _teacher_name = new Vector<String>();
		DebugClass.debug_start();
		for(int _index = 0 ; _index  < _detail.size() ; ++ _index){
			_teacher_name.add((User_Manager.queryUserInfo(_detail.elementAt(_index).getU_id()).getU_name()));
		    DebugClass.debug_info(this.toString(), "name:" + _teacher_name.elementAt(_index));
		}*/
		session.setAttribute("coursestea", _detail);
		session.setAttribute("pages", "SelectCourses.jsp");
		iResponse.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));
	}
	private void Request_DelFmlCrs()throws ServletException, IOException 
	{
		HttpSession session = iRequest.getSession();
		Vector<PreCourseSelectInfo> old = (Vector<PreCourseSelectInfo>) session.getAttribute("precrslist");
		String value = EncodeTool.ByteToISO((String)iRequest.getParameter("SelectCrsCommit"));
		int id = Integer.parseInt(value.substring("选择课程".length()));
		Course remove = new Course();
		remove.setCourse_name(old.elementAt(id).getCourse_name());
		DebugClass.debug_info(this.toString(),old.elementAt(id).getCourse_name());
		Vector<Course> rCourses = new Vector<Course>();
		rCourses.add(remove);
		courseselmgr.RemoveCourseFromFmlTab(rCourses);
		session.removeAttribute("coursetable");
		Vector<String> crstable = CourseTable.convertFmlTabFormat(courseselmgr.getFml_tab().get_course_list());
		session.setAttribute("coursetable", crstable);
		session.setAttribute("pages", "SelectCourses.jsp");
		iResponse.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + session.getAttribute("userid"));
	}
	public void getCourseTables() throws ServletException, IOException 
	{
		HttpSession session = iRequest.getSession();
		Vector<String> crstable = CourseTable.convertFmlTabFormat(courseselmgr.getFml_tab().get_course_list());
		session.setAttribute("coursetable", crstable);		
	}
	public void processRequest(HttpServletRequest req,
			HttpServletResponse response) throws ServletException, IOException {
		iRequest = req;
		iResponse = response;
		String value = EncodeTool.ByteToISO((String)req.getParameter("SelectCrsCommit"));
		//DebugClass.debug_info(this.toString(),"value: " + value);
		//byte[] B=value.getBytes("iso-8859-1");
		//value = new String(B);
		//DebugClass.debug_info(this.toString(),"value: " + value);
		String para = value.substring(0, "选择课程".length());
		DebugClass.debug_info(this.toString(), "value" + value);
		getCourseTables();
		if (para.equals("选择课程")){
			Request_StartSelCrs();
		} else if (para.equals("预选课程")) {
			Request_PreSelCrs();
		} else if (para.equals("退该课程")) {
			Request_DelPrsCrs();
		} else if(para.equals("选择老师")) {
			Request_SelCrsTea();
		} else if(para.equals("正选课程"))	{
			Request_SelFmlCrs();
		} else if(para.equals("清除课程")){
			Request_DelFmlCrs();
		} 	
	}
}
