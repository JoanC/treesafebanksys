package jiraiya.game.resource;

import com.wiyun.engine.library.R;
import com.wiyun.engine.nodes.Sprite;

public class ImageMgr {
	private Sprite mDefault;//���ʼ��ͼƬ default.png

	public Sprite getmDefault() {
		return mDefault;
	}
	
	//�����ʼͼƬ
	void loadDefault(){
		mDefault = Sprite.make(R.drawable.defaultimage);
	}
	
}
