package object;


import java.util.Vector;
import db_data_structure.Course;


//���ڽ�ʦ�鿴�Լ��Ŀγ̱���Ϣ
public class TeacherCourseTable {
	String u_id;					//��ʦ���û�id
	Vector<Course> course_list;		//��ʦ���̵Ŀγ��б�

	public String getU_id() {
		return u_id;
	}

	public void setU_id(String uId) {
		u_id = uId;
	}

	public Vector<Course> getCourse_list() {
		return course_list;
	}

	public void setCourse_list(Vector<Course> courseList) {
		course_list = courseList;
	}
	
	//��ȡ�γ��б�
	public Vector<Course> getcourse_list(){
		Vector<Course> courseList = null;
		//DB query..��дcourseList
		return courseList;
	}
}
