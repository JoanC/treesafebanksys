package jiraiya.game.skeleton;

import jiraiya.game.data.sprite_data_struct;

import com.wiyun.engine.types.WYPoint;

/*
 * 作者:万君亚
 * 时间:2011.1.26
 * 说明:定义了游戏中图片的相关接口,这些接口都适应于大图片和小目标图片
 * 			
 * 
 * 
 * 修改:万君亚
 * 日期:2011.1.27
 * 说明:完善接口函数
 * 
 * 
 * 修改:万君亚
 * 日期:2011.2.1
 * 说明:添加接口,以获取左上角坐标和size大小
 * 
 * 
 */

public interface Picture {
	/*取得左上角坐标
	 * 左上角坐标相对处不同,对于大图片来说,这个坐标相对于屏幕左上角
	 * 对于小目标图片来说,这相对于大图片左上角
	 * 而小目标的左上角坐标转化为相对屏幕上的左上角坐标则在StaticData中定义实现
	 */
	public WYPoint getLuPos();
	/*取得大小
	 * 均为对应图片的相应大小
	 */
	public WYPoint getSize();
	/*处理输入的坐标
	 * 对于大图片和小目标图片,两者的处理方式不同
	 * 在大图片中,应该去调用对应的小图片的坐标处理函式
	 */
	public int handleInputPosition(WYPoint _input);
	/*更改picture的状态,都是int,但是小目标图片的状态协议
	 * 与大图片的不同,分别定义在不同的协议数据中
	 */
	public void changeStatus(int _new);
	/*取得所有的UI数据信息,其实就是一个sprite_data_struct
	 * 每当图片更替,都在数据类中处理数据,再由layer重新得到数据,再刷新显示
	 */
	abstract sprite_data_struct getUIData();
	/*根据状态的不同,UI的数据也不一样
	 * 根据一个新的状态(在协议中定义),修改相应的UI数据
	 */
}
