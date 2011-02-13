package jiraiya.game.data;


/*
 * 作者:万君亚
 * 时间:2011.1.22
 * 说明:定义了default界面的布局数据结构,做为和xml通信的协议
 * 
 * 修改:万君亚
 * 日期:2011.1.24
 * 说明:将所有布局中的图片数据整理成一个结构体,保证数据完整性
 *         但是为了将底层的数据结构对xml数据接口不可见,仍然保持了所有基础接口
 */

public class Data_layer_default {
//default的层数据结构
	sprite_data_struct background = new sprite_data_struct();
	default_layer_text_data text = new default_layer_text_data();
	public sprite_data_struct getBackground() {
		return background;
	}
	public void setBackground(sprite_data_struct background) {
		this.background = background;
	}
	public default_layer_text_data getText() {
		return text;
	}
	public void setText(default_layer_text_data text) {
		this.text = text;
	}
}
