package dbquery;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import javax.annotation.Generated;

import db_data_structure.Week;
import db_data_structure.enCourseFreq;

/*
 * created by Sun 2010-12-1 
 * modified by Sun 2010-12-14
 * modified by Sun 2010-12-15
 * */
public class CourseTimeOperation {
	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;
	private static final int WEEK_DAYS = 7;

	static public String dateToString(Week _oneWeek){
		String _rlt = "";
		//将时间地图转化为string类型
		Map<Integer, Vector<Boolean>> _all = CourseTimeOperation.convert2Detail(_oneWeek);
		//首先判定周几有课
		Vector<Integer> _days_have_course = new Vector<Integer>();
		for(int _index = 0 ; _index < WEEK_DAYS ; ++_index){
			if(_all.containsKey(_index) == true){
				//发现有课
				_days_have_course.add(_index);
			}
		}
		//根据每天,判定那些节数有课,并对应生成字符串
		//注意生成字符串时需要单双周的信息
		for(int _index = 0 ; _index < _days_have_course.size();++_index){
			//逐一取出
		    String _one_day_time_str = "";
		    int _day = _days_have_course.elementAt(_index);
		    _one_day_time_str += generate_week_string(_day, _oneWeek) + "第 ";
		    Vector<Boolean> _day_times = _all.get(_day);
		    for(int _j = 0 ; _j <  _day_times.size() ; ++_j){
		    	if(_day_times.elementAt(_j) == true){
		    		//表示此时有课
		    		_one_day_time_str += (_j+1) + " ";
		    	}
		    }
		    _one_day_time_str += " 节";
		    _rlt += _one_day_time_str;
		}
		System.out.println(_rlt);
		return _rlt;
	}
	
	private static String generate_week_string(int _week_day,Week _oneWeek){
		String _week_day_string = "周" + (_week_day+1);
		//判断单双周
		int _feq = _oneWeek.getCourse_freq(_week_day+1);
		if(_feq == enCourseFreq.NONE){
			_week_day_string += "<" + "次时间段暂停" + ">";
		}
		else if(_feq == enCourseFreq.EVERY_WEEK){
			_week_day_string += "<" + "每周" + ">";
		}
		else if (_feq == enCourseFreq.ODD_WEEK){
			_week_day_string += "<" + "单周"  + ">";
		}
		else{
			_week_day_string += "<" + "双周" + ">";
		}
		return _week_day_string;
	} 
	
	static public Map<Integer, Vector<Boolean>> convert2Detail(Week oneWeek) {
		Map<Integer, Vector<Boolean>> rtn = new HashMap<Integer, Vector<Boolean>>();
		int[] time = { oneWeek.getCourse_time_mon(),
				oneWeek.getCourse_time_tues(), oneWeek.getCourse_time_wed(),
				oneWeek.getCourse_time_thur(), oneWeek.getCourse_time_fri(),
				oneWeek.getCourse_time_sat(), oneWeek.getCourse_time_sun() };
		for (int i = 0; i < WEEK_DAYS; ++i) // 7天
		{
			if (0 != time[i])// 如果这天有课
			{
				Vector<Boolean> temp = new Vector<Boolean>();
				int sample = 1;
				for (int j = MAX_NUM_OF_COURSES_PER_DAY; j > 0; --j) // MAX_NUM_OF_COURSES_PER_DAY
				// 节课
				{
					Boolean buff = new Boolean((sample & time[i]) == sample);
					temp.addElement(buff);
					sample <<= 1;
				}
				rtn.put(i, temp);
			}
		}
		return rtn;
	}

	static public Map<Integer, Vector<Boolean>> isConflict(Week lhs, Week rhs) // 输入参数为两节课的时间表
	{
		Map<Integer, Vector<Boolean>> rtn = new HashMap<Integer, Vector<Boolean>>();
		int[] ltime = { lhs.getCourse_time_mon(), lhs.getCourse_time_tues(),
				lhs.getCourse_time_wed(), lhs.getCourse_time_thur(),
				lhs.getCourse_time_fri(), lhs.getCourse_time_sat(),
				lhs.getCourse_time_sun() };

		int[] rtime = { rhs.getCourse_time_mon(), rhs.getCourse_time_tues(),
				rhs.getCourse_time_wed(), rhs.getCourse_time_thur(),
				rhs.getCourse_time_fri(), rhs.getCourse_time_sat(),
				rhs.getCourse_time_sun() };

		int[] lfreq = { lhs.getCourse_mon_freq(), lhs.getCourse_tues_freq(),
				lhs.getCourse_wed_freq(), lhs.getCourse_thur_freq(),
				lhs.getCourse_fri_freq(), lhs.getCourse_sat_freq(),
				lhs.getCourse_sun_freq(), };

		int[] rfreq = { rhs.getCourse_mon_freq(), rhs.getCourse_tues_freq(),
				rhs.getCourse_wed_freq(), rhs.getCourse_thur_freq(),
				rhs.getCourse_fri_freq(), rhs.getCourse_sat_freq(),
				rhs.getCourse_sun_freq(), };

		for (int i = 0; i < WEEK_DAYS; ++i) {

			boolean flag = (lfreq[i] == enCourseFreq.EVERY_WEEK || rfreq[i] == enCourseFreq.EVERY_WEEK) // 有一个是每周都有的
					|| (lfreq[i] == enCourseFreq.ODD_WEEK && rfreq[i] == enCourseFreq.ODD_WEEK) // 都是单周
					|| (lfreq[i] == enCourseFreq.EVEN_WEEK && rfreq[i] == enCourseFreq.EVEN_WEEK); // 都是双周
			/* 以上三种情况是需要进行判断的 */
			if (flag) {
				if ((ltime[i] & rtime[i]) != 0) // 如果冲突
				{
					Vector<Boolean> vecbuff = new Vector<Boolean>();
					int buff = ltime[i] & rtime[i];
					int sample = 1;
					for (int j = 0; j < MAX_NUM_OF_COURSES_PER_DAY; ++j) {
						Boolean boobuff = new Boolean((buff & sample) == sample);
						vecbuff.addElement(boobuff);
						sample <<= 1; // 左移一位
					}
					rtn.put(new Integer(i+1), vecbuff);
				}
			}
		}
		return rtn;
	}
}