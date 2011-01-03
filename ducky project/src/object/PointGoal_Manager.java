package object;


import db_data_structure.PointGoal;
import dbquery.DBOperation;
import dbquery.dbConnectParam;


//����ฺ������ƻ���ݵĴ��?����һ�����Ҳ������޸ı��������
//�ֱ����ڡ�ѧ��ͳ�ơ��͡��γ�����ƻ��༭����������
public class PointGoal_Manager {
	//���ѧԺ�ı�ʶ�����ȡ����ƻ����
	static public PointGoal SearchPointGoal(int _school_id){
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd);
		PointGoal point_goal = dbo.doQueryPointGoalFromTbPG(_school_id);
		dbo.disconnectDB();
		return point_goal;
	}
	
	//�༭����ƻ�������
	static public Exp EditPointGoal(PointGoal _new){
		Exp exp = new Exp();
		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd);
		dbo.doUpdatePointGoalFromTabPG(_new);
		dbo.disconnectDB();
		
		return exp;
	}
}
