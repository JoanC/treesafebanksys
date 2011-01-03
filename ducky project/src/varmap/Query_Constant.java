package varmap;

public class Query_Constant {
	//权限划分
	static public final String[] Permission = {"","Stu","Tea","Adm"};
	//用户一级菜单
	static public final String[] Stu_menu = {"课程","课表","学分",""};
	static public final String[] Tea_menu = {"课程","课表","",""};
	static public final String[] Adm_menu = {"课程","系统","学分",""};
	//学生二级菜单
	static public final String[] Stu_level1 = {"选择课程"};
	static public final String[] Stu_level2 = {"查看课表"};
	static public final String[] Stu_level3 = {"查看学分"};
	//教师二级菜单
	static public final String[] Tea_level1 = {"查看课程","修改课程"};
	static public final String[] Tea_level2 = {"查看课表"};
	//管理员二级菜单
	static public final String[] Adm_level1 = {"新增课程","修改课程","删除课程"};
	static public final String[] Adm_level2 = {"选课状态","选课模式"};
	static public final String[] Adm_level3 = {"修改培养计划"};
	
	//学分分类
	static public final String[] Grades ={"A1","A2","A3",
												"B1","B2","B3",
												"C1","C2","C3",
												"D1","D2","D3",
												"E1","E2","E3",
												"F1","F2","F3"};
	
}
