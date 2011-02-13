package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

public class menu_data_struct{
	String menu_item_text;//菜单上的文字说明
	int menu_item_rsId;//菜单对应图片的资源id
	WYPoint menu_item_pos;//菜单项的相对位置坐标
	
	public String getMenu_item_text() {
		return menu_item_text;
	}
	public void setMenu_item_text(String menuItemText) {
		menu_item_text = menuItemText;
	}
	public int getMenu_item_rsId() {
		return menu_item_rsId;
	}
	public void setMenu_item_rsId(int menuItemRsId) {
		menu_item_rsId = menuItemRsId;
	}
	public WYPoint getMenu_item_pos() {
		return menu_item_pos;
	}
	public void setMenu_item_pos(WYPoint menuItemPos) {
		menu_item_pos = menuItemPos;
	}
	
}
