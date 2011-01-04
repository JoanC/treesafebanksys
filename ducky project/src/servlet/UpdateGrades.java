package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Vector;

import javax.jms.Session;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import db_data_structure.PointGoal;

import object.DebugClass;
import object.EncodeTool;
import object.PointGoalPrac_Manager;
import object.PointGoal_Manager;
import varmap.Query_Constant;
import varmap.Query_SessionVar;

public class UpdateGrades extends HttpServlet {

	public HttpServletRequest UpdateGrades_Req;
	public HttpServletResponse UpdateGrades_Rep;
	/**
	 * Constructor of the object.
	 */
	public UpdateGrades() {
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
		UpdateGrades_Req = request;
		UpdateGrades_Rep = response;		
		String value = EncodeTool.ByteToISO((String)request.getParameter("UpdateCrsInfo"));
		String para = value.substring(0, "查看学分".length());
		if(para.equals("查看学分")){
			Request_QueryGrades();
		}
		else if(para.equals("修改学分"))
		{
			Request_ModifyGrades();
		}
		else if(para.equals("确认修改")){
			Request_ModifyGradesCmt();
		}
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
	private void Request_QueryGrades() throws IOException
	{
		//查询
		String useridString = (String)UpdateGrades_Req.getSession().getAttribute(Query_SessionVar.User_ID());
		Vector<Float> _rlt = PointGoalPrac_Manager.TurnPointGoalPracToVector(useridString);
		UpdateGrades_Req.getSession().setAttribute(Query_SessionVar.Stu_Grades(), _rlt);
		UpdateGrades_Req.getSession().setAttribute(Query_SessionVar.User_Pages(),"QueryGrades.jsp");
		UpdateGrades_Rep.sendRedirect("/TJSelCrsSys/Index.jsp?userid=" + UpdateGrades_Req.getSession().getAttribute("userid"));
		
	}
	private void Request_ModifyGradesCmt() throws IOException
	{
		//修改
		PointGoal _new = new PointGoal();
		_new.setU_school_id(1);//测试用数据
		_new.setSchool_name("软件学院");
		for(int _index = 0 ; _index < Query_Constant.Grades.length ; ++_index){
			DebugClass.debug_info(this.toString(), "the new grade " + Float.parseFloat(UpdateGrades_Req.getParameter(Query_Constant.Grades[_index])));
			_new.setData(_index, Float.parseFloat(UpdateGrades_Req.getParameter(Query_Constant.Grades[_index])));
		}
		PointGoal_Manager.EditPointGoal(_new);
		UpdateGrades_Req.getSession().setAttribute(Query_SessionVar.User_Pages(),"welcome.jsp");
		UpdateGrades_Req.getSession().setAttribute(Query_SessionVar.User_Info(),"修改培养计划成功！");
		UpdateGrades_Rep.sendRedirect("/TJSelCrsSys/Index.jsp?userid=" + UpdateGrades_Req.getSession().getAttribute("userid"));
	}
	private void Request_ModifyGrades() throws IOException
	{
		PointGoal _old = new PointGoal();
		_old = PointGoal_Manager.SearchPointGoal(1);
		UpdateGrades_Req.getSession().setAttribute("old_point_goal_info", _old);
		UpdateGrades_Req.getSession().setAttribute(Query_SessionVar.User_Pages(),"ModifyGrades.jsp");
		UpdateGrades_Rep.sendRedirect("/TJSelCrsSys/Index.jsp?userid=" + UpdateGrades_Req.getSession().getAttribute("userid"));
	}

}
