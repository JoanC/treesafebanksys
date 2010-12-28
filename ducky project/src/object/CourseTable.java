package object;


import java.util.Map;
import java.util.Vector;

import com.sun.net.ssl.internal.ssl.Debug;

import db_data_structure.Course;
import db_data_structure.enCourseFreq;
import dbquery.CourseTimeOperation;


public abstract class CourseTable {
	//ѧ�������ʦ���û�id�ļ�¼

	private static final int MAX_NUM_OF_COURSES_PER_DAY = 11;
	private static final int WEEK_DAYS = 7;
	
	public abstract void set_u_id(String uid);
	
	//ѧ�������ʦ���û�id�Ļ�ȡ
	public abstract String get_u_id();
	
	//����α��е����пγ���Ϣ�б�ļ�¼
	public abstract Vector get_course_list();
	
	//�ڳ�ʼ��ʱ��ȡ���u_id�µĿα��е����пγ��б�
	protected abstract Vector searchCourseList();
	
	// ����:�����
	// ʱ��:2010/12/15
	// ���γ̱�ת��Ϊsevelet����ҳ�˿�ʶ�����ݸ�ʽ
	public static Vector<String> convertFmlTabFormat(Vector<Course> _fml_tab) {
		/*
		 * ����һ����ſγ��б���Ϣ��һά���� ��ŵ�ԪΪcourse_id ��ʽ����
		 * ���߸�λ��λ,��һ���߸��ֱ��ʾ���һ~�ߵĵ�һ�ڿ�..��������
		 */
		Vector<String> _rlt = new Vector<String>();
		/*
		 * ʵ��ԭ�� 1.��7*11�������������һ�ж����� 2.�ҵ���Ӧ�Ŀγ�����Ҹ������1��,�������Ӧ�����
		 * 3.���ڵ�/˫�ܵĿγ�Ҫ��һ���ж�. 4.��������˵,һ��������,���������ſ�(��˫��)..
		 */
		// ����1:����ȫ���α��,����Ϊ7*11
		for (int _index = 0; _index < MAX_NUM_OF_COURSES_PER_DAY * WEEK_DAYS; ++_index) {
			// ����2:����ÿһ������,����������,�ҳ���Ӧ�Ŀγ̸���Ŀ,�洢��һ��Vector��
			// ��ž��0��ʼ����,����ʵ��1,2,3,4...��������Ϊ0,1,2,3,4,5,6...
			// ���Ҷ�Ӧ�����
			int _week = _index % WEEK_DAYS;
			int _seq = _index / WEEK_DAYS;
			//DebugClass.debug_info("CourseTable", "the course position is (" + _week + "," + _seq + ");");
			Vector<Course> _temp_list = new Vector<Course>();// �洢һ�������еĿγ��б�,�������
			for (int _index_all_list = 0; _index_all_list < _fml_tab
					.size(); ++_index_all_list) {
				// ȡ�ÿγ���Ϣ�������Ϣ
				Course _course = _fml_tab
						.elementAt(_index_all_list);
				Map<Integer, Vector<Boolean>> _time = CourseTimeOperation
						.convert2Detail(_course.getCourse_time_week());
				if (_time.containsKey(_week)) {
					// �ҵ��γ��ڸ������п�,���ҽ����Ƿ���
					Vector<Boolean> _seqs = _time.get(_week);
					if (_seqs.elementAt(_seq) == true) {
						// ȷ�������������д˿�
						_temp_list.add(_course);
					}
				}
			}
			// ����3:ȡ���˵�ǰ���Ŀγ��б�,��ͨ����Ŀ,��˫��,�ж���ʾ��ʲô��Ϣ,����_rlt�м���������ַ�
			_rlt.add(generateSubStrForFmlTab(_temp_list, (_week+1)));
			/*DebugClass.debug_info("CourseTable","time -- week : " + (_week+1) + " seq: " 
					+ (_seq + 1) + generateSubStrForFmlTab(_temp_list, _week));*/
		}
		return _rlt;
	}

	private static String generateSubStrForFmlTab(Vector<Course> _list, int _week_day) {
		for(int i = 0 ; i < _list.size() ; ++i){
			DebugClass.debug_info("CourseTable", " week : " + _week_day + " " + _list.elementAt(i).getCourse_name() + " "
					+ "feq:" + _list.elementAt(i).getCourse_time_week().getCourse_freq(_week_day));
		}
		String _generate_str = "";
		if (_list.size() == 0) {
			// û�пγ�
		} else if (_list.size() == 1) {
			// ǡ��һ�ſγ�,�����ڳ�ͻ
			// �жϵ�˫������
			Course _tmp = _list.elementAt(0);
			_generate_str += _tmp.getCourse_name()
					+ " " + generateSubStrByFeq(_tmp.getCourse_time_week().getCourse_freq(_week_day));
		} else if (_list.size() == 2) {
			Course _tmp_1 = _list.elementAt(0);
			Course _tmp_2 = _list.elementAt(1);
			// �жϵ�˫�������Ƿ�һ��,����һ�����ͻ
			if (_tmp_1.getCourse_time_week().getCourse_freq(_week_day) == _tmp_2.getCourse_time_week().getCourse_freq(_week_day)
					&& 0 != _tmp_1.getCourse_time_week().getCourse_freq(_week_day)*_tmp_2.getCourse_time_week().getCourse_freq(_week_day)) {
				// ���������ͬ,���ͻ
				DebugClass.debug_info("CourseTable", "course1:" + _tmp_1.getCourse_name()
						+ "course2:" + _tmp_2.getCourse_name());
				_generate_str += "�γ̳�ͻ!";
			} else {
				// ��˫�ܲ���ͻ
				_generate_str += _tmp_1.getCourse_name()
						+ " " + generateSubStrByFeq(_tmp_1.getCourse_time_week().getCourse_freq(_week_day));
				_generate_str += _tmp_2.getCourse_name() 
						+ " " + generateSubStrByFeq(_tmp_2.getCourse_time_week().getCourse_freq(_week_day));
			}
		}else{
			//�γ̳�ͻ
			/*_generate_str += "�γ� ";
			for(int _index = 0 ; _index < _list.size() ; ++_index){
				_generate_str += _list.elementAt(_index).getCourse_name() + " ";
			}
			_generate_str += "���ڳ�ͻ!";*/
			_generate_str += "课程冲突";
		}
		if(_generate_str == "") _generate_str += "--";
		return _generate_str;
	}

	private static String generateSubStrByFeq(int _feq) {
		String _sub = "";
		DebugClass.debug_info("CourseTable", "the feq is : " + _feq);
		if (_feq == enCourseFreq.NONE) {
			// û�пγ�
			_sub += "<课程暂停>";
		} else if (_feq == enCourseFreq.ODD_WEEK) {
			// ����
			_sub += "<单周>";
		} else if (_feq == enCourseFreq.EVEN_WEEK) {
			// ˫��
			_sub += "<双周>";
		} else {
			// ÿ��
			// ����ʾ
			//_sub += "<ÿ��>";
		}
		return _sub;
	}
}
