package object;


import object.PointGoal;
import object.Exp;


//����ฺ�������ƻ����ݵĴ���������һ�����Ҳ������޸ı��������
//�ֱ����ڡ�ѧ��ͳ�ơ��͡��γ������ƻ��༭����������
public class PointGoal_Manager {
	//����ѧԺ�ı�ʶ�����ȡ�����ƻ�����
	static public PointGoal SearchPointGoal(int _school_id){
		PointGoal point_goal = new PointGoal();
		//DB query...
		return point_goal;
	}
	
	//�༭�����ƻ�������
	static public Exp EditPointGoal(PointGoal _old, PointGoal _new){
		Exp exp = new Exp();
		//DB options...
		return exp;
	}
}
