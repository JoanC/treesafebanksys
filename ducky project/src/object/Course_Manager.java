package object;

import db_data_structure.Course;
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
		 for(int i = 0; i < _result.size() ; ++i){
			 DebugClass.debug_info("Course_Manager", "search the course_id:" + 
					 _result.elementAt(i).getCourse_id() + "the teacher id is " + _result.elementAt(i).getU_id());
		 }
		 dbo.disconnectDB() ;
		 return _result;
	 }
}
