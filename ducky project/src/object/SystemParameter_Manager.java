package object;


import object.SystemParameter;


//����ฺ��ϵͳ���������úͲ�ѯ����
public class SystemParameter_Manager {
	//��ѯϵͳ����
	static public SystemParameter getSystemParameter(){
		SystemParameter system_parameter = new SystemParameter();
		//DB query...
		return system_parameter;
	}
	
	//�༭�µ�ϵͳ������Ϣ
	static public Exp editSystemParameter(SystemParameter _new_config){
		Exp exp = new Exp();
		//
		return exp;
	}
}
