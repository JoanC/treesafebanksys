package db_data_structure;


public class LoginUser
{
	private String  		u_id;	 //用户id
	private String  		u_pwd; //用户密码
	private boolean   	u_isLogin; //用户当前是否在线
	public String getU_id()
	{
		return u_id; 
	}
	public void setU_id(String uId)
	{
		u_id = uId;
	}
	public String getU_pwd()
	{
		return u_pwd;
	}
	public void setU_pwd(String uPwd)
	{
		u_pwd = uPwd;
	}
	public boolean isU_isLogin()
	{
		return u_isLogin;
	}
	public void setU_isLogin(boolean uIsLogin)
	{
		u_isLogin = uIsLogin;
	}

}
