package dbquery;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import sun.org.mozilla.javascript.internal.ObjToIntMap.Iterator;

import db_data_structure.Course;
import db_data_structure.Week;
import db_data_structure.enCourseFreq;

/*
 * created by Sun 2010-12-1 
 * modified by Sun 2010-12-14
 * modified by Sun 2010-12-15
 * modified by Sun 2010-12-30
 * */
public class CourseTimeOperation {
	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;
	private static final int WEEK_DAYS = 7 ;

	static public String dateToString(Week _oneWeek){
		String _rlt = "";
		//��ʱ���ͼת��Ϊstring����
		Map<Integer, Vector<Boolean>> _all = CourseTimeOperation.convert2Detail(_oneWeek);
		//�����ж��ܼ��п�
		Vector<Integer> _days_have_course = new Vector<Integer>();
		for(int _index = 0 ; _index < WEEK_DAYS ; ++_index){
			if(_all.containsKey(_index) == true){
				//�����п�
				_days_have_course.add(_index);
			}
		}
		//���ÿ��,�ж���Щ�����п�,����Ӧ����ַ�
		//ע������ַ�ʱ��Ҫ��˫�ܵ���Ϣ
		for(int _index = 0 ; _index < _days_have_course.size();++_index){
			//��һȡ��
		    String _one_day_time_str = "";
		    int _day = _days_have_course.elementAt(_index);
		    _one_day_time_str += generate_week_string(_day, _oneWeek) + "�� ";
		    Vector<Boolean> _day_times = _all.get(_day);
		    for(int _j = 0 ; _j <  _day_times.size() ; ++_j){
		    	if(_day_times.elementAt(_j) == true){
		    		//��ʾ��ʱ�п�
		    		_one_day_time_str += (_j+1) + " ";
		    	}
		    }
		    _one_day_time_str += " ��";
		    _rlt += _one_day_time_str;
		}
		System.out.println(_rlt);
		return _rlt;
	}
	
	private static String generate_week_string(int _week_day,Week _oneWeek){
		String _week_day_string = "��" + (_week_day+1);
		//�жϵ�˫��
		int _feq = _oneWeek.getCourse_freq(_week_day+1);
		if(_feq == enCourseFreq.NONE){
			_week_day_string += "<" + "��ʱ�����ͣ" + ">";
		}
		else if(_feq == enCourseFreq.EVERY_WEEK){
			_week_day_string += "<" + "ÿ��" + ">";
		}
		else if (_feq == enCourseFreq.ODD_WEEK){
			_week_day_string += "<" + "����"  + ">";
		}
		else{
			_week_day_string += "<" + "˫��" + ">";
		}
		return _week_day_string;
	} 
	
	static public Map<Integer, Vector<Boolean>> convert2Detail(Week oneWeek) {
		Map<Integer, Vector<Boolean>> rtn = new HashMap<Integer, Vector<Boolean>>();
		int[] time = { oneWeek.getCourse_time_mon(),
				oneWeek.getCourse_time_tues(), oneWeek.getCourse_time_wed(),
				oneWeek.getCourse_time_thur(), oneWeek.getCourse_time_fri(),
				oneWeek.getCourse_time_sat(), oneWeek.getCourse_time_sun() };
		for (int i = 0; i < WEEK_DAYS; ++i) // 7��
		{
			if (0 != time[i])// ��������п�
			{
				Vector<Boolean> temp = new Vector<Boolean>();
				int sample = 1;
				for (int j = MAX_NUM_OF_COURSES_PER_DAY; j > 0; --j) // MAX_NUM_OF_COURSES_PER_DAY
				// �ڿ�
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

	static public Map<Integer, Vector<Boolean>> isConflict(Week lhs, Week rhs) // �������Ϊ���ڿε�ʱ���
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

			boolean flag = (lfreq[i] == enCourseFreq.EVERY_WEEK || rfreq[i] == enCourseFreq.EVERY_WEEK) // ��һ����ÿ�ܶ��е�
					|| (lfreq[i] == enCourseFreq.ODD_WEEK && rfreq[i] == enCourseFreq.ODD_WEEK) // ���ǵ���
					|| (lfreq[i] == enCourseFreq.EVEN_WEEK && rfreq[i] == enCourseFreq.EVEN_WEEK); // ����˫��
			/* ���������������Ҫ�����жϵ� */
			if (flag) {
				if ((ltime[i] & rtime[i]) != 0) // ����ͻ
				{
					Vector<Boolean> vecbuff = new Vector<Boolean>();
					int buff = ltime[i] & rtime[i];
					int sample = 1;
					for (int j = 0; j < MAX_NUM_OF_COURSES_PER_DAY; ++j) {
						Boolean boobuff = new Boolean((buff & sample) == sample);
						vecbuff.addElement(boobuff);
						sample <<= 1; // ����һλ
					}
					rtn.put(new Integer(i+1), vecbuff);
				}
			}
		}
		return rtn;
	}
	static private int convertOneDay(Vector<Boolean> data , int start_index)
	{
		int rtn = 0 ;
		for (int i = 0 ; i < MAX_NUM_OF_COURSES_PER_DAY ; ++i )
		{
			int temp = 1 ;
			if ( data.elementAt(start_index + i) )
				temp <<= i ; //左移i位
			rtn += temp ;
		}
		return rtn ;
	}
	static public Week convert2Course(Vector<Boolean> data,Vector<Integer> freq)
	{
		Week rtn = new Week() ;
		for ( int i = 0 ; i < WEEK_DAYS ; ++i )
		{
			int buf = convertOneDay( data , i * MAX_NUM_OF_COURSES_PER_DAY ) ;
			switch( i )
			{
			case 0 :
				rtn.setCourse_time_mon(buf) ;
				rtn.setCourse_mon_freq(freq.elementAt(i)) ;
				break ;
			case 1 :
				rtn.setCourse_time_tues(buf) ;
				rtn.setCourse_tues_freq(freq.elementAt(i)) ;
				break ;
			case 2 :
				rtn.setCourse_time_wed(buf) ;
				rtn.setCourse_wed_freq(freq.elementAt(i)) ;
				break ;
			case 3 :
				rtn.setCourse_time_thur(buf) ;
				rtn.setCourse_thur_freq(freq.elementAt(i)) ;
				break ;
			case 4 :
				rtn.setCourse_time_fri(buf) ;
				rtn.setCourse_fri_freq(freq.elementAt(i)) ;
				break ;
			case 5 :
				rtn.setCourse_time_sat(buf) ;
				rtn.setCourse_sat_freq(freq.elementAt(i)) ;
				break ;
			case 6 :
				rtn.setCourse_time_sun(buf) ;
				rtn.setCourse_sun_freq(freq.elementAt(i)) ;
				break ;
			default :
				break ;	
			}
		}
		
		return rtn ; 
	}
}