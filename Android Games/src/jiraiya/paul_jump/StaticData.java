package jiraiya.paul_jump;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.types.WYPoint;

public class StaticData {
	static public WYPoint GetMiddleData(){
		//ȡ��������Ļ��λ��
		WYPoint _pos = WYPoint.make(0, 0);
		//ȡ����������ֵ
		_pos.x = Director.getInstance().getWindowSize().width / 2;
		_pos.y = Director.getInstance().getWindowSize().height / 2;
		return _pos;
	}
}
