package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

public class SmallPic_changeUI_data {
	int smallTargetsSize;
	int current;//当前的目标小图片在Vector中所处的位置情况
	WYPoint position;//小目标图片的显示坐标
	WYPoint uiSize;//这个小UI在屏幕上的坐标判定大小
	
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
