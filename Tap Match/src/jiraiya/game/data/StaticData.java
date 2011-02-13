package jiraiya.game.data;

import jiraiya.game.controll.LayerMaker;
import jiraiya.game.controll.SceneMaker;
import protocal.Protocal_layers;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;

public class StaticData {
	private static Layer currentLayer;//当前的Layer值
	public static WYPoint GetMiddleData(){
		//取得中心屏幕的位置
		WYPoint _pos = WYPoint.make(0, 0);
		//取得两个坐标值
		_pos.x = Director.getInstance().getWindowSize().width / 2;
		_pos.y = Director.getInstance().getWindowSize().height / 2;
		return _pos;
	}
	
	public static WYPoint GetScreenSize(){
		//取得屏幕的大小,宽 * 高
		return WYPoint.make(Director.getInstance().getWindowSize().width,
				Director.getInstance().getWindowSize().height);
	}
	
	/*以大图片的左上角为原点的相对坐标转化为在屏幕上相对的左上角坐标*/
	public static WYPoint ConvertFromBigPicPosToScreenPos(WYPoint _bigLuPos
			,WYPoint _bigPicPos/*小目标图片在大图片上的相对坐标*/){
		WYPoint _screenPos = WYPoint.make(0, 0);
		_screenPos.x = _bigLuPos.x + _bigPicPos.x;
		_screenPos.y = _bigLuPos.y + _bigPicPos.y;
		return _screenPos;
	}
	
	/*对于一个picture,根据给出的相对左上角坐标以及大小,会给出在屏幕上的显示坐标*/
	public static WYPoint CalcuPosFromLuAndSize(WYPoint _lu,WYPoint _size){
		WYPoint _pos = WYPoint.make(0, 0);
		_pos.x = _lu.x + (0.5f) * _size.x;
		_pos.y = GetScreenSize().y - _lu.y - (0.5f)*_size.y;
		return _pos;
	}
	
	/*对于一个picture,根据给出的中心坐标以及大小,给出相对屏幕的左上角*/
	public static WYPoint CalcuLuFronPosAndSize(WYPoint _pos,WYPoint _size){
		WYPoint _lu = WYPoint.make(0, 0);
		_lu.x = _pos.x - (0.5f) * _size.x;
		_lu.y = GetScreenSize().y - _pos.y - (0.5f) * _size.y;
		return _lu;
	}
	
	/*对于一个position,将其转化为相对于左上角的坐标*/
	public static WYPoint ConvertFromPosToLuPos(WYPoint _pos){
		WYPoint _new = WYPoint.make(0, 0);
		_new.x = _pos.x;
		_new.y = GetScreenSize().y - _pos.y;
		return _new;
	}
	
	/*判断一个坐标是否在一个矩形内部,给出的是左上角坐标和矩形的大小*/
	/*返回true表示是在矩形内部,false表示在矩形外部*/
	public static boolean isPosInRect(WYPoint _pos,WYPoint _rectLu,WYPoint _rectSize,float _offset){
		if(_pos.x < _rectLu.x - _offset) return false;
		if(_pos.x > _rectLu.x + _rectSize.x + _offset) return false;
		if(_pos.y < _rectLu.y + _offset) return false;
		if(_pos.y > _rectLu.y + _rectSize.y - _offset) return false;
		return true;
	}
	
	/*取得当前的layer*/
	public static Layer getCurrentLayer(){
		return currentLayer;
	}
	/*切换场景(scene)*/
	public static void changeScene(int _layer_protocal){
		Layer _new = LayerMaker.makeLayer(_layer_protocal);
		Director.getInstance().pushScene(SceneMaker.makeSceneWithLayer(
				_new));
		currentLayer = _new;//对当前的Layer复值
	}
	/*初始驱动代码*/
	public static void runApplication(){
	     //载入初始的scene
		Layer _start = LayerMaker.makeLayer(Protocal_layers.default_layer);
        Director.getInstance().runWithScene(SceneMaker.makeSceneWithLayer(_start));
	    currentLayer = _start;
	}
}
