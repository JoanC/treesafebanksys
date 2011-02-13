package jiraiya.game.data;

import java.util.Vector;

import com.wiyun.engine.types.WYPoint;

public class Data_layer_menu {
	//宏观数据
	menu_grobal_data_struct grobal_data;
	//菜单的数据一维结构
	public Vector<menu_data_struct> menu_data = new Vector<menu_data_struct>();
	public Vector<menu_data_struct> getMenu_data() {
		return menu_data;
	}
	public menu_grobal_data_struct getGrobal_data() {
		return grobal_data;
	}
	public void setGrobal_data(menu_grobal_data_struct grobalData) {
		grobal_data = grobalData;
	}
}
