package main;

import java.util.Vector;

import other.Debuger;

import protocal.Protocal_UI;
import protocal.Protocal_bigPicHandleInputRlt;
import protocal.Protocal_smallPicHandleInputRlt;
import protocal.Protocal_smallPicStatus;

import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.types.WYPoint;

import jiraiya.game.controll.UIManager;
import jiraiya.game.data.Picture_big_struct;
import jiraiya.game.data.Picture_small_struct;
import jiraiya.game.data.StaticData;
import jiraiya.game.data.default_layer_text_data;
import jiraiya.game.data.sprite_data_struct;
import jiraiya.game.skeleton.Picture;

public class BigPicture implements Picture {
	Picture_big_struct InitData = null;//��ͼƬ������
	Vector<SmallPicture> targets = new Vector<SmallPicture>();//СĿ��ͼƬ��һά����
	

	public BigPicture(Picture_big_struct initData) {
		super();
		this.setData(initData);
		this.init();
	}

	private void setData(Picture_big_struct _data){
		InitData = _data;
	}
	
	@Override
	public void changeStatus(int _new) {
		// TODO Auto-generated method stub
		InitData.setStatus(_new);
	}

	@Override
	public sprite_data_struct getUIData() {
		// TODO Auto-generated method stub
		return InitData.getBigPic();
	}
	
	public sprite_data_struct getSmallPicUI(int _current){
		return targets.elementAt(_current).getUIData();
	}

	@Override
	public int handleInputPosition(WYPoint input) {
		// TODO Auto-generated method stub
		//��ÿһ��СĿ��ͼƬ������Ӧ���ж�
		for(int _index = 0; _index < targets.size(); ++_index){
			SmallPicture _small = targets.elementAt(_index);
			Debuger.printer("the small status is : " + _small.getStatus());
			if(_small.handleInputPosition(input) == Protocal_smallPicHandleInputRlt.selected){
				//ѡ��
				//����״̬
				selectSmallSucc(_small);
				return Protocal_bigPicHandleInputRlt.targetChosen;
			}
		}
		selectSmallFail();
		return Protocal_bigPicHandleInputRlt.nothingChosen;
	}
	
	public void changeSmallTarget(int _current){
		//�л�СĿ��ͼƬ��״̬
		if(_current < 0 || _current > targets.size() - 1){
			//Խ��
			return;
		}
		//����ѡ�е�ͼƬ���Ѿ���chosen��,��״̬����,�������״̬
		if(targets.elementAt(_current).getStatus() != Protocal_smallPicStatus.is_chosen){
			targets.elementAt(_current).changeStatus(Protocal_smallPicStatus.ready_to_choose);
		}
		//�������������Ľڵ�,����ǰ��ѡ��"ready"�ĸ�Ϊ"close"
		//��Ȼ,�Ѿ�isChosen�Ĳ����޸�
		for(int _index = 0 ; _index < targets.size() ; ++ _index){
			if(_index == _current) continue;//ֻ���������ڵ�
			if(targets.elementAt(_index).getStatus() != Protocal_smallPicStatus.is_chosen){
				targets.elementAt(_index).changeStatus(Protocal_smallPicStatus.close);
			}
		}
	}
	
	public void displayUI(Node _parent,int _target_id){
		//��ͼƬ
		UIManager.uiDisplay(this.getUIData(), _parent, Protocal_UI.sprite);
		//��ʱ��СͼƬ
		UIManager.uiDisplay(this.getSmallPicUI(_target_id),_parent, Protocal_UI.sprite);
	}
	
	//˽�д���ʽ
	private void selectSmallSucc(SmallPicture _be_selected){
		//�ɹ�ѡ��һ��СͼƬ�Ĳ�������
		_be_selected.changeStatus(Protocal_smallPicStatus.is_chosen);
	}
	
	private void selectSmallFail(){
		//ѡ��ʧ�ܵ���Ӧ����
	}
	
	private void init(){
		//��ʼ������
		if(InitData == null) return;
		//���������е�Ŀ��һά���������ɶ�Ӧ��targets
		Vector<Picture_small_struct> _data = InitData.getTargetsData();
		for(int _index = 0 ; _index < _data.size() ; ++_index){
			SmallPicture _new = new SmallPicture(_data.elementAt(_index));
			targets.add(_new);
		}
	}

	@Override
	public WYPoint getLuPos() {
		// TODO Auto-generated method stub
		return StaticData.CalcuLuFronPosAndSize(this.getUIData().getPosition(), 
				UIManager.getSpriteSize(this.getUIData()));
	}

	@Override
	public WYPoint getSize() {
		// TODO Auto-generated method stub
		return UIManager.getSpriteSize(this.getUIData());
	}
}
