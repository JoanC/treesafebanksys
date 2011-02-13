package layers;

import java.io.IOException;
import java.util.Vector;

import other.Debuger;
import protocal.Protocal_UI;
import protocal.Protocal_default;
import protocal.Protocal_file;
import protocal.Protocal_game_data;
import protocal.Protocal_layers;
import protocal.Protocal_menu;
import jiraiya.game.controll.FileMgr;
import jiraiya.game.controll.UIManager;
import jiraiya.game.data.Data_layer_default;
import jiraiya.game.data.StaticData;
import jiraiya.game.data.default_layer_text_data;
import jiraiya.game.data.sprite_data_struct;
import jiraiya.game.skeleton.Layer_Struct;

import android.util.Log;
import android.view.MotionEvent;

import com.wiyun.engine.library.R;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;


/*
 * ����:�����
 * ʱ��:2011.1.22
 * ˵��:������default������
 * 		|readData����Ŀǰ�����˹���ֵ�ķ������л�������	
 * 			
 * 
 * �޸�:
 * ����:
 * ˵��:
 */

public class Default_layer extends Layer implements Layer_Struct {
	private Data_layer_default data;//default��Ĳ����ݽṹ

	public Default_layer() {
		super();
		// TODO Auto-generated constructor stub
		Debuger.fprinter("Hi");
		this.generateLayer();
	}

	public void generateLayer() {
		// TODO Auto-generated method stub
		data = this.readData();
		UIManager.uiDisplay(data.getBackground(), this,Protocal_UI.sprite);
		this.setTouchEnabled(true);
	}

	public Data_layer_default readData() {
		// TODO Auto-generated method stub
		Data_layer_default _tmp = new Data_layer_default();
		try {
			Vector<Object> _data_info = FileMgr.readAllInfo(Protocal_default.defaultDataFile);
		    //����Э�����
			sprite_data_struct _background = (sprite_data_struct) _data_info.elementAt(Protocal_default.spriteInfoNum);
		    _tmp.setBackground(_background);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//��ȡ����ͼƬ���������
		//other data loading...
		return _tmp;
	}
	 
	 //��ת��,��defaultת����menu
	   @Override
		public boolean wyTouchesBegan(MotionEvent event) {
		   //�����Ĵ�����,��ת���˵�����
		  StaticData.changeScene(Protocal_layers.menu_layer);
//	   try {
//		   sprite_data_struct _tmp = (sprite_data_struct)(FileMgr.readAllInfo(Protocal_game_data.getFileName(1)).elementAt(1));
//		   Debuger.printer("the rs is " + _tmp.getResoruse_id());
//	   } catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		   return true;
		}
	}
