package object;


import java.util.Vector;

import db_data_structure.Course;
import object.CourseTable;
import object.Exp;


public class FmlCourseTable extends CourseTable {
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
	public Vector get_course_list(){
		Vector<Course> course_list = null;
		//...
		return course_list;
	}
	
	//�ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected void searchCourseList(){
		//...
		course_list = null;	//��course_list��ֵ
	}
	
	//��һ�ŵĿγ̼��뵽��ʽ�α���
	public Exp addCourse(Course _new){
		Exp exp = new Exp();
		//...
		return exp;
	}
	
	//��һ���γ̴���ʽ�α������
	public Exp deleteCourse(Course _old){
		Exp exp = new Exp();
		//...
		return exp;
	}
	
	//���α��еĳ�ͻ
	public Vector<Exp> checkException(){
		Vector<Exp> vec_exp = null;
		//...
		return vec_exp;
	}
	
	//������ʽ�α�
	public Exp save(){
		Exp exp = new Exp();
		//...
		return exp;
	}
}
