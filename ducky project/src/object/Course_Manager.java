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
	
	 //ͨ��Ԥѡ�еĿγ���Ϣ,��ѯ��ص�ƥ�������б�
	//��δ����
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
