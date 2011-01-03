package db_data_structure;

import java.sql.Date;


/*
 *	function : this class is a data structure which map the sql table TB_SYS_PARAM
 *	created by Sun 2010-12-21 
 * */
public class SysParam {
	boolean isCourseSelOpened = false ;
	int courseSelType = enCourseSelType.CST_NONE ;
	long openTime ;  // 格林威治时间
	long closeTime ;
	
public long getOpenTime() {
		return openTime;
	}
	public void setOpenTime(long openTime) {
		this.openTime = openTime;
	}
	public long getCloseTime() {
		return closeTime;
	}
	public void setCloseTime(long closeTime) {
		this.closeTime = closeTime;
	}
	public boolean isCourseSelOpened() {
		return isCourseSelOpened;
	}
	public void setCourseSelOpened(boolean isCourseSelOpened) {
		this.isCourseSelOpened = isCourseSelOpened;
	}
	public int getCourseSelType() {
		return courseSelType;
	}
	public void setCourseSelType(int courseSelType) {
		this.courseSelType = courseSelType;
	}

}
