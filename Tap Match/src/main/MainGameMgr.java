package main;

import java.io.IOException;
import java.util.Vector;

import other.Debuger;

import protocal.Protocal_UI;
import protocal.Protocal_bigPicHandleInputRlt;
import protocal.Protocal_bigPicStatus;
import protocal.Protocal_game_data;
import protocal.Protocal_smallPicStatus;
import jiraiya.game.controll.FileMgr;
import jiraiya.game.controll.UIManager;
import jiraiya.game.data.MainGame_data_struct;
import jiraiya.game.data.Picture_big_struct;
import jiraiya.game.data.Picture_small_struct;
import jiraiya.game.data.SmallPic_changeUI_data;
import jiraiya.game.data.StaticData;
import jiraiya.game.data.default_layer_text_data;
import jiraiya.game.data.sprite_data_struct;

import com.wiyun.engine.library.R;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.types.WYPoint;

/*
 * 作者:万君亚
 * 时间:2011.1.31
 * 说明:定义了主游戏驱动代码	
 * 			
 * 
 * 修改:万君亚
 * 日期:2011.2.2
 * 说明:添加了处理输入的函式
 */

public class MainGameMgr {
	MainGame_data_struct data = new MainGame_data_struct();
	BigPicture bigPictureMgr;
	SmallChangeUI targetChangeMgr;
	int mission = 0;
	
	
	
	public MainGameMgr(int _mission) {
		super();
		// TODO Auto-generated constructor stub
		mission = _mission;
		this.init();
	}

	public MainGame_data_struct readData(){
		//初始化所有数据...
		MainGame_data_struct InitData = new MainGame_data_struct();
		//从文件中读取数据
		try {
			Vector<Object> _datas = FileMgr.readAllInfo(Protocal_game_data.getFileName(mission));
			//目标切换数据设置
			SmallPic_changeUI_data _changeUiData = 
				(SmallPic_changeUI_data) _datas.elementAt(Protocal_game_data.targetChangeUIData);
			InitData.setTargetChange(_changeUiData);
			//大图片的UI数据
			sprite_data_struct _big = (sprite_data_struct) _datas.elementAt(Protocal_game_data.bigPicUIData);
			InitData.getBigPic().setBigPic(_big);
			//循环设置小目标图片
			Vector<Picture_small_struct> _small = new Vector<Picture_small_struct>();
			for (int _index = Protocal_game_data.smallPicDataStart; _index < InitData
					.getTargetChange().getSmallTargetsSize() + Protocal_game_data.smallPicDataStart
					; ++_index) {
				Picture_small_struct _tmp = (Picture_small_struct) _datas.elementAt(_index);
				//一致性设置<小目标图片的坐标与目标切换UI的坐标保持一致>
				_tmp.getSmall_picUI().setPosition(InitData.getTargetChange().getPosition());
				_small.add(_tmp);
			}
			//最后设置
			//设置目标集合
			InitData.getBigPic().setTargetsData(_small);
			//设置初始状态
			InitData.getBigPic().setStatus(Protocal_bigPicStatus.notaCompelish);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return InitData;
	}
	
	public void updateUI(Node _layer){
		bigPictureMgr.displayUI(_layer, targetChangeMgr.getCurrentTarget());
	}
	
	public void InputControll(WYPoint _input){
		//判定坐标范围
		if(this.isInputInBigPic(_input)){
			Debuger.printer("touch in big picture.");
			//调用BigPic的处理函式
			this.onBigPictureTouch(_input);
			return;
		}
		if(this.isInputInTargetChangeUI(_input)){
			Debuger.printer("touch in target change UI");
			targetChangeMgr.autoChangeTarget();
			bigPictureMgr.changeSmallTarget(targetChangeMgr.getCurrentTarget());
			return;
		}
	}
	
	/*
	 * 私有处理函式
	 */
	private void init(){
		data = readData();
		bigPictureMgr = new BigPicture(data.getBigPic());
		targetChangeMgr = new SmallChangeUI(data.getTargetChange());
		bigPictureMgr.changeSmallTarget(targetChangeMgr.getCurrentTarget());
	}
	
	private boolean isInputInBigPic(WYPoint _input){
		return StaticData.isPosInRect(_input, bigPictureMgr.getLuPos()
				,bigPictureMgr.getSize(), 0.0f);
	}
	
	private boolean isInputInTargetChangeUI(WYPoint _input){
		WYPoint _lu = StaticData.CalcuLuFronPosAndSize(data.getTargetChange().getPosition(),
				data.getTargetChange().getUiSize());
		return StaticData.isPosInRect(_input,_lu, data.getTargetChange().getUiSize(), 0.0f);
	}
	private void onBigPictureTouch(WYPoint _input){
		//点击大图片的响应处理函式
		switch (bigPictureMgr.handleInputPosition(_input)) {
		case Protocal_bigPicHandleInputRlt.targetChosen:
			Debuger.printer("choose a target succ!");
			targetChangeMgr.autoChangeTarget();
			bigPictureMgr.changeSmallTarget(targetChangeMgr.getCurrentTarget());
			break;
		default:
			Debuger.printer("nothing chosen!");
			break;
		}
	}
}
