package object;

import java.util.Map;
import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.Week;
import db_data_structure.enCourseFreq;
import dbquery.CourseTimeOperation;
import dbquery.DBOperation;
import dbquery.DecreaseByOne;
import dbquery.IncreaseByOne;
import dbquery.dbConnectParam;
import object.CourseTable;
import object.Exp;

public class FmlCourseTable extends CourseTable {
	private String u_id; // ѧ���id
	private Vector<Course> course_list_org; // �γ̱��еĿγ����������ԭʼ����б�
	private Vector<Course> course_list_fixedCourses;// ���ڱ��޸ĵĿγ�����б�
	private Vector<Course> course_addedCourses;// ѡ�ι������ӵĿγ�...Ϊ����ͳ����
	private Vector<Course> course_deletedCourses;// ѡ�ι����ɾ��Ŀγ�...Ϊ����ͳ����

	public FmlCourseTable(String _u_id) {
		super();
		// TODO Auto-generated constructor stub
		u_id = _u_id;
		course_list_fixedCourses = new Vector<Course>();
		course_addedCourses = new Vector<Course>();
		course_deletedCourses = new Vector<Course>();
		course_list_org = new Vector<Course>();
		// ���ԭʼ���
		DebugClass.debug_info(this.toString(),
				"copy data... from org data to fixed data...");
		course_list_org = this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
		
		for(int _index = 0; _index < course_list_fixedCourses.size() ; ++ _index){
			DebugClass.debug_info(this.toString(),"formal table:" + course_list_fixedCourses.elementAt(_index).getCourse_name());
		}
		//test the function "ToString"
		/*
		Vector<String>_test  = this.convertFmlTabFormat(course_list_org);
		for(int i = 0 ; i < _test.size() ; ++i){
			int _week = i % 7;
			int _seq = i / 7;
			DebugClass.debug_info(this.toString(),"Index : " + i + "_" + "(" + (_week+1) + "," + (_seq + 1) + ")  :" + _test.elementAt(i));
		}
		*/
	}

	// ѧ�������ʦ���û�id�ļ�¼
	public void set_u_id(String uid) {
		u_id = uid;
	}

	// ѧ�������ʦ���û�id�Ļ�ȡ
	public String get_u_id() {
		return u_id;
	}

	@Override
	public Vector<Course> get_course_list() {
		// TODO Auto-generated method stub
		// ��ȡ��ݿ��еĿα����
		return course_list_fixedCourses;
	}

	public Vector<Course> get_org_data() {
		// ��ȡ���һ�α���ǰ��ԭʼ���
		return course_list_org;
	}

	// �ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected Vector<Course> searchCourseList() {
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		DebugClass.debug_info(this.toString(),
				"search the formal table of u_id : " + u_id);
		Vector<Course> _result = dbo.doQueryAllCourseTabCourseSelectByUid(u_id);
		for (int i = 0; i < _result.size(); i++) {
			DebugClass.debug_info(this.toString(), "find course :  "
					+ _result.elementAt(i).getCourse_id());
		}
		DebugClass.debug_info(this.toString(), "search done!");
		dbo.disconnectDB();
		return _result;
	}

	// ��һ�ŵĿγ̼��뵽��ʽ�α���
	public Exp addCourse(Course _new) {
		Exp exp = new Exp();
		for(int _index = 0 ; _index < course_list_fixedCourses.size() ; ++_index){
			//�жϴ��ſγ��Ƿ��Ѿ�����
			if(course_list_fixedCourses.elementAt(_index).getCourse_id().equals(_new.getCourse_id())){
				return exp;
			}
			//�жϴ��ſγ��Ƿ�ͱ�Ŀγ��г�ͻ
		}
		
		//加入之前删除同名字的课程
		this.DelConCourseWhenAddSameNameCourse(_new.getCourse_name());
		
		DebugClass.debug_info(this.toString(), "add course " + _new.getCourse_name()
				+"to the fixed course list");
		course_list_fixedCourses.add(_new);
		course_addedCourses.add(_new);
		
		/*
		for(int _index = 0 ; _index < course_list_fixedCourses.size() ; ++_index){
			//�жϴ��ſγ��Ƿ�ͱ�Ŀγ��г�ͻ
			if(_new.getCourse_id().equals(course_list_fixedCourses.elementAt(_index).getCourse_id())) continue;
			if(CourseTimeOperation.isConflict(course_list_fixedCourses.elementAt(_index).getCourse_time_week(),
					_new.getCourse_time_week()).size() != 0){
				DebugClass.debug_info(this.toString(), "check the error! "+ _new.getCourse_name()
						+ " and " + course_list_fixedCourses.elementAt(_index).getCourse_name());
				return exp;
			}
		}*/
		
		DebugClass.debug_info(this.toString(), "no error , add the data...");
		//û�г�ͻ��ʵʱ����,������ѡ�����һ
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		//��ѡ�����һ
		dbo.doUpdateTabCourseCurrentSelectNum(_new.getCourse_id(), new IncreaseByOne());
		//����ݿ������ʽ�α�
	    dbo.doInsert2TabCourseSelect(u_id, _new.getCourse_id());
		dbo.disconnectDB();
		return exp;
	}

	// ��һ���γ̴���ʽ�α������
	public Exp deleteCourse(Course _old) {
		Exp exp = new Exp();
		//��ݼ�һ����ʵʱ����
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		//�����һ
		DebugClass.debug_info(this.toString(), "Update the course select number");
		dbo.doUpdateTabCourseCurrentSelectNum(_old.getCourse_id(), new DecreaseByOne());
		//ɾ��γ����
		DebugClass.debug_info(this.toString(), "delete course : " + _old.getCourse_id());
		dbo.doDeleteFromTabCourseSelect(u_id, _old.getCourse_id());
		//�������
		course_list_fixedCourses.clear();
		course_list_org.clear();
		course_list_org = this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
		dbo.disconnectDB();
		return exp;
	}

	// ���α��еĳ�ͻ
	public Vector<Exp_CourseConfict> checkException() {
		Vector<Exp_CourseConfict> vec_exp = new Vector<Exp_CourseConfict>();

		Vector<Course> _temp_1 = new Vector<Course>();
		Vector<Course> _temp_2 = new Vector<Course>();
		_temp_1.addAll(course_list_fixedCourses);
		_temp_2.addAll(course_list_fixedCourses);

		
		for (int _index_time = 0; _index_time < _temp_1.size(); ++_index_time) {
			for (int _j = _index_time; _j < _temp_2.size(); _j++) {
				Course _course_1 = _temp_1.elementAt(_index_time);
				Course _couese_2 = _temp_2.elementAt(_j);
				if (CourseTimeOperation.isConflict(_course_1.getCourse_time_week(),
						_couese_2.getCourse_time_week()).size() != 0) { // ���ֳ�ͻ
					Exp_CourseConfict _new_exp = new Exp_CourseConfict();
					_new_exp.setmCourse_id_1(_course_1.getCourse_id());
					_new_exp.setmCourse_id_2(_couese_2.getCourse_id());
					//_new_exp.getmConflicTime(CourseTimeOperation.isConflict(_course_1.getCourse_time_week(),
					//		_couese_2.getCourse_time_week()));
				}
			}
		}
		 
		return vec_exp;
	}

	// ������ʽ�α�
	@SuppressWarnings("unchecked")
	public Exp save() {
		DebugClass.debug_info(this.toString(), "start to save the course...");
		Exp exp = new Exp();
		// ������ݿ��б����
		course_list_org.clear();
		course_list_org = (Vector<Course>) course_list_fixedCourses.clone();// ����course_list_org�е����
		// ���������б�
		// ����ɾ�����пγ�
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		// ����ɾ�����оɿα�
		dbo.doDeleteAllInTabCourseSelectByUID(u_id);
		// ��ͨ��ѭ������µ��޸Ĺ�Ŀα�
		for (int i = 0; i < course_list_fixedCourses.size(); ++i) {
			DebugClass.debug_info(this.toString(), "save the course : ");
			dbo.doInsert2TabCourseSelect(u_id, course_list_fixedCourses
					.elementAt(i).getCourse_id());
		}

		// �������ѡ��������Ϣ
		
		// ���¸����б���Ϣ
		course_addedCourses.clear();
		course_deletedCourses.clear();

		// �ر���ݿ�
		dbo.disconnectDB();
		return exp;
	}
	
	public  boolean getIsConflic() {
		Vector<String> _check = CourseTable.convertFmlTabFormat(course_list_fixedCourses);
		for(int i = 0 ; i < _check.size() ; ++i){
			if(_check.elementAt(i).equals("课程冲突")){
				return true;
			}
		}
		return false;
	}
	
	//添加课程时,把原来在课表中的名称相同课程去除
	public void DelConCourseWhenAddSameNameCourse(String _course_name){
		Vector<Course> _rlt = new Vector<Course>();
		for(int _index = 0 ; _index <  course_list_fixedCourses.size() ; ++_index){
			if(course_list_fixedCourses.elementAt(_index).getCourse_name().equals(_course_name)){
				DebugClass.debug_info(this.toString(), "the same course name  " + _course_name);
				_rlt.addElement(course_list_fixedCourses.elementAt(_index));
			}
		}
		
		for(int _index = 0 ; _index < _rlt.size() ; ++_index){
			DebugClass.debug_info(this.toString(), "delete course : " + _rlt.elementAt(_index).getCourse_id());
			this.deleteCourse(_rlt.elementAt(_index));
		}
	}
}
