package object;


import java.util.Vector;

import db_data_structure.Course;


public abstract class CourseTable {
	//学生或者老师的用户id的记录
	public abstract void set_u_id(String uid);
	
	//学生或者老师的用户id的获取
	public abstract String get_u_id();
	
	//这个课表中的所有课程信息列表的记录
	public abstract Vector get_course_list();
	
	//在初始化时获取这个u_id下的课表中的所有课程列表
	protected abstract void searchCourseList();
}
