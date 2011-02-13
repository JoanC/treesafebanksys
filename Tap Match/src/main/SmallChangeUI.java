package main;

import other.Debuger;
import android.view.MotionEvent;


import jiraiya.game.data.SmallPic_changeUI_data;

public class SmallChangeUI {
	SmallPic_changeUI_data data;//小目标图片的选择UI数据
	
	
	public SmallChangeUI(SmallPic_changeUI_data data) {
		super();
		this.data = data;
	}

	public void setData(SmallPic_changeUI_data _data){
		this.data = _data;
	}
	
	public int getCurrentTarget(){
		return data.getCurrent();
	}
	
	public void autoChangeTarget() {
	   //点击后的处理函数,更替小目标图片,当前标号加1
		if(data.getCurrent() == data.getSmallTargetsSize() - 1){
			data.setCurrent(0);
		}
		else{
			data.setCurrent(data.getCurrent()+1);
			Debuger.printer("current target is NO." + this.getCurrentTarget());
		}
		return ;
	}
}
