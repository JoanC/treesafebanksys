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
 * ����:�����
 * ʱ��:2011.1.22
 * ˵��:������menu������
 * 		|readData����Ŀǰ�����˹���ֵ�ķ������л�������	
 * 			
 * 
 * �޸�:�����
 * ����:2011.1.24
 * ˵��:���Ӹ����ص������ĺ�����,����������menu��Э��һ��
 * 
 * 
 * �޸�:�����
 * ����:2011.2.6
 * ˵��:�����ݶ�ȡ������Ϊ�ļ���ȡ��ʽ,����ά��
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
		// ��ȡ���ݽӿ�
		Data_layer_menu _data = new Data_layer_menu();
		//��ȡ�ļ�
		try {
			Vector<Object> _info = FileMgr.readAllInfo(Protocal_menu.menuDataFileName);
			//ȡ�ú����Ϣ
			_data.setGrobal_data((menu_grobal_data_struct)_info.elementAt(Protocal_menu.menuGrobalInfo));
			//ѭ��ȡ�ò˵������Ϣ
			for(int _index = Protocal_menu.menuItemInfoStartID 
					; _index < Protocal_menu.menuItemInfoEndID + 1 ; ++_index){
				_data.getMenu_data().add((menu_data_struct)_info.elementAt(_index));
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		//����menu��Ļ�ϵ�����
//		_data.setMenu_position(WYPoint.make(240, 90));
		// ��ʱ���ַ������в���
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
//		//��Ӳ˵�ѡ��
//		_data.getMenu_data().add(_item_info_1);
//		_data.getMenu_data().add(_item_info_2);
//		_data.getMenu_data().add(_item_info_3);
//		_data.getMenu_data().add(_item_info_4);
//		_data.getMenu_data().add(_item_info_5);
//		_data.getMenu_data().add(_item_info_6);
		
		return _data;
	}

	private MenuItemLabel makeMenuItem(menu_data_struct _data,int _menu_protocol_id) {
		//���ɲ˵�ѡ��,��˵�����Э��Ľ������
		MenuItemLabel _item = MenuItemLabel.make(_data.getMenu_item_text(),
				this, Protocal_menu.callBackFunc[_menu_protocol_id]);
		_item.setPosition(_data.getMenu_item_pos());//���ò˵���������,�����ݽӿ��и���
		return _item;
	}

	private Menu generateMenu(Data_layer_menu _data) {
		/*makeMenuItem(_data.getMenu_data().elementAt(0),Protocal_menu.menu_play_id)*/
		Menu _menu = Menu.make(makeMenuItem(_data.getMenu_data().elementAt(Protocal_menu.menu_play_id),
				Protocal_menu.menu_play_id)
				);//�������еĵ�һ�����ݽ����µ�menu
		for(int _index = 1 ; _index < _data.getMenu_data().size() ; ++_index){
			//�ڶ���index��֤��Э���һ����
			_menu.addChild(makeMenuItem(_data.getMenu_data().elementAt(_index), _index));
		}
		_menu.setPosition(_data.getGrobal_data().getMenu_position());//���ò˵�����
		return _menu;
	}

	public void onPlayNewGame() {
		// ���play��ť��
		// �л���һ���µ�layer
		StaticData.changeScene(Protocal_layers.game_layer);
	}
	
	public void onSelectMission(){
		//������л���select�Ľ�����ȥ
		StaticData.changeScene(Protocal_layers.select_layer);
	}
	
	public void onQuit(){
		//�˳�����,��Ӧ��quit��ť
		//�ص�����˵��,���ļ� Protocal_menu.java ��
		Director.getInstance().end();
	}
	
	@Override
	public boolean wyKeyDown(KeyEvent event){
		//??��δ�����˵İ�������?
		if(event.getKeyCode() == KEYCODE_BACK){
			//Director.getInstance().popScene();
			return true;
		}
		return false;
	}
}
