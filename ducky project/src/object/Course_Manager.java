package object;

import db_data_structure.Course;
import db_data_structure.SysParam;
import db_data_structure.enCourseSelType;
import dbquery.* ;

import java.util.Vector;


public class Course_Manager {
	//取得所有课程信息列表,用于在预选界面进行显示
	static public Vector<Course> getAllCourseList(){
		Vector<Course> allCourseList = null ;
				
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		allCourseList = dbo.doQueryAllDistinctCourseName() ;
		/*do query*/
		dbo.disconnectDB() ;
		return allCourseList;
	}
	
	 //通过预选中的课程信息,查询相关的匹配数据列表
	//尚未测试
	 static public Vector<Course> getCourseListByName(String _course_name){
		 DebugClass.debug_info("Course_Manager", "query all courses which has name " + "'" + 
				 _course_name + "'" + "...");
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 Vector<Course> _result = dbo.doQuerybyCourseName(_course_name);
		 Vector<Course> _final_result = new Vector<Course>();
		 SysParam _sys = dbo.doQuerySysParam();
		if (_sys.getCourseSelType() == enCourseSelType.CST_FSFG) {
			//如果是先到先得,则进行数据的进一步清理
			for (int i = 0; i < _result.size(); ++i) {
				// 如果课程的容量未满才放到结果中
				 if(_result.elementAt(i).getCourse_current_seleted_num() < 
						 _result.elementAt(i).getCourse_volume()){
					 //如果已选人数小于课程容量,则添加到最终结果中
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
	 
	 //在数据库中,将选了某节课的学生列出
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
		 //添加一门课程
		 Exp _exp = new Exp();
		 DBOperation dbo = new DBOperation() ;
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 dbo.insertCourse2TabCourse(_course);
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
	 
}
