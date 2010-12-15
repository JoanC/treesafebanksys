package dbquery;

import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import db_data_structure.Week;
import db_data_structure.enCourseFreq;

/*
 * created by Sun 2010-12-1 
 * modified by Sun 2010-12-14
 * modified by Sun 2010-12-15
 * */
public class CourseTimeOperation {
	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;

	static public Map<Integer, Vector<Boolean>> convert2Detail(Week oneWeek) {
		Map<Integer, Vector<Boolean>> rtn = new HashMap<Integer, Vector<Boolean>>();
		int[] time = { oneWeek.getCourse_time_mon(),
				oneWeek.getCourse_time_tues(), oneWeek.getCourse_time_wed(),
				oneWeek.getCourse_time_thur(), oneWeek.getCourse_time_fri(),
				oneWeek.getCourse_time_sat(), oneWeek.getCourse_time_sun() };

		for (int i = 0; i < 7; ++i) // 7��
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

		for (int i = 0; i < 7; ++i) {

			boolean flag = (lfreq[i] == enCourseFreq.EVERY_WEEK || rfreq[i] == enCourseFreq.EVERY_WEEK) // ��һ����ÿ�ܶ��е�
					|| (lfreq[i] == enCourseFreq.ODD_WEEK && rfreq[i] == enCourseFreq.ODD_WEEK) // ���ǵ���
					|| (lfreq[i] == enCourseFreq.EVEN_WEEK && rfreq[i] == enCourseFreq.EVEN_WEEK); // ����˫��
			/* ���������������Ҫ�����жϵ� */
			if (flag) {
				if ((ltime[i] & rtime[i]) != 0) // �����ͻ
				{
					Vector<Boolean> vecbuff = new Vector<Boolean>();
					int buff = ltime[i] & rtime[i];
					int sample = 1;
					for (int j = 0; j < MAX_NUM_OF_COURSES_PER_DAY; ++j) {
						Boolean boobuff = new Boolean((buff & sample) == sample);
						vecbuff.addElement(boobuff);
						sample <<= 1; // ����һλ
					}
					rtn.put(new Integer(i), vecbuff);
				}
			}
		}
		return rtn;
	}
}