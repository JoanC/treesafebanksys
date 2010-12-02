package object;

import db_data_structure.Course;
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
}
