package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

/*
 * 作者:万君亚
 * 时间:2011.1.24
 * 说明:定义了一个图片持有的一般数据	
 * 			
 * 
 * 修改:
 * 日期:
 * 说明:
 * 
 */

public class sprite_data_struct {
	private int resoruse_id = 0;//资源id,本项目中所有的资源以整数形式进行存储
	private WYPoint position;//图片的位置数据
	private int display_z;//显示时的前后关系
	
	public int getResoruse_id() {
		return resoruse_id;
	}
	public void setResoruse_id(int resoruseId) {
		resoruse_id = resoruseId;
	}
	public WYPoint getPosition() {
		return position;
	}
	public void setPosition(WYPoint position) {
		this.position = position;
	}
	public int getDisplay_z() {
		return display_z;
	}
	public void setDisplay_z(int displayZ) {
		display_z = displayZ;
	}
}
