package dbquery;

import java.util.Vector;

/*
 * created by Sun 2010-12-1 
 * modified by Sun 2010-12-14
 * */


public class CourseTimeOperation
{
	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;

	// should not larger than 25 ;
	static public int convert2Day(int time)
	{
		int sample = 1;
		sample <<= 31;

		int day = 0;
		for (day = 0; day < 7; ++day)
		{
			if (sample == (time & sample))
				break;
			time <<= 1;
		}

		System.out.println("day : " + (day + 1));
		return day;
	}

	static public boolean isConflict(int time1, int time2)
	{
		if (convert2Day(time1) != convert2Day(time2))
			return false;

		int com = time1 & time2;
		for (int i = 0; i < MAX_NUM_OF_COURSES_PER_DAY; ++i)
		{
			if (1 == (1 & com))
				return true;
			com >>= 1;
		}
		return false;
	}

	static public Vector<Boolean> Convert2Detail(int time)
	{
		Vector<Boolean> rtn = new Vector<Boolean>();
		int sample = 1;
		for (int i = MAX_NUM_OF_COURSES_PER_DAY ; i > 0 ; --i )
		{
			Boolean buf = new Boolean((sample & time) == sample) ;
			rtn.addElement(buf) ;
			sample <<= 1 ;
		}
		return rtn;
	}
}