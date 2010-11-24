package object;

import dbquery.* ;

import java.util.Vector;
import object.Course;


public class Course_Manager {
	//取得所有课程信息列表,用于在预选界面进行显示
	public Vector<Course> getAllCourseList(){
		Vector<Course> allCourseList = null ;
				
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		
		allCourseList = dbo.doAllCourseQuery() ;
		/*do query*/
		dbo.disconnectDB() ;
		
		return allCourseList;
	}
}
