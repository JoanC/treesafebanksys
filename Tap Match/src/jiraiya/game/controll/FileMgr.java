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
		//获取夹在两个"#"(tag)的信息模块
		//所有模块信息分组
		Vector<Vector<String>> _rlt = new Vector<Vector<String>>();
		for(int _index = 0;_index < _all.size() ; ++_index){
			if(_all.elementAt(_index).equals(Protocal_file.tag)){
				//找到第一个"#"(tag)
				Vector<String> _modle = new Vector<String>();
				int _sub = _index + 1;
				while(!_all.elementAt(_sub).equals(Protocal_file.tag)){
					//添加模块
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
		//获取一个文件中的所有信息模块,保存为一个vector的形式
		Vector<Vector<String>> _all = 
			getAllInfo(readFileInfo(_filename));//取得所有字符信息
		Vector<Object> _rlt = new Vector<Object>();
		//判断每个信息模块的标识头
		for(int _index = 0 ; _index < _all.size() ; ++_index){
			//逐一获取信息模块
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
		//资源号码
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
		//坐标
		WYPoint _pos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.menuPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.menuPosY)));
		_menu.setMenu_position(_pos);
		int _display_z = Integer.parseInt(_info.elementAt(Protocal_file.menuDisplayZ));
		_menu.setDisplay_z(_display_z);
		return _menu;
	}
	
	private static menu_data_struct getMenuItemInfoModle(Vector<String> _info){
		menu_data_struct _menuItem = new menu_data_struct();
		//字符信息
		String _str = _info.elementAt(Protocal_file.menuItemInfo);
		_menuItem.setMenu_item_text(_str);
		//坐标
		WYPoint _pos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.menuItemPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.menuItemPosY)));
		_menuItem.setMenu_item_pos(_pos);
		return _menuItem;
	}
	
	private static SmallPic_changeUI_data getChangeUIInfoModle(Vector<String> _info){
		SmallPic_changeUI_data _changeUiData = new SmallPic_changeUI_data();
		//初始第一个小目标图片的ID
		int _default_id = Integer.parseInt(_info.elementAt(Protocal_file.changUIDefaultID));
		_changeUiData.setCurrent(_default_id);
		//在屏幕上的显示坐标
		WYPoint _pos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.changeDisplayPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.changeDisplayPosY)));
		_changeUiData.setPosition(_pos);
		//小目标图片的个数
		int _num = Integer.parseInt(_info.elementAt(Protocal_file.changeTargetNum));
		_changeUiData.setSmallTargetsSize(_num);
		//触摸判定大小
		WYPoint _size = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.changeSizeX))
				,Float.parseFloat(_info.elementAt(Protocal_file.changeSizeY)));
		_changeUiData.setUiSize(_size);
		return _changeUiData;
	}
	
	private static Picture_small_struct getSmallPicInfoModle(Vector<String> _info){
		Picture_small_struct _smallInfo = new Picture_small_struct();
		//设置初始状态
		int _current = Integer.parseInt(_info.elementAt(Protocal_file.smallPicDefaultStatus));
		_smallInfo.setStatus(_current);
		//设置资源检索号码
		int _rs = Integer.parseInt(_info.elementAt(Protocal_file.smallPicResourceID));
		_smallInfo.getSmall_picUI().setResoruse_id(_rs);
		//左上角坐标
		WYPoint _lupos = WYPoint.make(Float.parseFloat(_info.elementAt(Protocal_file.smallPicLuPosX))
				,Float.parseFloat(_info.elementAt(Protocal_file.smllPicLuPosY)));
		_smallInfo.setLuPos(_lupos);
		//显示层数据
		int _z = Integer.parseInt(_info.elementAt(Protocal_file.smallPicDisplayZ));
		_smallInfo.getSmall_picUI().setDisplay_z(_z);
		return _smallInfo;
	}
}
