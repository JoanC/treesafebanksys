package object;


import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;
import object.CourseTable;
import object.Exp;
import db_data_structure.*;

public class CourseSelect_Manager {

	String u_id; 				//��¼��ѧ�����
	PreCourseTable pre_tab;		//Ԥѡ�α���Ϣ
	FmlCourseTable fml_tab;		//��ʽ�α���Ϣ
	
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
	 * ��������ʾ���б�ʱȡ�ô��б������
	 * ����:�����
	 * ����: 2010/12/9
	 */
	 public Vector<Course> getListData(){
		DebugClass.debug_info(this.toString(), "generate all the course list...");
		Vector<Course> _data = new Vector<Course>();//�������
		//ȡ�����ݿ������еĿγ�����
		Vector<Course> _all = Course_Manager.getAllCourseList();
		//�������ѧ����idȡ������Ԥѡ����
		Vector<PreCourseSelectInfo> _pre_tab = this.getPre_tab().get_course_list();
		//ȡ�����ѧ������ѡ�α�
		//...��δʵ��
		
		//ɾѡ��Ϣ,��Ԥѡ��Ϣ����ѡ��Ϣ����б��е��ظ���Ϣ�ų�
		//�ų�����Ϊ�γ̵�����
		for (int _index = 0; _index < _all.size(); _index++) {
			//��һ�ж�
			//�ȴ�Ԥѡ��Ϣ�п�ʼ����..�����ǿγ���,���ò�дһ��ѭ���������
			Course _temp_data = _all.elementAt(_index);
			boolean _is_corr = true;//�Ƿ�Ӧ�ü���,��ʼΪ��
			for(int _index_pre = 0 ; _index_pre < _pre_tab.size() ; ++_index_pre){
				if(_temp_data.getCourse_name().equals(_pre_tab.elementAt(_index_pre).getCourse_name())){
					//������ͬ
					DebugClass.debug_info(this.toString(), "the course " + "'" + _temp_data.getCourse_name()
							+ "'" + " has already existed in the pre_select_table of user : " + u_id);
					_is_corr = false;
					break;
				}
			}
			//����ʽѡ���е���Ϣ�ж�..
			//**δ���**
			if(_is_corr){
				_data.add(_temp_data);
			}
		}
		return _data;
	}
	 
	//��һ�Ż��߶��ſγ�ѡ��Ԥѡ�α�
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
	
	//��һ�Ż��߶��ſγ�ѡ����ʽ�α�
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
	
	//��һ�Ż��߶��ſγ̴�Ԥѡ�α����Ƴ�
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
	
	//��һ�Ż��߶��ſγ̴���ʽ�α����Ƴ�
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
	
	//�����˴ε�ѡ�β���,�����Ӧ������
	public Exp SelectDone(){
		Exp exp = null;
		//...
		return exp;
	}
}
