package varmap;

public class Query_VarString {
	
	public static String User_Permission(String _id)
	{
		int id = Integer.parseInt(_id);
		if (id == 1) {
			return "Stu";
		}
		else if(id == 2)
		{
			return "Tea";
		}
		else if(id == 3)
		{
			return "Adm";
		}
		return _id;		
	}	
}

