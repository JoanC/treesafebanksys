package object;


import db_data_structure.LoginInputInfo;
import db_data_structure.LoginQueryInfo;
import db_data_structure.LoginUser;
import db_data_structure.User;
import dbquery.DBOperation;
import dbquery.dbConnectParam;


//�����ڵ�¼��ע��������н�����ݿ�Ĳ�ѯ��д�����.
public class LoginUser_Manager {
	private static LoginQueryInfo sendLoginInfoToDB(LoginReqDB reqDb){
		LoginQueryInfo queryInfo = new LoginQueryInfo();
		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		
		LoginUser lu = dbo.doQueryLogin(reqDb.getU_id()) ;
		User user = dbo.doQueryUser(reqDb.getU_id()) ;
		if(lu.getU_id() != null){
			//get the data from database to the query information
			DebugClass.debug_info("Login modle", "connect the DB success!");
			DebugClass.debug_info("Login modle", "get the user information!");
			queryInfo.setU_pwd(lu.getU_pwd());
			queryInfo.setU_id(user.getU_id());
			queryInfo.setU_isLogin(lu.isU_isLogin());
			queryInfo.setU_type(user.getU_type());
			DebugClass.debug_info("Login modle", "user id : " + lu.getU_id());
			DebugClass.debug_info("Login modle", "user password : " + lu.getU_pwd());
			DebugClass.debug_info("Login modle", "user is : " + (lu.isU_isLogin() ? "online" : "offline") + " now");
			DebugClass.debug_info("Login modle","user type is : " + user.getU_type());
		}
		else{
			//id not exist!!!
			//queryInfo.setU_isLogin(false);
			DebugClass.debug_info("Login modle", "user_id " + reqDb.getU_id() + " can not find!");
			queryInfo.setU_type(0);//0 stands for the null
			queryInfo.setU_id(null);
		}
		//dbo.doUpdateIsLogin(reqDb.getU_id(),queryInfo.isU_isLogin()) ; // set the flag of login to be true 
		dbo.disconnectDB();
		return queryInfo;
	}
	
	private static LoginRltInfo LoginCheck(LoginInputInfo _input , LoginQueryInfo _query){
		//�쿴�Ƿ�����û�
		LoginRltInfo _rlt = new LoginRltInfo();
		_rlt.setU_id(_query.getU_id());
		if(_query.getU_id() == null){
			//�û������ڵĴ��?ʽ..
			//_rlt.setExp("�û�������!");
			DebugClass.debug_info("Login modle", "user not exist!");
			_rlt.setIs_succ(false);
		}
		else if(!_query.getU_pwd().equals(_input.getU_pwd())){
			//��������?ʽ
			DebugClass.debug_info("Login modle", "password not correct!");
			_rlt.setIs_succ(false);
		}
		else if(_query.isU_isLogin()){
			DebugClass.debug_info("Login modle", "the user is online now , login request reject!");
			_rlt.setIs_succ(false);
		}
		else{ 
			//��½��ȷ
			DebugClass.debug_info("Login modle", "login data check done!");
			_rlt.setIs_succ(true);
			_rlt.setU_type(_query.getU_type());
		}
		return _rlt;
	}
	
	private static LogoutQueryInfo sendLogoutInfoToDB(LogoutReqDB reqDb){
		LogoutQueryInfo tmpInfo = new LogoutQueryInfo();

		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		
		LoginUser lu = dbo.doQueryLogin(reqDb.getU_id()) ;
		
		if(lu != null){
			dbo.doUpdateIsLogin(reqDb.getU_id(), false) ; // set the flag of login to be true
		}
		
		dbo.disconnectDB() ;
		
		tmpInfo.setU_id(lu.getU_id());
		tmpInfo.setIs_succ(true);
		tmpInfo.setExp(null);
		
		return tmpInfo;
	}
	
	public static LoginRltInfo login(LoginInputInfo inputInfo){
		LoginReqDB reqDb = new LoginReqDB();
		DebugClass.debug_info("Login modle", "user input id is : " + inputInfo.getU_id() + " user input password is : " + inputInfo.getU_pwd());
		reqDb.setU_id(inputInfo.getU_id());
		LoginQueryInfo queryInfo = sendLoginInfoToDB(reqDb);
		DebugClass.debug_info("Login modle", "user input id is : " + queryInfo.getU_id());
		LoginRltInfo rltInfo = LoginCheck(inputInfo,queryInfo);
		//����½�ɹ�,�򽫵�ǰ���û�����״̬��Ϊonline
		/*
		 * �˴�ע����!
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		dbo.connectDB(driverName, url, userName, dbPwd) ;
		
		if(rltInfo.isIs_succ()){
			dbo.doUpdateIsLogin(rltInfo.getU_id(), true);
		}
		dbo.disconnectDB();
		*/
		return rltInfo;
	}
	
	public static LogoutRltInfo logout(LogoutInfo info){
		LogoutReqDB reqDb = new LogoutReqDB();
		reqDb.setU_id(info.getU_id());
		LogoutQueryInfo queryInfo = sendLogoutInfoToDB(reqDb);
		LogoutRltInfo rltInfo = new LogoutRltInfo();
		rltInfo.setExp(queryInfo.getExp());
		rltInfo.setIs_succ(queryInfo.isIs_succ());
		return rltInfo;
	}
}
