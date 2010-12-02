package db_data_structure;

public class LoginQueryInfo {
	private String u_id;
	private String u_pwd;
	private boolean u_isLogin;
	private int u_type;		//用户类型不详,暂用char代替
	private String exp;
	
	public String getU_id() {
		return u_id;
	}
	
	public void setU_id(String uId) {
		u_id = uId;
	}
	
	public String getU_pwd() {
		return u_pwd;
	}
	
	public void setU_pwd(String uPwd) {
		u_pwd = uPwd;
	}
	
	public boolean isU_isLogin() {
		return u_isLogin;
	}
	
	public void setU_isLogin(boolean uIsLogin) {
		u_isLogin = uIsLogin;
	}
	
	public int getU_type() {
		return u_type;
	}
	
	public void setU_type(int uType) {
		u_type = uType;
	}
	
	public String getExp() {
		return exp;
	}
	
	public void setExp(String exp) {
		this.exp = exp;
	}
}
