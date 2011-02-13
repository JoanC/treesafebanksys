package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

public class menu_grobal_data_struct {
	WYPoint menu_position;//菜单在屏幕上的相对坐标
	int display_z = 0;
	public WYPoint getMenu_position() {
		return menu_position;
	}
	public void setMenu_position(WYPoint menuPosition) {
		menu_position = menuPosition;
	}
	public int getDisplay_z() {
		return display_z;
	}
	public void setDisplay_z(int displayZ) {
		display_z = displayZ;
	}	
}
