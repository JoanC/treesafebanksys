package object;


import object.SystemParameter;


//这个类负责系统参数的设置和查询操作
public class SystemParameter_Manager {
	//查询系统参数
	static public SystemParameter getSystemParameter(){
		SystemParameter system_parameter = new SystemParameter();
		//DB query...
		return system_parameter;
	}
	
	//编辑新的系统配置信息
	static public Exp editSystemParameter(SystemParameter _new_config){
		Exp exp = new Exp();
		//
		return exp;
	}
}
