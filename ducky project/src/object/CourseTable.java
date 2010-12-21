package object;


import java.util.Map;
import java.util.Vector;

import com.sun.net.ssl.internal.ssl.Debug;

import db_data_structure.Course;
import db_data_structure.enCourseFreq;
import dbquery.CourseTimeOperation;


public abstract class CourseTable {
	//学生或者老师的用户id的记录

	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;
	private static final int WEEK_DAYS = 7;
	
	public abstract void set_u_id(String uid);
	
	//学生或者老师的用户id的获取
	public abstract String get_u_id();
	
	//这个课表中的所有课程信息列表的记录
	public abstract Vector get_course_list();
	
	//在初始化时获取这个u_id下的课表中的所有课程列表
	protected abstract Vector searchCourseList();
	
	// 作者:万君亚
	// 时间:2010/12/15
	// 将课程表转化为sevelet与网页端可识别的数据格式
	public static Vector<String> convertFmlTabFormat(Vector<Course> _fml_tab) {
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
			//DebugClass.debug_info("CourseTable", "the course position is (" + _week + "," + _seq + ");");
			Vector<Course> _temp_list = new Vector<Course>();// 存储一个格子中的课程列表,最多两个
			for (int _index_all_list = 0; _index_all_list < _fml_tab
					.size(); ++_index_all_list) {
				// 取得课程信息与坐标信息
				Course _course = _fml_tab
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
			_rlt.add(generateSubStrForFmlTab(_temp_list, (_week+1)));
			/*DebugClass.debug_info("CourseTable","time -- week : " + (_week+1) + " seq: " 
					+ (_seq + 1) + generateSubStrForFmlTab(_temp_list, _week));*/
		}
		return _rlt;
	}

	private static String generateSubStrForFmlTab(Vector<Course> _list, int _week_day) {
		for(int i = 0 ; i < _list.size() ; ++i){
			DebugClass.debug_info("CourseTable", " week : " + _week_day + " " + _list.elementAt(i).getCourse_name() + " "
					+ "feq:" + _list.elementAt(i).getCourse_time_week().getCourse_freq(_week_day));
		}
		String _generate_str = "";
		if (_list.size() == 0) {
			// 没有课程
		} else if (_list.size() == 1) {
			// 恰好一门课程,不存在冲突
			// 判断单双周问题
			Course _tmp = _list.elementAt(0);
			_generate_str += _tmp.getCourse_name()
					+ " " + generateSubStrByFeq(_tmp.getCourse_time_week().getCourse_freq(_week_day));
		} else if (_list.size() == 2) {
			Course _tmp_1 = _list.elementAt(0);
			Course _tmp_2 = _list.elementAt(1);
			// 判断单双周序列是否一致,若有一致则冲突
			if (_tmp_1.getCourse_time_week().getCourse_freq(_week_day) == _tmp_2.getCourse_time_week().getCourse_freq(_week_day)
					&& 0 != _tmp_1.getCourse_time_week().getCourse_freq(_week_day)*_tmp_2.getCourse_time_week().getCourse_freq(_week_day)) {
				// 如果序列相同,则冲突
				DebugClass.debug_info("CourseTable", "course1:" + _tmp_1.getCourse_name()
						+ "course2:" + _tmp_2.getCourse_name());
				_generate_str += "课程冲突!";
			} else {
				// 单双周不冲突
				_generate_str += _tmp_1.getCourse_name()
						+ " " + generateSubStrByFeq(_tmp_1.getCourse_time_week().getCourse_freq(_week_day));
				_generate_str += _tmp_2.getCourse_name() 
						+ " " + generateSubStrByFeq(_tmp_2.getCourse_time_week().getCourse_freq(_week_day));
			}
		}else{
			//课程冲突
			/*_generate_str += "课程 ";
			for(int _index = 0 ; _index < _list.size() ; ++_index){
				_generate_str += _list.elementAt(_index).getCourse_name() + " ";
			}
			_generate_str += "存在冲突!";*/
			_generate_str += "此时间存在严重冲突! 为避免恶意行为,请先解决冲突再继续选课!";
		}
		if(_generate_str == "") _generate_str += "--";
		return _generate_str;
	}

	private static String generateSubStrByFeq(int _feq) {
		String _sub = "";
		DebugClass.debug_info("CourseTable", "the feq is : " + _feq);
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
			//_sub += "<每周>";
		}
		return _sub;
	}
}
