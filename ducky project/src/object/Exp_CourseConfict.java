package object;

import java.util.Map;
import java.util.Vector;

public class Exp_CourseConfict extends Exp {
	private String mCourse_id_1;
	private String mCourse_id_2;
	private Map<Integer, Vector<Boolean>> mConflicTime;
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
	public Map<Integer, Vector<Boolean>> getmConflicTime() {
		return mConflicTime;
	}
}
