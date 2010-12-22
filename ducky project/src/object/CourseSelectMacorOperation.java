package object;


import java.util.Vector;

import db_data_structure.Course;
import dbquery.DBOperation;
import dbquery.dbConnectParam;

import object.Exp;
import sun.nio.cs.ext.MacRoman;

//
public class CourseSelectMacorOperation {
	//ϵͳִ��������˲���
	static public Exp RadomSelect(){
		Exp exp = new Exp();
		//ȡ�����еĿγ��б�
		Vector<Course> _all_course_list = Course_Manager.getAllCourseList();
		for(int _index = 0 ; _index < _all_course_list.size() ; ++_index){
			Course _tag = _all_course_list.elementAt(_index);
			if(calCourseDiff(_tag) > 0){
				//����γ�����
				//ִ�����˲���
				bootStudent(_tag);
			}
		}
		return exp;
	}
	
	static private Vector<String> getRadomUID(Course _course,int _diff){
		//��ѡ�����ſγ̵ĸ��ߵ���u_id��������
		Vector<String> _rlt = new Vector<String>();
		Vector<String> _all = new Vector<String>();
		if(_diff <= 0) return _rlt;//���ؽ��
		//�ҵ�����ѡ�����ſε�ѧ��id
		//*******************************//�ȴ��ﳬ�ӿ�
		////////////////////////////////////
		for(int _index = 0 ; _index < _diff ; ++_index){
			int _rdm = getRadomNumber(_all.size());
			DebugClass.debug_info("MacroOperation", "get the radom number : " + _rdm);
			DebugClass.debug_info("MacroOperation", "boot the u_id :  " + _all.elementAt(_rdm));
			_rlt.add(_all.elementAt(_rdm));
			//�����ظ�
			_all.remove(_rdm);
		}
		DebugClass.debug_info("MacroOperation", "the booted user index : _______list_______");
		for(int _index = 0 ; _index < _rlt.size() ; ++_index){
			//���Դ�ӡ����
			DebugClass.debug_info("MacroOperation", _rlt.elementAt(_index));
		}
		return _rlt;
	}
	
	static private int getRadomNumber(int _max){
		//����һ����0��_max���漴����
		int _radom = 0;
		_radom = (int)Math.random() * _max;
		return _radom;
	}
	
	 static private int calCourseDiff(Course _course){
		return(_course.getCourse_current_seleted_num() - _course.getCourse_volume());
	 }
	 
	 static private void bootStudent(Course _course){
		 
	 }
}
