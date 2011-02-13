package layers;

import static android.view.KeyEvent.KEYCODE_BACK;

import java.io.IOException;
import java.util.Vector;

import protocal.Protocal_layers;
import protocal.Protocal_menu;
import jiraiya.game.controll.FileMgr;
import jiraiya.game.data.Data_layer_menu;
import jiraiya.game.data.StaticData;
import jiraiya.game.data.menu_data_struct;
import jiraiya.game.data.menu_grobal_data_struct;
import jiraiya.game.skeleton.Layer_Struct;

import android.view.KeyEvent;

import com.wiyun.engine.nodes.Menu;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.types.WYPoint;

/*
 * 作者:万君亚
 * 时间:2011.1.22
 * 说明:定义了menu界面类
 * 		|readData函数目前采用人工赋值的方法进行基础测试	
 * 			
 * 
 * 修改:万君亚
 * 日期:2011.1.24
 * 说明:增加各个回调函数的函数体,函数名称与menu的协议一致
 * 
 * 
 * 修改:万君亚
 * 日期:2011.2.6
 * 说明:将数据读取函数改为文件读取形式,便于维护
 */

public class Menu_layer extends Layer implements Layer_Struct {
	private Data_layer_menu menu_data;

	public Menu_layer() {
		super();
		// TODO Auto-generated constructor stub
		this.generateLayer();
	}

	@Override
	public void generateLayer() {
		// TODO Auto-generated method stub
		menu_data = (Data_layer_menu) readData();
		Menu _menu = this.generateMenu(menu_data);
		this.addChild(_menu,menu_data.getGrobal_data().getDisplay_z());
	}

	@Override
	public Object readData() {
		// TODO Auto-generated method stub
		// 读取数据接口
		Data_layer_menu _data = new Data_layer_menu();
		//读取文件
		try {
			Vector<Object> _info = FileMgr.readAllInfo(Protocal_menu.menuDataFileName);
			//取得宏观信息
			_data.setGrobal_data((menu_grobal_data_struct)_info.elementAt(Protocal_menu.menuGrobalInfo));
			//循环取得菜单项的信息
			for(int _index = Protocal_menu.menuItemInfoStartID 
					; _index < Protocal_menu.menuItemInfoEndID + 1 ; ++_index){
				_data.getMenu_data().add((menu_data_struct)_info.elementAt(_index));
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		//设置menu屏幕上的坐标
//		_data.setMenu_position(WYPoint.make(240, 90));
		// 暂时用字符串进行测试
//		menu_data_struct _item_info_1 = new menu_data_struct();
//		_item_info_1.setMenu_item_text("Play");
//		_item_info_1.setMenu_item_pos(WYPoint.make(0, 200));
//		menu_data_struct _item_info_2 = new menu_data_struct();
//		_item_info_2.setMenu_item_text("Select");
//		_item_info_2.setMenu_item_pos(WYPoint.make(0, 150));
//		menu_data_struct _item_info_3 = new menu_data_struct();
//		_item_info_3.setMenu_item_text("High Score");
//		_item_info_3.setMenu_item_pos(WYPoint.make(0, 100));
//		menu_data_struct _item_info_4 = new menu_data_struct();
//		_item_info_4.setMenu_item_text("About");
//		_item_info_4.setMenu_item_pos(WYPoint.make(0, 50));
//		menu_data_struct _item_info_5 = new menu_data_struct();
//		_item_info_5.setMenu_item_text("Help");
//		_item_info_5.setMenu_item_pos(WYPoint.make(0, 0));
//		menu_data_struct _item_info_6 = new menu_data_struct();
//		_item_info_6.setMenu_item_text("Quit");
//		_item_info_6.setMenu_item_pos(WYPoint.make(0, -50));
//		//添加菜单选项
//		_data.getMenu_data().add(_item_info_1);
//		_data.getMenu_data().add(_item_info_2);
//		_data.getMenu_data().add(_item_info_3);
//		_data.getMenu_data().add(_item_info_4);
//		_data.getMenu_data().add(_item_info_5);
//		_data.getMenu_data().add(_item_info_6);
		
		return _data;
	}

	private MenuItemLabel makeMenuItem(menu_data_struct _data,int _menu_protocol_id) {
		//生成菜单选项,与菜单数据协议的交互入口
		MenuItemLabel _item = MenuItemLabel.make(_data.getMenu_item_text(),
				this, Protocal_menu.callBackFunc[_menu_protocol_id]);
		_item.setPosition(_data.getMenu_item_pos());//设置菜单布局坐标,从数据接口中给入
		return _item;
	}

	private Menu generateMenu(Data_layer_menu _data) {
		/*makeMenuItem(_data.getMenu_data().elementAt(0),Protocal_menu.menu_play_id)*/
		Menu _menu = Menu.make(makeMenuItem(_data.getMenu_data().elementAt(Protocal_menu.menu_play_id),
				Protocal_menu.menu_play_id)
				);//用数据中的第一个数据建立新的menu
		for(int _index = 1 ; _index < _data.getMenu_data().size() ; ++_index){
			//第二个index保证与协议的一致性
			_menu.addChild(makeMenuItem(_data.getMenu_data().elementAt(_index), _index));
		}
		_menu.setPosition(_data.getGrobal_data().getMenu_position());//设置菜单坐标
		return _menu;
	}

	public void onPlayNewGame() {
		// 点击play按钮后
		// 切换到一个新的layer
		StaticData.changeScene(Protocal_layers.game_layer);
	}
	
	public void onSelectMission(){
		//点击后切换到select的界面中去
		StaticData.changeScene(Protocal_layers.select_layer);
	}
	
	public void onQuit(){
		//退出程序,对应于quit按钮
		//回调函数说明,在文件 Protocal_menu.java 中
		Director.getInstance().end();
	}
	
	@Override
	public boolean wyKeyDown(KeyEvent event){
		//??如何处理回退的按键处理?
		if(event.getKeyCode() == KEYCODE_BACK){
			//Director.getInstance().popScene();
			return true;
		}
		return false;
	}
}
