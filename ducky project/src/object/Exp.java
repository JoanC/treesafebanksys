package object;


//��������ڴ���
public class Exp {
	int err_no;		//�������
	String err_comment;		//������Ϣ
	
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
