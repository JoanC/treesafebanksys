package object;

public class Course {
	String course_id;					//�γ̱�ʶ��
	String course_name;					//�γ�����
	int course_type;					//�γ�����
	String u_id;						//�γ̵��ον�ʦ
	int course_time;					//�γ̵��Ͽ�ʱ��
	String course_place;				//�γ̵��Ͽεص�
	String course_comment;				//�γ̵�����
	int course_volume;					//�γ�����
	int course_current_seleted_num;		//��ѡ����
	int course_exam_type;				//�γ̵Ŀ�������
	int course_point ;          //�γ�ѧ��
	
	public int getCourse_point()
	{
		return course_point;
	}

	public void setCourse_point(int coursePoint)
	{
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