package object;


import java.util.Vector;

import db_data_structure.Course;


public abstract class CourseTable {
	//ѧ��������ʦ���û�id�ļ�¼
	public abstract void set_u_id(String uid);
	
	//ѧ��������ʦ���û�id�Ļ�ȡ
	public abstract String get_u_id();
	
	//����α��е����пγ���Ϣ�б�ļ�¼
	public abstract Vector get_course_list();
	
	//�ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected abstract void searchCourseList();
}
