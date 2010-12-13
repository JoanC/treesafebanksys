package object;


import object.PointGoal;
import object.Exp;


//这个类负责培养计划数据的处理，包含了一个查找操作和修改保存操作，
//分别用于“学分统计”和“课程培养计划编辑”两个用例
public class PointGoal_Manager {
	//根据学院的标识号码获取培养计划数据
	static public PointGoal SearchPointGoal(int _school_id){
		PointGoal point_goal = new PointGoal();
		//DB query...
		return point_goal;
	}
	
	//编辑培养计划并保存
	static public Exp EditPointGoal(PointGoal _old, PointGoal _new){
		Exp exp = new Exp();
		//DB options...
		return exp;
	}
}
