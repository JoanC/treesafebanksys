package object;



import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;
import object.CourseTable;
import object.Exp;
import dbquery.* ;

public class PreCourseTable extends CourseTable {
	String u_id; 				//学生的id
//	Vector<Course> course_list; //课程表中的课程数据容器
	
	//学生或者老师的用户id的记录
	public void set_u_id(String uid){
		u_id = uid;
	}
	
	//学生或者老师的用户id的获取
	public String get_u_id(){
		return u_id;
	}
	
	//这个课表中的所有课程信息列表的记录
	//从数据库中读取列表数据
	public Vector get_course_list(){
		return this.searchCourseList();
     }
	
	//在初始化时获取这个u_id下的课表中的所有课程列表
	protected Vector searchCourseList(){
		//...
		//course_list = null;	//给course_list赋值
		Vector<PreCourseSelectInfo> course_list = null;
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, 
				dbConnectParam.userName, dbConnectParam.dbPwd) ;
		//读取列表代码
		course_list = dbo.doQueryPreTabByID(u_id);
		//底层数据的调试信息
		DebugClass.debug_info("PreTable", "get all course list from id :" + u_id);
		for(int i = 0; i< course_list.size();++i){
			DebugClass.debug_info("PreTable get list:", course_list.elementAt(i).getCourse_name());
		}
		//断开数据库
		dbo.disconnectDB();
		return course_list;
	}
	
	//预选数据的自动保存,这个在实现预选课表的add和delete方法时调用
	private Exp altoSave(){
		Exp exp = null;
		//...
		return exp;
	}
	
	//将一门课程从选课初始的大列表选入到预选课程表中
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
	
	//将一门课程从预选课程表中删除
	public Exp deleteCourse(PreCourseSelectInfo info){
		Exp exp = null;
		//altoSave();
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		
		dbo.doDeleteFromPreSelTab(info) ;
		
		dbo.disconnectDB() ;
		return exp;
	}
}
