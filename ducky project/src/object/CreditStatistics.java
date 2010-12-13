package object;


import java.util.Vector;
import object.StudentPerformance;
import object.CreditStatisticInfo;


//这个类负责学生学分的统计工作
public class CreditStatistics {
	String u_id;									//要统计学分的学生的用户id
	Vector<StudentPerformance>	performance_list;	//该学生的所有选修的课程表现列表
	
	public String getU_id() {
		return u_id;
	}
	
	public void setU_id(String uId) {
		u_id = uId;
	}
	
	public Vector<StudentPerformance> getPerformance_list() {
		return performance_list;
	}
	
	public void setPerformance_list(Vector<StudentPerformance> performanceList) {
		performance_list = performanceList;
	}
	
	//学生学分统计函数接口
	public CreditStatisticInfo statistic(){
		CreditStatisticInfo credit_statistic_info = new CreditStatisticInfo();
		//统计工作...
		return credit_statistic_info;
	}
}
