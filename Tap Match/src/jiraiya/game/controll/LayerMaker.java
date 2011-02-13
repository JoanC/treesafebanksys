package jiraiya.game.controll;

import layers.Default_layer;
import layers.Game_layer;
import layers.Menu_layer;
import layers.Select_layer;
import protocal.Protocal_layers;

import com.wiyun.engine.nodes.Layer;

public class LayerMaker {
	
	private LayerMaker() {
		super();
		// TODO Auto-generated constructor stub
		//禁用构造函数
	}

	private static Layer makeDefaultLayer(){
		return new Default_layer();
	}
	
	private static Layer makeMenuLayer(){
		return new Menu_layer();
	}
	
	private static Layer makeSelectLayer(){
		return new Select_layer();
	}
	
	private static Layer makeGameLayer(){
		return new Game_layer();
	}
	
	public static Layer makeLayer(int _protocol_layer_id){
		switch (_protocol_layer_id) {
		case Protocal_layers.default_layer:{
			return makeDefaultLayer();
		}
		case Protocal_layers.menu_layer:{
			return makeMenuLayer();
		}
		case Protocal_layers.select_layer:{
			return makeSelectLayer();
		}
		case Protocal_layers.game_layer:{
			return makeGameLayer();
		}
		default:
			return null;
		}
	}
}
