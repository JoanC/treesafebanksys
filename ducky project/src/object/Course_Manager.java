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
}
