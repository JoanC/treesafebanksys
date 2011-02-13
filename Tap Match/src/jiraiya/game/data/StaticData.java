package jiraiya.game.data;

import jiraiya.game.controll.LayerMaker;
import jiraiya.game.controll.SceneMaker;
import protocal.Protocal_layers;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;

public class StaticData {
	private static Layer currentLayer;//��ǰ��Layerֵ
	public static WYPoint GetMiddleData(){
		//ȡ��������Ļ��λ��
		WYPoint _pos = WYPoint.make(0, 0);
		//ȡ����������ֵ
		_pos.x = Director.getInstance().getWindowSize().width / 2;
		_pos.y = Director.getInstance().getWindowSize().height / 2;
		return _pos;
	}
	
	public static WYPoint GetScreenSize(){
		//ȡ����Ļ�Ĵ�С,�� * ��
		return WYPoint.make(Director.getInstance().getWindowSize().width,
				Director.getInstance().getWindowSize().height);
	}
	
	/*�Դ�ͼƬ�����Ͻ�Ϊԭ����������ת��Ϊ����Ļ����Ե����Ͻ�����*/
	public static WYPoint ConvertFromBigPicPosToScreenPos(WYPoint _bigLuPos
			,WYPoint _bigPicPos/*СĿ��ͼƬ�ڴ�ͼƬ�ϵ��������*/){
		WYPoint _screenPos = WYPoint.make(0, 0);
		_screenPos.x = _bigLuPos.x + _bigPicPos.x;
		_screenPos.y = _bigLuPos.y + _bigPicPos.y;
		return _screenPos;
	}
	
	/*����һ��picture,���ݸ�����������Ͻ������Լ���С,���������Ļ�ϵ���ʾ����*/
	public static WYPoint CalcuPosFromLuAndSize(WYPoint _lu,WYPoint _size){
		WYPoint _pos = WYPoint.make(0, 0);
		_pos.x = _lu.x + (0.5f) * _size.x;
		_pos.y = GetScreenSize().y - _lu.y - (0.5f)*_size.y;
		return _pos;
	}
	
	/*����һ��picture,���ݸ��������������Լ���С,���������Ļ�����Ͻ�*/
	public static WYPoint CalcuLuFronPosAndSize(WYPoint _pos,WYPoint _size){
		WYPoint _lu = WYPoint.make(0, 0);
		_lu.x = _pos.x - (0.5f) * _size.x;
		_lu.y = GetScreenSize().y - _pos.y - (0.5f) * _size.y;
		return _lu;
	}
	
	/*����һ��position,����ת��Ϊ��������Ͻǵ�����*/
	public static WYPoint ConvertFromPosToLuPos(WYPoint _pos){
		WYPoint _new = WYPoint.make(0, 0);
		_new.x = _pos.x;
		_new.y = GetScreenSize().y - _pos.y;
		return _new;
	}
	
	/*�ж�һ�������Ƿ���һ�������ڲ�,�����������Ͻ�����;��εĴ�С*/
	/*����true��ʾ���ھ����ڲ�,false��ʾ�ھ����ⲿ*/
	public static boolean isPosInRect(WYPoint _pos,WYPoint _rectLu,WYPoint _rectSize,float _offset){
		if(_pos.x < _rectLu.x - _offset) return false;
		if(_pos.x > _rectLu.x + _rectSize.x + _offset) return false;
		if(_pos.y < _rectLu.y + _offset) return false;
		if(_pos.y > _rectLu.y + _rectSize.y - _offset) return false;
		return true;
	}
	
	/*ȡ�õ�ǰ��layer*/
	public static Layer getCurrentLayer(){
		return currentLayer;
	}
	/*�л�����(scene)*/
	public static void changeScene(int _layer_protocal){
		Layer _new = LayerMaker.makeLayer(_layer_protocal);
		Director.getInstance().pushScene(SceneMaker.makeSceneWithLayer(
				_new));
		currentLayer = _new;//�Ե�ǰ��Layer��ֵ
	}
	/*��ʼ��������*/
	public static void runApplication(){
	     //�����ʼ��scene
		Layer _start = LayerMaker.makeLayer(Protocal_layers.default_layer);
        Director.getInstance().runWithScene(SceneMaker.makeSceneWithLayer(_start));
	    currentLayer = _start;
	}
}
