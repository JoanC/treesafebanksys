package object;

import db_data_structure.SysParam;




//����ฺ��ϵͳ���������úͲ�ѯ����
public class SystemParameter_Manager {
	//��ѯϵͳ����
	static public SysParam getSystemParameter(){
		SysParam system_parameter = new SysParam();
		//DB query...
		return system_parameter;
	}
	
	//�༭�µ�ϵͳ������Ϣ
	static public Exp editSystemParameter(SysParam _new_config){
		Exp exp = new Exp();
		//
		return exp;
	}
}
