package object;


import db_data_structure.PointGoal;
import dbquery.*;


//����ฺ�������ƻ����ݵĴ���������һ�����Ҳ������޸ı��������
//�ֱ����ڡ�ѧ��ͳ�ơ��͡��γ������ƻ��༭����������
public class PointGoal_Manager {
	//����ѧԺ�ı�ʶ�����ȡ�����ƻ�����
	static public PointGoal SearchPointGoal(int _school_id){
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd);
		PointGoal point_goal = dbo.doQueryPointGoalFromTbPG(_school_id);
		dbo.disconnectDB();
		return point_goal;
	}
	
	//�༭�����ƻ�������
	static public Exp EditPointGoal(PointGoal _old, PointGoal _new){
		Exp exp = new Exp();
		//DB options...
		return exp;
	}
}
