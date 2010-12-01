package dbquery;

import java.util.ArrayList;



public class CourseTimeOperation
{
	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11 ;
	// should not larger than 25 ;
	static public int convert2Day(int data)
	{
		int sample = 1 ;
		sample  <<=  31 ;
		
		int day = 0 ;
		for ( day = 0 ; day < 7 ; ++day  )
		{
			if  ( sample == ( data & sample ) )
				break ;
			data <<= 1 ;
		}
		
		System.out.println("day : " + (day+1) ) ;
		return day ;
	}
	static public boolean isConflict(int time1,int time2) 
	{
		if ( convert2Day(time1) != convert2Day(time2) )
			return false ;
		
		int com = time1 & time2 ;
		for ( int i = 0 ; i < MAX_NUM_OF_COURSES_PER_DAY ; ++i )
		{
			if ( 1 == ( 1 & com ) )
				return true ;
			com >>= 1 ;
		}
		return false ;
	}
	static public ArrayList CourseTimeOperation() 
	{
		ArrayList rtn = new ArrayList() ;
		for ( int i = MAX_NUM_OF_COURSES_PER_DAY ; i > 0 ; --i )
		{
			
		}
		return rtn ;
	}
}
