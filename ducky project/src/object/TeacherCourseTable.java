package object;


import java.util.Vector;
import db_data_structure.Course;


//用于教师查看自己的课程表信息
public class TeacherCourseTable {
	String u_id;					//教师的用户id
	Vector<Course> course_list;		//教师所教的课程列表

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
