package db_data_structure;

//���ѡ��ϵͳ�����Ľṹ��
public class SystemParameter {
	boolean isCsOpened;//ѡ��ϵͳ��ǰ�Ƿ񿪷�
	int csType;//ѡ����ȡ������,<�������>/<�ȵ��ȵ�>
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

