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
	Picture_big_struct InitData = null;//大图片的数据
	Vector<SmallPicture> targets = new Vector<SmallPicture>();//小目标图片的一维数组
	

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
		//对每一个小目标图片进行相应的判定
		for(int _index = 0; _index < targets.size(); ++_index){
			SmallPicture _small = targets.elementAt(_index);
			Debuger.printer("the small status is : " + _small.getStatus());
			if(_small.handleInputPosition(input) == Protocal_smallPicHandleInputRlt.selected){
				//选中
				//更新状态
				selectSmallSucc(_small);
				return Protocal_bigPicHandleInputRlt.targetChosen;
			}
		}
		selectSmallFail();
		return Protocal_bigPicHandleInputRlt.nothingChosen;
	}
	
	public void changeSmallTarget(int _current){
		//切换小目标图片的状态
		if(_current < 0 || _current > targets.size() - 1){
			//越界
			return;
		}
		//将被选中的图片若已经被chosen过,则状态不变,否则更改状态
		if(targets.elementAt(_current).getStatus() != Protocal_smallPicStatus.is_chosen){
			targets.elementAt(_current).changeStatus(Protocal_smallPicStatus.ready_to_choose);
		}
		//遍历所有其它的节点,将先前被选中"ready"的改为"close"
		//当然,已经isChosen的不用修改
		for(int _index = 0 ; _index < targets.size() ; ++ _index){
			if(_index == _current) continue;//只遍历其它节点
			if(targets.elementAt(_index).getStatus() != Protocal_smallPicStatus.is_chosen){
				targets.elementAt(_index).changeStatus(Protocal_smallPicStatus.close);
			}
		}
	}
	
	public void displayUI(Node _parent,int _target_id){
		//大图片
		UIManager.uiDisplay(this.getUIData(), _parent, Protocal_UI.sprite);
		//此时的小图片
		UIManager.uiDisplay(this.getSmallPicUI(_target_id),_parent, Protocal_UI.sprite);
	}
	
	//私有处理函式
	private void selectSmallSucc(SmallPicture _be_selected){
		//成功选择一个小图片的操作过程
		_be_selected.changeStatus(Protocal_smallPicStatus.is_chosen);
	}
	
	private void selectSmallFail(){
		//选择失败的相应操作
	}
	
	private void init(){
		//初始化数据
		if(InitData == null) return;
		//根据数据中的目标一维数据项生成对应的targets
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
