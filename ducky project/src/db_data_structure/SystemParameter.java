package db_data_structure;

//存放选课系统参数的结构体
public class SystemParameter {
	boolean isCsOpened;//选课系统当前是否开放
	int csType;//选课所取得类型,<随机踢人>/<先到先得>
	public boolean isCsOpened() {
		return isCsOpened;
	}
	public void setCsOpened(boolean isCsOpened) {
		this.isCsOpened = isCsOpened;
	}
	public int getCsType() {
		return csType;
	}
	public void setCsType(int csType) {
		this.csType = csType;
	}
}

