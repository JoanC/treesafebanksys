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
	public static String[] Menu_Levels(String _menuname)
	{
		
		return null;
	}
}

