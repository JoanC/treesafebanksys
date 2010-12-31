package object;

import db_data_structure.Course;
import db_data_structure.SysParam;
import db_data_structure.enCourseSelType;
import dbquery.* ;

import java.util.Vector;


public class Course_Manager {
	//ȡ�����пγ���Ϣ�б�,������Ԥѡ���������ʾ
	static public Vector<Course> getAllCourseList(){
		Vector<Course> allCourseList = null ;
				
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		allCourseList = dbo.doQueryAllDistinctCourseName() ;
		/*do query*/
		dbo.disconnectDB() ;
		return allCourseList;
	}
	
	static public Vector<String> getAllCourseID(){
		Vector<String> _list = new Vector<String>();
		Vector<Course> _crsCourses = getAllCourseList();
		for(int i = 0 ; i < _crsCourses.size() ; ++i){
			Course _tmpCourse = _crsCourses.elementAt(i);
			_list.add(_tmpCourse.getCourse_id() + " " + _tmpCourse.getCourse_name());
		}
		return _list;
	}
	
	 //ͨ��Ԥѡ�еĿγ���Ϣ,��ѯ��ص�ƥ������б�
	//��δ����
	 static public Vector<Course> getCourseListByName(String _course_name){
		 DebugClass.debug_info("Course_Manager", "query all courses which has name " + "'" + 
				 _course_name + "'" + "...");
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 Vector<Course> _result = dbo.doQuerybyCourseName(_course_name);
		 Vector<Course> _final_result = new Vector<Course>();
		 SysParam _sys = dbo.doQuerySysParam();
		if (_sys.getCourseSelType() == enCourseSelType.CST_FSFG) {
			//������ȵ��ȵ�,�������ݵĽ�һ������
			for (int i = 0; i < _result.size(); ++i) {
				// ���γ̵�����δ��ŷŵ������
				 if(_result.elementAt(i).getCourse_current_seleted_num() < 
						 _result.elementAt(i).getCourse_volume()){
					 //�����ѡ����С�ڿγ�����,����ӵ����ս����
					 _final_result.add(_result.elementAt(i));
				 }
			}
		}
		else{
			dbo.disconnectDB() ;
			return _result;
		}
		 dbo.disconnectDB() ;
		 return _final_result;
	 }
	 
	 //����ݿ���,��ѡ��ĳ�ڿε�ѧ���г�
	 public static Vector<String> searchSelectStudentByCourseId(String _course_id) {
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
	     Vector<String> _all = dbo.doQueryAllStudentSelectCertainCourse(_course_id);
		 dbo.disconnectDB();
		 return _all;
	 }
	 public Course_Manager() {
		// TODO Auto-generated constructor stub
	}
	 
	 public static Exp AddCourse(Course _course){
		 //���һ�ſγ�
		 Exp _exp = new Exp();
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 DebugClass.debug_info("Course Manager", "start to add course...");
		 dbo.insertCourse2TabCourse(_course);
		 DebugClass.debug_info("Course Manager", "add success!");
		 dbo.disconnectDB();
		 return _exp;
	 }
	 
	 public static Exp DeleteCourse(Course _course){
		 Exp _exp = new Exp();
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 dbo.doDeleteCourseFromTabCourse(_course.getCourse_id());
		 dbo.disconnectDB();
		 return _exp;
	 }
	 
	 public static Exp EditCourse(Course _new,Course _old){
		 Exp _exp = new Exp();
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 dbo.doDeleteCourseFromTabCourse(_old.getCourse_id());
		 dbo.insertCourse2TabCourse(_new);
		 dbo.disconnectDB();
		 return _exp;
	 }
	 
	 public static String generateCourseID(){
		Vector<Course> _list = getAllCourseList();
		DebugClass.debug_info("Course Manager", "last course id : " + _list.elementAt(_list.size() - 1).getCourse_id());
		int _id = Integer.parseInt(_list.elementAt(_list.size() - 1).getCourse_id());
		DebugClass.debug_info("Course Manager", "new id is : " + ("" + (_id ++)));
		return ("" + (_id ++));
	 }
	 
	 public static String checkNewCourse(Course _course){
		 Vector<Course> _list = getAllCourseList();
		 for(int _index = 0 ; _index < _list.size() ; ++_index){
			 Course _tmp = _list.elementAt(_index);
			 if(!CourseTimeOperation.isConflict(_tmp.getCourse_time_week(), _course.getCourse_time_week()).isEmpty()){
				//时间有冲突,则继续判定 
				 if(_tmp.getU_id().equals(_course.getU_id())){
					//教师冲突
					 return ("与课程" + _tmp.getCourse_id() + "  " + _tmp.getCourse_name() + "有教师冲突");
				 }
				 if(_tmp.getCourse_place().equals(_course.getCourse_place())){
					 return ("与课程" + _tmp.getCourse_id() + "  " + _tmp.getCourse_name() + "有地点冲突");
				 }
			 }
		 }
		 return "";
	 }
}
