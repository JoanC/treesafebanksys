package object;



import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;
import object.CourseTable;
import object.Exp;
import dbquery.* ;

public class PreCourseTable extends CourseTable {
	String u_id; 				//ѧ���id
//	Vector<Course> course_list; //�γ̱��еĿγ��������
	
	//ѧ�������ʦ���û�id�ļ�¼
	public void set_u_id(String uid){
		u_id = uid;
	}
	
	//ѧ�������ʦ���û�id�Ļ�ȡ
	public String get_u_id(){
		return u_id;
	}
	
	//����α��е����пγ���Ϣ�б�ļ�¼
	//����ݿ��ж�ȡ�б����
	public Vector<PreCourseSelectInfo> get_course_list(){
		return this.searchCourseList();
     }
	
	//�ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected Vector<PreCourseSelectInfo> searchCourseList(){
		//...
		//course_list = null;	//��course_list��ֵ
		Vector<PreCourseSelectInfo> course_list = null;
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, 
				dbConnectParam.userName, dbConnectParam.dbPwd) ;
		//��ȡ�б����
		course_list = dbo.doQueryPreCourseInfoFromTabPreCourseSelectByID(u_id);
		//�ײ���ݵĵ�����Ϣ
		DebugClass.debug_info("PreTable", "get all course list from id :" + u_id);
		for(int i = 0; i< course_list.size();++i){
			DebugClass.debug_info("PreTable get list", course_list.elementAt(i).getCourse_name());
		}
		//�Ͽ���ݿ�
		dbo.disconnectDB();
		return course_list;
	}
	
	//��һ�ſγ̴�ѡ�γ�ʼ�Ĵ��б�ѡ�뵽Ԥѡ�γ̱���
	public Exp addCourse(PreCourseSelectInfo info){

		Exp exp = null;
		//altoSave();
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, 
				dbConnectParam.userName, dbConnectParam.dbPwd) ;
		DebugClass.debug_info("PreTable", "add class info : " + info.getCourse_name()
				+ "user id : " + info.getUid());
		dbo.doInsert2PreSelTab(info) ;
		dbo.disconnectDB() ;
		return exp;
	}
	
	//��һ�ſγ̴�Ԥѡ�γ̱���ɾ��
	public Exp deleteCourse(PreCourseSelectInfo info){
		Exp exp = null;
		//altoSave();
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		DebugClass.debug_info("PreTable", "delete class info : " + info.getCourse_name()
				+ "user id : " + info.getUid());
		dbo.doDeleteFromPreSelTab(info) ;
		dbo.disconnectDB() ;
		return exp;
	}
}
