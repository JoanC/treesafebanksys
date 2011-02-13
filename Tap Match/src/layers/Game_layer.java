package layers;

import other.Debuger;
import main.MainGameMgr;
import jiraiya.game.data.StaticData;
import jiraiya.game.skeleton.Layer_Struct;

import android.view.MotionEvent;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;

public class Game_layer extends Layer implements Layer_Struct {
	MainGameMgr test;
	
	public Game_layer() {
		// TODO Auto-generated constructor stub
		test = new MainGameMgr(1);
		test.updateUI(this);
		generateLayer();
	}
	@Override
	public void generateLayer() {
		// TODO Auto-generated method stub
		this.setTouchEnabled(true);
	}

	@Override
	public Object readData() {
		// TODO Auto-generated method stub
		return null;
	}
	
	 @Override
	public boolean wyTouchesBegan(MotionEvent event) {
		WYPoint convertedLocation = StaticData.ConvertFromPosToLuPos(
				Director.getInstance().convertToGL(event.getX(), event.getY()));
		Debuger.printer("the touch position: " + (int)convertedLocation.x +"," + 
				(int)convertedLocation.y);
		test.InputControll(convertedLocation);
		test.updateUI(this);
		return true;
	}
}
