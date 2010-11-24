package object;


public class Course {
	String course_id;					//课程标识号
	String course_name;					//课程名称
	int course_type;					//课程类型
	String u_id;						//课程的任课教师
	int course_time;					//课程的上课时间
	String course_place;				//课程的上课地点
	String course_comment;				//课程的描述
	int course_volume;					//课程容量
	int course_current_seleted_num;		//已选人数
	int course_exam_type;				//课程的考试类型
	
	public String getCourse_id() {
		return course_id;
	}
	
	public void setCourse_id(String courseId) {
		course_id = courseId;
	}
	
	public String getCourse_name() {
		return course_name;
	}
	
	public void setCourse_name(String courseName) {
		course_name = courseName;
	}
	
	public int getCourse_type() {
		return course_type;
	}
	
	public void setCourse_type(int courseType) {
		course_type = courseType;
	}
	
	public String getU_id() {
		return u_id;
	}
	
	public void setU_id(String uId) {
		u_id = uId;
	}
	
	public int getCourse_time() {
		return course_time;
	}
	
	public void setCourse_time(int courseTime) {
		course_time = courseTime;
	}
	
	public String getCourse_place() {
		return course_place;
	}
	
	public void setCourse_place(String coursePlace) {
		course_place = coursePlace;
	}
	
	public String getCourse_comment() {
		return course_comment;
	}
	
	public void setCourse_comment(String courseComment) {
		course_comment = courseComment;
	}
	
	public int getCourse_volume() {
		return course_volume;
	}
	
	public void setCourse_volume(int courseVolume) {
		course_volume = courseVolume;
	}
	
	public int getCourse_current_seleted_num() {
		return course_current_seleted_num;
	}
	
	public void setCourse_current_seleted_num(int courseCurrentSeletedNum) {
		course_current_seleted_num = courseCurrentSeletedNum;
	}
	
	public int getCourse_exam_type() {
		return course_exam_type;
	}
	
	public void setCourse_exam_type(int courseExamType) {
		course_exam_type = courseExamType;
	}
}
