package jiraiya.paul_jump;

import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.nodes.Sprite;

public class GameLayer extends Scene {

	public GameLayer() {
		super();
		// TODO Auto-generated constructor stub
		this.LoadGameBackground();
	}
	
	void LoadGameBackground(){
		Sprite _back = Sprite.make(R.drawable.game);//‘ÿ»ÎÕº∆¨
		_back.setPosition(StaticData.GetMiddleData());
		this.addChild(_back,-1);
	}
	
}
