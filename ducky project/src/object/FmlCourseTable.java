package object;

import java.util.Map;
import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.Week;
import db_data_structure.enCourseFreq;
import dbquery.CourseTimeOperation;
import dbquery.DBOperation;
import dbquery.dbConnectParam;
import object.CourseTable;
import object.Exp;

public class FmlCourseTable extends CourseTable {
	private String u_id; // 学生的id
	private Vector<Course> course_list_org; // 课程表中的课程数据容器的原始数据列表
	private Vector<Course> course_list_fixedCourses;// 正在被修改的课程数据列表
	private Vector<Course> course_addedCourses;// 选课过程中添加的课程...为人数统计用
	private Vector<Course> course_deletedCourses;// 选课过程中删除的课程...为人数统计用

	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;
	private static final int WEEK_DAYS = 7;

	public FmlCourseTable(String _u_id) {
		super();
		// TODO Auto-generated constructor stub
		u_id = _u_id;
		course_list_fixedCourses = new Vector<Course>();
		course_addedCourses = new Vector<Course>();
		course_deletedCourses = new Vector<Course>();
		course_list_org = new Vector<Course>();
		// 填充原始数据
		DebugClass.debug_info(this.toString(),
				"copy data... from org data to fixed data...");
		course_list_org = this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
		//test the function "ToString"
		Vector<String>_test  = this.convertFmlTabFormat(course_list_org);
		for(int i = 0 ; i < _test.size() ; ++i){
			DebugClass.debug_info(this.toString(), _test.elementAt(i));
		}
	}

	// 学生或者老师的用户id的记录
	public void set_u_id(String uid) {
		u_id = uid;
	}

	// 学生或者老师的用户id的获取
	public String get_u_id() {
		return u_id;
	}

	@Override
	public Vector<Course> get_course_list() {
		// TODO Auto-generated method stub
		// 读取数据库中的课表数据
		return course_list_fixedCourses;
	}

	public Vector<Course> get_org_data() {
		// 获取最近一次保存前的原始数据
		return course_list_org;
	}

	// 在初始化时获取这个u_id下的课表中的所有课程列表
	protected Vector<Course> searchCourseList() {
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		DebugClass.debug_info(this.toString(),
				"search the formal table of u_id : " + u_id);
		Vector<Course> _result = dbo.doQueryAllCourseTabCourseSelectByUid(u_id);
		for (int i = 0; i < _result.size(); i++) {
			DebugClass.debug_info(this.toString(), "find course :  "
					+ _result.elementAt(i).getCourse_id());
		}
		DebugClass.debug_info(this.toString(), "search done!");
		dbo.disconnectDB();
		return _result;
	}

	// 将一门的课程加入到正式课表中
	public Exp addCourse(Course _new) {
		Exp exp = new Exp();
		course_list_fixedCourses.add(_new);
		course_addedCourses.add(_new);
		return exp;
	}

	// 将一个课程从正式课表中清除
	public Exp deleteCourse(Course _old) {
		Exp exp = new Exp();
		course_list_fixedCourses.remove(_old);
		course_deletedCourses.add(_old);
		return exp;
	}

	// 检测课表中的冲突
	public Vector<Exp_CourseConfict> checkException() {
		Vector<Exp_CourseConfict> vec_exp = new Vector<Exp_CourseConfict>();
		// 检测fixed之后课表本身的冲突
		// 复制两个列表进行比较
		Vector<Course> _temp_1 = new Vector<Course>();
		Vector<Course> _temp_2 = new Vector<Course>();
		_temp_1.addAll(course_list_fixedCourses);
		_temp_2.addAll(course_list_fixedCourses);
		// 判定冲突
		// 两两判定
		/*
		 * for(int _index_time = 0 ; _index_time < _temp_1.size() ; ++
		 * _index_time){ for(int _j = _index_time ; _j < _temp_2.size() ; _j++){
		 * Course _course_1 = _temp_1.elementAt(_index_time); Course _couese_2 =
		 * _temp_2.elementAt(_j);
		 * if(CourseTimeOperation.isConflict(_course_1.getCourse_time(),
		 * _couese_2.getCourse_time())){ //发现冲突
		 * DebugClass.debug_info(this.toString(),
		 * "find conflict,the two couse is : " + _course_1.getCourse_name() +
		 * " and  " + _couese_2.getCourse_name());
		 * DebugClass.debug_info(this.toString(),"the conflict time is : " +
		 * _course_1.getCourse_time()); Exp_CourseConfict _new_exp = new
		 * Exp_CourseConfict();
		 * _new_exp.setmCourse_id_1(_course_1.getCourse_id());
		 * _new_exp.setmCourse_id_2(_couese_2.getCourse_id());
		 * _new_exp.setmConflicTime(_course_1.getCourse_time()); } } }
		 */
		return vec_exp;
	}

	// 保存正式课表
	@SuppressWarnings("unchecked")
	public Exp save() {
		DebugClass.debug_info(this.toString(), "start to save the course...");
		Exp exp = new Exp();
		// 更新数据库列表数据
		course_list_org.clear();
		course_list_org = (Vector<Course>) course_list_fixedCourses.clone();// 更新course_list_org中的数据
		// 更新所有列表
		// 首先删除所有课程
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		// 首先删除所有旧课表
		dbo.doDeleteAllInTabCourseSelectByUID(u_id);
		// 再通过循环添加新的修改过的课表

		for (int i = 0; i < course_list_fixedCourses.size(); ++i) {
			DebugClass.debug_info(this.toString(), "save the course : ");
			dbo.doInsert2TabCourseSelect(u_id, course_list_fixedCourses
					.elementAt(i).getCourse_id());
		}

		// 下面更新选课人数信息

		// 更新辅助列表信息
		course_addedCourses.clear();
		course_deletedCourses.clear();

		// 关闭数据库
		dbo.disconnectDB();
		return exp;
	}

	// 作者:万君亚
	// 时间:2010/12/15
	// 将课程表转化为sevelet与网页端可识别的数据格式
	public Vector<String> convertFmlTabFormat(Vector<Course> _fml_tab) {
		/*
		 * 返回一个存放课程列表信息的一维数组 存放单元为course_id 格式如下
		 * 以七个位单位,第一个七个分别表示礼拜一~七的第一节课..依次类推
		 */
		Vector<String> _rlt = new Vector<String>();
		/*
		 * 实现原理 1.对7*11各个表项进行逐一判定搜索 2.找到对应的课程坐标且个数等于1的,则填入对应的名称
		 * 3.对于单/双周的课程要做一步判断. 4.理论上来说,一个格子内,最多仅有两门课(单双周)..
		 */
		// 步骤1:遍历全部课表格,总数为7*11
		for (int _index = 0; _index < MAX_NUM_OF_COURSES_PER_DAY * WEEK_DAYS; ++_index) {
			// 步骤2:对于每一个格子,进行坐标查找,找出对应的课程个数目,存储在一个Vector中
			// 序号均从0开始计算,非现实的1,2,3,4...例如星期为0,1,2,3,4,5,6...
			// 查找对应的坐标
			int _week = _index % WEEK_DAYS;
			int _seq = _index / WEEK_DAYS;
			DebugClass.debug_info(this.toString(), "the course position is (" + _week + "," + _seq + ");");
			Vector<Course> _temp_list = new Vector<Course>();// 存储一个格子中的课程列表,最多两个
			for (int _index_all_list = 0; _index_all_list < course_list_fixedCourses
					.size(); ++_index_all_list) {
				// 取得课程信息与坐标信息
				Course _course = course_list_fixedCourses
						.elementAt(_index_all_list);
				Map<Integer, Vector<Boolean>> _time = CourseTimeOperation
						.convert2Detail(_course.getCourse_time_week());
				if (_time.containsKey(_week)) {
					// 找到课程在该星期有课,查找节数是否有
					Vector<Boolean> _seqs = _time.get(_week);
					if (_seqs.elementAt(_seq) == true) {
						// 确定在这个坐标上有此课
						_temp_list.add(_course);
					}
				}
			}
			// 步骤3:取得了当前坐标的课程列表,再通过数目,单双周,判断显示出什么信息,即在_rlt中加入怎样的字符串
			_rlt.add(this.generateSubStrForFmlTab(_temp_list, _week));
			DebugClass.debug_info(this.toString(),"time -- week : " + (_week+1) + " seq: " 
					+ (_seq + 1) + this.generateSubStrForFmlTab(_temp_list, _week));
		}
		return _rlt;
	}

	private String generateSubStrForFmlTab(Vector<Course> _list, int _week_day) {
		DebugClass.debug_info(this.toString(), "course in the list : ");
		for(int i = 0 ; i < _list.size() ; ++i){
			DebugClass.debug_info(this.toString(), " " + _list.elementAt(i) + " ");
		}
		String _generate_str = "";
		if (_list.size() == 0) {
			// 没有课程
		} else if (_list.size() == 1) {
			// 恰好一门课程,不存在冲突
			// 判断单双周问题
			Course _tmp = _list.elementAt(0);
			_generate_str += _tmp.getCourse_name();
		} else if (_list.size() == 2) {
			Course _tmp_1 = _list.elementAt(0);
			Course _tmp_2 = _list.elementAt(1);
			// 判断单双周序列是否一致,若有一致则冲突
			if (!CourseTimeOperation.isConflict(_tmp_1.getCourse_time_week(), _tmp_2.getCourse_time_week()).isEmpty()) {
				// 如果序列相同,则冲突
				_generate_str += "课程 " + _tmp_1.getCourse_name() + " " + _tmp_2.getCourse_name() + "存在冲突!";
			} else {
				// 单双周不冲突
				_generate_str += _tmp_1.getCourse_name()
						+ " " + this.generateSubStrByFeq(_tmp_1.getCourse_time_week().getCourse_freq(_week_day));
				_generate_str += "\n";//换行符
				_generate_str += _tmp_2.getCourse_name() 
						+ " " + this.generateSubStrByFeq(_tmp_2.getCourse_time_week().getCourse_freq(_week_day));
			}
		}else{
			//课程冲突
			_generate_str += "课程冲突!";
		}
		return _generate_str;
	}

	private String generateSubStrByFeq(int _feq) {
		String _sub = "";
		if (_feq == enCourseFreq.NONE) {
			// 没有课程
			_sub += "<课程暂停>";
		} else if (_feq == enCourseFreq.ODD_WEEK) {
			// 单周
			_sub += "<单周>";
		} else if (_feq == enCourseFreq.EVEN_WEEK) {
			// 双周
			_sub += "<双周>";
		} else {
			// 每周
			// 不显示
			_sub += "<每周>";
		}
		return _sub;
	}

}
