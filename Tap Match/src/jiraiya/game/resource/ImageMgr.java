package jiraiya.game.resource;

import com.wiyun.engine.library.R;
import com.wiyun.engine.nodes.Sprite;

public class ImageMgr {
	private Sprite mDefault;//最初始的图片 default.png

	public Sprite getmDefault() {
		return mDefault;
	}
	
	//载入初始图片
	void loadDefault(){
		mDefault = Sprite.make(R.drawable.defaultimage);
	}
	
}
