package object;


import java.util.Vector;

import db_data_structure.Course;
import dbquery.CourseTimeOperation;
import dbquery.DBOperation;
import dbquery.dbConnectParam;
import object.CourseTable;
import object.Exp;


public class FmlCourseTable extends CourseTable {
	private String u_id; 				//ѧ����id
	private Vector<Course> course_list_org; //�γ̱��еĿγ�����������ԭʼ�����б�
	private Vector<Course> course_list_fixedCourses;//���ڱ��޸ĵĿγ������б�
	
	@SuppressWarnings("unchecked")
	public FmlCourseTable(String _u_id) {
		super();
		// TODO Auto-generated constructor stub
		u_id = _u_id;
		//���ԭʼ����
		course_list_org = this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
	}

	//ѧ��������ʦ���û�id�ļ�¼
	public void set_u_id(String uid){
		u_id = uid;
	}
	
	//ѧ��������ʦ���û�id�Ļ�ȡ
	public String get_u_id(){
		return u_id;
	}
	
	
	@Override
	public Vector get_course_list() {
		// TODO Auto-generated method stub
		//��ȡ���ݿ��еĿα�����
		return course_list_org;
	}

	//�ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected Vector searchCourseList(){
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		Vector<Course> _result =  dbo.doQueryAllCourseTabCourseSelectByUid(u_id);
		dbo.disconnectDB();
		return _result;
	}
	
	//��һ�ŵĿγ̼��뵽��ʽ�α���
	public Exp addCourse(Course _new){
		Exp exp = new Exp();
		course_list_fixedCourses.add(_new);
		return exp;
	}
	
	//��һ���γ̴���ʽ�α������
	public Exp deleteCourse(Course _old){
		Exp exp = new Exp();
		course_list_fixedCourses.remove(_old);
		return exp;
	}
	
	//���α��еĳ�ͻ
	@SuppressWarnings("unchecked")
	public Vector<Exp_CourseConfict> checkException(){
		Vector<Exp_CourseConfict> vec_exp = null;
		//���fixed֮��α���ĳ�ͻ
		//���������б���бȽ�
		Vector<Course> _temp_1 = new Vector<Course>();
		Vector<Course> _temp_2 = new Vector<Course>();
		_temp_1.addAll(course_list_fixedCourses);
		_temp_2.addAll(course_list_fixedCourses);
		//�ж���ͻ
		//�����ж�
		for(int _index_time = 0 ; _index_time <  _temp_1.size() ; ++ _index_time){
			for(int _j = _index_time ; _j < _temp_2.size() ; _j++){
				Course _course_1 = _temp_1.elementAt(_index_time);
				Course _couese_2 = _temp_2.elementAt(_j);
				if(CourseTimeOperation.isConflict(_course_1.getCourse_time(),
						_couese_2.getCourse_time())){
					//���ֳ�ͻ
					DebugClass.debug_info(this.toString(), "find conflict,the two couse is : " + _course_1.getCourse_name()
							+ " and  " + _couese_2.getCourse_name());
					DebugClass.debug_info(this.toString(),"the conflict time is : " + _course_1.getCourse_time());
					Exp_CourseConfict _new_exp = new Exp_CourseConfict();
					_new_exp.setmCourse_id_1(_course_1.getCourse_id());
					_new_exp.setmCourse_id_2(_couese_2.getCourse_id());
					_new_exp.setmConflicTime(_course_1.getCourse_time());
				}
			}
		}
		return vec_exp;
	}
	
	//������ʽ�α�
	@SuppressWarnings("unchecked")
	public Exp save(){
		DebugClass.debug_info(this.toString(), "start to save the course...");
		Exp exp = new Exp();
		//�������ݿ��б�����
		course_list_org.clear();
		course_list_org = (Vector<Course>) course_list_fixedCourses.clone();//����course_list_org�е�����
		//���������б�
		//����ɾ�����пγ�
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd) ;
		//����ɾ�����оɿα�
		dbo.doDeleteAllInTabCourseSelectByUID(u_id);
		//��ͨ��ѭ������µ��޸Ĺ��Ŀα�
		for(int i = 0 ; i < course_list_fixedCourses.size() ; ++i){
			DebugClass.debug_info(this.toString(), "save the course : ");
			dbo.doInsert2TabCourseSelect(u_id, course_list_fixedCourses.elementAt(i).getCourse_id());
		}
		dbo.disconnectDB();
		return exp;
	}
}
