package main;

import other.Debuger;
import protocal.Protocal_smallPicHandleInputRlt;
import protocal.Protocal_smallPicStatus;

import com.wiyun.engine.types.WYPoint;

import jiraiya.game.controll.UIManager;
import jiraiya.game.data.Picture_small_struct;
import jiraiya.game.data.StaticData;
import jiraiya.game.data.sprite_data_struct;
import jiraiya.game.skeleton.Picture;

/*
 * 作者:万君亚
 * 时间:2011.1.27
 * 说明:定义了小目标图片的类以及底层的数据计算
 * 对于UI部分,交给Layer进行处理,但是所有关于小图片的UI数据都会从这个类中获取
 * 			
 * 
 * 修改:
 * 日期:
 * 说明:
 */

public class SmallPicture implements Picture {
	Picture_small_struct data = new Picture_small_struct();//小目标图片的数据结构
	public SmallPicture(Picture_small_struct _data) {
		super();
		// TODO Auto-generated constructor stub
		data = _data;
	}

	@Override
	public void changeStatus(int _new) {
		// TODO Auto-generated method stub
		data.setStatus(_new);
	}
	
	public int getStatus(){
		return data.getStatus();
	}

	@Override
	//该函数的返回值定义在Protocal_smallPicHandleInputRlt中
	public int handleInputPosition(WYPoint _input) {
		// TODO Auto-generated method stub
		if(data.getStatus() != Protocal_smallPicStatus.ready_to_choose){
			return Protocal_smallPicHandleInputRlt.noChange;
		}
		if(isInSmallPic(_input, data.getOffset())){
			return Protocal_smallPicHandleInputRlt.selected;
		}
		return Protocal_smallPicHandleInputRlt.noChange;
	}
	
	@Override
	public sprite_data_struct getUIData(){
		//返回小图片的UI显示信息
		return data.getSmall_picUI();
	}
	//内部处理函式
	private boolean isInSmallPic(WYPoint _pos,float _offset){
		WYPoint _lu = this.getLuPos();
		WYPoint _size = this.getSize();
		Debuger.printer("the lu position is : " + _lu.x + "," + _lu.y);
		Debuger.printer("the size is : " + _size.x + "," + _size.y);
		Debuger.printer("the offset is : " + _offset);
		return StaticData.isPosInRect(_pos, _lu, _size, _offset);
	}

	@Override
	public WYPoint getLuPos() {
		//相对于大图片左上角的坐标
		return data.getLuPos();
	}

	@Override
	public WYPoint getSize() {
		// TODO Auto-generated method stub
		return UIManager.getSpriteSize(data.getSmall_picUI());
	}
}
