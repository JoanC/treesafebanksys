package object;


import object.PointGoalPrac;
import java.util.Vector;


//����ฺ��ѧ�������ƻ��������Ĵ���Ŀǰֻ�в�ѯ����
public class PointGoalPrac_Manager {
	//����ѧ����ID��������ݿ��л�ȡ�����ƻ�����������
	static public PointGoalPrac SearchPointGoalPrac(String _uid){
		PointGoalPrac point_goal_prac = new PointGoalPrac();
		point_goal_prac.setU_id(_uid);
		//DB query
		//...
		return point_goal_prac;
	}
	
	//��ѧ���������ƻ�������ת����vector���ϲ�ʹ��
	static public Vector<Float> TurnPointGoalPracToVector(){
		Vector<Float> point_goal_prac_vec = new Vector<Float>();
		//...
		return point_goal_prac_vec;
	}
}
