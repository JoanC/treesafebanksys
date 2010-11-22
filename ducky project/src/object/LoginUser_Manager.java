package object;


import object.*;
import dbquery.DBOperation;

//用于在登录和注销的用例中进行数据库的查询和写入操作.
public class LoginUser_Manager {
	private static LoginQueryInfo sendLoginInfoToDB(LoginReqDB reqDb){
		LoginQueryInfo tmpInfo = new LoginQueryInfo();
		
		String driverName = "com.microsoft.sqlserver.jdbc.SQLServerDriver" ;
		String url = "jdbc:sqlserver://192.168.0.140:1433; DatabaseName=J2EE_Course_Selecting_Sys" ;
		String userName = "j2eeServletUser" ;
		String pwd = "321" ;
		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(driverName, url, userName, pwd) ;
		
		LoginUser lu = dbo.doLoginQuery(reqDb.getU_id()) ;
		User user = dbo.doUserQuery(reqDb.getU_id()) ;
		
		if(lu != null){
			dbo.doUpdateIsLogin(reqDb.getU_id(),true) ; // set the flag of login to be true 
			tmpInfo.setU_pwd(lu.getU_pwd());
			tmpInfo.setU_isLogin(true);
			tmpInfo.setU_id(user.getU_id());
			tmpInfo.setU_type(user.getU_type());
			tmpInfo.setExp(null);
		}else{
			//id not exist!!!
			tmpInfo.setU_isLogin(false);
		}

		dbo.disconnectDB();

		return tmpInfo;
	}
	
	private static LogoutQueryInfo sendLogoutInfoToDB(LogoutReqDB reqDb){
		LogoutQueryInfo tmpInfo = new LogoutQueryInfo();
		
		String driverName = "com.microsoft.sqlserver.jdbc.SQLServerDriver" ;
		String url = "jdbc:sqlserver://192.168.0.140:1433; DatabaseName=J2EE_Course_Selecting_Sys" ;
		String userName = "j2eeServletUser" ;
		String pwd = "321" ;
		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(driverName, url, userName, pwd) ;
		
		LoginUser lu = dbo.doLoginQuery(reqDb.getU_id()) ;
		dbo.doUpdateIsLogin(reqDb.getU_id(), false) ; // set the flag of login to be true 
		
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
		
		LoginRltInfo rltInfo = new LoginRltInfo();
		rltInfo.setU_id(queryInfo.getU_id());
		rltInfo.setU_type(queryInfo.getU_type());
		rltInfo.setIs_succ(queryInfo.isU_isLogin());
		rltInfo.setExp(queryInfo.getExp());
		
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
