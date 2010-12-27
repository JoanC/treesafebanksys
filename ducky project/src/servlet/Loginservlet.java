package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import db_data_structure.LoginInputInfo;
import db_data_structure.SysParam;

import object.*;

public class Loginservlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public Loginservlet() {
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
		String username = (String)req.getParameter("username").trim();
		String userpassword = (String)req.getParameter("userpassword").trim();
		DebugClass.debug_info("Login servlet", ("get the user id : " + username 
				+ "the user password: " + userpassword));
		//zhou
        LoginRltInfo _rlt = this.loginFrame(username, userpassword);
        HttpSession session = req.getSession();
        session.setAttribute("userid", username);
        if(_rlt.isIs_succ() == false) {
        	DebugClass.debug_info("Login servlet", "login fail!");
        }
        else{
          //System.out.println(_rlt.getU_type());
          //System.out.println(_rlt.getU_id());
          DebugClass.debug_info("Login servlet", "login success!");
          session.setAttribute("info", "欢迎您！" + User_Manager.queryUserInfo(_rlt.getU_id()).getU_name());
          if (_rlt.getU_type() == 1) {
        	  DebugClass.debug_info("Login servlet", "login 1!");
        	  response.sendRedirect("/TJSelCrsSys/StuIndex.jsp?userid=" + username);
          }
          else if(_rlt.getU_type() == 2)
          {
        	  DebugClass.debug_info("Login servlet", "login 2!");
        	  response.sendRedirect("/TJSelCrsSys/TeaIndex.jsp?userid=" + username);
          }
          else if(_rlt.getU_type() == 3)
          {
        	  DebugClass.debug_info("Login servlet", "login 3!");
        	  SysParam _data = SystemParameter_Manager.getSystemParameter();
        	  session.setAttribute("SystemPara", _data);
        	  response.sendRedirect("/TJSelCrsSys/AdmIndex.jsp?userid=" + username);
          }
        }
	}
	
	/*
	 * 2010_11_18
	 * by Jiraiya
	 * 对从网页中传回的用户名和密码进行处理分析
	 * 返回一个login_rlt_info
	 */
	public LoginRltInfo loginFrame(String _name,String _pwd){
		LoginInputInfo _input = new LoginInputInfo();
		_input.setU_id(_name);
		_input.setU_pwd(_pwd);
		return LoginUser_Manager.login(_input);
	}
}
