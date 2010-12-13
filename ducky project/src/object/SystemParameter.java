package object;


//这个类负责对系统参数的存储和读取
public class SystemParameter {
	boolean is_cs_opened;		//选课功能是否开放
	int cs_type;				//选课类型
	
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
