package object;

import dbquery.* ;

import java.util.Vector;
import object.Course;


public class Course_Manager {
	//ȡ�����пγ���Ϣ�б�,������Ԥѡ���������ʾ
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
