package layers;

import protocal.Protocal_select;
import jiraiya.game.data.Data_layer_select;
import jiraiya.game.data.StaticData;
import jiraiya.game.skeleton.Layer_Struct;

import com.wiyun.engine.library.R;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYPoint;

public class Select_layer extends Layer implements Layer_Struct {
	Data_layer_select data = new Data_layer_select();//关卡选择层的数据
	public Select_layer() {
		super();
		// TODO Auto-generated constructor stub
		data = (Data_layer_select) this.readData();
		this.generateLayer();
	}

	@Override
	public void generateLayer() {
		// TODO Auto-generated method stub
		this.addChild(this.generateBackGround(), data.getBackGround().getDisplay_z());
		this.addChild(this.generateBackButton(), data.getBackButton().getDisplay_z());
	}

	@Override
	public Object readData() {
		// TODO Auto-generated method stub
		Data_layer_select _data = new Data_layer_select();
		//按钮的数据信息
		_data.getBackButton().setNomal_resourse_id(R.drawable.test_back_button_normal);
		_data.getBackButton().setSelect_resourse_id(R.drawable.test_back_button_selectes);
		_data.getBackButton().setPosition(WYPoint.make(100, 100));
		_data.getBackButton().setDisplay_z(1);
		//背景图片的数据信息
		_data.getBackGround().setResoruse_id(R.drawable.defaultimage);
		_data.getBackGround().setPosition(StaticData.GetMiddleData());
		_data.getBackGround().setDisplay_z(-1);
		return _data;
	}
	
	private Button generateBackButton(){
		String _callback =  Protocal_select.backButtonCallBackFunc;//回调函数
		Button _back = Button.make(data.getBackButton().getNomal_resourse_id(),
				data.getBackButton().getSelect_resourse_id(), this,_callback);
		_back.setPosition(data.getBackButton().getPosition());
		return _back;
	}
	
	private Sprite generateBackGround(){
		Sprite _background = Sprite.make(data.getBackGround().getResoruse_id());
		_background.setPosition(data.getBackGround().getPosition());
		return _background;
	}
	
	public void onBackToMenu(){
		Director.getInstance().popScene();
	}
}
