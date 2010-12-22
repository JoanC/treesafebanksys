package object;

import db_data_structure.SysParam;
import dbquery.DBOperation;
import dbquery.dbConnectParam;




//这个类负责系统参数的设置和查询操作
public class SystemParameter_Manager {
	//查询系统参数
	static public SysParam getSystemParameter(){
		SysParam system_parameter = new SysParam();
		//DB query...
		DBOperation dbo = new DBOperation();
		 dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		 system_parameter = dbo.doQuerySysParam();//查询
		 dbo.disconnectDB();
		 return system_parameter;
	}
	
	//编辑新的系统配置信息
	static public Exp editSystemParameter(SysParam _new_config){
		Exp exp = new Exp();
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		dbo.doUpdateSysParam(_new_config);
		dbo.disconnectDB();
		return exp;
	}
}
