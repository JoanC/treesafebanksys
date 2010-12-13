package object;


//学生表现情况的数据记录和读取，主要为了学分的统计与计算
public class StudentPerformance {
	String u_id;		//学生的用户id
	String course_id;	//学生选修的课程编号
	
	public String getU_id() {
		return u_id;
	}
	
	public void setU_id(String uId) {
		u_id = uId;
	}
	
	public String getCourse_id() {
		return course_id;
	}
	
	public void setCourse_id(String courseId) {
		course_id = courseId;
	}
}
