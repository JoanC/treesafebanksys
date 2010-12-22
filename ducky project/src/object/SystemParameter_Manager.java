package object;

import db_data_structure.SysParam;
import dbquery.DBOperation;
import dbquery.dbConnectParam;




//����ฺ��ϵͳ���������úͲ�ѯ����
public class SystemParameter_Manager {
	//��ѯϵͳ����
	static public SysParam getSystemParameter(){
		SysParam system_parameter = new SysParam();
		//DB query...
		DBOperation dbo = new DBOperation();
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 system_parameter = dbo.doQuerySysParam();//��ѯ
		 dbo.disconnectDB();
		 return system_parameter;
	}
	
	//�༭�µ�ϵͳ������Ϣ
	static public Exp editSystemParameter(SysParam _new_config){
		Exp exp = new Exp();
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		dbo.doUpdateSysParam(_new_config);
		dbo.disconnectDB();
		return exp;
	}
}
