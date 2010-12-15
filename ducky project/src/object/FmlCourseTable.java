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
	private Vector<Course> course_addedCourses;//选课过程中添加的课程...为人数统计用
	private Vector<Course> course_deletedCourses;//选课过程中删除的课程...为人数统计用
	

	public FmlCourseTable(String _u_id) {
		super();
		// TODO Auto-generated constructor stub
		u_id = _u_id;
		course_list_fixedCourses = new Vector<Course>();
		course_addedCourses = new Vector<Course>();
		course_deletedCourses = new Vector<Course>();
		course_list_org = new Vector<Course>();
		//填充原始数据
		DebugClass.debug_info(this.toString(), "copy data... from org data to fixed data...");
		course_list_org =  this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
		for (int i = 0; i < course_list_org.size(); i++) {
			DebugClass.debug_info(this.toString(), "the copied course is :" + course_list_org.elementAt(i).getCourse_id());
		}
		DebugClass.debug_info(this.toString(), "copy done!");
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
	public Vector<Course> get_course_list() {
		// TODO Auto-generated method stub
		//读取数据库中的课表数据
		return course_list_fixedCourses;
	}
	
	public Vector<Course> get_org_data(){
		//获取最近一次保存前的原始数据
		return course_list_org;
	}

	//在初始化时获取这个u_id下的课表中的所有课程列表
	protected Vector<Course> searchCourseList(){
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		DebugClass.debug_info(this.toString(), "search the formal table of u_id : " + u_id);
		Vector<Course> _result =  dbo.doQueryAllCourseTabCourseSelectByUid(u_id);
		for (int i = 0; i < _result.size(); i++) {
			DebugClass.debug_info(this.toString(), "find course :  " + _result.elementAt(i).getCourse_id());
		}
		DebugClass.debug_info(this.toString(), "search done!");
		dbo.disconnectDB();
		return _result;
	}
	
	//将一门的课程加入到正式课表中
	public Exp addCourse(Course _new){
		Exp exp = new Exp();
		course_list_fixedCourses.add(_new);
		course_addedCourses.add(_new);
		return exp;
	}
	
	//将一个课程从正式课表中清除
	public Exp deleteCourse(Course _old){
		Exp exp = new Exp();
		course_list_fixedCourses.remove(_old);
		course_deletedCourses.add(_old);
		return exp;
	}
	
	//检测课表中的冲突
	@SuppressWarnings("unchecked")
	public Vector<Exp_CourseConfict> checkException(){
		Vector<Exp_CourseConfict> vec_exp = new Vector<Exp_CourseConfict>();
		//检测fixed之后课表本身的冲突
		//复制两个列表进行比较
		Vector<Course> _temp_1 = new Vector<Course>();
		Vector<Course> _temp_2 = new Vector<Course>();
		_temp_1.addAll(course_list_fixedCourses);
		_temp_2.addAll(course_list_fixedCourses);
		//判定冲突
		//两两判定
		/*
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
		}*/
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
		
		//下面更新选课人数信息
		
		//更新辅助列表信息
		course_addedCourses.clear();
		course_deletedCourses.clear();
		
		//关闭数据库
		dbo.disconnectDB();
		return exp;
	}
	
	//作者:万君亚
	//时间:2010/12/15
	//将课程表转化为sevelet与网页端可识别的数据格式
	public Vector<String> convertFmlTabFormat(Vector<Course> _fml_tab){
		/*
		 * 返回一个存放课程列表信息的一维数组
		 * 存放单元为course_id
		 * 格式如下
		 * 以七个位单位,第一个七个分别表示礼拜一~七的第一节课..依次类推
		 */
		Vector<String> _rlt = new Vector<String>();
		return _rlt;
	}
}
