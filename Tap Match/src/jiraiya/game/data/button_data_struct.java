package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

/*
 * 作者:万君亚
 * 时间:2011.1.24
 * 说明:定义了一个按钮的基础数据,该按钮基于图片,
 *         分别定义了三种不同状态下的图片id
 * 
 * 修改:
 * 日期:
 * 说明:
 */

public class button_data_struct {
	int nomal_resourse_id;//正常状态下的资源号码
	int select_resourse_id;//被选中状态下的资源号码
	int disable_resourse_id;//禁用状态下的资源号码
	int display_z;//显示层次
	WYPoint position;//按钮的位置坐标
	public int getNomal_resourse_id() {
		return nomal_resourse_id;
	}
	public void setNomal_resourse_id(int nomalResourseId) {
		nomal_resourse_id = nomalResourseId;
	}
	public int getSelect_resourse_id() {
		return select_resourse_id;
	}
	public void setSelect_resourse_id(int selectResourseId) {
		select_resourse_id = selectResourseId;
	}
	public int getDisable_resourse_id() {
		return disable_resourse_id;
	}
	public void setDisable_resourse_id(int disableResourseId) {
		disable_resourse_id = disableResourseId;
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
