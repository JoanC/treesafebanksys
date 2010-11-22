package object;


import object.*;
import dbquery.DBOperation;

//用于在登录和注销的用例中进行数据库的查询和写入操作.
public class LoginUser_Manager {
	private static LoginQueryInfo sendLoginInfoToDB(LoginReqDB reqDb){
		LoginQueryInfo queryInfo = new LoginQueryInfo();
		
		//连接数据库的参数
		//要么存在一个全局数据集中,要么放在连接函数中
		String driverName = "com.microsoft.sqlserver.jdbc.SQLServerDriver" ;
		String url = "jdbc:sqlserver://192.168.0.145:1433; DatabaseName=J2EE_Course_Selecting_Sys" ;
		String userName = "j2eeServletUser" ;
		String dbPwd = "321" ;
		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(driverName, url, userName, dbPwd) ;
		
		LoginUser lu = dbo.doLoginQuery(reqDb.getU_id()) ;
		User user = dbo.doUserQuery(reqDb.getU_id()) ;
		
		if(lu != null){
			//get the data from database to the query information
			DebugClass.debug_info("Login modle", "connect the DB success!");
			DebugClass.debug_info("Login modle", "get the user information!");
			queryInfo.setU_pwd(lu.getU_pwd());
			queryInfo.setU_id(user.getU_id());
			queryInfo.setU_isLogin(lu.isU_isLogin());
/*
			if(lu.getU_pwd() == pwd){
				queryInfo.setU_isLogin(true);
			}else{
				queryInfo.setU_isLogin(false);
			}
	*/		
			queryInfo.setU_type(user.getU_type());
		}
		else{
			//id not exist!!!
			//queryInfo.setU_isLogin(false);
			DebugClass.debug_info("Login modle", "no user");
			queryInfo.setU_type(0);//0 stands for the null
			queryInfo.setU_id(null);
		}
		//dbo.doUpdateIsLogin(reqDb.getU_id(),queryInfo.isU_isLogin()) ; // set the flag of login to be true 
		dbo.disconnectDB();
		return queryInfo;
	}
	
	private static LoginRltInfo LoginCheck(LoginInputInfo _input , LoginQueryInfo _query){
		//察看是否存在用户
		LoginRltInfo _rlt = new LoginRltInfo();
		_rlt.setU_id(_query.getU_id());
		if(_query.getU_id() == null){
			//用户不存在的处理函式..
			//_rlt.setExp("用户不存在!");
			_rlt.setIs_succ(false);
		}
		else if(_query.getU_pwd() != _input.getU_pwd()){
			//密码错误处理函式
			_rlt.setIs_succ(false);
		}
		else{
			//登陆正确
			_rlt.setIs_succ(true);
		}
		return _rlt;
	}
	
	private static LogoutQueryInfo sendLogoutInfoToDB(LogoutReqDB reqDb){
		LogoutQueryInfo tmpInfo = new LogoutQueryInfo();
		
		String driverName = "com.microsoft.sqlserver.jdbc.SQLServerDriver" ;
		String url = "jdbc:sqlserver://192.168.0.145:1433; DatabaseName=J2EE_Course_Selecting_Sys" ;
		String userName = "j2eeServletUser" ;
		String pwd = "321" ;
		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(driverName, url, userName, pwd) ;
		
		LoginUser lu = dbo.doLoginQuery(reqDb.getU_id()) ;
		
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
		reqDb.setU_id(inputInfo.getU_id());
		LoginQueryInfo queryInfo = sendLoginInfoToDB(reqDb);
		LoginRltInfo rltInfo = LoginCheck(inputInfo,queryInfo);
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
