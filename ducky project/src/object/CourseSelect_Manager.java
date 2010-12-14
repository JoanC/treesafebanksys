package object;


import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;
import object.CourseTable;
import object.Exp;
import db_data_structure.*;

public class CourseSelect_Manager {

	String u_id; 				//登录的学生编号
	PreCourseTable pre_tab;		//预选课表信息
	FmlCourseTable fml_tab;		//正式课表信息
	
	public CourseSelect_Manager(String uId) {
		super();
		// TODO Auto-generated constructor stub
		DebugClass.debug_info("CourseSelectManager",	"the init uId is :" + uId);
		u_id = uId;
		pre_tab = new PreCourseTable();
		pre_tab.set_u_id(u_id);
		//formal table
		fml_tab = new FmlCourseTable();
		fml_tab.set_u_id(u_id);
	}
	
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
	
	/*
	 * 用于在显示大列表时取得大列表的数据
	 * 作者:万君亚
	 * 日期: 2010/12/9
	 */
	 public Vector<Course> getListData(){
		DebugClass.debug_info(this.toString(), "generate all the course list...");
		Vector<Course> _data = new Vector<Course>();//结果数据
		//取得数据库中所有的课程数据
		Vector<Course> _all = Course_Manager.getAllCourseList();
		//根据这个学生的id取得所有预选数据
		Vector<PreCourseSelectInfo> _pre_tab = this.getPre_tab().get_course_list();
		//取得这个学生的正选课表
		//...尚未实现
		
		//删选信息,将预选信息和正选信息与大列表中的重复信息排除
		//排除依据为课程的名称
		for (int _index = 0; _index < _all.size(); _index++) {
			//逐一判断
			//先从预选信息中开始查找..由于是课程名,不得不写一个循环逐个查找
			Course _temp_data = _all.elementAt(_index);
			boolean _is_corr = true;//是否应该加入,初始为真
			for(int _index_pre = 0 ; _index_pre < _pre_tab.size() ; ++_index_pre){
				if(_temp_data.getCourse_name().equals(_pre_tab.elementAt(_index_pre).getCourse_name())){
					//名字相同
					DebugClass.debug_info(this.toString(), "the course " + "'" + _temp_data.getCourse_name()
							+ "'" + " has already existed in the pre_select_table of user : " + u_id);
					_is_corr = false;
					break;
				}
			}
			//做正式选课中的信息判定..
			//**未完成**
			if(_is_corr){
				_data.add(_temp_data);
			}
		}
		return _data;
	}
	 
	//把一门或者多门课程选入预选课表
	public Exp SelectCourseToPreTab(Vector<PreCourseSelectInfo> _new){
		Exp exp = null;
		
		DebugClass.debug_info("CourseSelectManger:", "start to add new courses to preTable....");
		DebugClass.debug_info("CourseSelectManger:", "the total course number : " + _new.size());
		for(int i = 0; i < _new.size(); i++){
			PreCourseSelectInfo tmpCourse = new PreCourseSelectInfo();
			tmpCourse = _new.elementAt(i);
			tmpCourse.setUid(u_id);
			DebugClass.debug_info("CourseSelectManger:", "add course name: " 
					+ tmpCourse.getCourse_name());
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
	public Exp RemoveCourseFromPreTab(Vector<PreCourseSelectInfo> _rmv){
		Exp exp = null;
		int i;
		PreCourseSelectInfo tmpCourse;
		DebugClass.debug_info("CourseSelectManger:", "start to delete new courses to preTable....");
		for(i = 0; i < _rmv.size(); i++){
			tmpCourse = _rmv.get(i);
			tmpCourse.setUid(u_id);
			pre_tab.deleteCourse(tmpCourse);
			DebugClass.debug_info("CourseSelectManger:", "delete course name: " 
					+ tmpCourse.getCourse_name());
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
