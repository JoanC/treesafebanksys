package object;


public class LoginRltInfo {
	private String u_id;
	private boolean is_succ;
	private String exp;			//����Ӧ����Exp_Login����,������,����String����
	private int u_type;		//�û����Ͳ���,����char����
	
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
