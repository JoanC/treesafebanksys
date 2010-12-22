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
	
	 //ͨ��Ԥѡ�еĿγ���Ϣ,��ѯ��ص�ƥ�������б�
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
			//������ȵ��ȵ�,��������ݵĽ�һ������
			for (int i = 0; i < _result.size(); ++i) {
				// ����γ̵�����δ���ŷŵ������
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
}
