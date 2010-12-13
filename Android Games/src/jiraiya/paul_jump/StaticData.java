package jiraiya.paul_jump;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.types.WYPoint;

public class StaticData {
	static public WYPoint GetMiddleData(){
		//取得中心屏幕的位置
		WYPoint _pos = WYPoint.make(0, 0);
		//取得两个坐标值
		_pos.x = Director.getInstance().getWindowSize().width / 2;
		_pos.y = Director.getInstance().getWindowSize().height / 2;
		return _pos;
	}
}
