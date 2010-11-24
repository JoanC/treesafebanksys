package dbquery;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import object.LoginUser;
import object.User;

import object.DebugClass;

public class DBOperation
{
	/************* member variables ***************/
	private Connection m_conn;

	
	/************* member methods ****************/
	public DBOperation()
	{}
	public DBOperation(String driverName, String url, String userName,
			String pwd)  
	{
		connectDB(driverName,url,userName,pwd) ;
	}

	public boolean connectDB(String driverName, String url, String userName,
			String pwd)
	{
		m_conn = null;
		try
		{
			Class.forName(driverName);
			m_conn = DriverManager.getConnection(url, userName, pwd);
			m_conn.setAutoCommit(false);
			return true;
		} catch (Exception e)
		{
			//System.out.println("error : " + e);
			DebugClass.debug_info("DB","error : " + e);
			return false;
		}
	}
	public boolean disconnectDB()
	{
		try
		{
			m_conn.close() ;
			m_conn = null ;
			return true ;
		}catch(Exception e)
		{
			//System.err.println("error"+e) ;
			DebugClass.debug_info("DB","error : " + e);
			return false ;
		}
	}
	public LoginUser doLoginQuery(String uid)
	{
		LoginUser rtn = new LoginUser() ;
		
		try
		{
			String query_login = "SELECT * FROM TB_LOGIN WHERE U_ID=?" ;
			PreparedStatement ps_login = m_conn.prepareStatement(query_login);
			ps_login.setString(1, uid) ;
			/*some preparing work...*/
			
			ResultSet results  = ps_login.executeQuery() ;
			/*do query*/
			while ( results.next() ) {
				rtn.setU_id(results.getString("U_ID")) ;  
				rtn.setU_pwd(results.getString("U_PWD"))   ;
				rtn.setU_isLogin(results.getBoolean("U_IS_LOGIN"))  ;
				/*write to rtn*/
				
				results.close() ;
				/*close the resultset*/
				return rtn;
			}
			
		}catch(Exception e)
		{
			//System.err.println("error : " + e);
			DebugClass.debug_info("DB","error : " + e);
			return null;
		}
		return null;
	}
	public User doUserQuery(String uid)
	{
		User rtn = new User() ; 
		/*return value*/
	
		try
		{
			String query_login = "SELECT * FROM TB_USER WHERE U_ID=?" ;
			PreparedStatement ps_user = m_conn.prepareStatement(query_login);
			ps_user.setString(1, uid) ;
			/*some preparing work...*/
			
			ResultSet results  = ps_user.executeQuery() ;
			/*do query*/
			while ( results.next() ) {
				rtn.setU_id(results.getString("U_ID")) ;  
				rtn.setU_name(results.getString("U_NAME"))   ;
				rtn.setU_type(results.getInt("U_TYPE"))  ;
				rtn.setU_class(results.getInt("U_CLASS")) ;
				rtn.setU_school_id(results.getInt("U_SCHOOL_ID")) ;
				rtn.setU_grade(results.getInt("U_GRADE")) ;
				/*write to rtn*/
				
				results.close() ;
				/*close the resultset*/
				return rtn ;
			}
		}catch(Exception e)
		{
			//System.err.println("error : " + e);
			DebugClass.debug_info("DB","error : " + e);
			return null;
		}
		return null ;
	}
	
	public void doUpdateIsLogin(String uid,boolean isLogin)
	{
		try
		{
			String query_login = "UPDATE TB_LOGIN SET U_IS_LOGIN=? WHERE U_ID=?" ;
			
			PreparedStatement ps = m_conn.prepareStatement(query_login);
		
			ps.setString(1,isLogin ?   "true" : "false") ;
			ps.setString(2, uid) ;
			/*some preparing work...*/
			
			ps.executeUpdate() ;
			/*do update*/
			m_conn.commit() ;
		
		}catch(Exception e)
		{
			//System.err.println("error : " + e);
			DebugClass.debug_info("DB","error : " + e);
		}
	}
	
}

