package object;


//����ฺ���ϵͳ�����Ĵ洢�Ͷ�ȡ
public class SystemParameter {
	boolean is_cs_opened;		//ѡ�ι����Ƿ񿪷�
	int cs_type;				//ѡ������
	
	public boolean isIs_cs_opened() {
		return is_cs_opened;
	}
	
	public void setIs_cs_opened(boolean isCsOpened) {
		is_cs_opened = isCsOpened;
	}
	
	public int getCs_type() {
		return cs_type;
	}
	
	public void setCs_type(int csType) {
		cs_type = csType;
	}
}
