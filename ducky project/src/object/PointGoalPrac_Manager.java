package object;


import object.PointGoalPrac;
import java.util.Vector;
import db_data_structure.Course;
import db_data_structure.PointGoal;
import dbquery.DBOperation;
import dbquery.dbConnectParam;
import db_data_structure.PointGoal;
import db_data_structure.User;
import db_data_structure.enCourseType;;


//����ฺ��ѧ�������ƻ��������Ĵ���Ŀǰֻ�в�ѯ����
public class PointGoalPrac_Manager {
	//����ѧ����ID��������ݿ��л�ȡ�����ƻ�����������
	static private PointGoalPrac SearchPointGoalPrac(String _u_id){
		PointGoalPrac point_goal_prac = new PointGoalPrac();
		
		//u_id
		point_goal_prac.setU_id(_u_id);
		
		DBOperation dbo = new DBOperation() ;
		dbo.connectDB(dbConnectParam.driverName, dbConnectParam.url, dbConnectParam.userName, dbConnectParam.dbPwd);
		User user = User_Manager.queryUserInfo(_u_id);
		PointGoal point_goal = dbo.doQueryPointGoalFromTbPG(user.getU_school_id());
		Vector<Course> finished_courses = dbo.doQueryAllFinishedCourseOfCertainStudent(_u_id);
		dbo.disconnectDB();
		
		//A1
		{
			//A1��γ�Ӧ��ѧ��
			point_goal_prac.setA1_all(point_goal.getA1());
			
			//A1��γ�����ѧ��
			float _a1_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_A1){
					_a1_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setA1_finished(_a1_finished);
			
			//A1��γ̴���ѧ��
			point_goal_prac.setA1_unfinished(point_goal.getA1() - _a1_finished);
		}
		
		//A2
		{
			//A2��γ�Ӧ��ѧ��
			point_goal_prac.setA2_all(point_goal.getA2());
			
			//A2��γ�����ѧ��
			float _a2_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_A2){
					_a2_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setA2_finished(_a2_finished);
			
			//A2��γ̴���ѧ��
			point_goal_prac.setA2_unfinished(point_goal.getA2() - _a2_finished);
		}
		
		//A3
		{
			//A3��γ�Ӧ��ѧ��
			point_goal_prac.setA3_all(point_goal.getA3());
			
			//A3��γ�����ѧ��
			float _a3_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_A3){
					_a3_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setA3_finished(_a3_finished);
			
			//A3��γ̴���ѧ��
			point_goal_prac.setA3_unfinished(point_goal.getA3() - _a3_finished);
		}
		
		//B1
		{
			//B1��γ�Ӧ��ѧ��
			point_goal_prac.setB1_all(point_goal.getB1());
			
			//B1��γ�����ѧ��
			float _b1_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_B1){
					_b1_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setB1_finished(_b1_finished);
			
			//B1��γ̴���ѧ��
			point_goal_prac.setB1_unfinished(point_goal.getB1() - _b1_finished);
		}
		
		//B2
		{
			//B2��γ�Ӧ��ѧ��
			point_goal_prac.setB2_all(point_goal.getB2());
			
			//B2��γ�����ѧ��
			float _b2_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_B2){
					_b2_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setB2_finished(_b2_finished);
			
			//B2��γ̴���ѧ��
			point_goal_prac.setB2_unfinished(point_goal.getB2() - _b2_finished);
		}
		
		//B3
		{
			//B3��γ�Ӧ��ѧ��
			point_goal_prac.setB3_all(point_goal.getB3());
			
			//B3��γ�����ѧ��
			float _b3_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_B3){
					_b3_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setB3_finished(_b3_finished);
			
			//B3��γ̴���ѧ��
			point_goal_prac.setB3_unfinished(point_goal.getB3() - _b3_finished);
		}
		
		//C1
		{
			//C1��γ�Ӧ��ѧ��
			point_goal_prac.setC1_all(point_goal.getC1());
			
			//C1��γ�����ѧ��
			float _c1_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_C1){
					_c1_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setC1_finished(_c1_finished);
			
			//C1��γ̴���ѧ��
			point_goal_prac.setC1_unfinished(point_goal.getC1() - _c1_finished);
		}
		
		//C2
		{
			//C2��γ�Ӧ��ѧ��
			point_goal_prac.setC2_all(point_goal.getC2());
			
			//C2��γ�����ѧ��
			float _c2_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_C2){
					_c2_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setC2_finished(_c2_finished);
			
			//C2��γ̴���ѧ��
			point_goal_prac.setC2_unfinished(point_goal.getC2() - _c2_finished);
		}
		
		//C3
		{
			//C3��γ�Ӧ��ѧ��
			point_goal_prac.setC3_all(point_goal.getC3());
			
			//C3��γ�����ѧ��
			float _c3_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_C3){
					_c3_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setC3_finished(_c3_finished);
			
			//C3��γ̴���ѧ��
			point_goal_prac.setC3_unfinished(point_goal.getC3() - _c3_finished);
		}
		
		//D1
		{
			//D1��γ�Ӧ��ѧ��
			point_goal_prac.setD1_all(point_goal.getD1());
			
			//D1��γ�����ѧ��
			float _d1_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_D1){
					_d1_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setD1_finished(_d1_finished);
			
			//D1��γ̴���ѧ��
			point_goal_prac.setD1_unfinished(point_goal.getD1() - _d1_finished);
		}
		
		//D2
		{
			//D2��γ�Ӧ��ѧ��
			point_goal_prac.setD2_all(point_goal.getD2());
			
			//D2��γ�����ѧ��
			float _d2_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_D2){
					_d2_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setD2_finished(_d2_finished);
			
			//D2��γ̴���ѧ��
			point_goal_prac.setD2_unfinished(point_goal.getD2() - _d2_finished);
		}
		
		//D3
		{
			//D3��γ�Ӧ��ѧ��
			point_goal_prac.setD3_all(point_goal.getD3());
			
			//D3��γ�����ѧ��
			float _d3_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_D3){
					_d3_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setD3_finished(_d3_finished);
			
			//D3��γ̴���ѧ��
			point_goal_prac.setD3_unfinished(point_goal.getD3() - _d3_finished);
		}
		
		//E1
		{
			//E1��γ�Ӧ��ѧ��
			point_goal_prac.setE1_all(point_goal.getE1());
			
			//E1��γ�����ѧ��
			float _e1_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_E1){
					_e1_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setE1_finished(_e1_finished);
			
			//E1��γ̴���ѧ��
			point_goal_prac.setE1_unfinished(point_goal.getE1() - _e1_finished);
		}
		
		//E2
		{
			//E2��γ�Ӧ��ѧ��
			point_goal_prac.setE2_all(point_goal.getE2());
			
			//E2��γ�����ѧ��
			float _e2_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_E2){
					_e2_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setE2_finished(_e2_finished);
			
			//E2��γ̴���ѧ��
			point_goal_prac.setE2_unfinished(point_goal.getE2() - _e2_finished);
		}
		
		//E3
		{
			//E3��γ�Ӧ��ѧ��
			point_goal_prac.setE3_all(point_goal.getE3());
			
			//E3��γ�����ѧ��
			float _e3_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_E3){
					_e3_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setE3_finished(_e3_finished);
			
			//E3��γ̴���ѧ��
			point_goal_prac.setE3_unfinished(point_goal.getE3() - _e3_finished);
		}
		
		//F1
		{
			//F1��γ�Ӧ��ѧ��
			point_goal_prac.setF1_all(point_goal.getF1());
			
			//F1��γ�����ѧ��
			float _f1_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_F1){
					_f1_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setF1_finished(_f1_finished);
			
			//F1��γ̴���ѧ��
			point_goal_prac.setF1_unfinished(point_goal.getF1() - _f1_finished);
		}
		
		//F2
		{
			//F2��γ�Ӧ��ѧ��
			point_goal_prac.setF2_all(point_goal.getF2());
			
			//F2��γ�����ѧ��
			float _f2_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_F2){
					_f2_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setF2_finished(_f2_finished);
			
			//F2��γ̴���ѧ��
			point_goal_prac.setF2_unfinished(point_goal.getF2() - _f2_finished);
		}
		
		//F3
		{
			//F3��γ�Ӧ��ѧ��
			point_goal_prac.setF3_all(point_goal.getF3());
			
			//F3��γ�����ѧ��
			float _f3_finished = 0;
			for(int i = 0; i < finished_courses.size(); i++){ 
				if(finished_courses.get(i).getCourse_type() == enCourseType.CT_F3){
					_f3_finished += finished_courses.get(i).getCourse_point();
				}
			}
			point_goal_prac.setF3_finished(_f3_finished);
			
			//F3��γ̴���ѧ��
			point_goal_prac.setF3_unfinished(point_goal.getF3() - _f3_finished);
		}
		
		return point_goal_prac;
	}
	
	//��ѧ���������ƻ�������ת����vector���ϲ�ʹ��
	static public Vector<Float> TurnPointGoalPracToVector(String _u_id){
		PointGoalPrac point_goal_prac = SearchPointGoalPrac(_u_id);
		
		Vector<Float> point_goal_prac_vec = new Vector<Float>();
		
		point_goal_prac_vec.add(point_goal_prac.getA1_finished());
		point_goal_prac_vec.add(point_goal_prac.getA1_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getA1_all());
		point_goal_prac_vec.add(point_goal_prac.getA2_finished());
		point_goal_prac_vec.add(point_goal_prac.getA2_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getA2_all());
		point_goal_prac_vec.add(point_goal_prac.getA3_finished());
		point_goal_prac_vec.add(point_goal_prac.getA3_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getA3_all());
		point_goal_prac_vec.add(point_goal_prac.getB1_finished());
		point_goal_prac_vec.add(point_goal_prac.getB1_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getB1_all());
		point_goal_prac_vec.add(point_goal_prac.getB2_finished());
		point_goal_prac_vec.add(point_goal_prac.getB2_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getB2_all());
		point_goal_prac_vec.add(point_goal_prac.getB3_finished());
		point_goal_prac_vec.add(point_goal_prac.getB3_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getB3_all());
		point_goal_prac_vec.add(point_goal_prac.getC1_finished());
		point_goal_prac_vec.add(point_goal_prac.getC1_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getC1_all());
		point_goal_prac_vec.add(point_goal_prac.getC2_finished());
		point_goal_prac_vec.add(point_goal_prac.getC2_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getC2_all());
		point_goal_prac_vec.add(point_goal_prac.getC3_finished());
		point_goal_prac_vec.add(point_goal_prac.getC3_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getC3_all());
		point_goal_prac_vec.add(point_goal_prac.getD1_finished());
		point_goal_prac_vec.add(point_goal_prac.getD1_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getD1_all());
		point_goal_prac_vec.add(point_goal_prac.getD2_finished());
		point_goal_prac_vec.add(point_goal_prac.getD2_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getD2_all());
		point_goal_prac_vec.add(point_goal_prac.getD3_finished());
		point_goal_prac_vec.add(point_goal_prac.getD3_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getD3_all());
		point_goal_prac_vec.add(point_goal_prac.getE1_finished());
		point_goal_prac_vec.add(point_goal_prac.getE1_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getE1_all());
		point_goal_prac_vec.add(point_goal_prac.getE2_finished());
		point_goal_prac_vec.add(point_goal_prac.getE2_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getE2_all());
		point_goal_prac_vec.add(point_goal_prac.getE3_finished());
		point_goal_prac_vec.add(point_goal_prac.getE3_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getE3_all());
		point_goal_prac_vec.add(point_goal_prac.getF1_finished());
		point_goal_prac_vec.add(point_goal_prac.getF1_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getF1_all());
		point_goal_prac_vec.add(point_goal_prac.getF2_finished());
		point_goal_prac_vec.add(point_goal_prac.getF2_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getF2_all());
		point_goal_prac_vec.add(point_goal_prac.getF3_finished());
		point_goal_prac_vec.add(point_goal_prac.getF3_unfinished());
		point_goal_prac_vec.add(point_goal_prac.getF3_all());
		
		return point_goal_prac_vec;
	}
}
