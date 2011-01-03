package object;

import java.util.Vector;

import db_data_structure.Course;
import object.Exp;

//
public class CourseSelectMacorOperation {
	// ϵͳִ��������˲���
	static public Exp RadomSelect() {
		Exp exp = new Exp();
		// ȡ�����еĿγ��б�
		Vector<Course> _all_course_list = Course_Manager.getAllCourseList();
		for (int _index = 0; _index < _all_course_list.size(); ++_index) {
			Course _tag = _all_course_list.elementAt(_index);
			bootStudent(_tag);
		}
		return exp;
	}

	static private void bootStudent(Course _course){
		 //�õ����ſ�Ӧ�ñ��ߵ��˵�id
		 Vector<String> _boot = getRadomUID(_course, calCourseDiff(_course));
		 //����ÿһ��user,�����߿β���
		 for(int _index = 0 ; _index < _boot.size() ; ++_index){
			 delStudent(_course, _boot.elementAt(_index));
		 }
	 }

	static private void delStudent(Course _course, String _u_id) {
		// ɾ�����ſ��µ����ѧ��
		//������ѧ�����ʽѡ�α�
		FmlCourseTable _fml = new FmlCourseTable(_u_id);
		//ɾ����ſγ�,Ҳ����������
		_fml.deleteCourse(_course);
	}

	static private Vector<String> getRadomUID(Course _course, int _diff) {
		// ��ѡ�����ſγ̵ĸ��ߵ���u_id��������
		Vector<String> _rlt = new Vector<String>();
		Vector<String> _all = new Vector<String>();
		if (_diff <= 0)
			return _rlt;// ���ؽ��
		// �ҵ�����ѡ�����ſε�ѧ��id
		_all = Course_Manager.searchSelectStudentByCourseId(_course.getCourse_id());
		for (int _index = 0; _index < _diff; ++_index) {
			int _rdm = getRadomNumber(_all.size());
			DebugClass.debug_info("MacroOperation", "get the radom number : "
					+ _rdm);
			DebugClass.debug_info("MacroOperation", "boot the u_id :  "
					+ _all.elementAt(_rdm));
			_rlt.add(_all.elementAt(_rdm));
			//踢人
			_all.remove(_rdm);
		}
		DebugClass.debug_info("MacroOperation",
				"the booted user index : __________________list__________________");
		for (int _index = 0; _index < _rlt.size(); ++_index) {
			// ���Դ�ӡ���
			DebugClass.debug_info("MacroOperation", _rlt.elementAt(_index));
		}
		return _rlt;
	}
	
	static private int getRadomNumber(int _max) {
		//生成一个随机数字
		int _radom = 0;
		_radom = (int) Math.random() * _max;
		return _radom;
	}

	static private int calCourseDiff(Course _course) {
		return (_course.getCourse_current_seleted_num() - _course
				.getCourse_volume());
	}

}
