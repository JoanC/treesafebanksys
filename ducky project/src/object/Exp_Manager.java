package object;


import object.Exp;


//这个类主要对所有的异常数据做一个管理
public class Exp_Manager {
	//根据错误代码获取错误信息
	static public Exp searchExpInfo(int err_no){
		Exp exp = new Exp();
		//DB query...
		return exp;
	}
}
