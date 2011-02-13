package jiraiya.game.data;

import java.util.Vector;

/*
 * 作者:万君亚
 * 时间:2011.1.30
 * 说明:定义了大图片的基本数据	
 * 			
 * 修改:
 * 日期:
 * 说明:
 */

public class Picture_big_struct {
	sprite_data_struct bigPic;// 大图片的UI数据
	Vector<Picture_small_struct> targetsData = new Vector<Picture_small_struct>();// 目标小图片的数据集合
	int status;//大图的状态,所有状态值定义在Protocal_bigPicStatus类中
	public sprite_data_struct getBigPic() {
		return bigPic;
	}
	public void setBigPic(sprite_data_struct bigPic) {
		this.bigPic = bigPic;
	}
	public Vector<Picture_small_struct> getTargetsData() {
		return targetsData;
	}
	public int getStatus() {
		return status;
	}
	public void setStatus(int status) {
		this.status = status;
	}
	public void setTargetsData(Vector<Picture_small_struct> targetsData) {
		this.targetsData = targetsData;
	}
}
