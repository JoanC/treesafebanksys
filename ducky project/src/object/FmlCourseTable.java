package object;

import java.util.Map;
import java.util.Vector;

import db_data_structure.Course;
import db_data_structure.Week;
import db_data_structure.enCourseFreq;
import dbquery.CourseTimeOperation;
import dbquery.DBOperation;
import dbquery.dbConnectParam;
import object.CourseTable;
import object.Exp;

public class FmlCourseTable extends CourseTable {
	private String u_id; // ѧ����id
	private Vector<Course> course_list_org; // �γ̱��еĿγ�����������ԭʼ�����б�
	private Vector<Course> course_list_fixedCourses;// ���ڱ��޸ĵĿγ������б�
	private Vector<Course> course_addedCourses;// ѡ�ι�������ӵĿγ�...Ϊ����ͳ����
	private Vector<Course> course_deletedCourses;// ѡ�ι�����ɾ���Ŀγ�...Ϊ����ͳ����

	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;
	private static final int WEEK_DAYS = 7;

	public FmlCourseTable(String _u_id) {
		super();
		// TODO Auto-generated constructor stub
		u_id = _u_id;
		course_list_fixedCourses = new Vector<Course>();
		course_addedCourses = new Vector<Course>();
		course_deletedCourses = new Vector<Course>();
		course_list_org = new Vector<Course>();
		// ���ԭʼ����
		DebugClass.debug_info(this.toString(),
				"copy data... from org data to fixed data...");
		course_list_org = this.searchCourseList();
		course_list_fixedCourses.addAll(course_list_org);
		//test the function "ToString"
		Vector<String>_test  = this.convertFmlTabFormat(course_list_org);
		for(int i = 0 ; i < _test.size() ; ++i){
			DebugClass.debug_info(this.toString(), _test.elementAt(i));
		}
	}

	// ѧ��������ʦ���û�id�ļ�¼
	public void set_u_id(String uid) {
		u_id = uid;
	}

	// ѧ��������ʦ���û�id�Ļ�ȡ
	public String get_u_id() {
		return u_id;
	}

	@Override
	public Vector<Course> get_course_list() {
		// TODO Auto-generated method stub
		// ��ȡ���ݿ��еĿα�����
		return course_list_fixedCourses;
	}

	public Vector<Course> get_org_data() {
		// ��ȡ���һ�α���ǰ��ԭʼ����
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
		course_list_fixedCourses.add(_new);
		course_addedCourses.add(_new);
		return exp;
	}

	// ��һ���γ̴���ʽ�α������
	public Exp deleteCourse(Course _old) {
		Exp exp = new Exp();
		course_list_fixedCourses.remove(_old);
		course_deletedCourses.add(_old);
		return exp;
	}

	// ���α��еĳ�ͻ
	public Vector<Exp_CourseConfict> checkException() {
		Vector<Exp_CourseConfict> vec_exp = new Vector<Exp_CourseConfict>();
		// ���fixed֮��α���ĳ�ͻ
		// ���������б���бȽ�
		Vector<Course> _temp_1 = new Vector<Course>();
		Vector<Course> _temp_2 = new Vector<Course>();
		_temp_1.addAll(course_list_fixedCourses);
		_temp_2.addAll(course_list_fixedCourses);
		// �ж���ͻ
		// �����ж�
		/*
		 * for(int _index_time = 0 ; _index_time < _temp_1.size() ; ++
		 * _index_time){ for(int _j = _index_time ; _j < _temp_2.size() ; _j++){
		 * Course _course_1 = _temp_1.elementAt(_index_time); Course _couese_2 =
		 * _temp_2.elementAt(_j);
		 * if(CourseTimeOperation.isConflict(_course_1.getCourse_time(),
		 * _couese_2.getCourse_time())){ //���ֳ�ͻ
		 * DebugClass.debug_info(this.toString(),
		 * "find conflict,the two couse is : " + _course_1.getCourse_name() +
		 * " and  " + _couese_2.getCourse_name());
		 * DebugClass.debug_info(this.toString(),"the conflict time is : " +
		 * _course_1.getCourse_time()); Exp_CourseConfict _new_exp = new
		 * Exp_CourseConfict();
		 * _new_exp.setmCourse_id_1(_course_1.getCourse_id());
		 * _new_exp.setmCourse_id_2(_couese_2.getCourse_id());
		 * _new_exp.setmConflicTime(_course_1.getCourse_time()); } } }
		 */
		return vec_exp;
	}

	// ������ʽ�α�
	@SuppressWarnings("unchecked")
	public Exp save() {
		DebugClass.debug_info(this.toString(), "start to save the course...");
		Exp exp = new Exp();
		// �������ݿ��б�����
		course_list_org.clear();
		course_list_org = (Vector<Course>) course_list_fixedCourses.clone();// ����course_list_org�е�����
		// ���������б�
		// ����ɾ�����пγ�
		DBOperation dbo = new DBOperation();
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url,
				dbConnectParam.userName, dbConnectParam.dbPwd);
		// ����ɾ�����оɿα�
		dbo.doDeleteAllInTabCourseSelectByUID(u_id);
		// ��ͨ��ѭ������µ��޸Ĺ��Ŀα�

		for (int i = 0; i < course_list_fixedCourses.size(); ++i) {
			DebugClass.debug_info(this.toString(), "save the course : ");
			dbo.doInsert2TabCourseSelect(u_id, course_list_fixedCourses
					.elementAt(i).getCourse_id());
		}

		// �������ѡ��������Ϣ

		// ���¸����б���Ϣ
		course_addedCourses.clear();
		course_deletedCourses.clear();

		// �ر����ݿ�
		dbo.disconnectDB();
		return exp;
	}

	// ����:�����
	// ʱ��:2010/12/15
	// ���γ̱�ת��Ϊsevelet����ҳ�˿�ʶ������ݸ�ʽ
	public Vector<String> convertFmlTabFormat(Vector<Course> _fml_tab) {
		/*
		 * ����һ����ſγ��б���Ϣ��һά���� ��ŵ�ԪΪcourse_id ��ʽ����
		 * ���߸�λ��λ,��һ���߸��ֱ��ʾ���һ~�ߵĵ�һ�ڿ�..��������
		 */
		Vector<String> _rlt = new Vector<String>();
		/*
		 * ʵ��ԭ�� 1.��7*11�������������һ�ж����� 2.�ҵ���Ӧ�Ŀγ������Ҹ�������1��,�������Ӧ������
		 * 3.���ڵ�/˫�ܵĿγ�Ҫ��һ���ж�. 4.��������˵,һ��������,���������ſ�(��˫��)..
		 */
		// ����1:����ȫ���α��,����Ϊ7*11
		for (int _index = 0; _index < MAX_NUM_OF_COURSES_PER_DAY * WEEK_DAYS; ++_index) {
			// ����2:����ÿһ������,�����������,�ҳ���Ӧ�Ŀγ̸���Ŀ,�洢��һ��Vector��
			// ��ž���0��ʼ����,����ʵ��1,2,3,4...��������Ϊ0,1,2,3,4,5,6...
			// ���Ҷ�Ӧ������
			int _week = _index % WEEK_DAYS;
			int _seq = _index / WEEK_DAYS;
			DebugClass.debug_info(this.toString(), "the course position is (" + _week + "," + _seq + ");");
			Vector<Course> _temp_list = new Vector<Course>();// �洢һ�������еĿγ��б�,�������
			for (int _index_all_list = 0; _index_all_list < course_list_fixedCourses
					.size(); ++_index_all_list) {
				// ȡ�ÿγ���Ϣ��������Ϣ
				Course _course = course_list_fixedCourses
						.elementAt(_index_all_list);
				Map<Integer, Vector<Boolean>> _time = CourseTimeOperation
						.convert2Detail(_course.getCourse_time_week());
				if (_time.containsKey(_week)) {
					// �ҵ��γ��ڸ������п�,���ҽ����Ƿ���
					Vector<Boolean> _seqs = _time.get(_week);
					if (_seqs.elementAt(_seq) == true) {
						// ȷ��������������д˿�
						_temp_list.add(_course);
					}
				}
			}
			// ����3:ȡ���˵�ǰ����Ŀγ��б�,��ͨ����Ŀ,��˫��,�ж���ʾ��ʲô��Ϣ,����_rlt�м����������ַ���
			_rlt.add(this.generateSubStrForFmlTab(_temp_list, _week));
			DebugClass.debug_info(this.toString(),"time -- week : " + (_week+1) + " seq: " 
					+ (_seq + 1) + this.generateSubStrForFmlTab(_temp_list, _week));
		}
		return _rlt;
	}

	private String generateSubStrForFmlTab(Vector<Course> _list, int _week_day) {
		DebugClass.debug_info(this.toString(), "course in the list : ");
		for(int i = 0 ; i < _list.size() ; ++i){
			DebugClass.debug_info(this.toString(), " " + _list.elementAt(i) + " ");
		}
		String _generate_str = "";
		if (_list.size() == 0) {
			// û�пγ�
		} else if (_list.size() == 1) {
			// ǡ��һ�ſγ�,�����ڳ�ͻ
			// �жϵ�˫������
			Course _tmp = _list.elementAt(0);
			_generate_str += _tmp.getCourse_name();
		} else if (_list.size() == 2) {
			Course _tmp_1 = _list.elementAt(0);
			Course _tmp_2 = _list.elementAt(1);
			// �жϵ�˫�������Ƿ�һ��,����һ�����ͻ
			if (!CourseTimeOperation.isConflict(_tmp_1.getCourse_time_week(), _tmp_2.getCourse_time_week()).isEmpty()) {
				// ���������ͬ,���ͻ
				_generate_str += "�γ� " + _tmp_1.getCourse_name() + " " + _tmp_2.getCourse_name() + "���ڳ�ͻ!";
			} else {
				// ��˫�ܲ���ͻ
				_generate_str += _tmp_1.getCourse_name()
						+ " " + this.generateSubStrByFeq(_tmp_1.getCourse_time_week().getCourse_freq(_week_day));
				_generate_str += "\n";//���з�
				_generate_str += _tmp_2.getCourse_name() 
						+ " " + this.generateSubStrByFeq(_tmp_2.getCourse_time_week().getCourse_freq(_week_day));
			}
		}else{
			//�γ̳�ͻ
			_generate_str += "�γ̳�ͻ!";
		}
		return _generate_str;
	}

	private String generateSubStrByFeq(int _feq) {
		String _sub = "";
		if (_feq == enCourseFreq.NONE) {
			// û�пγ�
			_sub += "<�γ���ͣ>";
		} else if (_feq == enCourseFreq.ODD_WEEK) {
			// ����
			_sub += "<����>";
		} else if (_feq == enCourseFreq.EVEN_WEEK) {
			// ˫��
			_sub += "<˫��>";
		} else {
			// ÿ��
			// ����ʾ
			_sub += "<ÿ��>";
		}
		return _sub;
	}

}
