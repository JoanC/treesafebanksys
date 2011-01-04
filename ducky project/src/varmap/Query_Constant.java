package varmap;

public class Query_Constant {
	//权限划分
	static public final String[] Permission = {"","Stu","Tea","Adm"};
	//用户一级菜单
	static public final String[] Stu_menu = {"课程","课表","学分"};
	static public final String[] Tea_menu = {"课程","课表"," "};
	static public final String[] Adm_menu = {"课程","系统","学分"};
	//学生二级菜单
	static public final String[] Stu_level1 = {"选择课程"};
	static public final String[] Stu_level2 = {"查看课表"};
	static public final String[] Stu_level3 = {"查看学分"};
	//教师二级菜单
	static public final String[] Tea_level1 = {"查看课程","修改课程"};
	static public final String[] Tea_level2 = {"查看课表"};
	static public final String[] Tea_level3 = {" "};
	//管理员二级菜单
	static public final String[] Adm_level1 = {"新增课程","修改课程","删除课程"};
	static public final String[] Adm_level2 = {"选课状态","选课模式"};
	static public final String[] Adm_level3 = {"修改学分"};
	//菜单最大数量
	static public final int MenuNums = 4;	
	//学分分类
	static public final String[] Grades ={"A1","A2","A3",
												"B1","B2","B3",
												"C1","C2","C3",
												"D1","D2","D3",
												"E1","E2","E3",
												"F1","F2","F3"};
	//表单元素之name
	static public final String[] Names = {"SelectCrsCommit",
											"QueryCrsTable",
											"UpdateCrsInfo",
											"UpdateCrsInfo",
											"SelCrsSysPara"};
	static public final String[] Actions = {"CourseListsServlet",
											"QueryCrsTable",
											"UpdateGrades",
											"UpdateCrsInfo",
											"SystemParaServelt"};
	//课程类型
	static public final String[] CourseType = {"公共课","选修课","专业课"};
	//上课地点
	static public final String[] CoursePlaces = {"嘉定"};
	//上课大楼号
	static public final String[] CourseBuildings = {"南楼","北楼"};
	static public final String[] JDCourseBuildings = {"A","B","C","D","E","F"};
	//上课教室
	static public final String[] CourseClasses = {"101","102","103","104","105"};
	
}
