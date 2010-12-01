package object;


import java.util.Vector;
import object.CourseTable;
import object.Exp;


public class CourseSelect_Manager {
	String u_id; 				//��¼��ѧ�����
	PreCourseTable pre_tab;		//Ԥѡ�α���Ϣ
	FmlCourseTable fml_tab;		//��ʽ�α���Ϣ
	
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
	
	//��һ�Ż��߶��ſγ�ѡ��Ԥѡ�α�
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
