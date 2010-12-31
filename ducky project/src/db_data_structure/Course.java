package db_data_structure;

import dbquery.CourseTimeOperation;


public class Course {
	private String course_id; // �γ̱�ʶ��
	private String course_name; // �γ����
	private int course_type; // �γ�����
	private String u_id; // �γ̵��ον�ʦ
	private String course_place; // �γ̵��Ͽεص�
	private String course_comment; // �γ̵�����
	private int course_volume; // �γ�����
	private int course_current_seleted_num; // ��ѡ����
	private int course_exam_type; // �γ̵Ŀ�������
	private float course_point; // �γ�ѧ��

	private Week course_time_week ;

	public Week getCourse_time_week() {
		return course_time_week;
	}

	public void setCourse_time_week(Week courseTimeWeek) {
		course_time_week = courseTimeWeek;
	}

	public float getCourse_point() {
		return course_point;
	}

	public void setCourse_point(float coursePoint) {
		course_point = coursePoint;
	}

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
	
	public String getCourseTimeDetail(){
		//���ؿγ̵�ʱ������
		return CourseTimeOperation.dateToString(this.getCourse_time_week());
	}
}
