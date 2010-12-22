package object;


import java.util.Vector;

import db_data_structure.Course;
import dbquery.DBOperation;
import dbquery.dbConnectParam;

import object.Exp;
import sun.nio.cs.ext.MacRoman;

//
public class CourseSelectMacorOperation {
	//系统执行随机踢人操作
	static public Exp RadomSelect(){
		Exp exp = new Exp();
		//取得所有的课程列表
		Vector<Course> _all_course_list = Course_Manager.getAllCourseList();
		for(int _index = 0 ; _index < _all_course_list.size() ; ++_index){
			Course _tag = _all_course_list.elementAt(_index);
			if(calCourseDiff(_tag) > 0){
				//如果课程满了
				//执行踢人操作
				bootStudent(_tag);
			}
		}
		return exp;
	}
	
	static private Vector<String> getRadomUID(Course _course,int _diff){
		//把选了这门课程的该踢得人u_id保存下来
		Vector<String> _rlt = new Vector<String>();
		Vector<String> _all = new Vector<String>();
		if(_diff <= 0) return _rlt;//返回结果
		//找到所有选过这门课的学生id
		//*******************************//等待孙超接口
		////////////////////////////////////
		for(int _index = 0 ; _index < _diff ; ++_index){
			int _rdm = getRadomNumber(_all.size());
			DebugClass.debug_info("MacroOperation", "get the radom number : " + _rdm);
			DebugClass.debug_info("MacroOperation", "boot the u_id :  " + _all.elementAt(_rdm));
			_rlt.add(_all.elementAt(_rdm));
			//避免重复
			_all.remove(_rdm);
		}
		DebugClass.debug_info("MacroOperation", "the booted user index : _______list_______");
		for(int _index = 0 ; _index < _rlt.size() ; ++_index){
			//测试打印数据
			DebugClass.debug_info("MacroOperation", _rlt.elementAt(_index));
		}
		return _rlt;
	}
	
	static private int getRadomNumber(int _max){
		//产生一个从0到_max的随即数字
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
