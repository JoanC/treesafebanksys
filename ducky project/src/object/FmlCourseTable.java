package object;

import java.util.Map;
import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.Week;
import db_data_structure.enCourseFreq;
import dbquery.CourseTimeOperation;
import dbquery.DBOperation;
import dbquery.dbConnectParam;
import object.CourseTable;
import object.Exp;

public class FmlCourseTable extends CourseTable {
	private String u_id; // ѧ����id
	private Vector<Course> course_list_org; // �γ̱��еĿγ�����������ԭʼ�����б�
	private Vector<Course> course_list_fixedCourses;// ���ڱ��޸ĵĿγ������б�
	private Vector<Course> course_addedCourses;// ѡ�ι�������ӵĿγ�...Ϊ����ͳ����
	private Vector<Course> course_deletedCourses;// ѡ�ι�����ɾ���Ŀγ�...Ϊ����ͳ����

	public FmlCourseTable(String _u_id) {
		super();
		// TODO Auto-generated constructor stub
		u_id = _u_id;
		course_list_fixedCourses = new Vector<Course>();
		course_addedCourses = new Vector<Course>();
		course_deletedCourses = new Vector<Course>();
		course_list_org = new Vector<Course>();
		// ���ԭʼ����
		DebugClass.debug_info(this.toString(),
				"copy data... from org data to fixed data...");
		course_list_org = this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
		//test the function "ToString"
		/*
		Vector<String>_test  = this.convertFmlTabFormat(course_list_org);
		for(int i = 0 ; i < _test.size() ; ++i){
			int _week = i % WEEK_DAYS;
			int _seq = i / WEEK_DAYS;
			DebugClass.debug_info(this.toString(),"Index : " + i + "_" + "(" + (_week+1) + "," + (_seq + 1) + ")  :" + _test.elementAt(i));
		}
		*/
	}

	// ѧ��������ʦ���û�id�ļ�¼
	public void set_u_id(String uid) {
		u_id = uid;
	}

	// ѧ��������ʦ���û�id�Ļ�ȡ
	public String get_u_id() {
		return u_id;
	}

	@Override
	public Vector<Course> get_course_list() {
		// TODO Auto-generated method stub
		// ��ȡ���ݿ��еĿα�����
		return course_list_fixedCourses;
	}

	public Vector<Course> get_org_data() {
		// ��ȡ���һ�α���ǰ��ԭʼ����
		return course_list_org;
	}

	// �ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected Vector<Course> searchCourseList() {
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		DebugClass.debug_info(this.toString(),
				"search the formal table of u_id : " + u_id);
		Vector<Course> _result = dbo.doQueryAllCourseTabCourseSelectByUid(u_id);
		for (int i = 0; i < _result.size(); i++) {
			DebugClass.debug_info(this.toString(), "find course :  "
					+ _result.elementAt(i).getCourse_id());
		}
		DebugClass.debug_info(this.toString(), "search done!");
		dbo.disconnectDB();
		return _result;
	}

	// ��һ�ŵĿγ̼��뵽��ʽ�α���
	public Exp addCourse(Course _new) {
		Exp exp = new Exp();
		course_list_fixedCourses.add(_new);
		course_addedCourses.add(_new);
		return exp;
	}

	// ��һ���γ̴���ʽ�α������
	public Exp deleteCourse(Course _old) {
		Exp exp = new Exp();
		course_list_fixedCourses.remove(_old);
		course_deletedCourses.add(_old);
		return exp;
	}

	// ���α��еĳ�ͻ
	public Vector<Exp_CourseConfict> checkException() {
		Vector<Exp_CourseConfict> vec_exp = new Vector<Exp_CourseConfict>();
		// ���fixed֮��α���ĳ�ͻ
		// ���������б���бȽ�
		Vector<Course> _temp_1 = new Vector<Course>();
		Vector<Course> _temp_2 = new Vector<Course>();
		_temp_1.addAll(course_list_fixedCourses);
		_temp_2.addAll(course_list_fixedCourses);
		// �ж���ͻ
		// �����ж�
		
		for (int _index_time = 0; _index_time < _temp_1.size(); ++_index_time) {
			for (int _j = _index_time; _j < _temp_2.size(); _j++) {
				Course _course_1 = _temp_1.elementAt(_index_time);
				Course _couese_2 = _temp_2.elementAt(_j);
				if (CourseTimeOperation.isConflict(_course_1.getCourse_time_week(),
						_couese_2.getCourse_time_week()).size() != 0) { // ���ֳ�ͻ
					Exp_CourseConfict _new_exp = new Exp_CourseConfict();
					_new_exp.setmCourse_id_1(_course_1.getCourse_id());
					_new_exp.setmCourse_id_2(_couese_2.getCourse_id());
					//_new_exp.getmConflicTime(CourseTimeOperation.isConflict(_course_1.getCourse_time_week(),
					//		_couese_2.getCourse_time_week()));
				}
			}
		}
		 
		return vec_exp;
	}

	// ������ʽ�α�
	@SuppressWarnings("unchecked")
	public Exp save() {
		DebugClass.debug_info(this.toString(), "start to save the course...");
		Exp exp = new Exp();
		// �������ݿ��б�����
		course_list_org.clear();
		course_list_org = (Vector<Course>) course_list_fixedCourses.clone();// ����course_list_org�е�����
		// ���������б�
		// ����ɾ�����пγ�
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		// ����ɾ�����оɿα�
		dbo.doDeleteAllInTabCourseSelectByUID(u_id);
		// ��ͨ��ѭ������µ��޸Ĺ��Ŀα�

		for (int i = 0; i < course_list_fixedCourses.size(); ++i) {
			DebugClass.debug_info(this.toString(), "save the course : ");
			dbo.doInsert2TabCourseSelect(u_id, course_list_fixedCourses
					.elementAt(i).getCourse_id());
		}

		// �������ѡ��������Ϣ

		// ���¸����б���Ϣ
		course_addedCourses.clear();
		course_deletedCourses.clear();

		// �ر����ݿ�
		dbo.disconnectDB();
		return exp;
	}
}
