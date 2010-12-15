package db_data_structure;

public class Week {
	private int course_time_mon; // 星期一的课
	private int course_mon_freq ;
	private int course_time_tues; // ..二..
	private int course_tues_freq ;
	private int course_time_wed; // ..三...
	private int course_wed_freq ;
	private int course_time_thur; // ..四...
	private int course_thur_freq ;
	private int course_time_fri; // ..五..
	private int course_fri_freq ;
	private int course_time_sat; // ..六..
	private int course_sat_freq ;
	private int course_time_sun; // ..日..
	private int course_sun_freq ;
	

	
	public int getCourse_mon_freq() {
		return course_mon_freq;
	}

	public void setCourse_mon_freq(int courseMonFreq) {
		course_mon_freq = courseMonFreq;
	}

	public int getCourse_tues_freq() {
		return course_tues_freq;
	}

	public void setCourse_tues_freq(int courseTuesFreq) {
		course_tues_freq = courseTuesFreq;
	}

	public int getCourse_wed_freq() {
		return course_wed_freq;
	}

	public void setCourse_wed_freq(int courseWedFreq) {
		course_wed_freq = courseWedFreq;
	}

	public int getCourse_thur_freq() {
		return course_thur_freq;
	}

	public void setCourse_thur_freq(int courseThurFreq) {
		course_thur_freq = courseThurFreq;
	}

	public int getCourse_fri_freq() {
		return course_fri_freq;
	}

	public void setCourse_fri_freq(int courseFriFreq) {
		course_fri_freq = courseFriFreq;
	}

	public int getCourse_sat_freq() {
		return course_sat_freq;
	}

	public void setCourse_sat_freq(int courseSatFreq) {
		course_sat_freq = courseSatFreq;
	}

	public int getCourse_sun_freq() {
		return course_sun_freq;
	}

	public void setCourse_sun_freq(int courseSunFreq) {
		course_sun_freq = courseSunFreq;
	}

	public int getCourse_freq(int index) {
		switch(index){
		case 1:
			return course_mon_freq;

		case 2:
			return course_tues_freq;

		case 3:
			return course_wed_freq;
	
		case 4:
			return course_thur_freq;
	
		case 5:
			return course_fri_freq;
	
		case 6:
			return course_sat_freq;

		case 7 : 
			return course_sun_freq;

		default:
			return 0 ;
		}
	}

	public void setCourse_freq(int index,int value) {
		switch(index){
		case 1:
			course_mon_freq = value;
			break ;
		case 2:
			course_tues_freq = value;
			break ;
		case 3:
			course_wed_freq = value ;
			break ;
		case 4:
			course_thur_freq = value ;
			break ;
		case 5:
			course_fri_freq = value;
			break ;
		case 6:
			course_sat_freq = value;
			break ;
		case 7 : 
			course_sun_freq = value;
			break ;
		default:
			break ;
		}
	}
	
	public int getCourse_time_mon() {
		return course_time_mon;
	}

	public void setCourse_time_mon(int courseTimeMon) {
		course_time_mon = courseTimeMon;
	}

	public int getCourse_time_tues() {
		return course_time_tues;
	}

	public void setCourse_time_tues(int courseTimeTues) {
		course_time_tues = courseTimeTues;
	}

	public int getCourse_time_wed() {
		return course_time_wed;
	}

	public void setCourse_time_wed(int courseTimeWed) {
		course_time_wed = courseTimeWed;
	}

	public int getCourse_time_thur() {
		return course_time_thur;
	}

	public void setCourse_time_thur(int courseTimeThur) {
		course_time_thur = courseTimeThur;
	}

	public int getCourse_time_fri() {
		return course_time_fri;
	}

	public void setCourse_time_fri(int courseTimeFri) {
		course_time_fri = courseTimeFri;
	}

	public int getCourse_time_sat() {
		return course_time_sat;
	}

	public void setCourse_time_sat(int courseTimeSat) {
		course_time_sat = courseTimeSat;
	}

	public int getCourse_time_sun() {
		return course_time_sun;
	}

	public void setCourse_time_sun(int courseTimeSun) {
		course_time_sun = courseTimeSun;
	}
}
