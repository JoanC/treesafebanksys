package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

public class SmallPic_changeUI_data {
	int smallTargetsSize;
	int current;//��ǰ��Ŀ��СͼƬ��Vector��������λ�����
	WYPoint position;//СĿ��ͼƬ����ʾ����
	WYPoint uiSize;//���СUI����Ļ�ϵ������ж���С
	
	public int getSmallTargetsSize() {
		return smallTargetsSize;
	}
	public void setSmallTargetsSize(int smallTargetsSize) {
		this.smallTargetsSize = smallTargetsSize;
	}
	public WYPoint getPosition() {
		return position;
	}
	public void setPosition(WYPoint position) {
		this.position = position;
	}
	public int getCurrent() {
		return current;
	}
	public void setCurrent(int current) {
		this.current = current;
	}
	public WYPoint getUiSize() {
		return uiSize;
	}
	public void setUiSize(WYPoint uiSize) {
		this.uiSize = uiSize;
	}
}
