package dbquery;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Vector;

import object.DebugClass;
import db_data_structure.*;

/*
 * created by Sun 2010-11-?
 * modified by Sun 2010-11-?
 * modified by Sun 2010-11-?
 * modified by Sun 2010-11-?
 * modified by Sun 2010-12-1 
 * modified by Sun 2010-12-2
 * modified by Sun 2010-12-6
 * modified by Sun 2010-12-7
 * modified by Sun 2010-12-13
 * modified by Sun 2010-12-14
 */

public class DBOperation {
	/************* member variables ***************/
	private Connection m_conn;

	/************* member methods ****************/
	public DBOperation() {
	}

	public DBOperation(String driverName, String url, String userName,
			String pwd) {
		connectDB(driverName, url, userName, pwd);
	}

	public boolean connectDB(String driverName, String url, String userName,
			String pwd) {
		m_conn = null;
		try {
			Class.forName(driverName);
			m_conn = DriverManager.getConnection(url, userName, pwd);
			m_conn.setAutoCommit(false);
			return true;
		} catch (Exception e) {
			System.out.println("error : " + e);
			return false;
		}
	}

	public boolean disconnectDB() {
		try {
			m_conn.close();
			m_conn = null;
			return true;
		} catch (Exception e) {
			System.err.println("error" + e);
			return false;
		}
	}

	public LoginUser doQueryLogin(String uid) {
		LoginUser rtn = new LoginUser();

		try {
			String query_login = "SELECT * FROM TB_LOGIN WHERE U_ID=?";
			PreparedStatement ps_login = m_conn.prepareStatement(query_login);
			ps_login.setString(1, uid);
			/* some preparing work... */
			// System.out.println("query = "+ps_login.toString()) ;//for test
			ResultSet results = ps_login.executeQuery();
			/* do query */

			while (results.next()) {
				rtn.setU_id(results.getString("U_ID"));
				rtn.setU_pwd(results.getString("U_PWD"));
				rtn.setU_isLogin(results.getBoolean("U_IS_LOGIN"));
				/* write to rtn */
			}
			results.close();
			/* close the resultset */
			return rtn;

		} catch (Exception e) {
			System.err.println("error : " + e);
			return null;
		}
	}

	public User doQueryUser(String uid) {
		User rtn = new User();
		/* return value */

		try {
			String query_login = "SELECT * FROM TB_USER WHERE U_ID=?";
			PreparedStatement ps_user = m_conn.prepareStatement(query_login);
			ps_user.setString(1, uid);
			/* some preparing work... */

			ResultSet results = ps_user.executeQuery();
			/* do query */
			while (results.next()) {
				rtn.setU_id(results.getString("U_ID"));
				rtn.setU_name(results.getString("U_NAME"));
				rtn.setU_type(results.getInt("U_TYPE"));
				rtn.setU_class(results.getInt("U_CLASS"));
				rtn.setU_school_id(results.getInt("U_SCHOOL_ID"));
				rtn.setU_grade(results.getInt("U_GRADE"));
				/* write to rtn */

				results.close();
				/* close the resultset */
				return rtn;
			}
		} catch (Exception e) {
			System.err.println("error : " + e);
			return null;
		}
		return null;
	}

	public void doUpdateIsLogin(String uid, boolean isLogin) {
		DebugClass.debug_info(this.toString(), "update the isLogin...");
		DebugClass.debug_info(this.toString(), "the new data is : "
				+ (isLogin ? "is login" : "is not login"));
		try {
			String query_login = "UPDATE TB_LOGIN SET U_IS_LOGIN=? WHERE U_ID=?";

			PreparedStatement ps = m_conn.prepareStatement(query_login);

			ps.setString(1, isLogin ? "true" : "false");
			ps.setString(2, uid);
			/* some preparing work... */
			// System.out.println("query = "+ps) ;//for test
			ps.executeUpdate();
			/* do update */
			m_conn.commit();

		} catch (Exception e) {
			System.err.println("error : " + e);
		}
	}

	public Vector<Course> doQueryAllDistinctCourseName() {
		Vector<Course> rtn = new Vector<Course>();
		try {
			String query_course = "SELECT DISTINCT COURSE_NAME,COURSE_TYPE "
					+ "FROM TB_COURSE " + "ORDER BY COURSE_TYPE";
			PreparedStatement ps = m_conn.prepareStatement(query_course);
			/* some preparing work... */

			ResultSet results = ps.executeQuery();
			while (results.next()) {
				Course temp = new Course();

				// temp.setCourse_id(results.getString("COURSE_ID"));
				temp.setCourse_name(results.getString("COURSE_NAME"));
				temp.setCourse_type(results.getInt("COURSE_TYPE"));
				// temp.setU_id(results.getString("U_ID"));
				// temp.setCourse_point(results.getInt("COURSE_POINT"));
				// temp.setCourse_time(results.getInt("COURSE_TIME"));
				// temp.setCourse_place(results.getString("COURSE_PLACE"));
				// temp.setCourse_comment(results.getString("COURSE_COMMENT"));
				// temp.setCourse_volume(results.getInt("COURSE_VOLUME"));
				// temp.setCourse_current_seleted_num(results
				// .getInt("COURSE_CURRENT_SELECTED_NUM"));
				// temp.setCourse_exam_type(results.getInt("COURSE_EXAM_TYPE"));

				rtn.addElement(temp);
				/* write to rtn */
			}
			results.close();
			/* close the resultset */

		} catch (Exception e) {
			System.err.println("error : " + e);

		}
		return rtn;
	}

	private Vector<String> doQueryCourseID(String uid) {
		Vector<String> rtn = new Vector<String>();

		try {
			String query_course_id = "SELECT COURSE_ID FROM TB_COURSE_SELECT WHERE U_ID=?";
			PreparedStatement ps = m_conn.prepareStatement(query_course_id);
			ps.setString(1, uid);
			ResultSet results = ps.executeQuery();

			while (results.next()) {
				rtn.addElement(results.getString("COURSE_ID"));
				/* write to rtn */
			}
			results.close();
			/* close the resultset */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}

		return rtn;
	}

	private Course doMappingCourse(ResultSet results) {
		Course rtn = new Course();
		Week buff = new Week() ;
		try {
			rtn.setCourse_id(results.getString("COURSE_ID"));
			rtn.setCourse_name(results.getString("COURSE_NAME"));
			rtn.setCourse_type(results.getInt("COURSE_TYPE"));
			rtn.setU_id(results.getString("U_ID"));
			rtn.setCourse_point(results.getInt("COURSE_POINT"));
			rtn.setCourse_place(results.getString("COURSE_PLACE"));
			rtn.setCourse_comment(results.getString("COURSE_COMMENT"));
			rtn.setCourse_volume(results.getInt("COURSE_VOLUME"));
			rtn.setCourse_current_seleted_num(results
					.getInt("COURSE_CURRENT_SELECTED_NUM"));
			rtn.setCourse_exam_type(results.getInt("COURSE_EXAM_TYPE"));
			
			buff.setCourse_time_mon(results.getInt("COURSE_TIME_MON"));
			buff.setCourse_time_tues(results.getInt("COURSE_TIME_TUES"));
			buff.setCourse_time_wed(results.getInt("COURSE_TIME_WED"));
			buff.setCourse_time_thur(results.getInt("COURSE_TIME_THUR"));
			buff.setCourse_time_fri(results.getInt("COURSE_TIME_FRI"));
			buff.setCourse_time_sat(results.getInt("COURSE_TIME_SAT"));
			buff.setCourse_time_sun(results.getInt("COURSE_TIME_SUN"));
			
			buff.setCourse_mon_freq(results.getInt("COURSE_MON_FREQ")) ;
			buff.setCourse_tues_freq(results.getInt("COURSE_TUES_FREQ")) ;
			buff.setCourse_wed_freq(results.getInt("COURSE_WED_FREQ")) ;
			buff.setCourse_thur_freq(results.getInt("COURSE_THUR_FREQ")) ;
			buff.setCourse_fri_freq(results.getInt("COURSE_FRI_FREQ")) ;
			buff.setCourse_sat_freq(results.getInt("COURSE_SAT_FREQ")) ;
			buff.setCourse_sun_freq(results.getInt("COURSE_SUN_FREQ")) ;
			
			rtn.setCourse_time_week(buff) ;
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
		return rtn;
	}

	private Course doQueryCertainCourse(String course_id) {
		Course rtn = null;

		try {
			String query_course = "SELECT * " + "FROM TB_COURSE "
					+ "WHERE COURSE_ID=?";
			PreparedStatement ps = m_conn.prepareStatement(query_course);
			ps.setString(1, course_id);
			ResultSet results = ps.executeQuery();

			while (results.next()) {
				rtn = doMappingCourse(results);
				/* write to rtn */
			}
			results.close();
			/* close the resultset */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}

		return rtn;
	}

	public Vector<Course> doQueryPersonalCourse(String uid) {
		Vector<Course> rtn = new Vector<Course>();

		Vector<String> course_id = doQueryCourseID(uid);
		/* get all course id referred to this guy */

		for (int i = 0; i < course_id.size(); ++i) {
			rtn.add(doQueryCertainCourse(course_id.elementAt(i)));
		}

		return rtn;
	}

	public void doInsert2PreSelTab(PreCourseSelectInfo pcsi) {
		try {
			String sql_insert = "INSERT INTO " + "TB_PRE_COURSE_SELECT "
					+ "VALUES ( ? , ? )";
			PreparedStatement ps = m_conn.prepareStatement(sql_insert);
			ps.setString(1, pcsi.getUid());
			ps.setString(2, pcsi.getCourse_name());

			ps.executeUpdate();

			m_conn.commit(); /* commit it if there is no exception */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
	}

	public void doDeleteFromPreSelTab(PreCourseSelectInfo pcsi) {
		try {
			String sql_delete = "DELETE FROM " + "TB_PRE_COURSE_SELECT "
					+ "WHERE U_ID=? AND COURSE_NAME=?";
			PreparedStatement ps = m_conn.prepareStatement(sql_delete);

			ps.setString(1, pcsi.getUid());
			ps.setString(2, pcsi.getCourse_name());
			/* prepare sql string */
			ps.executeUpdate();

			m_conn.commit();/* commit it if there is no exception */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
	}

	public Vector<PreCourseSelectInfo> doQueryPreCourseInfoFromTabPreCourseSelectByID(
			String uid) {
		Vector<PreCourseSelectInfo> rtn = new Vector<PreCourseSelectInfo>();

		try {
			String query_course = "SELECT COURSE_NAME "
					+ "FROM TB_PRE_COURSE_SELECT " + "WHERE U_ID=?";
			PreparedStatement ps = m_conn.prepareStatement(query_course);
			ps.setString(1, uid);
			ResultSet results = ps.executeQuery();

			while (results.next()) {
				PreCourseSelectInfo buff = new PreCourseSelectInfo();
				buff.setUid(uid);
				buff.setCourse_name(results.getString("COURSE_NAME"));

				rtn.addElement(buff);
				/* write to rtn */
			}
			results.close();
			/* close the resultset */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}

		return rtn;
	}

	public Vector<Course> doQuerybyCourseName(String course_name) {
		Vector<Course> rtn = new Vector<Course>();
		try {
			String query_course_id = "SELECT * FROM TB_COURSE WHERE COURSE_NAME=?";
			PreparedStatement ps = m_conn.prepareStatement(query_course_id);
			ps.setString(1, course_name);
			ResultSet results = ps.executeQuery();

			while (results.next()) {
				Course temp = doMappingCourse(results);

				rtn.addElement(temp);
				/* write to rtn */
			}
			results.close();
			/* close the resultset */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
		return rtn;
	}

	public void doInsert2TabCourseSelect(String uid, String courseid) {
		try {
			String sql_insert = "INSERT INTO " + "TB_COURSE_SELECT "
					+ "VALUES ( ? , ? )";
			PreparedStatement ps = m_conn.prepareStatement(sql_insert);
			ps.setString(1, uid);
			ps.setString(2, courseid);

			ps.executeUpdate();

			m_conn.commit(); /* commit it if there is no exception */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
	}

	public void doDeleteFromTabCourseSelect(String uid, String courseid) {
		try {
			String sql_delete = "DELETE FROM " + "TB_COURSE_SELECT "
					+ "WHERE U_ID=? AND COURSE_ID=?";
			PreparedStatement ps = m_conn.prepareStatement(sql_delete);
			ps.setString(1, uid);
			ps.setString(2, courseid);
			/* prepare sql string */
			ps.executeUpdate();

			m_conn.commit();/* commit it if there is no exception */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
	}

	private Vector<String> doQueryCertainCourseIDFromTabCourseSelectByUid(
			String uid) {
		Vector<String> rtn = new Vector<String>();

		try {
			String query_str = "SELECT COURSE_ID " + "FROM TB_COURSE_SELECT "
					+ "WHERE U_ID=?";
			PreparedStatement ps = m_conn.prepareStatement(query_str);
			ps.setString(1, uid);

			ResultSet results = ps.executeQuery();

			while (results.next()) {
				rtn.addElement(results.getString("COURSE_ID"));
			}
			results.close();
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
		return rtn;

	}

	public Vector<Course> doQueryAllCourseTabCourseSelectByUid(String uid) {
		Vector<Course> rtn = new Vector<Course>();
		Vector<String> courseid = doQueryCertainCourseIDFromTabCourseSelectByUid(uid);

		for (int i = 0; i != courseid.size(); ++i) {
			try {
				String query_str = "SELECT * " + "FROM TB_COURSE "
						+ "WHERE COURSE_ID=?";
				PreparedStatement ps = m_conn.prepareStatement(query_str);
				ps.setString(1, courseid.elementAt(i));
				ResultSet results = ps.executeQuery();

				while (results.next()) {
					Course temp = doMappingCourse(results);

					rtn.addElement(temp);
				}
				results.close();
			} catch (Exception e) {
				System.err.println("error : " + e);
			}
		}
		return rtn;
	}

	public void doDeleteAllInTabCourseSelectByUID(String uid) {
		try {
			String sql_delete = "DELETE FROM " + "TB_COURSE_SELECT "
					+ "WHERE U_ID=?";
			PreparedStatement ps = m_conn.prepareStatement(sql_delete);
			ps.setString(1, uid);
			/* prepare sql string */
			ps.executeUpdate();

			m_conn.commit();/* commit it if there is no exception */
		} catch (Exception e) {
			System.err.println("error : " + e);
		}
	}
}
