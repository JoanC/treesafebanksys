package object;


public class LoginRltInfo {
	private String u_id;
	private boolean is_succ;
	private String exp;			//这里应该是Exp_Login类型,待定义,先用String代替
	private int u_type;		//用户类型不详,暂用char代替
	
	public String getU_id() {
		return u_id;
	}
	
	public void setU_id(String uId) {
		u_id = uId;
	}
	
	public boolean isIs_succ() {
		return is_succ;
	}
	
	public void setIs_succ(boolean isSucc) {
		is_succ = isSucc;
	}
	
	public String getExp() {
		return exp;
	}
	
	public void setExp(String exp) {
		this.exp = exp;
	}
	
	public int getU_type() {
		return u_type;
	}
	
	public void setU_type(int uType) {
		u_type = uType;
	}
}
