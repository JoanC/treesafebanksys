package varmap;

public class Query_VarString {
	
	public static String User_Permission(String _id)
	{
		int id = Integer.parseInt(_id);
		return Query_Constant.Permission[id];	
	}
	public static String[] User_Menu(String _permission)
	{
		if (_permission.equals(Query_Constant.Permission[1])) {
			return Query_Constant.Stu_menu;
		}
		else if(_permission.equals(Query_Constant.Permission[2]))
		{
			return Query_Constant.Tea_menu;
		}
		else if(_permission.equals(Query_Constant.Permission[3]))
		{
			return Query_Constant.Adm_menu;
		}
		return null;
	}
	public static String[] Menu_Levels(String _permission,String _menuname)
	{
		if (_permission.equals(Query_Constant.Permission[1])) {
			if (_menuname.equals(Query_Constant.Stu_menu[0])) {
				return Query_Constant.Stu_level1;
			}
			else if(_menuname.equals(Query_Constant.Stu_menu[1])){
				return Query_Constant.Stu_level2;
			}
			else if (_menuname.equals(Query_Constant.Stu_menu[2])) {
				return Query_Constant.Stu_level3;
			}
		}
		else if(_permission.equals(Query_Constant.Permission[2]))
		{
			if (_menuname.equals(Query_Constant.Tea_menu[0])) {
				return Query_Constant.Tea_level1;
			}
			else if(_menuname.equals(Query_Constant.Tea_menu[1])){
				return Query_Constant.Tea_level2;
			}
			else if(_menuname.equals(Query_Constant.Tea_menu[2])){
				return Query_Constant.Tea_level3;
			}
		}
		else if(_permission.equals(Query_Constant.Permission[3]))
		{
			if (_menuname.equals(Query_Constant.Adm_menu[0])) {
				return Query_Constant.Adm_level1;
			}
			else if(_menuname.equals(Query_Constant.Adm_menu[1])){
				return Query_Constant.Adm_level2;
			}
			else if (_menuname.equals(Query_Constant.Adm_menu[2])) {
				return Query_Constant.Adm_level3;
			}
		}
		return null;
	}
	public static String InputElemtName(String _value)
	{
		if (_value.equals(Query_Constant.Stu_level1[0])) {
			return Query_Constant.Names[0];
		}
		else if(_value.equals(Query_Constant.Stu_level2[0])||
				_value.equals(Query_Constant.Tea_level2[0])	)
		{
			return Query_Constant.Names[1];
		}
		else if(_value.equals(Query_Constant.Stu_level3[0])||
				_value.equals(Query_Constant.Adm_level3[0]))
		{
			return Query_Constant.Names[2];
		}
		else if(_value.equals(Query_Constant.Tea_level1[0])||
				_value.equals(Query_Constant.Tea_level1[1])||
				_value.equals(Query_Constant.Adm_level1[0])||
				_value.equals(Query_Constant.Adm_level1[1])||
				_value.equals(Query_Constant.Adm_level1[2]))
		{
			return Query_Constant.Names[3];
		}
		else if(_value.equals(Query_Constant.Adm_level2[0])||
				_value.equals(Query_Constant.Adm_level2[1]))
		{
			return Query_Constant.Names[4];
		}
		return _value;
	}
	public static String InputElemtAction(String _value)
	{
		if (_value.equals(Query_Constant.Stu_level1[0])) {
			return Query_Constant.Actions[0];
		}
		else if(_value.equals(Query_Constant.Stu_level2[0])||
				_value.equals(Query_Constant.Tea_level2[0])	)
		{
			return Query_Constant.Actions[1];
		}
		else if(_value.equals(Query_Constant.Stu_level3[0])||
				_value.equals(Query_Constant.Adm_level3[0]))
		{
			return Query_Constant.Actions[2];
		}
		else if(_value.equals(Query_Constant.Tea_level1[0])||
				_value.equals(Query_Constant.Tea_level1[1])||
				_value.equals(Query_Constant.Adm_level1[0])||
				_value.equals(Query_Constant.Adm_level1[1])||
				_value.equals(Query_Constant.Adm_level1[2]))
		{
			return Query_Constant.Actions[3];
		}
		else if(_value.equals(Query_Constant.Adm_level2[0])||
				_value.equals(Query_Constant.Adm_level2[1]))
		{
			return Query_Constant.Actions[4];
		}
		return _value;
	}
	public static String CourseType(int _id)
	{
		return Query_Constant.CourseType[_id];
	}
}

