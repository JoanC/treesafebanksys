package jiraiya.game.data;

import com.wiyun.engine.types.WYPoint;

/*
 * 作者:万君亚
 * 时间:2011.1.26
 * 说明:定义了小目标图片的数据结构
 * 			
 * 
 * 修改:
 * 日期:
 * 说明:
 */

public class Picture_small_struct {
	//UI显示层
	sprite_data_struct small_picUI = new sprite_data_struct();
	//数据层
	//计算数据值,用于表示其在大图片中的相对位置以及为计算进行准备
	/*注意,UI显示的pos值与数据中相对大图片的坐标值是不同的*/
	WYPoint luPos;//<left_up>左上角的坐标值
	WYPoint smallPicSize; //定义了小目标图片在大图片中所占的大小,实际上,这个大小应该跟UI中所显示的图片保持一致
	int status;//小目标图片的状态,其值被定义在协议Protocal_smallPicStatus中
	float offset = 5.0f;//进行输入坐标判定时,四周的偏差值数据
	public WYPoint getLuPos() {
		return luPos;
	}
	public void setLuPos(WYPoint luPos) {
		this.luPos = luPos;
	}
	public WYPoint getSmallPicSize() {
		return smallPicSize;
	}
	public void setSmallPicSize(WYPoint size) {
		this.smallPicSize = size;
	}
	public int getStatus() {
		return status;
	}
	public void setStatus(int status) {
		this.status = status;
	}
	public sprite_data_struct getSmall_picUI() {
		return small_picUI;
	}
	public float getOffset() {
		return offset;
	}
	public void setOffset(float offset) {
		this.offset = offset;
	}
}
