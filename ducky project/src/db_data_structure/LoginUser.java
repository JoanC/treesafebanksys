package db_data_structure;


public class LoginUser
{
	private String  		u_id;	 //�û�id
	private String  		u_pwd; //�û�����
	private boolean   	u_isLogin; //�û���ǰ�Ƿ�����
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
