package object;

import db_data_structure.Course;
import db_data_structure.SysParam;
import db_data_structure.enCourseSelType;
import dbquery.*;

import java.util.Vector;

import javax.mail.search.FromStringTerm;

public class Course_Manager {
	// ȡ�����пγ���Ϣ�б�,������Ԥѡ���������ʾ
	private static final int course_min_id = 10001;

	static public Vector<Course> getAllCourseList() {
		Vector<Course> allCourseList = null;

		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		allCourseList = dbo.doQueryAllCourseName();
		/* do query */
		dbo.disconnectDB();
		return allCourseList;
	}

	static public Vector<Course> getAllCourseListOderbyID() {
		Vector<Course> allCourseList = null;

		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		allCourseList = dbo.doQueryAllCourseNameOderByID();
		/* do query */
		dbo.disconnectDB();
		return allCourseList;
	}

	static public Vector<Course> getDistinctCourseList() {
		Vector<Course> allCourseList = null;

		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		allCourseList = dbo.doQueryAllDistinctCourseName();
		/* do query */
		dbo.disconnectDB();
		return allCourseList;
	}

	static public Vector<String> getAllCourseID() {
		Vector<String> _list = new Vector<String>();
		Vector<Course> _crsCourses = getAllCourseList();
		for (int i = 0; i < _crsCourses.size(); ++i) {
			Course _tmpCourse = _crsCourses.elementAt(i);
			_list.add(_tmpCourse.getCourse_id() + " "
					+ _tmpCourse.getCourse_name());
		}
		return _list;
	}

	// ͨ��Ԥѡ�еĿγ���Ϣ,��ѯ��ص�ƥ������б�
	// ��δ����
	static public Vector<Course> getCourseListByName(String _course_name){
		 DebugClass.debug_info("Course_Manager", "query all courses which has name " + "'" + 
				 _course_name + "'" + "...");
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 Vector<Course> _result = dbo.doQuerybyCourseName(_course_name);
		 Vector<Course> _final_result = new Vector<Course>();
		 SysParam _sys = dbo.doQuerySysParam();

			//������ȵ��ȵ�,�������ݵĽ�һ������
			for (int i = 0; i < _result.size(); ++i) {
				// ���γ̵�����δ��ŷŵ������
				if(_result.elementAt(i).getCourse_point() < 0){
					continue;
				}
				if (_sys.getCourseSelType() == enCourseSelType.CST_FSFG) {
				   if(_result.elementAt(i).getCourse_current_seleted_num() >= 
						 _result.elementAt(i).getCourse_volume()){
					 //�����ѡ����С�ڿγ�����,����ӵ����ս����
					   continue;
				   }
				}
				 _final_result.add(_result.elementAt(i));
		}
		 dbo.disconnectDB() ;
		 return _final_result;
	 }

	// ����ݿ���,��ѡ��ĳ�ڿε�ѧ���г�
	public static Vector<String> searchSelectStudentByCourseId(String _course_id) {
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		Vector<String> _all = dbo
				.doQueryAllStudentSelectCertainCourse(_course_id);
		dbo.disconnectDB();
		return _all;
	}

	public Course_Manager() {
		// TODO Auto-generated constructor stub
	}

	public static Exp AddCourse(Course _course) {
		// ���һ�ſγ�
		Exp _exp = new Exp();
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		DebugClass.debug_info("Course Manager", "start to add course...");
		dbo.insertCourse2TabCourse(_course);
		// 更新老师的数据库表
		addCourseUpdateTab(_course);
		DebugClass.debug_info("Course Manager", "add success!");
		dbo.disconnectDB();
		return _exp;
	}

	public static Exp DeleteCourse(Course _course) {
		Exp _exp = new Exp();
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		DebugClass.debug_info("Course Manager", "delete course : "
				+ _course.getCourse_id());
		// 更新其他数据
		delCourseUpdateTab(_course.getCourse_id());
		dbo.doDeleteCourseFromTabCourse(_course.getCourse_id());
		dbo.disconnectDB();
		return _exp;
	}

	public static Exp EditCourse(Course _new, Course _old) {
		Exp _exp = new Exp();
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		dbo.doDeleteCourseFromTabCourse(_old.getCourse_id());
		dbo.insertCourse2TabCourse(_new);
		dbo.disconnectDB();
		return _exp;
	}

	public static String generateCourseID() {
		Vector<Course> _list = getAllCourseListOderbyID();
		DebugClass
				.debug_info("Course Manager", "course_size : " + _list.size());
		return ("" + (Integer.parseInt(_list.lastElement().getCourse_id()) + 1));
	}

	public static String checkNewCourse(Course _course) {
		Vector<Course> _list = getAllCourseList();

		for (int _index = 0; _index < _list.size(); ++_index) {
			Course _tmp = _list.elementAt(_index);
			if (!CourseTimeOperation.isConflict(_tmp.getCourse_time_week(),
					_course.getCourse_time_week()).isEmpty()) {
				// 时间有冲突,则继续判定
				if (_tmp.getU_id().equals(_course.getU_id())) {
					// 教师冲突
					return ("与课程" + _tmp.getCourse_id() + _tmp.getCourse_name() + "有教师冲突");
				}
				if (_tmp.getCourse_place().equals(_course.getCourse_place())) {
					return ("与课程" + _tmp.getCourse_id() + _tmp.getCourse_name() + "有地点冲突");
				}
			}
		}
		return "";
	}

	private static void delCourseUpdateTab(String _course_id) {
		// 在所有人的正选课表中删除这门课
		Vector<String> _users = searchSelectStudentByCourseId(_course_id);
		for (int _index = 0; _index < _users.size(); ++_index) {
			FmlCourseTable _fml = new FmlCourseTable(_users.elementAt(_index));
			Course _oldCourse = new Course();
			_oldCourse.setCourse_id(_course_id);
			_fml.deleteCourse(_oldCourse);
			DebugClass.debug_info("Course Manager", "the user id : "
					+ _users.elementAt(_index) + "the delete course  : "
					+ _course_id);
		}
	}

	private static void addCourseUpdateTab(Course _course) {
		// 将这门课加入老师对应的正式课表中
		// 老师即为u_id
		FmlCourseTable _fml = new FmlCourseTable(_course.getU_id());
		_fml.addCourse(_course);
	}

	public static Course queryCourse(String _course_id) {
		Vector<Course> _rlt = getAllCourseList();
		for (int _index = 0; _index < _rlt.size(); ++_index) {
			if (_rlt.elementAt(_index).getCourse_id().equals(_course_id)) {
				return _rlt.elementAt(_index);
			}
		}
		return null;
	}
}
