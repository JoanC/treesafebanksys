package object;


import java.util.Vector;

import db_data_structure.Course;
import object.CourseTable;
import object.Exp;


public class FmlCourseTable extends CourseTable {
	String u_id; 				//学生的id
	Vector<Course> course_list; //课程表中的课程数据容器
	
	//学生或者老师的用户id的记录
	public void set_u_id(String uid){
		u_id = uid;
	}
	
	//学生或者老师的用户id的获取
	public String get_u_id(){
		return u_id;
	}
	
	//这个课表中的所有课程信息列表的记录
	public Vector get_course_list(){
		Vector<Course> course_list = null;
		//...
		return course_list;
	}
	
	//在初始化时获取这个u_id下的课表中的所有课程列表
	protected void searchCourseList(){
		//...
		course_list = null;	//给course_list赋值
	}
	
	//将一门的课程加入到正式课表中
	public Exp addCourse(Course _new){
		Exp exp = new Exp();
		//...
		return exp;
	}
	
	//将一个课程从正式课表中清除
	public Exp deleteCourse(Course _old){
		Exp exp = new Exp();
		//...
		return exp;
	}
	
	//检测课表中的冲突
	public Vector<Exp> checkException(){
		Vector<Exp> vec_exp = null;
		//...
		return vec_exp;
	}
	
	//保存正式课表
	public Exp save(){
		Exp exp = new Exp();
		//...
		return exp;
	}
}
