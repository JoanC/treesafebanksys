package main;

import other.Debuger;
import android.view.MotionEvent;


import jiraiya.game.data.SmallPic_changeUI_data;

public class SmallChangeUI {
	SmallPic_changeUI_data data;//СĿ��ͼƬ��ѡ��UI����
	
	
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
	   //�����Ĵ�����,����СĿ��ͼƬ,��ǰ��ż�1
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
