package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.sun.org.apache.xerces.internal.impl.dv.ValidatedInfo;

import db_data_structure.Course;
import db_data_structure.User;
import dbquery.CourseTimeOperation;

import object.Course_Manager;
import object.DebugClass;
import object.EncodeTool;
import object.User_Manager;

public class UpdateCrsInfo extends HttpServlet {

	public HttpServletRequest UpdateCrsInfo_Req;
	public HttpServletResponse UpdateCrsInfo_Rep;
	/**
	 * Constructor of the object.
	 */
	public UpdateCrsInfo() {
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
		UpdateCrsInfo_Req = request;
		UpdateCrsInfo_Rep = response;		
		String value = EncodeTool.ByteToISO((String)request.getParameter("UpdateCrsInfo"));
		String para = value.substring(0, "查看课程".length());
		if(para.equals("查看课程")){
			Request_QueryCrsInfo();
		}
		else if(para.equals("修改课程")){
			
		}
		else if(para.equals("确认修改")){
			Request_ModifyCrsInfo();
		}
		else if(value.equals("新增课程"))
		{
			Request_AddNewCrs();
		}
		else if(value.equals("确认增加"))
		{
			Request_AddNewCrsCmt();
		}
		else if(value.equals("删除课程"))
		{
			Request_DelCrs();
		}
		else if(value.equals("确认删除"))
		{
			Request_DelCrsCmt();
		}
	}
	private void Request_DelCrs() throws IOException
	{
		UpdateCrsInfo_Req.getSession().setAttribute("pages", "DelCrs.jsp");
		UpdateCrsInfo_Rep.sendRedirect("/TJSelCrsSys/AdmIndex.jsp?userid=" + UpdateCrsInfo_Req.getSession().getAttribute("userid"));
	}
	private void Request_DelCrsCmt() throws IOException
	{
		
	}
	private void Request_AddNewCrs() throws IOException
	{
		UpdateCrsInfo_Req.getSession().setAttribute("pages", "Adm_NewCrs.jsp");
		UpdateCrsInfo_Rep.sendRedirect("/TJSelCrsSys/AdmIndex.jsp?userid=" + UpdateCrsInfo_Req.getSession().getAttribute("userid"));
	}
	private void Request_AddNewCrsCmt() throws IOException
	{
		//String _old_id = "";
		Course _new = new Course();
		_new.setCourse_id(UpdateCrsInfo_Req.getParameter("course_id"));
		//_new.setCourse_id(Course_Manager.generateCourseID());
		DebugClass.debug_info(this.toString(), "id: " + UpdateCrsInfo_Req.getParameter("course_id"));
		_new.setCourse_type(Integer.parseInt(UpdateCrsInfo_Req.getParameter("course_type")));
		DebugClass.debug_info(this.toString(), "type: " + UpdateCrsInfo_Req.getParameter("course_type"));
		_new.setCourse_name(EncodeTool.ByteToISO(UpdateCrsInfo_Req.getParameter("course_name")));
		DebugClass.debug_info(this.toString(), "name: " + EncodeTool.ByteToISO(UpdateCrsInfo_Req.getParameter("course_name")));
		_new.setCourse_place("[" + EncodeTool.ByteToISO(UpdateCrsInfo_Req.getParameter("course_place")) + "]" + UpdateCrsInfo_Req.getParameter("course_building") + UpdateCrsInfo_Req.getParameter("course_class"));
		DebugClass.debug_info(this.toString(), "[" + EncodeTool.ByteToISO(UpdateCrsInfo_Req.getParameter("course_place")) + "]" + UpdateCrsInfo_Req.getParameter("course_building") + UpdateCrsInfo_Req.getParameter("course_class"));
		String[] check = (String[])UpdateCrsInfo_Req.getParameterValues("coursetime");
		
		_new.setCourse_volume(Integer.parseInt(UpdateCrsInfo_Req.getParameter("course_column")));
		_new.setCourse_point((float) (Float.parseFloat(UpdateCrsInfo_Req.getParameter("course_point_int")) + 0.1 * Float.parseFloat((UpdateCrsInfo_Req.getParameter("course_point_digit")))));
		/*******************************/
		_new.setU_id(UpdateCrsInfo_Req.getParameter("course_tea"));		
		/*******************************/
		_new.setCourse_comment("内容未填");
		_new.setCourse_exam_type(0);//考试类型
		
		//时间处理。。。。。。。
		Vector<Boolean> coursetime = new Vector<Boolean>();
		for (int i = 0; i != 77; i++) {
			coursetime.addElement(false);
		}
		DebugClass.debug_info(this.toString(),"vector size: " + coursetime.size());
		for (int i = 0; i < check.length; i++) {
			coursetime.set(Integer.parseInt(check[i])-1,true);
			DebugClass.debug_info(this.toString(), "check[i]: " + Integer.parseInt(check[i]));
		}	
		Vector<Integer> coursefre = new Vector<Integer>();
		for (int i = 0; i < 7; i++) {
			DebugClass.debug_info(this.toString(), "coursefre" + i + UpdateCrsInfo_Req.getParameter("coursefre" + i));
			coursefre.add(Integer.parseInt(UpdateCrsInfo_Req.getParameter("coursefre" + i)));		
		}
		//进一步时间处理		
		_new.setCourse_time_week( CourseTimeOperation.convert2Course(coursetime, coursefre));
		//String _check = Course_Manager.checkNewCourse(_new);
		String _check = "";
		if(_check.equals("")){
			Course_Manager.AddCourse(_new);
			UpdateCrsInfo_Req.getSession().setAttribute("info", "添加课程成功！");
		}
		else{
			UpdateCrsInfo_Req.getSession().setAttribute("info", _check);
		}
		UpdateCrsInfo_Req.getSession().setAttribute("pages", "Adm_NewCrs.jsp");
		
		UpdateCrsInfo_Rep.sendRedirect("/TJSelCrsSys/AdmIndex.jsp?userid=" + UpdateCrsInfo_Req.getSession().getAttribute("userid"));
	}
	private void Request_QueryCrsInfo() throws IOException
	{
		//万君亚
		//查询课程信息
		Vector<Course> _course_list = Course_Manager.getAllCourseList();
		UpdateCrsInfo_Req.getSession().setAttribute("CourseInfo", _course_list);
		UpdateCrsInfo_Rep.sendRedirect("/TJSelCrsSys/AdmIndex.jsp?userid=" + UpdateCrsInfo_Req.getSession().getAttribute("userid"));
	}
	private void Request_ModifyCrsInfo() throws IOException
	{
		//万君亚
		//修改课程信息
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
		doGet(request, response);
	}

	/**
	 * Initialization of the servlet. <br>
	 *
	 * @throws ServletException if an error occurs
	 */
	public void init() throws ServletException {
		// Put your code here
	}
	
	private Vector<String> getAllTeacherInfo(){
		Vector<String> _rlt = new Vector<String>();
		Vector<User> _tea_list= User_Manager.queryAllTea();
		for(int _index = 0 ; _index < _tea_list.size() ; ++_index){
			_rlt.add(_tea_list.elementAt(_index).getU_id() + " " + _tea_list.get(_index).getU_name());
		}
		return _rlt;
	}
	
}
