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

import object.EncodeTool;
import object.PointGoalPrac_Manager;
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
		UpdateGrades_Rep.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + UpdateGrades_Req.getSession().getAttribute("userid"));
		
	}
	private void Request_ModifyGradesCmt() throws IOException
	{
		//修改
		String useridString = (String)UpdateGrades_Req.getSession().getAttribute(Query_SessionVar.User_ID());
		UpdateGrades_Req.getParameter(Query_Constant.Grades[0]);
	}
	private void Request_ModifyGrades() throws IOException
	{
		UpdateGrades_Req.getSession().setAttribute(Query_SessionVar.User_Pages(),"ModifyGrades.jsp");
		UpdateGrades_Rep.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + UpdateGrades_Req.getSession().getAttribute("userid"));
	}

}
