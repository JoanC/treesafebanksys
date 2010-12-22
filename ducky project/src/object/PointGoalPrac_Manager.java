package object;


import object.PointGoalPrac;
import java.util.Vector;


//这个类负责学生培养计划完成情况的处理，目前只有查询作用
public class PointGoalPrac_Manager {
	//根据学生的ID号码从数据库中获取培养计划完成情况数据
	static public PointGoalPrac SearchPointGoalPrac(String _uid){
		PointGoalPrac point_goal_prac = new PointGoalPrac();
		point_goal_prac.setU_id(_uid);
		//DB query
		//...
		return point_goal_prac;
	}
	
	//将学生的培养计划完成情况转化成vector供上层使用
	static public Vector<Float> TurnPointGoalPracToVector(){
		Vector<Float> point_goal_prac_vec = new Vector<Float>();
		//...
		return point_goal_prac_vec;
	}
}
