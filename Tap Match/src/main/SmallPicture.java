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
 * ����:�����
 * ʱ��:2011.1.27
 * ˵��:������СĿ��ͼƬ�����Լ��ײ�����ݼ���
 * ����UI����,����Layer���д���,�������й���СͼƬ��UI���ݶ����������л�ȡ
 * 			
 * 
 * �޸�:
 * ����:
 * ˵��:
 */

public class SmallPicture implements Picture {
	Picture_small_struct data = new Picture_small_struct();//СĿ��ͼƬ�����ݽṹ
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
	//�ú����ķ���ֵ������Protocal_smallPicHandleInputRlt��
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
		//����СͼƬ��UI��ʾ��Ϣ
		return data.getSmall_picUI();
	}
	//�ڲ�����ʽ
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
		//����ڴ�ͼƬ���Ͻǵ�����
		return data.getLuPos();
	}

	@Override
	public WYPoint getSize() {
		// TODO Auto-generated method stub
		return UIManager.getSpriteSize(data.getSmall_picUI());
	}
}
