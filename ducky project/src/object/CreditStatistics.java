package object;


import java.util.Vector;
import object.StudentPerformance;
import object.CreditStatisticInfo;


//����ฺ��ѧ��ѧ�ֵ�ͳ�ƹ���
public class CreditStatistics {
	String u_id;									//Ҫͳ��ѧ�ֵ�ѧ�����û�id
	Vector<StudentPerformance>	performance_list;	//��ѧ��������ѡ�޵Ŀγ̱����б�
	
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
	
	//ѧ��ѧ��ͳ�ƺ����ӿ�
	public CreditStatisticInfo statistic(){
		CreditStatisticInfo credit_statistic_info = new CreditStatisticInfo();
		//ͳ�ƹ���...
		return credit_statistic_info;
	}
}
