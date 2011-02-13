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
 * 作者:万君亚
 * 时间:2011.1.22
 * 说明:定义了default界面类
 * 		|readData函数目前采用人工赋值的方法进行基础测试	
 * 			
 * 
 * 修改:
 * 日期:
 * 说明:
 */

public class Default_layer extends Layer implements Layer_Struct {
	private Data_layer_default data;//default类的层数据结构

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
		    //根据协议填充
			sprite_data_struct _background = (sprite_data_struct) _data_info.elementAt(Protocal_default.spriteInfoNum);
		    _tmp.setBackground(_background);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//获取背景图片的相关数据
		//other data loading...
		return _tmp;
	}
	 
	 //层转化,从default转化到menu
	   @Override
		public boolean wyTouchesBegan(MotionEvent event) {
		   //点击后的处理函数,跳转到菜单界面
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
