package object;


import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.PreCourseSelectInfo;
import object.CourseTable;
import object.Exp;
import dbquery.* ;

public class PreCourseTable extends CourseTable {
	String u_id; 				//学生的id
	Vector<Course> course_list; //课程表中的课程数据容器
	
	//学生或者老师的用户id的记录
	public void set_u_id(String uid){
		u_id = uid;
	}
	
	//学生或者老师的用户id的获取
	public String get_u_id(){
		return u_id;
	}
	
	//这个课表中的所有课程信息列表的记录
	public Vector<Course> get_course_list(){
		Vector<Course> course_list = null;
		//...
		return course_list;
	}
	
	//在初始化时获取这个u_id下的课表中的所有课程列表
	protected void searchCourseList(){
		//...
		course_list = null;	//给course_list赋值
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
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		
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
