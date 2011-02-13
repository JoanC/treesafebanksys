package jiraiya.game.controll;

import protocal.Protocal_UI;

import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYPoint;

import jiraiya.game.data.label_data_struct;
import jiraiya.game.data.sprite_data_struct;

/*
 * 作者:万君亚
 * 时间:2011.1.27
 * 说明:定义了各个Node的显示函式,即根据
 * 修改:
 * 日期:
 * 说明:
 */

public class UIManager {
	public static Node uiDisplay(Object _data,Node _parent,int _ui_protocal){
		switch (_ui_protocal) {
		case Protocal_UI.sprite:
			return spriteDisplay((sprite_data_struct)_data, _parent);
		case Protocal_UI.label:
			return labelDisplay((label_data_struct)_data, _parent);
		}
		return null;
	}
	
	private static Sprite spriteDisplay(sprite_data_struct _data,Node _parent){
		Sprite _tmp = Sprite.make(_data.getResoruse_id());
		_tmp.setPosition(_data.getPosition());
		_parent.addChild(_tmp,_data.getDisplay_z());
		return _tmp;
	}
	
	private static Label labelDisplay(label_data_struct _data,Node _parent){
		Label _tmp = Label.make(_data.getInfo(),
				_data.getFontSize(), _data.getFontName(),_data.getType());
		_tmp.setPosition(_data.getPostion());
		_parent.addChild(_tmp, _data.getDisplay_z());
		return _tmp;
	}
	
	public static WYPoint getSpriteSize(sprite_data_struct _data){
		WYPoint _size = WYPoint.make(0, 0);
		if(_data.getResoruse_id() == 0) return _size;
		Sprite _tmp = Sprite.make(_data.getResoruse_id());
		_size.x = _tmp.getWidth();
		_size.y = _tmp.getHeight();
		return _size;
	}
	
	public static void removeUI(Node _ui,Node _parent){
		_parent.removeChild(_ui,true);//删除一个UI
		_ui.releaseNative();
	}
}
