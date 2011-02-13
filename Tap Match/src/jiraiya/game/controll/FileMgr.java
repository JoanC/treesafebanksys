package jiraiya.game.controll;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

import main.SmallChangeUI;

import other.Debuger;

import com.wiyun.engine.types.WYPoint;

import android.R.integer;

import protocal.Protocal_file;

import jiraiya.game.data.Picture_small_struct;
import jiraiya.game.data.SmallPic_changeUI_data;
import jiraiya.game.data.menu_data_struct;
import jiraiya.game.data.menu_grobal_data_struct;
import jiraiya.game.data.sprite_data_struct;
import jiraiya.game.tap.MainGain;



public class FileMgr {
	public static Vector<String> readFileInfo(String _filename) throws IOException{
		InputStreamReader _input = 
			new InputStreamReader(MainGain.getAssetManager().open(_filename));
		BufferedReader _buf = new BufferedReader(_input);
		String _line = "";
		Vector<String> _result = new Vector<String>();
		while((_line = _buf.readLine()) != null) _result.add(_line);
		_input.close();
		return _result;
	}
	
	public static Vector<Vector<String>> getAllInfo(Vector<String> _all){
		//��ȡ��������"#"(tag)����Ϣģ��
		//����ģ����Ϣ����
		Vector<Vector<String>> _rlt = new Vector<Vector<String>>();
		for(int _index = 0;_index < _all.size() ; ++_index){
			if(_all.elementAt(_index).equals(Protocal_file.tag)){
				//�ҵ���һ��"#"(tag)
				Vector<String> _modle = new Vector<String>();
				int _sub = _index + 1;
				while(!_all.elementAt(_sub).equals(Protocal_file.tag)){
					//���ģ��
					_modle.add((_all.elementAt(_sub)));
					_sub ++;
				}
				_rlt.add(_modle);
				_index = _sub;
			}
		}
		return _rlt;
	}

	public static Vector<Object> readAllInfo(String _filename) throws IOException{
		//��ȡһ���ļ��е�������Ϣģ��,����Ϊһ��vector����ʽ
		Vector<Vector<String>> _all = 
			getAllInfo(readFileInfo(_filename));//ȡ�������ַ���Ϣ
		Vector<Object> _rlt = new Vector<Object>();
		//�ж�ÿ����Ϣģ��ı�ʶͷ
		for(int _index = 0 ; _index < _all.size() ; ++_index){
			//��һ��ȡ��Ϣģ��
			_rlt.add(getInfoModle(_all.elementAt(_index)));
		}
		return _rlt;
	}
	
	private static Object getInfoModle(Vector<String> _info){
		int _info_tag = Integer.parseInt(_info.elementAt(Protocal_file.infoID));
		switch (_info_tag) {
		case (Protocal_file.spriteTag): 
			return getSpriteInfoModle(_info);
		case (Protocal_file.menuTag):
			return getMenuGrobalInfoModle(_info);
		case (Protocal_file.menuItemTag):
			return getMenuItemInfoModle(_info);
		case (Protocal_file.changeUITag):
			return getChangeUIInfoModle(_info);
		case (Protocal_file.smallPicTag):
			return getSmallPicInfoModle(_info);
		default:
			return null;
		}
	}
	
	private static sprite_data_struct getSpriteInfoModle(Vector<String> _info){
		sprite_data_struct _sprite = new sprite_data_struct();
		//��Դ����
		int _resID =  Integer.parseInt(_info.elementAt(Protocal_file.spriteResourceNumID));
		_sprite.setResoruse_id(_resID);
		WYPoint _pos = WYPoint.make(Float.parseFloat(_info.elementAt( Protocal_file.spritePosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.spritePosY)));
		_sprite.setPosition(_pos);
		int _display_z = Integer.parseInt(_info.elementAt(Protocal_file.spriteDisplayZ));
		_sprite.setDisplay_z(_display_z);
		return _sprite;
	}
	
	private static menu_grobal_data_struct getMenuGrobalInfoModle(Vector<String> _info){
		menu_grobal_data_struct _menu = new menu_grobal_data_struct();
		//����
		WYPoint _pos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.menuPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.menuPosY)));
		_menu.setMenu_position(_pos);
		int _display_z = Integer.parseInt(_info.elementAt(Protocal_file.menuDisplayZ));
		_menu.setDisplay_z(_display_z);
		return _menu;
	}
	
	private static menu_data_struct getMenuItemInfoModle(Vector<String> _info){
		menu_data_struct _menuItem = new menu_data_struct();
		//�ַ���Ϣ
		String _str = _info.elementAt(Protocal_file.menuItemInfo);
		_menuItem.setMenu_item_text(_str);
		//����
		WYPoint _pos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.menuItemPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.menuItemPosY)));
		_menuItem.setMenu_item_pos(_pos);
		return _menuItem;
	}
	
	private static SmallPic_changeUI_data getChangeUIInfoModle(Vector<String> _info){
		SmallPic_changeUI_data _changeUiData = new SmallPic_changeUI_data();
		//��ʼ��һ��СĿ��ͼƬ��ID
		int _default_id = Integer.parseInt(_info.elementAt(Protocal_file.changUIDefaultID));
		_changeUiData.setCurrent(_default_id);
		//����Ļ�ϵ���ʾ����
		WYPoint _pos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.changeDisplayPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.changeDisplayPosY)));
		_changeUiData.setPosition(_pos);
		//СĿ��ͼƬ�ĸ���
		int _num = Integer.parseInt(_info.elementAt(Protocal_file.changeTargetNum));
		_changeUiData.setSmallTargetsSize(_num);
		//�����ж���С
		WYPoint _size = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.changeSizeX))
				,Float.parseFloat(_info.elementAt(Protocal_file.changeSizeY)));
		_changeUiData.setUiSize(_size);
		return _changeUiData;
	}
	
	private static Picture_small_struct getSmallPicInfoModle(Vector<String> _info){
		Picture_small_struct _smallInfo = new Picture_small_struct();
		//���ó�ʼ״̬
		int _current = Integer.parseInt(_info.elementAt(Protocal_file.smallPicDefaultStatus));
		_smallInfo.setStatus(_current);
		//������Դ��������
		int _rs = Integer.parseInt(_info.elementAt(Protocal_file.smallPicResourceID));
		_smallInfo.getSmall_picUI().setResoruse_id(_rs);
		//���Ͻ�����
		WYPoint _lupos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.smallPicLuPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.smllPicLuPosY)));
		_smallInfo.setLuPos(_lupos);
		//��ʾ������
		int _z = Integer.parseInt(_info.elementAt(Protocal_file.smallPicDisplayZ));
		_smallInfo.getSmall_picUI().setDisplay_z(_z);
		return _smallInfo;
	}
}
