package object;


import java.util.Vector;
import db_data_structure.Course;


//用于教师查看自己的课程表信息
public class StudentCourseTable {
	String u_id;					//学生的用户id
	Vector<Course> course_list;		//学生的课表信息
	
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
	
	//获取课程列表
	public Vector<Course> getcourse_list(){
		Vector<Course> courseList = null;
		//DB query..填写courseList
		return courseList;
	}
}
