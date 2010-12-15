package object;


import java.util.Vector;

import db_data_structure.Course;
import dbquery.CourseTimeOperation;
import dbquery.DBOperation;
import dbquery.dbConnectParam;
import object.CourseTable;
import object.Exp;


public class FmlCourseTable extends CourseTable {
	private String u_id; 				//学生的id
	private Vector<Course> course_list_org; //课程表中的课程数据容器的原始数据列表
	private Vector<Course> course_list_fixedCourses;//正在被修改的课程数据列表
	
	@SuppressWarnings("unchecked")
	public FmlCourseTable(String _u_id) {
		super();
		// TODO Auto-generated constructor stub
		u_id = _u_id;
		//填充原始数据
		course_list_org = this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
	}

	//学生或者老师的用户id的记录
	public void set_u_id(String uid){
		u_id = uid;
	}
	
	//学生或者老师的用户id的获取
	public String get_u_id(){
		return u_id;
	}
	
	
	@Override
	public Vector get_course_list() {
		// TODO Auto-generated method stub
		//读取数据库中的课表数据
		return course_list_org;
	}

	//在初始化时获取这个u_id下的课表中的所有课程列表
	protected Vector searchCourseList(){
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		Vector<Course> _result =  dbo.doQueryAllCourseTabCourseSelectByUid(u_id);
		dbo.disconnectDB();
		return _result;
	}
	
	//将一门的课程加入到正式课表中
	public Exp addCourse(Course _new){
		Exp exp = new Exp();
		course_list_fixedCourses.add(_new);
		return exp;
	}
	
	//将一个课程从正式课表中清除
	public Exp deleteCourse(Course _old){
		Exp exp = new Exp();
		course_list_fixedCourses.remove(_old);
		return exp;
	}
	
	//检测课表中的冲突
	@SuppressWarnings("unchecked")
	public Vector<Exp_CourseConfict> checkException(){
		Vector<Exp_CourseConfict> vec_exp = null;
		//检测fixed之后课表本身的冲突
		//复制两个列表进行比较
		Vector<Course> _temp_1 = new Vector<Course>();
		Vector<Course> _temp_2 = new Vector<Course>();
		_temp_1.addAll(course_list_fixedCourses);
		_temp_2.addAll(course_list_fixedCourses);
		//判定冲突
		//两两判定
		for(int _index_time = 0 ; _index_time <  _temp_1.size() ; ++ _index_time){
			for(int _j = _index_time ; _j < _temp_2.size() ; _j++){
				Course _course_1 = _temp_1.elementAt(_index_time);
				Course _couese_2 = _temp_2.elementAt(_j);
				if(CourseTimeOperation.isConflict(_course_1.getCourse_time(),
						_couese_2.getCourse_time())){
					//发现冲突
					DebugClass.debug_info(this.toString(), "find conflict,the two couse is : " + _course_1.getCourse_name()
							+ " and  " + _couese_2.getCourse_name());
					DebugClass.debug_info(this.toString(),"the conflict time is : " + _course_1.getCourse_time());
					Exp_CourseConfict _new_exp = new Exp_CourseConfict();
					_new_exp.setmCourse_id_1(_course_1.getCourse_id());
					_new_exp.setmCourse_id_2(_couese_2.getCourse_id());
					_new_exp.setmConflicTime(_course_1.getCourse_time());
				}
			}
		}
		return vec_exp;
	}
	
	//保存正式课表
	@SuppressWarnings("unchecked")
	public Exp save(){
		DebugClass.debug_info(this.toString(), "start to save the course...");
		Exp exp = new Exp();
		//更新数据库列表数据
		course_list_org.clear();
		course_list_org = (Vector<Course>) course_list_fixedCourses.clone();//更新course_list_org中的数据
		//更新所有列表
		//首先删除所有课程
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		//首先删除所有旧课表
		dbo.doDeleteAllInTabCourseSelectByUID(u_id);
		//再通过循环添加新的修改过的课表
		for(int i = 0 ; i < course_list_fixedCourses.size() ; ++i){
			DebugClass.debug_info(this.toString(), "save the course : ");
			dbo.doInsert2TabCourseSelect(u_id, course_list_fixedCourses.elementAt(i).getCourse_id());
		}
		dbo.disconnectDB();
		return exp;
	}
}
