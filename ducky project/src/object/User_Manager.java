package object;

import db_data_structure.User;
import dbquery.DBOperation;
import dbquery.dbConnectParam;

public class User_Manager {
	//2010.12.14
	//����u_idȡ��һ���û��������Ϣ
	//����:Jiraiya
	public static User queryUserInfo(String u_id){
		User _info = new User();;
		DBOperation dbo = new DBOperation() ;
		DebugClass.debug_info("User_Manager", "start to query the user : " + u_id);
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		_info = dbo.doQueryUser(u_id) ;
		DebugClass.debug_info("User_Manager", "query the user name: " + _info.getU_name());
		dbo.disconnectDB();
		return _info;
	}
}
