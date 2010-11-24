package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import object.*;
import object.DebugClass;

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
		String username = (String)req.getParameter("UserName").trim();
		String userpassword = (String)req.getParameter("UserPassword").trim();
		DebugClass.debug_info("Login servlet", ("get the user id : " + username 
				+ "the user password: " + userpassword));
		//zhou
        LoginRltInfo _rlt = this.loginFrame(username, userpassword);
        if(_rlt.isIs_succ() == false) System.out.println("login error!");
        else{
          System.out.println(_rlt.getU_type());
          System.out.println(_rlt.getU_id());
		  req.getRequestDispatcher("/StuIndex.html").forward(req,response);
        }
	}
	
	/*
	 * 2010_11_18
	 * by Jiraiya
	 * �Դ���ҳ�д��ص��û�����������д�������
	 * ����һ��login_rlt_info
	 */
	public LoginRltInfo loginFrame(String _name,String _pwd){
		LoginInputInfo _input = new LoginInputInfo();
		_input.setU_id(_name);
		_input.setU_pwd(_pwd);
		return LoginUser_Manager.login(_input);
	}
}