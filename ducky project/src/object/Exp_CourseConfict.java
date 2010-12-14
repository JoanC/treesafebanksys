package object;

public class Exp_CourseConfict extends Exp {
	private String mCourse_id_1;
	private String mCourse_id_2;
	private int mConflicTime;
	public String getmCourse_id_1() {
		return mCourse_id_1;
	}
	public void setmCourse_id_1(String mCourseId_1) {
		mCourse_id_1 = mCourseId_1;
	}
	public String getmCourse_id_2() {
		return mCourse_id_2;
	}
	public void setmCourse_id_2(String mCourseId_2) {
		mCourse_id_2 = mCourseId_2;
	}
	public int getmConflicTime() {
		return mConflicTime;
	}
	public void setmConflicTime(int mConflicTime) {
		this.mConflicTime = mConflicTime;
	}
}
