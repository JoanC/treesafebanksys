package object;


import java.util.Vector;
import object.CourseTable;
import object.Exp;


public class PreCourseTable extends CourseTable {
	String u_id; 				//ѧ����id
	Vector<Course> course_list; //�γ̱��еĿγ���������
	
	//ѧ��������ʦ���û�id�ļ�¼
	public void set_u_id(String uid){
		u_id = uid;
	}
	
	//ѧ��������ʦ���û�id�Ļ�ȡ
	public String get_u_id(){
		return u_id;
	}
	
	//����α��е����пγ���Ϣ�б�ļ�¼
	public Vector<Course> get_course_list(){
		Vector<Course> course_list = null;
		//...
		return course_list;
	}
	
	//�ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected void searchCourseList(){
		//...
		course_list = null;	//��course_list��ֵ
	}
	
	//Ԥѡ���ݵ��Զ�����,�����ʵ��Ԥѡ�α��add��delete����ʱ����
	private Exp altoSave(){
		Exp exp = null;
		//...
		return exp;
	}
	
	//��һ�ſγ̴�ѡ�γ�ʼ�Ĵ��б�ѡ�뵽Ԥѡ�γ̱���
	public Exp addCourse(Course _new){
		Exp exp = null;
		//altoSave();
		//...
		return exp;
	}
	
	//��һ�ſγ̴�Ԥѡ�γ̱���ɾ��
	public Exp deleteCourse(Course _old){
		Exp exp = null;
		//altoSave();
		//...
		return exp;
	}
}
