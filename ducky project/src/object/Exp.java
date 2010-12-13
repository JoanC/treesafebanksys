package object;


//这个类用于错误
public class Exp {
	int err_no;		//错误代码
	String err_comment;		//错误信息
	
	public int getErr_no() {
		return err_no;
	}
	
	public void setErr_no(int errNo) {
		err_no = errNo;
	}
	
	public String getErr_comment() {
		return err_comment;
	}
	
	public void setErr_comment(String errComment) {
		err_comment = errComment;
	}
}
