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
 * ����:�����
 * ʱ��:2011.1.31
 * ˵��:����������Ϸ��������	
 * 			
 * 
 * �޸�:�����
 * ����:2011.2.2
 * ˵��:����˴�������ĺ�ʽ
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
		//��ʼ����������...
		MainGame_data_struct InitData = new MainGame_data_struct();
		//���ļ��ж�ȡ����
		try {
			Vector<Object> _datas = FileMgr.readAllInfo(Protocal_game_data.getFileName(mission));
			//Ŀ���л���������
			SmallPic_changeUI_data _changeUiData = 
				(SmallPic_changeUI_data) _datas.elementAt(Protocal_game_data.targetChangeUIData);
			InitData.setTargetChange(_changeUiData);
			//��ͼƬ��UI����
			sprite_data_struct _big = (sprite_data_struct) _datas.elementAt(Protocal_game_data.bigPicUIData);
			InitData.getBigPic().setBigPic(_big);
			//ѭ������СĿ��ͼƬ
			Vector<Picture_small_struct> _small = new Vector<Picture_small_struct>();
			for (int _index = Protocal_game_data.smallPicDataStart; _index < InitData
					.getTargetChange().getSmallTargetsSize() + Protocal_game_data.smallPicDataStart
					; ++_index) {
				Picture_small_struct _tmp = (Picture_small_struct) _datas.elementAt(_index);
				//һ��������<СĿ��ͼƬ��������Ŀ���л�UI�����걣��һ��>
				_tmp.getSmall_picUI().setPosition(InitData.getTargetChange().getPosition());
				_small.add(_tmp);
			}
			//�������
			//����Ŀ�꼯��
			InitData.getBigPic().setTargetsData(_small);
			//���ó�ʼ״̬
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
		//�ж����귶Χ
		if(this.isInputInBigPic(_input)){
			Debuger.printer("touch in big picture.");
			//����BigPic�Ĵ���ʽ
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
	 * ˽�д���ʽ
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
		//�����ͼƬ����Ӧ����ʽ
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
