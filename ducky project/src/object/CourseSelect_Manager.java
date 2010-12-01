package object;


import java.util.Vector;
import object.CourseTable;
import object.Exp;


public class CourseSelect_Manager {
	String u_id; 				//登录的学生编号
	PreCourseTable pre_tab;		//预选课表信息
	FmlCourseTable fml_tab;		//正式课表信息
	
	public String getU_id() {
		return u_id;
	}
	
	public void setU_id(String uId) {
		u_id = uId;
	}
	
	public PreCourseTable getPre_tab() {
		return pre_tab;
	}
	
	public void setPre_tab(PreCourseTable preTab) {
		pre_tab = preTab;
	}
	
	public FmlCourseTable getFml_tab() {
		return fml_tab;
	}
	
	public void setFml_tab(FmlCourseTable fmlTab) {
		fml_tab = fmlTab;
	}
	
	//把一门或者多门课程选入预选课表
	public Exp SelectCourseToPreTab(Vector<Course> _new){
		Exp exp = null;
		
		int i;
		Course tmpCourse;
		for(i = 0; i < _new.size(); i++){
			tmpCourse = _new.get(i);
			pre_tab.addCourse(tmpCourse);
		}
		
		return exp;
	}
	
	//把一门或者多门课程选入正式课表
	public Exp SelectCourseToFmlTab(Vector<Course> _new){
		Exp exp = null;
		
		int i;
		Course tmpCourse;
		for(i = 0; i < _new.size(); i++){
			tmpCourse = _new.get(i);
			fml_tab.addCourse(tmpCourse);
		}
		
		return exp;
	}
	
	//把一门或者多门课程从预选课表中移出
	public Exp RemoveCourseFromPreTab(Vector<Course> _rmv){
		Exp exp = null;
		
		int i;
		Course tmpCourse;
		for(i = 0; i < _rmv.size(); i++){
			tmpCourse = _rmv.get(i);
			pre_tab.deleteCourse(tmpCourse);
		}
		
		return exp;
	}
	
	//把一门或者多门课程从正式课表中移出
	public Exp RemoveCourseFromFmlTab(Vector<Course> _rmv){
		Exp exp = null;
		
		int i;
		Course tmpCourse;
		for(i = 0; i < _rmv.size(); i++){
			tmpCourse = _rmv.get(i);
			fml_tab.deleteCourse(tmpCourse);
		}
		
		return exp;
	}
	
	//结束此次的选课操作,保存对应的数据
	public Exp SelectDone(){
		Exp exp = null;
		//...
		return exp;
	}
}
